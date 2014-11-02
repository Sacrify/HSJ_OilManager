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
}


BEGIN_MESSAGE_MAP(HSJ_OilPriceDlg, CDialog)
END_MESSAGE_MAP()


// HSJ_OilPriceDlg 消息处理程序
