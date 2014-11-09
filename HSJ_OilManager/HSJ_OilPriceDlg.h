#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "HSJ_BaseDlg.h"
#include "OilPriceModal.h"

// HSJ_OilPriceDlg �Ի���

class HSJ_OilPriceDlg : public CDialog, public HSJ_BaseDlg
{
    DECLARE_DYNAMIC(HSJ_OilPriceDlg)

public:
    HSJ_OilPriceDlg(CWnd* pParent = NULL);   // ��׼���캯��
    virtual ~HSJ_OilPriceDlg();

// �Ի�������
    enum { IDD = IDD_PRICE_DIALOG };

protected:
    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

    DECLARE_MESSAGE_MAP()
public:
    CEdit m_varIDEdit;
    CEdit m_varSTimeEdit;
    CEdit m_varPriceEdit;
    CButton m_varEditBtn;
    CButton m_varAddBtn;
    CButton m_varDelBtn;
    CComboBox m_OilTypeCombo;
    CStatic m_OilTypeLabel;
    CStatic m_LoadStatusLabel;
    CListCtrl m_OilPriceListCtrl;

    OilPriceModal m_varOilPriceModal;

    virtual void SetValues();

    afx_msg void OnBnClickedOilPriceLoadBtn();
    afx_msg void OnBnClickedOilPriceEditBtn();
    afx_msg void OnBnClickedOilPriceAddBtn();
    afx_msg void OnBnClickedOilPriceDelBtn();


};
