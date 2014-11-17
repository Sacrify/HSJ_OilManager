// HSJ_OilPriceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HSJ_OilManager.h"
#include "HSJ_OilPriceDlg.h"


// HSJ_OilPriceDlg 对话框

IMPLEMENT_DYNAMIC(HSJ_OilPriceDlg, CDialog)

HSJ_OilPriceDlg::HSJ_OilPriceDlg(CWnd* pParent /*=NULL*/)
    : CDialog(HSJ_OilPriceDlg::IDD, pParent)
{

}

HSJ_OilPriceDlg::~HSJ_OilPriceDlg()
{
}

void HSJ_OilPriceDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_PRICE_DETAIL_ID_EDIT, m_varIDEdit);
    DDX_Control(pDX, IDC_PRICE_STIME_EDIT, m_varSTimeEdit);
    DDX_Control(pDX, IDC_PRICE_DETAIL_PRICE_EDIT, m_varPriceEdit);
    DDX_Control(pDX, IDC_PRICE_EDIT_BTN, m_varEditBtn);
    DDX_Control(pDX, IDC_PRICE_ADD_BTN, m_varAddBtn);
    DDX_Control(pDX, IDC_PRICE_DEL_BTN, m_varDelBtn);
    DDX_Control(pDX, IDC_PRICE_LOAD_STATUS_LABEL, m_LoadStatusLabel);
    DDX_Control(pDX, IDC_PRICE_LIST_LISTCONTROL, m_OilPriceListCtrl);
    DDX_Control(pDX, IDC_PRICE_OIL_TYPE_COMBO, m_OilTypeCombo);
    DDX_Control(pDX, IDC_PRICE_OIL_TYPE_CONTENT_LABEL, m_OilTypeLabel);
}

BOOL HSJ_OilPriceDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    SetValues();
    SetListReport();

    m_OilPriceListCtrl.InsertColumn(0, STR_UI_OIL_PRICE_ID, LVCFMT_LEFT, 100);
    m_OilPriceListCtrl.InsertColumn(1, STR_UI_OIL_PRICE_STIME, LVCFMT_LEFT, 200);
    m_OilPriceListCtrl.InsertColumn(2, STR_UI_OIL_PRICE_PRICE, LVCFMT_LEFT, 200);

    ResetVarEdit();

    return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(HSJ_OilPriceDlg, CDialog)
    ON_BN_CLICKED(IDC_PRICE_LOAD_BTN, &HSJ_OilPriceDlg::OnBnClickedOilPriceLoadBtn)
    ON_BN_CLICKED(IDC_PRICE_EDIT_BTN, &HSJ_OilPriceDlg::OnBnClickedOilPriceEditBtn)
    ON_BN_CLICKED(IDC_PRICE_ADD_BTN, &HSJ_OilPriceDlg::OnBnClickedOilPriceAddBtn)
    ON_BN_CLICKED(IDC_PRICE_DEL_BTN, &HSJ_OilPriceDlg::OnBnClickedOilPriceDelBtn)
    ON_CBN_SELCHANGE(IDC_PRICE_OIL_TYPE_COMBO, &HSJ_OilPriceDlg::OnCbnSelchangePriceOilTypeCombo)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_PRICE_LIST_LISTCONTROL, &HSJ_OilPriceDlg::OnLvnItemchangedPriceListListcontrol)
END_MESSAGE_MAP()


// HSJ_OilPriceDlg 消息处理程序

void HSJ_OilPriceDlg::SetValues()
{
    m_pListCtrl = &m_OilPriceListCtrl;
    m_pvarEditBtn = &m_varEditBtn;
    m_pvarAddBtn = &m_varAddBtn;
    m_pvarDelBtn = &m_varDelBtn;
    m_pBaseModal = &m_varOilPriceModal;

    m_staticEditVec.push_back(&m_varIDEdit);
    m_varEditVec.push_back(&m_varSTimeEdit);
    m_varEditVec.push_back(&m_varPriceEdit);

    m_dlgHWND = m_hWnd;
}

void HSJ_OilPriceDlg::RefreshListCtrl()
{
    m_OilPriceListCtrl.DeleteAllItems();
    ResetVarEdit();

    int nIndex = m_OilTypeCombo.GetCurSel();
    if (nIndex == -1) return;
    CString strTypeID = STR_EMPTY;
    m_OilTypeCombo.GetLBText(nIndex, strTypeID);
    if (strTypeID.GetLength() == 0) return;
    int typeID = _ttoi(strTypeID);

    OilPriceMap* oilPriceMap = DBHelper::GetInstance()->GetOilPriceMap();

    POSITION pos = oilPriceMap->GetStartPosition();
    while (pos != NULL)
    {
        int key = 0;
        OilPriceModal opm;
        oilPriceMap->GetNextAssoc(pos, key, opm);

        if (opm.m_OilTypeID != typeID) continue;

        int nRow = m_OilPriceListCtrl.InsertItem(0, Utils::Int2CString(key));
        m_OilPriceListCtrl.SetItemText(nRow, 1, opm.GetStime());
        m_OilPriceListCtrl.SetItemText(nRow, 2, opm.GetPrice());
    }
}

bool HSJ_OilPriceDlg::UpdateModal2UI()
{
    m_varIDEdit.SetWindowTextW(m_varOilPriceModal.GetOilPriceID());
    m_varSTimeEdit.SetWindowTextW(m_varOilPriceModal.GetStime());
    m_varPriceEdit.SetWindowTextW(m_varOilPriceModal.GetPrice());

    return true;
}

