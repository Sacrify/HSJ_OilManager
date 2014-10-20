#pragma once
#include "basemodal.h"

class CompanyDensityModal :
	public BaseModal
{
public:
	CompanyDensityModal(void);
	virtual ~CompanyDensityModal(void);

	int m_OilDensityID;
	int m_CompanyID;
	int m_OilTypeID;
	float m_OilDensitySummer;
	float m_OilDensityWinter;
};
