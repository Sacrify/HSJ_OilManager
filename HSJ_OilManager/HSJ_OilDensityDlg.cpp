// HSJ_OilDensityDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HSJ_OilManager.h"
#include "HSJ_OilDensityDlg.h"

// HSJ_OilDensityDlg 对话框

IMPLEMENT_DYNAMIC(HSJ_OilDensityDlg, CDialog)

HSJ_OilDensityDlg::HSJ_OilDensityDlg(CWnd* pParent /*=NULL*/)
    : CDialog(HSJ_OilDensityDlg::IDD, pParent)
    , m_bEditMode(false)
    , m_bAddMode(false)
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
END_MESSAGE_MAP()


// HSJ_OilDensityDlg 消息处理程序
BOOL HSJ_OilDensityDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    DWORD dwExStyle = m_OilDensityListCtrl.GetExtendedStyle();
    m_OilDensityListCtrl.SetExtendedStyle(dwExStyle|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

    m_OilDensityListCtrl.InsertColumn(0, STR_UI_OIL_DENSITY_ID, LVCFMT_LEFT, 100);
    m_OilDensityListCtrl.InsertColumn(1, STR_UI_OIL_DENSITY_SUMMER, LVCFMT_LEFT, 200);
    m_OilDensityListCtrl.InsertColumn(2, STR_UI_OIL_DENSITY_WINTER, LVCFMT_LEFT, 200);

    ResetVarEdit();

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void HSJ_OilDensityDlg::OnBnClickedDensityLoadBtn()
{
    DBHelper::GetInstance()->ReloadOilDensity();

    if (m_CompanyIDCombo)
    {
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
    }

    if (m_OilTypeCombo)
    {
        m_OilTypeCombo.ResetContent();

        OilTypeMap* oilTypeMap = DBHelper::GetInstance()->GetOilTypeMap();

        POSITION pos = oilTypeMap->GetStartPosition();
        while (pos != NULL)
        {
            int key = 0;
            OilTypeModal om;
            oilTypeMap->GetNextAssoc(pos, key, om);
            m_OilTypeCombo.AddString(Utils::Int2CString(key));
        }
    }

    RefreshOilDensityListCtrl();

    m_LoadStatus.SetWindowTextW(STR_LOADED);
}

void HSJ_OilDensityDlg::RefreshOilDensityListCtrl()
{
    if (m_OilDensityListCtrl)
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
}

void HSJ_OilDensityDlg::OnCbnSelchangeDensityCompanyIdCombo()
{
    int nIndex = m_CompanyIDCombo.GetCurSel();
    CString strCompanyID = STR_EMPTY;
    m_CompanyIDCombo.GetLBText(nIndex, strCompanyID);

    int companyID = _ttoi(strCompanyID);
    CompanyMap* companyMap = DBHelper::GetInstance()->GetCompanyMap();

    CompanyModal cm;
    if (companyMap->Lookup(companyID, cm))
    {
        m_CompanyNameLabel.SetWindowTextW(cm.m_CompanyName);
    }

    RefreshOilDensityListCtrl();
}

void HSJ_OilDensityDlg::OnCbnSelchangeDensityOilTypeCombo()
{
    int nIndex = m_OilTypeCombo.GetCurSel();
    CString strTypeID = STR_EMPTY;
    m_OilTypeCombo.GetLBText(nIndex, strTypeID);

    int typeID = _ttoi(strTypeID);
    OilTypeMap* oilTypeMap = DBHelper::GetInstance()->GetOilTypeMap();

    OilTypeModal om;
    if (oilTypeMap->Lookup(typeID, om))
    {
        m_OilTypeLabel.SetWindowTextW(om.m_OilTypeComments);
    }

    RefreshOilDensityListCtrl();
}

void HSJ_OilDensityDlg::OnLvnItemchangedOilDensityListcontrol(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

    BOOL bSelectedNow = (pNMLV->uNewState & LVIS_SELECTED);
    BOOL bSelectedBefore = (pNMLV ->uOldState & LVIS_SELECTED);
    if (bSelectedNow && !bSelectedBefore)
    {
        int nItemIndex = pNMLV->iItem;

        EnableVarEdit(nItemIndex != -1);

        if (nItemIndex != -1)
        {
            int oilDensityID = 
                Utils::CString2Int(m_OilDensityListCtrl.GetItemText(nItemIndex, 0));
            
             OilDensityMap* oilDensityMap = DBHelper::GetInstance()->GetOilDensityMap();

             if (oilDensityMap != NULL)
             {
                if (oilDensityMap->Lookup(oilDensityID, m_varOilDensityModal))
                {
                    m_varIDEdit.SetWindowTextW(m_varOilDensityModal.GetOilDensityID());
                    m_varDensitySummerEdit.SetWindowTextW(m_varOilDensityModal.GetOilDensitySummer());
                    m_varDensityWinterEdit.SetWindowTextW(m_varOilDensityModal.GetOilDensityWinter());
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

    if (pWnd->GetDlgCtrlID() == IDC_DENSITY_DETAIL_ID_EDIT ||
        pWnd->GetDlgCtrlID() == IDC_DENSITY_DETAIL_SUMMBER_EDIT || 
        pWnd->GetDlgCtrlID() == IDC_DENSITY_DETAIL_WINTER_EDIT)
    {
        if (m_bEditMode)
        {
            pDC->SetTextColor(RGB(0, 0, 0));
        }
        else
        {
            pDC->SetTextColor(RGB(128, 128, 128));
        }
    }

    return hbr;
}

void HSJ_OilDensityDlg::ResetVarEdit()
{
    m_bEditMode = false;
    m_bAddMode = false;

    EnableVarEdit(false);

    m_varIDEdit.SetWindowTextW(STR_EMPTY);
    m_varDensitySummerEdit.SetWindowTextW(STR_EMPTY);
    m_varDensityWinterEdit.SetWindowTextW(STR_EMPTY);
}

void HSJ_OilDensityDlg::EnableVarEdit(bool bEnable)
{
    m_varEditBtn.EnableWindow(bEnable);
    m_varAddBtn.EnableWindow(bEnable);
    m_varDelBtn.EnableWindow(bEnable);

    m_varDensitySummerEdit.SetReadOnly(!bEnable);
    m_varDensityWinterEdit.SetReadOnly(!bEnable);
}

void HSJ_OilDensityDlg::SetVarEditBtn(bool bEnable)
{
    m_varEditBtn.SetWindowTextW(bEnable ? STR_OK : STR_EDIT);
}

void HSJ_OilDensityDlg::SetVarAddBtn(bool bEnable)
{
    m_varAddBtn.SetWindowTextW(bEnable ? STR_OK : STR_ADD);
}

void HSJ_OilDensityDlg::OnBnClickedDensityEditBtn()
{
    m_bEditMode = !m_bEditMode;
    EnableVarEdit(m_bEditMode);
    SetVarEditBtn(m_bEditMode);

    if (m_bEditMode == false)
    {
        CString windowText(STR_EMPTY);
        m_varDensitySummerEdit.GetWindowTextW(windowText);
        m_varOilDensityModal.m_OilDensitySummer = Utils::CString2Double(windowText);

        m_varDensityWinterEdit.GetWindowTextW(windowText);
        m_varOilDensityModal.m_OilDensityWinter = Utils::CString2Double(windowText);

        bool bEditSuc = DBHelper::GetInstance()->UpdateOilDensity(m_varOilDensityModal, DBHelper::DB_ACT_UPDATE);
        if (bEditSuc)
        {
            DBHelper::GetInstance()->ReloadOilDensity();
            RefreshOilDensityListCtrl();
        }

        MessageBox(CString(STR_UPDATE_OIL_DENSITY) + (bEditSuc ? CString(STR_SUCCESS) : CString(STR_FAILED)), 
            CString(STR_TIP), MB_OK);
    }
}

void HSJ_OilDensityDlg::OnBnClickedDensityAddBtn()
{
    
}
