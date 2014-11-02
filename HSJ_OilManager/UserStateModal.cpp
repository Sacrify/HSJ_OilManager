#include "StdAfx.h"
#include "UserStateModal.h"

UserStateModal::UserStateModal() : BaseModal()
{
}

UserStateModal::~UserStateModal()
{
}

void UserStateModal::Clear()
{
    m_StateID = 0;
    m_StateComments.Empty();
}