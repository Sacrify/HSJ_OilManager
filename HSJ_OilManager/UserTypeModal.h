#pragma once
#include "basemodal.h"

class UserTypeModal :
	public BaseModal
{
public:
	UserTypeModal(void);
	virtual ~UserTypeModal(void);

	int m_UserTypeID;
	TCHAR m_UseTypeComments[DEF_STR_SIZE];
};
