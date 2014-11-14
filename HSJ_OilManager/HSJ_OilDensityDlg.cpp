// HSJ_OilDensityDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HSJ_OilManager.h"
#include "HSJ_OilDensityDlg.h"

// HSJ_OilDensityDlg 对话框

IMPLEMENT_DYNAMIC(HSJ_OilDensityDlg, CDialog)

HSJ_OilDensityDlg::HSJ_OilDensityDlg(CWnd* pParent /*=NULL*/)
    : CDialog(HSJ_OilDensityDlg::IDD, pParent),
    HSJ_BaseDlg()
{

}

HSJ_OilDensityDlg::~HSJ_OilDensityDlg()
{
}

void HSJ_OilDensityDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_OIL_DENSITY_LISTCONTROL, m_OilDensityListCtrl);
    DDX_Control(pDX, IDC_COMPANY_ID_COMBO, m_CompanyIDCombo);
    DDX_Control(pDX, IDC_OIL_TYPE_COMBO, m_OilTypeCombo);
    DDX_Control(pDX, IDC_COMPANY_NAME_CONTENT_LABEL, m_CompanyNameLabel);
    DDX_Control(pDX, IDC_OIL_TYPE_CONTENT_LABEL, m_OilTypeLabel);
    DDX_Control(pDX, IDC_DENSITY_LOAD_STATUS_LABEL, m_LoadStatus);
    DDX_Control(pDX, IDC_DENSITY_DETAIL_ID_EDIT, m_varIDEdit);
    DDX_Control(pDX, IDC_DENSITY_DETAIL_SUMMBER_EDIT, m_varDensitySummerEdit);
    DDX_Control(pDX, IDC_DENSITY_DETAIL_WINTER_EDIT, m_varDensityWinterEdit);
    DDX_Control(pDX, IDC_DENSITY_EDIT_BTN, m_varEditBtn);
    DDX_Control(pDX, IDC_DENSITY_ADD_BTN, m_varAddBtn);
    DDX_Control(pDX, IDC_DENSITY_DELETE_BTN, m_varDelBtn);
}


BEGIN_MESSAGE_MAP(HSJ_OilDensityDlg, CDialog)
    ON_BN_CLICKED(IDC_DENSITY_LOAD_BTN, &HSJ_OilDensityDlg::OnBnClickedDensityLoadBtn)
    ON_CBN_SELCHANGE(IDC_DENSITY_COMPANY_ID_COMBO, &HSJ_OilDensityDlg::OnCbnSelchangeDensityCompanyIdCombo)
    ON_CBN_SELCHANGE(IDC_DENSITY_OIL_TYPE_COMBO, &HSJ_OilDensityDlg::OnCbnSelchangeDensityOilTypeCombo)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_OIL_DENSITY_LISTCONTROL, &HSJ_OilDensityDlg::OnLvnItemchangedOilDensityListcontrol)
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_DENSITY_EDIT_BTN, &HSJ_OilDensityDlg::OnBnClickedDensityEditBtn)
    ON_BN_CLICKED(IDC_DENSITY_ADD_BTN, &HSJ_OilDensityDlg::OnBnClickedDensityAddBtn)
    ON_BN_CLICKED(IDC_DENSITY_DELETE_BTN, &HSJ_OilDensityDlg::OnBnClickedDensityDeleteBtn)
END_MESSAGE_MAP()


// HSJ_OilDensityDlg 消息处理程序
BOOL HSJ_OilDensityDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    SetValues();
    SetListReport();

    m_OilDensityListCtrl.InsertColumn(0, STR_UI_OIL_DENSITY_ID, LVCFMT_LEFT, 100);
    m_OilDensityListCtrl.InsertColumn(1, STR_UI_OIL_DENSITY_SUMMER, LVCFMT_LEFT, 200);
    m_OilDensityListCtrl.InsertColumn(2, STR_UI_OIL_DENSITY_WINTER, LVCFMT_LEFT, 200);    

    ResetVarEdit();

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void HSJ_OilDensityDlg::SetValues()
{
    m_pListCtrl = &m_OilDensityListCtrl;
    m_pvarEditBtn = &m_varEditBtn;
    m_pvarAddBtn = &m_varAddBtn;
    m_pvarDelBtn = &m_varDelBtn;
    m_pBaseModal = &m_varOilDensityModal;

    m_staticEditVec.push_back(&m_varIDEdit);
    m_varEditVec.push_back(&m_varDensitySummerEdit);
    m_varEditVec.push_back(&m_varDensityWinterEdit);

    m_dlgHWND = m_hWnd;
}

