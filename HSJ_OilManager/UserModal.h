#pragma once
#include "basemodal.h"

class UserModal :
	public BaseModal
{
public:
	UserModal(void);
	virtual ~UserModal(void);

	int m_ID;
	TCHAR m_UserName[DEF_STR_SIZE];
	TCHAR m_UserPwd[DEF_STR_SIZE];
	int m_UserType;
	TCHAR m_RealName[DEF_STR_SIZE];
	int m_State;
	int m_CompanyID;
};
