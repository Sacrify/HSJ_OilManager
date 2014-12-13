#include "StdAfx.h"
#include "DBHelper.h"

//#include <comdef.h>
//#include <icrsint.h>
//#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "ADOEOF")


DBHelper::DBHelper(void)
{
    m_CompanyTypeMap = new CompanyTypeMap();
    m_CompanyMap = new CompanyMap();

    m_OilTypeMap = new OilTypeMap();
    m_OilDensityMap = new OilDensityMap();

    m_OilPriceMap = new OilPriceMap();
    m_ShipList = new ShipList();
}

DBHelper::~DBHelper(void)
{
    if (m_pConnection)
    {
        if (m_pConnection->GetState() == adStateOpen)
        {
            m_pConnection->Close();
        }

        m_pConnection.Release();
        m_pConnection = NULL;
    }

    if (m_CompanyTypeMap)
    {
        delete m_CompanyTypeMap;
        m_CompanyTypeMap = NULL;
    }

    if (m_CompanyMap)
    {
        delete m_CompanyMap;
        m_CompanyMap = NULL;
    }

    if (m_OilTypeMap)
    {
        delete m_OilTypeMap;
        m_OilTypeMap = NULL;
    }

    if (m_OilDensityMap)
    {
        delete m_OilDensityMap;
        m_OilDensityMap = NULL;
    }

    if (m_ShipList)
    {
        delete m_ShipList;
        m_ShipList = NULL;
    }
}

DBHelper* DBHelper::m_pInstance = NULL;
DBHelper* DBHelper::GetInstance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new DBHelper();
    }

    return m_pInstance;
}

bool DBHelper::InitInstance()
{
    if (AfxOleInit() == false)
    {
        AfxMessageBox(_T("OLE Initialzation Fail!"));
        return false;
    }

    try
    {
        if (FAILED(m_pConnection.CreateInstance("ADODB.Connection")))
        {
            AfxMessageBox(_T("Create ADODB Connection Fail!"));
            return false;
        }
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return false;
    }

    try
    {
        if(FAILED(m_pRecordset.CreateInstance("ADODB.Recordset")))
        {
            AfxMessageBox(_T("Create ADODB Recordset Fail!"));
            return false;
        }
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return false;
    }

    return true;
}

CompanyTypeMap* DBHelper::GetCompanyTypeMap()
{
    return m_CompanyTypeMap;
}

CompanyMap* DBHelper::GetCompanyMap()
{
    return m_CompanyMap;
}

OilTypeMap* DBHelper::GetOilTypeMap()
{
    return m_OilTypeMap;
}

OilDensityMap* DBHelper::GetOilDensityMap()
{
    return m_OilDensityMap;
}

OilPriceMap* DBHelper::GetOilPriceMap()
{
    return m_OilPriceMap;
}

ShipList* DBHelper::GetShipList()
{
    return m_ShipList;
}

bool DBHelper::OpenDB()
{
    if (m_pConnection)
    {
        if (m_pConnection->GetState() != adStateOpen)
        {
            try
            {
				CString connStr = Utils::GetConnectionString();
				if (connStr.IsEmpty())
				{
					connStr = _T("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=OilDB;Data Source=.");
				}

                return 
                    (SUCCEEDED(
                    m_pConnection->Open(
                    (_bstr_t)connStr,
					"",
                    "",
                    adModeUnknown)));///连接数据库
            }
            catch (_com_error &e)  
            {  
                AfxMessageBox(e.Description());
                return false;
            }
        }
        else
        {
            return true;
        }
    }

    return false;
}

void DBHelper::ReloadAll()
{
    ReloadCompanyTypeMap();
    ReloadCompanyMap();

    ReloadOilTypeMap();
    ReloadOilDensityMap();
}

void DBHelper::ReloadOilDensity()
{
    ReloadCompanyTypeMap();
    ReloadCompanyMap();

    ReloadOilTypeMap();
    ReloadOilDensityMap();
}

void DBHelper::ReloadOilPrice()
{
    ReloadOilTypeMap();
    ReloadOilPriceMap();
}

