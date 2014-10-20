#pragma once
#include "basemodal.h"

class OilTypeModal :
	public BaseModal
{
public:
	OilTypeModal(void);
	virtual ~OilTypeModal(void);

	int m_OilTypeID;
	CString m_OilTypeComments;
};
