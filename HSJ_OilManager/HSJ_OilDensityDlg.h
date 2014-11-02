#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "DBHelper.h"

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

    bool m_bEditMode;
    bool m_bAddMode;

    OilDensityModal m_varOilDensityModal;

	CEdit m_varIDEdit;
	CEdit m_varDensitySummerEdit;
	CEdit m_varDensityWinterEdit;
	CButton m_varEditBtn;
    CButton m_varAddBtn;
    CButton m_varDelBtn;

    void EnableVarEdit(bool bEnable);
    void EnableVarEdit(bool bEnableBtn, bool bEnableEdit);
    void ResetVarEdit();
    void ResetVarModal();

    void SetVarEditBtn(bool bEnable);
    void SetVarAddBtn(bool bEnable);

	afx_msg void OnBnClickedDensityLoadBtn();
	afx_msg void OnCbnSelchangeDensityCompanyIdCombo();
	afx_msg void OnCbnSelchangeDensityOilTypeCombo();
	void RefreshOilDensityListCtrl();
    void UnselectListCtrl();
	afx_msg void OnLvnItemchangedOilDensityListcontrol(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedDensityEditBtn();
    afx_msg void OnBnClickedDensityAddBtn();
    afx_msg void OnBnClickedDensityDeleteBtn();
};
