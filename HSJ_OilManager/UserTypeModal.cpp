#include "StdAfx.h"
#include "UserTypeModal.h"

UserTypeModal::UserTypeModal() : BaseModal()
{
}

UserTypeModal::~UserTypeModal()
{
}

void UserTypeModal::Clear()
{
    m_UserTypeID = 0;
    m_UseTypeComments.Empty();
}