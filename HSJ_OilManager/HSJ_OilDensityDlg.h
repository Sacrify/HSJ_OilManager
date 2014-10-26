#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// HSJ_OilDensityDlg 对话框

class HSJ_OilDensityDlg : public CDialog
{
	DECLARE_DYNAMIC(HSJ_OilDensityDlg)

public:
	HSJ_OilDensityDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HSJ_OilDensityDlg();

// 对话框数据
	enum { IDD = IDD_OIL_DENSITY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// Generated message map functions
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_OilDensityListCtrl;
	
	CComboBox m_CompanyIDCombo;
	CComboBox m_OilTypeCombo;
	CStatic m_CompanyNameLabel;
	CStatic m_OilTypeLabel;
	CStatic m_LoadStatus;

	CEdit m_varIDEdit;
	CEdit m_varDensitySummerEdit;
	CEdit m_varDensityWinterEdit;

	bool m_bEditMode;

	afx_msg void OnBnClickedDensityLoadBtn();
	afx_msg void OnCbnSelchangeDensityCompanyIdCombo();
	afx_msg void OnCbnSelchangeDensityOilTypeCombo();
	void RefreshOilDensityListCtrl();
	afx_msg void OnLvnItemchangedOilDensityListcontrol(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
