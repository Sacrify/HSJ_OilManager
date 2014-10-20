#pragma once
#include "basemodal.h"

class UserModal :
	public BaseModal
{
public:
	UserModal(void);
	virtual ~UserModal(void);

	int m_ID;
	CString m_UserName;
	CString m_UserPwd;
	int m_UserType;
	CString m_RealName;
	int m_State;
	int m_CompanyID;
};
