// HSJ_OilManagerDlg.h : ͷ�ļ�
//

#pragma once
#include "HSJ_OilDensityDlg.h"

// CHSJ_OilManagerDlg �Ի���
class CHSJ_OilManagerDlg : public CDialog
{
// ����
public:
	CHSJ_OilManagerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CHSJ_OilManagerDlg();

// �Ի�������
	enum { IDD = IDD_HSJ_OILMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	HSJ_OilDensityDlg* m_OilDensityDlg;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOilDensity();
	afx_msg void OnBnClickedMainRefresh();
};