bool HSJ_OilPriceDlg::UpdateUI2Modal(bool bNoEmpty)
{
    CString windowText(STR_EMPTY);
    m_varSTimeEdit.GetWindowTextW(windowText);
    if (bNoEmpty && 
        windowText.GetLength() == 0)
    {
        MessageBox(CString(STR_ERROR_INPUT_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }
    m_varOilPriceModal.m_Stime = Utils::CString2CTimeDay(windowText);

    m_varPriceEdit.GetWindowTextW(windowText);
    if (bNoEmpty && 
        windowText.GetLength() == 0)
    {
        MessageBox(CString(STR_ERROR_INPUT_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }
    m_varOilPriceModal.m_Price = Utils::CString2Double(windowText);

    return true;
}


void HSJ_OilPriceDlg::OnBnClickedOilPriceLoadBtn()
{
    DBHelper::GetInstance()->ReloadOilPrice();

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

    RefreshListCtrl();
    m_LoadStatusLabel.SetWindowTextW(STR_LOADED);
}

void HSJ_OilPriceDlg::OnBnClickedOilPriceEditBtn()
{
    OnEditBtnClick();
}

bool HSJ_OilPriceDlg::PrepareEdit()
{
    return UpdateUI2Modal(true);
}

bool HSJ_OilPriceDlg::DoEdit()
{
    bool bEditSuc = DBHelper::GetInstance()->UpdateOilPrice(m_varOilPriceModal, DBHelper::DB_ACT_UPDATE);
    if (bEditSuc)
    {
        DBHelper::GetInstance()->ReloadOilPrice();
        RefreshListCtrl();
    }

    MessageBox(CString(STR_UPDATE_OIL_PRICE) + (bEditSuc ? CString(STR_SUCCESS) : CString(STR_FAILED)), 
        CString(STR_TIP), MB_OK);

    return bEditSuc;
}

void HSJ_OilPriceDlg::OnBnClickedOilPriceAddBtn()
{
    OnAddBtnClick();
}

bool HSJ_OilPriceDlg::PrepareAdd()
{
    UpdateUI2Modal(false);

    if (m_varOilPriceModal.m_Price == 0)
    {
        MessageBox(CString(STR_ERROR_INPUT_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }

    if (CB_ERR == m_OilTypeCombo.GetCurSel())
    {
        MessageBox(CString(STR_ERROR_OIL_TYPE_WRONG), CString(STR_TIP), MB_ICONWARNING | MB_OK);
        return false;
    }

    return true;
}

bool HSJ_OilPriceDlg::DoAdd()
{
    bool bAddSuc = DBHelper::GetInstance()->UpdateOilPrice(m_varOilPriceModal, DBHelper::DB_ACT_ADD);
    if (bAddSuc)
    {
        DBHelper::GetInstance()->ReloadOilPrice();
        RefreshListCtrl();
    }

    MessageBox(CString(STR_ADD_OIL_PRICE) + (bAddSuc ? CString(STR_SUCCESS) : CString(STR_FAILED)), 
        CString(STR_TIP), MB_OK);

    return bAddSuc;
}

void HSJ_OilPriceDlg::OnBnClickedOilPriceDelBtn()
{
    OnDelBtnClick();
}

bool HSJ_OilPriceDlg::PrepareDel()
{
    return true;
}

bool HSJ_OilPriceDlg::DoDel()
{
    bool bDelSuc = DBHelper::GetInstance()->UpdateOilPrice(m_varOilPriceModal, DBHelper::DB_ACT_DEL);
    if (bDelSuc)
    {
        DBHelper::GetInstance()->ReloadOilPrice();
        RefreshListCtrl();
        ResetVarModal();
    }

    MessageBox(CString(STR_DEL_OIL_PRICE) + (bDelSuc ? CString(STR_SUCCESS) : CString(STR_FAILED)), 
        CString(STR_TIP), MB_OK);

    return bDelSuc;
}

void HSJ_OilPriceDlg::OnCbnSelchangePriceOilTypeCombo()
{
    int nIndex = m_OilTypeCombo.GetCurSel();
    if (nIndex == CB_ERR) return;

    CString strTypeID = STR_EMPTY;
    m_OilTypeCombo.GetLBText(nIndex, strTypeID);

    int typeID = Utils::CString2Int(strTypeID);
    m_varOilPriceModal.m_OilTypeID = typeID;

    OilTypeMap* oilTypeMap = DBHelper::GetInstance()->GetOilTypeMap();
    OilTypeModal om;

    if (oilTypeMap->Lookup(typeID, om))
    {
        m_OilTypeLabel.SetWindowTextW(om.m_OilTypeComments);
    }

    RefreshListCtrl();
}

void HSJ_OilPriceDlg::OnLvnItemchangedPriceListListcontrol(NMHDR *pNMHDR, LRESULT *pResult)
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
            int oilPriceID = 
                Utils::CString2Int(m_OilPriceListCtrl.GetItemText(nItemIndex, 0));

            OilPriceMap* oilPriceMap = DBHelper::GetInstance()->GetOilPriceMap();

            if (oilPriceMap != NULL)
            {
                if (oilPriceMap->Lookup(oilPriceID, m_varOilPriceModal))
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
