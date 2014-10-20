#pragma once
#include "basemodal.h"

class UserTypeModal :
	public BaseModal
{
public:
	UserTypeModal(void);
	virtual ~UserTypeModal(void);

	int m_UserTypeID;
	CString m_UseTypeComments;
};