void HSJ_OilDensityDlg::OnBnClickedDensityLoadBtn()
{
    DBHelper::GetInstance()->ReloadOilDensity();

    m_CompanyIDCombo.ResetContent();

    CompanyMap* companyMap = DBHelper::GetInstance()->GetCompanyMap();

    POSITION pos = companyMap->GetStartPosition();
    while (pos != NULL)
    {
        int key = 0;
        CompanyModal cm;
        companyMap->GetNextAssoc(pos, key, cm);
        m_CompanyIDCombo.AddString(Utils::Int2CString(key));
    }


    m_OilTypeCombo.ResetContent();

    OilTypeMap* oilTypeMap = DBHelper::GetInstance()->GetOilTypeMap();

    pos = oilTypeMap->GetStartPosition();
    while (pos != NULL)
    {
        int key = 0;
        OilTypeModal om;
        oilTypeMap->GetNextAssoc(pos, key, om);
        m_OilTypeCombo.AddString(Utils::Int2CString(key));
    }

    RefreshListCtrl();

    m_LoadStatus.SetWindowTextW(STR_LOADED);
}

void HSJ_OilDensityDlg::RefreshListCtrl()
{
    m_OilDensityListCtrl.DeleteAllItems();
    ResetVarEdit();

    int nIndex = m_CompanyIDCombo.GetCurSel();
    if (nIndex == -1) return;
    CString strCompanyID = STR_EMPTY;
    m_CompanyIDCombo.GetLBText(nIndex, strCompanyID);
    if (strCompanyID.GetLength() == 0) return;
    int companyID = Utils::CString2Int(strCompanyID);

    nIndex = m_OilTypeCombo.GetCurSel();
    if (nIndex == -1) return;
    CString strTypeID = STR_EMPTY;
    m_OilTypeCombo.GetLBText(nIndex, strTypeID);
    if (strTypeID.GetLength() == 0) return;
    int typeID = _ttoi(strTypeID);

    OilDensityMap* oilDensityMap = DBHelper::GetInstance()->GetOilDensityMap();

    POSITION pos = oilDensityMap->GetStartPosition();
    while (pos != NULL)
    {
        int key = 0;
        OilDensityModal odm;
        oilDensityMap->GetNextAssoc(pos, key, odm);

        if (odm.m_CompanyID != companyID || 
            odm.m_OilTypeID != typeID) continue;

        CString str;
        str.Format(STR_INT, key);
        int nRow = m_OilDensityListCtrl.InsertItem(0, str);

        str.Format(STR_FLOAT_3, odm.m_OilDensitySummer);
        m_OilDensityListCtrl.SetItemText(nRow, 1, str);

        str.Format(STR_FLOAT_3, odm.m_OilDensityWinter);
        m_OilDensityListCtrl.SetItemText(nRow, 2, str);
    }
}

bool HSJ_OilDensityDlg::UpdateModal2UI()
{
    m_varIDEdit.SetWindowTextW(m_varOilDensityModal.GetOilDensityID());
    m_varDensitySummerEdit.SetWindowTextW(m_varOilDensityModal.GetOilDensitySummer());
    m_varDensityWinterEdit.SetWindowTextW(m_varOilDensityModal.GetOilDensityWinter());

    return true;
}

