// HSJ_OilManager.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
    #error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"        // ������


// CHSJ_OilManagerApp:
// �йش����ʵ�֣������ HSJ_OilManager.cpp
//

class CHSJ_OilManagerApp : public CWinApp
{
public:
    CHSJ_OilManagerApp();

// ��д
    public:
    virtual BOOL InitInstance();

// ʵ��

    DECLARE_MESSAGE_MAP()
};

extern CHSJ_OilManagerApp theApp;