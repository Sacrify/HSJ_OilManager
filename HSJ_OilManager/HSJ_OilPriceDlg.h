#pragma once


// HSJ_OilPriceDlg 对话框

class HSJ_OilPriceDlg : public CDialog
{
	DECLARE_DYNAMIC(HSJ_OilPriceDlg)

public:
	HSJ_OilPriceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HSJ_OilPriceDlg();

// 对话框数据
	enum { IDD = IDD_OIL_PRICE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
