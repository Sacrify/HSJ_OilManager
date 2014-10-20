#include "StdAfx.h"
#include "DBHelper.h"

//#include <comdef.h>
//#include <icrsint.h>
//#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "ADOEOF")


DBHelper::DBHelper(void)
{
	m_CompanyMap = new CompanyMap();
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

	if (m_CompanyMap)
	{
		delete m_CompanyMap;
		m_CompanyMap = NULL;
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

bool DBHelper::OpenDB()
{
	if (m_pConnection)
	{
		if (m_pConnection->GetState() != adStateOpen)
		{
			try
			{
				return 
					(SUCCEEDED(
					m_pConnection->Open(
					"Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=OilDB;Data Source=.",
					"",
					"",
					adModeReadWrite)));///连接数据库
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
	ReloadCompanyMap();
}

void DBHelper::ReloadCompanyMap()
{
	if (OpenDB() == false) return;

	try
	{
		_variant_t RecordsAffected; 
		m_pRecordset = m_pConnection->Execute(
			"SELECT CompanyID, CompanyName, CompanyTypeID, CompanyParentID " \
			"FROM hsj_company",
			&RecordsAffected,
			adCmdText);
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