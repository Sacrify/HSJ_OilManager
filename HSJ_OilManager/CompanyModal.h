#pragma once
#include "basemodal.h"

class CompanyModal :
	public BaseModal
{
public:
	CompanyModal(void);
	virtual ~CompanyModal(void);

	int m_CompanyID;
	CString m_CompanyName;
	int m_CompanyTypeID;
	int m_CompanyParentID;
};

