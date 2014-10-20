#include "StdAfx.h"
#include "UserModal.h"

UserModal::UserModal(void)
: m_ID(0)
, m_UserType(0)
, m_State(0)
, m_CompanyID(0)
{
	memset(m_UserName, 0, sizeof(m_UserName));
	memset(m_UserPwd, 0, sizeof(m_UserPwd));
	memset(m_RealName, 0, sizeof(m_RealName));
}

UserModal::~UserModal(void)
{
}
