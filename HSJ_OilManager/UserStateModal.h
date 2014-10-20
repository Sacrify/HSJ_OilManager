#pragma once
#include "basemodal.h"

class UserStateModal :
	public BaseModal
{
public:
	UserStateModal(void);
	virtual ~UserStateModal(void);

	int m_StateID;
	CString m_StateComments;
};