bool HSJ_OilDensityDlg::UpdateUI2Modal(bool bNoEmpty)
{
    CString windowText(STR_EMPTY);
    m_varDensitySummerEdit.GetWindowTextW(windowText);
    m_varOilDensityModal.m_OilDensitySummer = Utils::CString2Double(windowText);

    if (bNoEmpty && 
        (windowText.GetLength() == 0 ||
        m_varOilDensityModal.m_OilDensitySummer == 0))
    {
        MessageBox(CString(STR_ERROR_INPUT_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }

    m_varDensityWinterEdit.GetWindowTextW(windowText);
    m_varOilDensityModal.m_OilDensityWinter = Utils::CString2Double(windowText);

    if (bNoEmpty && 
        (windowText.GetLength() == 0 ||
        m_varOilDensityModal.m_OilDensityWinter == 0))
    {
        MessageBox(CString(STR_ERROR_INPUT_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }

    return true;
}

void HSJ_OilDensityDlg::OnCbnSelchangeDensityCompanyIdCombo()
{
    int nIndex = m_CompanyIDCombo.GetCurSel();
    if (nIndex == CB_ERR) return;

    CString strCompanyID = STR_EMPTY;
    m_CompanyIDCombo.GetLBText(nIndex, strCompanyID);

    int companyID = Utils::CString2Int(strCompanyID);
    m_varOilDensityModal.m_CompanyID = companyID;

    CompanyMap* companyMap = DBHelper::GetInstance()->GetCompanyMap();
    CompanyModal cm;

    if (companyMap->Lookup(companyID, cm))
    {
        m_CompanyNameLabel.SetWindowTextW(cm.m_CompanyName);
    }

    RefreshListCtrl();
}

void HSJ_OilDensityDlg::OnCbnSelchangeDensityOilTypeCombo()
{
    int nIndex = m_OilTypeCombo.GetCurSel();
    if (nIndex == CB_ERR) return;

    CString strTypeID = STR_EMPTY;
    m_OilTypeCombo.GetLBText(nIndex, strTypeID);

    int typeID = Utils::CString2Int(strTypeID);
    m_varOilDensityModal.m_OilTypeID = typeID;

    OilTypeMap* oilTypeMap = DBHelper::GetInstance()->GetOilTypeMap();
    OilTypeModal om;

    if (oilTypeMap->Lookup(typeID, om))
    {
        m_OilTypeLabel.SetWindowTextW(om.m_OilTypeComments);
    }

    RefreshListCtrl();
}

void HSJ_OilDensityDlg::OnLvnItemchangedOilDensityListcontrol(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

    BOOL bSelectedNow = (pNMLV->uNewState & LVIS_SELECTED);
    BOOL bSelectedBefore = (pNMLV ->uOldState & LVIS_SELECTED);
    
    if (!bSelectedNow && bSelectedBefore)
    {
        ResetVarEdit();
    }

    if (bSelectedNow && !bSelectedBefore)
    {
        int nItemIndex = pNMLV->iItem;

        if (nItemIndex != -1)
        {
            int oilDensityID = 
                Utils::CString2Int(m_OilDensityListCtrl.GetItemText(nItemIndex, 0));
            
             OilDensityMap* oilDensityMap = DBHelper::GetInstance()->GetOilDensityMap();

             if (oilDensityMap != NULL)
             {
                if (oilDensityMap->Lookup(oilDensityID, m_varOilDensityModal))
                {
                    ResetVarEdit();
                    UpdateModal2UI();
                    EnableVarEdit(true, false);
                }
             }
        }
        else
        {
            ResetVarEdit();
        }
    }

    *pResult = 0;
}

HBRUSH HSJ_OilDensityDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

    //if (pWnd->GetDlgCtrlID() == IDC_DENSITY_DETAIL_ID_EDIT ||
    //    pWnd->GetDlgCtrlID() == IDC_DENSITY_DETAIL_SUMMBER_EDIT || 
    //    pWnd->GetDlgCtrlID() == IDC_DENSITY_DETAIL_WINTER_EDIT)
    //{
    //    if (m_bEditMode)
    //    {
    //        pDC->SetTextColor(RGB(0, 0, 0));
    //    }
    //    else
    //    {
    //        pDC->SetTextColor(RGB(128, 128, 128));
    //    }
    //}

    return hbr;
}

void HSJ_OilDensityDlg::OnBnClickedDensityEditBtn()
{
    OnEditBtnClick();
}

bool HSJ_OilDensityDlg::PrepareEdit()
{
    return UpdateUI2Modal(true);
}

bool HSJ_OilDensityDlg::DoEdit()
{
    bool bEditSuc = DBHelper::GetInstance()->UpdateOilDensity(m_varOilDensityModal, DBHelper::DB_ACT_UPDATE);
    if (bEditSuc)
    {
        DBHelper::GetInstance()->ReloadOilDensity();
        RefreshListCtrl();
    }

    MessageBox(CString(STR_UPDATE_OIL_DENSITY) + (bEditSuc ? CString(STR_SUCCESS) : CString(STR_FAILED)), 
        CString(STR_TIP), MB_OK);

    return bEditSuc;
}

void HSJ_OilDensityDlg::OnBnClickedDensityAddBtn()
{
    OnAddBtnClick();
}

bool HSJ_OilDensityDlg::PrepareAdd()
{
    UpdateUI2Modal(false);

    if (m_varOilDensityModal.m_OilDensitySummer == 0 || 
        m_varOilDensityModal.m_OilDensityWinter == 0)
    {
        MessageBox(CString(STR_ERROR_INPUT_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }

    if (CB_ERR == m_CompanyIDCombo.GetCurSel())
    {
        MessageBox(CString(STR_ERROR_COMPANY_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }

    if (CB_ERR == m_OilTypeCombo.GetCurSel())
    {
        MessageBox(CString(STR_ERROR_OIL_TYPE_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }

    return true;
}

bool HSJ_OilDensityDlg::DoAdd()
{
    bool bAddSuc = DBHelper::GetInstance()->UpdateOilDensity(m_varOilDensityModal, DBHelper::DB_ACT_ADD);
    if (bAddSuc)
    {
        DBHelper::GetInstance()->ReloadOilDensity();
        RefreshListCtrl();
    }

    MessageBox(CString(STR_ADD_OIL_DENSITY) + (bAddSuc ? CString(STR_SUCCESS) : CString(STR_FAILED)), 
        CString(STR_TIP), MB_OK);

    return bAddSuc;
}

void HSJ_OilDensityDlg::OnBnClickedDensityDeleteBtn()
{
    OnDelBtnClick();
}

bool HSJ_OilDensityDlg::PrepareDel()
{
    return true;
}

bool HSJ_OilDensityDlg::DoDel()
{
    bool bDelSuc = DBHelper::GetInstance()->UpdateOilDensity(m_varOilDensityModal, DBHelper::DB_ACT_DEL);
    if (bDelSuc)
    {
        DBHelper::GetInstance()->ReloadOilDensity();
        RefreshListCtrl();
        ResetVarModal();
    }

    MessageBox(CString(STR_DEL_OIL_DENSITY) + (bDelSuc ? CString(STR_SUCCESS) : CString(STR_FAILED)), 
        CString(STR_TIP), MB_OK);

    return bDelSuc;
}