#pragma once
#include "basemodal.h"

class CompanyTypeModal :
	public BaseModal
{
public:
	CompanyTypeModal(void);
	virtual ~CompanyTypeModal(void);

	int m_CompanyTypeID;
	CString m_CompanyTypeName;
};
