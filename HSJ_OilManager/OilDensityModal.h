#pragma once
#include "basemodal.h"

class OilDensityModal :
	public BaseModal
{
public:
	OilDensityModal(void);
	virtual ~OilDensityModal(void);

	PROPERTY_INT(OilDensityID);
	PROPERTY_INT(CompanyID);
	PROPERTY_INT(OilTypeID);
	PROPERTY_DOUBLE(OilDensitySummer, DENSITY_LEN);
	PROPERTY_DOUBLE(OilDensityWinter, DENSITY_LEN);
};