void DBHelper::ReloadShip()
{
    ReloadCompanyTypeMap();
    ReloadCompanyMap();
    ReloadShipList();
}

void DBHelper::ReloadCompanyTypeMap()
{
    try
    {
        if (SelectDB("SELECT CompanyTypeID, CompanyTypeName " \
            "FROM hsj_company_type") == false) return;
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return;
    }

    if (m_CompanyTypeMap) m_CompanyTypeMap->RemoveAll();

    while (!m_pRecordset->ADOEOF)
    {
        _variant_t CompanyTypeID, CompanyTypeName;

        try
        {
            CompanyTypeID = m_pRecordset->GetCollect("CompanyTypeID");
            CompanyTypeName = m_pRecordset->GetCollect("CompanyTypeName");

            CompanyTypeModal ctm;
            ctm.m_CompanyTypeID = CompanyTypeID.intVal;
            ctm.m_CompanyTypeName = CompanyTypeName.bstrVal;

            m_CompanyTypeMap->SetAt(ctm.m_CompanyTypeID, ctm);
        }
        catch (_com_error &e)  
        {  
            AfxMessageBox(e.Description());
        }

        m_pRecordset->MoveNext();
    }

    m_pRecordset->Close();
}

void DBHelper::ReloadCompanyMap()
{
    try
    {
        if (SelectDB("SELECT CompanyID, CompanyName, CompanyTypeID, CompanyParentID " \
            "FROM hsj_company") == false) return;
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return;
    }

    if (m_CompanyMap) m_CompanyMap->RemoveAll();

    while (!m_pRecordset->ADOEOF)
    {
        _variant_t CompanyID, CompanyName, CompanyTypeID, CompanyParentID;

        try
        {
            CompanyID = m_pRecordset->GetCollect("CompanyID");
            CompanyName = m_pRecordset->GetCollect("CompanyName");
            CompanyTypeID = m_pRecordset->GetCollect("CompanyTypeID");
            CompanyParentID = m_pRecordset->GetCollect("CompanyParentID");

            CompanyModal cm;
            cm.m_CompanyID = CompanyID.intVal;
            cm.m_CompanyName = CompanyName.bstrVal;
            cm.m_CompanyTypeID = CompanyTypeID.intVal;
            cm.m_CompanyParentID = CompanyParentID.intVal;

            m_CompanyMap->SetAt(cm.m_CompanyID, cm);
        }
        catch (_com_error &e)  
        {  
            AfxMessageBox(e.Description());
        }

        m_pRecordset->MoveNext();
    }

    m_pRecordset->Close();
}

void DBHelper::ReloadOilTypeMap()
{
    try
    {
        if (SelectDB("SELECT OilTypeID, OilTypeComments " \
            "FROM hsj_oil_type") == false) return;
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return;
    }

    if (m_OilTypeMap) m_OilTypeMap->RemoveAll();

    while (!m_pRecordset->ADOEOF)
    {
        _variant_t OilTypeID, OilTypeComments;

        try
        {
            OilTypeID = m_pRecordset->GetCollect("OilTypeID");
            OilTypeComments = m_pRecordset->GetCollect("OilTypeComments");

            OilTypeModal otm;
            otm.m_OilTypeID = OilTypeID.intVal;
            otm.m_OilTypeComments = OilTypeComments.bstrVal;

            m_OilTypeMap->SetAt(otm.m_OilTypeID, otm);
        }
        catch (_com_error &e)  
        {  
            AfxMessageBox(e.Description());
        }

        m_pRecordset->MoveNext();
    }

    m_pRecordset->Close();
}

