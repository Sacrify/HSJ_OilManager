#include "StdAfx.h"
#include "UserTypeModal.h"

UserTypeModal::UserTypeModal(void)
: m_UserTypeID(0)
{
	memset(m_UseTypeComments, 0, sizeof(m_UseTypeComments));
}

UserTypeModal::~UserTypeModal(void)
{
}
