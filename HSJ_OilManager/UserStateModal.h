#pragma once
#include "basemodal.h"

class UserStateModal :
	public BaseModal
{
public:
	UserStateModal();
	virtual ~UserStateModal();
    void Clear();

	PROPERTY_INT(StateID);
	PROPERTY_CSTRING(StateComments);
};