void DBHelper::ReloadOilDensityMap()
{
    try
    {
        if (SelectDB("SELECT OilDensityID, CompanyID, OilTypeID, OilDensitySummer, OilDensityWinter " \
            "FROM hsj_oil_density") == false) return;
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return;
    }

    if (m_OilDensityMap) m_OilDensityMap->RemoveAll();

    while (!m_pRecordset->ADOEOF)
    {
        _variant_t OilDensityID, CompanyID, OilTypeID, OilDensitySummer, OilDensityWinter;

        try
        {
            OilDensityID = m_pRecordset->GetCollect("OilDensityID");
            CompanyID = m_pRecordset->GetCollect("CompanyID");
            OilTypeID = m_pRecordset->GetCollect("OilTypeID");
            OilDensitySummer = m_pRecordset->GetCollect("OilDensitySummer");
            OilDensityWinter = m_pRecordset->GetCollect("OilDensityWinter");

            OilDensityModal odm;
            odm.m_OilDensityID = OilDensityID.intVal;
            odm.m_CompanyID = CompanyID.intVal;
            odm.m_OilTypeID = OilTypeID.intVal;
            odm.m_OilDensitySummer = OilDensitySummer.dblVal;
            odm.m_OilDensityWinter = OilDensityWinter.dblVal;

            if (m_OilDensityMap) m_OilDensityMap->SetAt(odm.m_OilDensityID, odm);
        }
        catch (_com_error &e)  
        {  
            AfxMessageBox(e.Description());
        }

        m_pRecordset->MoveNext();
    }

    m_pRecordset->Close();
}

void DBHelper::ReloadOilPriceMap()
{
    try
    {
        if (SelectDB("SELECT OilPriceID, stime, price, OilTypeID " \
                "FROM hsj_oil_price") == false) return;
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return;
    }

    if (m_OilPriceMap) m_OilPriceMap->RemoveAll();

    while (!m_pRecordset->ADOEOF)
    {
        _variant_t OilPriceID, stime, price, OilTypeID;

        try
        {
            OilPriceID = m_pRecordset->GetCollect("OilPriceID");
            stime = m_pRecordset->GetCollect("stime");
            price = m_pRecordset->GetCollect("price");
            OilTypeID = m_pRecordset->GetCollect("OilTypeID");

            OilPriceModal opm;
            opm.m_OilPriceID = OilPriceID.intVal;
            opm.m_Stime = Utils::Variant2CTimeDay(stime);
            opm.m_Price = price.dblVal;
            opm.m_OilTypeID = OilTypeID.intVal;

            if (m_OilPriceMap) m_OilPriceMap->SetAt(opm.m_OilPriceID, opm);
        }
        catch (_com_error &e)
        {  
            AfxMessageBox(e.Description());
        }

        m_pRecordset->MoveNext();
    }

    m_pRecordset->Close();
}

void DBHelper::ReloadShipList()
{
    
}

bool DBHelper::SelectDB(const _bstr_t& commandLine)
{
    if (OpenDB() == false) return false;
    if (commandLine.length() == 0) return false;

    try
    {
        _variant_t RecordsAffected;
        m_pRecordset = m_pConnection->Execute(
            commandLine,
            &RecordsAffected,
            adCmdText);
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return false;
    }

    return true;
}

bool DBHelper::UpdateDB(const _bstr_t& commandLine)
{
    if (OpenDB() == false) return false;
    if (commandLine.length() == 0) return false;

    try
    {
        _variant_t RecordsAffected;
        m_pConnection->Execute(
            commandLine,
            &RecordsAffected,
            adCmdText);
    }
    catch (_com_error &e)  
    {  
        AfxMessageBox(e.Description());
        return false;
    }

    return true;
}

