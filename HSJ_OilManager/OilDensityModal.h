#pragma once
#include "basemodal.h"

class OilDensityModal :
	public BaseModal
{
public:
	OilDensityModal(void);
	virtual ~OilDensityModal(void);

	int m_OilDensityID;
	int m_CompanyID;
	int m_OilTypeID;
	double m_OilDensitySummer;
	double m_OilDensityWinter;
};
