#pragma once


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
};
