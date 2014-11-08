#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// HSJ_OilPriceDlg �Ի���

class HSJ_OilPriceDlg : public CDialog
{
    DECLARE_DYNAMIC(HSJ_OilPriceDlg)

public:
    HSJ_OilPriceDlg(CWnd* pParent = NULL);   // ��׼���캯��
    virtual ~HSJ_OilPriceDlg();

// �Ի�������
    enum { IDD = IDD_OIL_PRICE_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

    DECLARE_MESSAGE_MAP()
public:
    CEdit m_varIDEdit;
    CEdit m_varSTimeEdit;
    CEdit m_varPriceEdit;
    CButton m_varEditBtn;
    CButton m_varAddBtn;
    CButton m_varDelBtn;
    CStatic m_LoadStatusLabel;
    CListCtrl m_OilPriceListCtrl;
    afx_msg void OnBnClickedOilPriceLoadBtn();
    afx_msg void OnBnClickedOilPriceEditBtn();
    afx_msg void OnBnClickedOilPriceAddBtn();
    afx_msg void OnBnClickedOilPriceDelBtn();
};
