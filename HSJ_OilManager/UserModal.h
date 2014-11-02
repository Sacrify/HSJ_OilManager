#pragma once
#include "basemodal.h"

class UserModal :
	public BaseModal
{
public:
	UserModal();
	virtual ~UserModal();
    void Clear();

	PROPERTY_INT(ID);
	PROPERTY_CSTRING(UserName);
	PROPERTY_CSTRING(UserPwd);
	PROPERTY_INT(UserType);
	PROPERTY_CSTRING(RealName);
	PROPERTY_INT(State);
	PROPERTY_INT(CompanyID);
};
