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
    DDX_Control(pDX, IDC_OIL_PRICE_DETAIL_ID_EDIT, m_varIDEdit);
    DDX_Control(pDX, IDC_OIL_PRICE_STIME_EDIT, m_varSTimeEdit);
    DDX_Control(pDX, IDC_OIL_PRICE_DETAIL_PRICE_EDIT, m_varPriceEdit);
    DDX_Control(pDX, IDC_OIL_PRICE_EDIT_BTN, m_varEditBtn);
    DDX_Control(pDX, IDC_OIL_PRICE_ADD_BTN, m_varAddBtn);
    DDX_Control(pDX, IDC_OIL_PRICE_DEL_BTN, m_varDelBtn);
    DDX_Control(pDX, IDC_OIL_PRICE_LOAD_STATUS_LABEL, m_LoadStatusLabel);
    DDX_Control(pDX, IDC_OIL_PRICE_LIST_LISTCONTROL, m_OilPriceListCtrl);
}


BEGIN_MESSAGE_MAP(HSJ_OilPriceDlg, CDialog)
    ON_BN_CLICKED(IDC_OIL_PRICE_LOAD_BTN, &HSJ_OilPriceDlg::OnBnClickedOilPriceLoadBtn)
    ON_BN_CLICKED(IDC_OIL_PRICE_EDIT_BTN, &HSJ_OilPriceDlg::OnBnClickedOilPriceEditBtn)
    ON_BN_CLICKED(IDC_OIL_PRICE_ADD_BTN, &HSJ_OilPriceDlg::OnBnClickedOilPriceAddBtn)
    ON_BN_CLICKED(IDC_OIL_PRICE_DEL_BTN, &HSJ_OilPriceDlg::OnBnClickedOilPriceDelBtn)
END_MESSAGE_MAP()


// HSJ_OilPriceDlg 消息处理程序

void HSJ_OilPriceDlg::OnBnClickedOilPriceLoadBtn()
{
    
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
