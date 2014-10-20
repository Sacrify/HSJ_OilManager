// HSJ_OilDensityDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HSJ_OilManager.h"
#include "HSJ_OilDensityDlg.h"


// HSJ_OilDensityDlg 对话框

IMPLEMENT_DYNAMIC(HSJ_OilDensityDlg, CDialog)

HSJ_OilDensityDlg::HSJ_OilDensityDlg(CWnd* pParent /*=NULL*/)
	: CDialog(HSJ_OilDensityDlg::IDD, pParent)
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
}


BEGIN_MESSAGE_MAP(HSJ_OilDensityDlg, CDialog)
END_MESSAGE_MAP()


// HSJ_OilDensityDlg 消息处理程序
BOOL HSJ_OilDensityDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	DWORD dwExStyle = m_OilDensityListCtrl.GetExtendedStyle();
	m_OilDensityListCtrl.SetExtendedStyle(dwExStyle|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_OilDensityListCtrl.InsertColumn(0, _T("OilDensityID"),LVCFMT_LEFT, 100);
	m_OilDensityListCtrl.InsertColumn(1, _T("OilDensitySummer"),LVCFMT_LEFT, 200);
	m_OilDensityListCtrl.InsertColumn(2, _T("OilDensityWiner"),LVCFMT_LEFT, 200);

	return TRUE;  // return TRUE  unless you set the focus to a control
}