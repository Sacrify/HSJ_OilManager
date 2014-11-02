#include "StdAfx.h"
#include "UserModal.h"

UserModal::UserModal() : BaseModal()
{
}

UserModal::~UserModal()
{
}

void UserModal::Clear()
{
    m_ID = 0;
    m_UserName.Empty();
    m_UserPwd.Empty();
    m_UserType = 0;
    m_RealName.Empty();
    m_State = 0;
    m_CompanyID = 0;
}