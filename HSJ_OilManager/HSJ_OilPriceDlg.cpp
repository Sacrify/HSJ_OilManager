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

    
}

bool HSJ_OilPriceDlg::UpdateModal2UI()
{
    return false;
}

bool HSJ_OilPriceDlg::UpdateUI2Modal(bool bNoEmpty)
{
    return false;
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
    
}

void HSJ_OilPriceDlg::OnBnClickedOilPriceAddBtn()
{
    
}

void HSJ_OilPriceDlg::OnBnClickedOilPriceDelBtn()
{
    
}
