#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "HSJ_BaseDlg.h"
#include "DBHelper.h"

// HSJ_OilDensityDlg 对话框

class HSJ_OilDensityDlg : public CDialog, public HSJ_BaseDlg
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

    OilDensityModal m_varOilDensityModal;

    CEdit m_varIDEdit;
    CEdit m_varDensitySummerEdit;
    CEdit m_varDensityWinterEdit;
    CButton m_varEditBtn;
    CButton m_varAddBtn;
    CButton m_varDelBtn;

    virtual void SetValues();

    afx_msg void OnBnClickedDensityLoadBtn();
    afx_msg void OnCbnSelchangeDensityCompanyIdCombo();
    afx_msg void OnCbnSelchangeDensityOilTypeCombo();
    
    virtual void RefreshOilDensityListCtrl();
    virtual bool UpdateModal2UI();
    virtual bool UpdateUI2Modal(bool bNoEmpty);

    afx_msg void OnLvnItemchangedOilDensityListcontrol(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

    afx_msg void OnBnClickedDensityEditBtn();
    virtual bool PrepareEdit();
    virtual bool DoEdit();

    afx_msg void OnBnClickedDensityAddBtn();
    virtual bool PrepareAdd();
    virtual bool DoAdd();

    afx_msg void OnBnClickedDensityDeleteBtn();
    virtual bool PrepareDel();
    virtual bool DoDel();
};