// Update Functions
bool DBHelper::UpdateOilDensity(const OilDensityModal& modal, DB_ACT act)
{
    CString commandLine = STR_EMPTY;
    switch (act)
    {
    case DB_ACT_UPDATE:
        {
            commandLine = 
                CString("UPDATE hsj_oil_density ") +
                CString("SET ") +
                CString("OilDensitySummer = ") +
                modal.GetOilDensitySummer() + CString(", ") + 
                CString("OilDensityWinter = ") + 
                modal.GetOilDensityWinter() + CString(" ") + 
                CString("WHERE ") + 
                CString("OilDensityID = ") + 
                modal.GetOilDensityID();
        }
        break;

    case DB_ACT_ADD:
        {
            commandLine = 
                CString("INSERT INTO hsj_oil_density (CompanyID, OilTypeID, OilDensitySummer, OilDensityWinter) ") + 
                CString("VALUES ( ") + 
                modal.GetCompanyID() + CString(", ") +
                modal.GetOilTypeID() + CString(", ") +
                modal.GetOilDensitySummer() + CString(", ") + 
                modal.GetOilDensityWinter() + CString(" )");
        }
        break;

    case DB_ACT_DEL:
        {
            commandLine = 
                CString("DELETE FROM hsj_oil_density WHERE OilDensityID = ") + 
                modal.GetOilDensityID();
        }
        break;
    }

    if (commandLine != STR_EMPTY) return UpdateDB((_bstr_t)commandLine);
    else return false;
}

bool DBHelper::UpdateOilPrice(const OilPriceModal& modal, DB_ACT act)
{
    CString commandLine = STR_EMPTY;

    switch (act)
    {
    case DB_ACT_UPDATE:
        {
            commandLine = 
                CString("UPDATE hsj_oil_price ") + 
                CString("SET ") + 
                CString("stime = '") + modal.GetStime() + CString("', ") + 
                CString("price = ") + modal.GetPrice() + CString(" ") + 
                CString("WHERE ") + 
                CString("OilPriceID = ") + modal.GetOilPriceID();
        }
        break;

    case DB_ACT_ADD:
        {
            commandLine = 
                CString("INSERT INTO hsj_oil_price (stime, price, OilTypeID) ") + 
                CString("VALUES ( ") + 
                CString("'") + modal.GetStime() + CString("', ") + 
                modal.GetPrice() + CString(", ") +
                modal.GetOilTypeID() + CString(" )");
        }
        break;

    case DB_ACT_DEL:
        {
            commandLine = 
                CString("DELETE FROM hsj_oil_price WHERE OilPriceID = ") + 
                modal.GetOilPriceID();
        }
        break;
    }

    if (commandLine != STR_EMPTY) return UpdateDB((_bstr_t)commandLine);
    else return false;
}

bool DBHelper::UpdateCompany(const CompanyModal& modal, DB_ACT act)
{
    CString commandLine = STR_EMPTY;

    switch (act)
    {
    case DB_ACT_UPDATE:
        {
            commandLine = 
                CString("UPDATE hsj_company ") + 
                CString("SET ") + 
                CString("CompanyName = '" ) + modal.GetCompanyName() + CString("', ") +  
                CString("CompanyTypeID = ") + modal.GetCompanyTypeID() + CString(", ") +
                CString("CompanyParentID = ") + modal.GetCompanyParentID() + CString(", ") +
                CString("WHERE ") + 
                CString("CompanyID = ") + modal.GetCompanyID();

        }
        break;

    case DB_ACT_ADD:
        {
            commandLine = 
                CString("INSERT INTO hsj_company (CompanyName, CompanyTypeID, CompanyParentID) ") + 
                CString("VALUES ( ") + 
                CString("'") + modal.GetCompanyName() + CString("', ") +
                modal.GetCompanyTypeID() + CString(", ") + 
                modal.GetCompanyParentID() + CString(" )");
        }
        break;

    case DB_ACT_DEL:
        {
            commandLine = 
                CString("DELETE FROM hsj_company WHERE CompanyID = ") + 
                modal.GetCompanyID();
        }
        break;
    }

    if (commandLine != STR_EMPTY) return UpdateDB((_bstr_t)commandLine);
    else return false;
}


bool DBHelper::UpdateShipRegInfo(const ShipRegInfoModal& modal, DB_ACT act)
{
    CString commandLine = STR_EMPTY;

    switch (act)
    {
    case DB_ACT_UPDATE:
        {

        }
        break;

    case DB_ACT_ADD:
        {

        }
        break;

    case DB_ACT_DEL:
        {

        }
        break;
    }

    if (commandLine != STR_EMPTY) return UpdateDB((_bstr_t)commandLine);
    else return false;
}