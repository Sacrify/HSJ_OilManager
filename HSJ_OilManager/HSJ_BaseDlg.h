#pragma once
#include "afxwin.h"
#include <vector>

class BaseModal;

class HSJ_BaseDlg
{
public:
    HSJ_BaseDlg();
    ~HSJ_BaseDlg();

    CListCtrl* m_pListCtrl;
    CButton* m_pvarEditBtn;
    CButton* m_pvarAddBtn;
    CButton* m_pvarDelBtn;

    bool m_bEditMode;
    bool m_bAddMode;

    BaseModal* m_pBaseModal;

    std::vector<CEdit*> m_staticEditVec;
    std::vector<CEdit*> m_varEditVec;

    HWND m_dlgHWND;

public:
    virtual void SetListReport();
    virtual void SetValues();

    virtual void EnableVarEdit(bool bEnable);
    virtual void EnableVarEdit(bool bEnableBtn, bool bEnableEdit);
    virtual void ResetVarEdit();
    virtual void ResetVarModal();

    virtual void SetVarEditBtn(bool bEnable);
    virtual void SetVarAddBtn(bool bEnable);

    virtual void RefreshOilDensityListCtrl();
    virtual void UnselectListCtrl();

    virtual bool UpdateModal2UI();
    virtual bool UpdateUI2Modal(bool bNoEmpty);

    virtual void OnEditBtnClick();
    virtual bool PrepareEdit();
    virtual bool DoEdit();

    virtual void OnAddBtnClick();
    virtual bool PrepareAdd();
    virtual bool DoAdd();

    virtual void OnDelBtnClick();
    virtual bool PrepareDel();
    virtual bool DoDel();
};
