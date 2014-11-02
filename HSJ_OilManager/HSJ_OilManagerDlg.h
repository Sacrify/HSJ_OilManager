// HSJ_OilManagerDlg.h : 头文件
//

#pragma once
#include "HSJ_OilDensityDlg.h"
#include "HSJ_OilPriceDlg.h"

// CHSJ_OilManagerDlg 对话框
class CHSJ_OilManagerDlg : public CDialog
{
// 构造
public:
	CHSJ_OilManagerDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CHSJ_OilManagerDlg();

// 对话框数据
	enum { IDD = IDD_HSJ_OILMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	HSJ_OilDensityDlg*  m_OilDensityDlg;
    HSJ_OilPriceDlg*    m_OilPriceDlg;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOilDensity();
	afx_msg void OnBnClickedMainRefresh();
    afx_msg void OnBnClickedBtnOilPrice();
};
