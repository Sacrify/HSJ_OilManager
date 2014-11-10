#include "StdAfx.h"
#include "HSJ_BaseDlg.h"
#include "BaseModal.h"

HSJ_BaseDlg::HSJ_BaseDlg()
{
    m_pListCtrl = NULL;
    m_pvarEditBtn = NULL;
    m_pvarAddBtn = NULL;
    m_pvarDelBtn = NULL;

    m_pBaseModal = NULL;
    m_bEditMode = false;
    m_bAddMode = false;
}

HSJ_BaseDlg::~HSJ_BaseDlg()
{
}

void HSJ_BaseDlg::SetListReport()
{
    if (m_pListCtrl)
    {
        DWORD dwExStyle = m_pListCtrl->GetExtendedStyle();
        m_pListCtrl->SetExtendedStyle(dwExStyle|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    }
}

void HSJ_BaseDlg::SetValues()
{
}

void HSJ_BaseDlg::EnableVarEdit(bool bEnable)
{
    EnableVarEdit(bEnable, bEnable);
}

void HSJ_BaseDlg::EnableVarEdit(bool bEnableBtn, bool bEnableEdit)
{
    if (m_pvarEditBtn) m_pvarEditBtn->EnableWindow(bEnableBtn);
    if (m_pvarDelBtn) m_pvarDelBtn->EnableWindow(bEnableBtn);

    for (unsigned int i = 0; i < m_varEditVec.size(); i++)
    {
        m_varEditVec[i]->SetReadOnly(!bEnableEdit);
    }
}

void HSJ_BaseDlg::ResetVarEdit()
{
    m_bEditMode = false;
    m_bAddMode = false;

    EnableVarEdit(false);

    SetVarEditBtn(false);
    SetVarAddBtn(false);

    for (unsigned int i = 0; i < m_staticEditVec.size(); i++)
    {
        if (m_staticEditVec[i]) m_staticEditVec[i]->SetWindowTextW(STR_EMPTY);
    }

    for (unsigned int i = 0; i < m_varEditVec.size(); i++)
    {
        if (m_varEditVec[i]) m_varEditVec[i]->SetWindowTextW(STR_EMPTY);
    }
}

void HSJ_BaseDlg::ResetVarModal()
{
    if (m_pBaseModal) m_pBaseModal->Clear();
}

void HSJ_BaseDlg::SetVarEditBtn(bool bEnable)
{
    m_pvarEditBtn->SetWindowTextW(bEnable ? STR_OK : STR_EDIT);
}

void HSJ_BaseDlg::SetVarAddBtn(bool bEnable)
{
    m_pvarAddBtn->SetWindowTextW(bEnable ? STR_OK : STR_ADD);
}

void HSJ_BaseDlg::RefreshListCtrl()
{

}

void HSJ_BaseDlg::UnselectListCtrl()
{
    if (m_pListCtrl == NULL) return;

    POSITION pos = m_pListCtrl->GetFirstSelectedItemPosition();
    while (pos != NULL)
    {
        int index = m_pListCtrl->GetNextSelectedItem(pos);
        m_pListCtrl->SetItemState(index, 0, LVIS_SELECTED | LVIS_FOCUSED);
    }
}

bool HSJ_BaseDlg::UpdateModal2UI()
{
    return true;
}

bool HSJ_BaseDlg::UpdateUI2Modal(bool bNoEmpty)
{
    return true;
}

void HSJ_BaseDlg::OnEditBtnClick()
{
    if (m_bEditMode == false)
    {
        m_bEditMode = true;
        EnableVarEdit(m_bEditMode);
        SetVarEditBtn(m_bEditMode);
    }
    else
    {
        if (PrepareEdit()) DoEdit();
    }
}

bool HSJ_BaseDlg::PrepareEdit()
{
    return true;
}

bool HSJ_BaseDlg::DoEdit()
{
    return true;
}

void HSJ_BaseDlg::OnAddBtnClick()
{
    if (m_bEditMode)
    {
        if (IDYES == MessageBox(m_dlgHWND, CString(STR_EDIT_STATUS_WARNNING), CString(STR_TIP), MB_ICONWARNING | MB_YESNO))
        {
            OnEditBtnClick();
        }
        
        ResetVarEdit();
    }

    if (m_bAddMode == false)
    {
        UnselectListCtrl();

        m_bAddMode = true;
        EnableVarEdit(false, m_bAddMode);
        SetVarAddBtn(m_bAddMode);
    }
    else
    {
        if (PrepareAdd()) DoAdd();
    }
}

bool HSJ_BaseDlg::PrepareAdd()
{
    return true;
}

bool HSJ_BaseDlg::DoAdd()
{
    return true;
}

void HSJ_BaseDlg::OnDelBtnClick()
{
    if (PrepareDel()) DoDel();
}

bool HSJ_BaseDlg::PrepareDel()
{
    return true;
}

bool HSJ_BaseDlg::DoDel()
{
    return true;
}
