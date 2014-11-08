#pragma once
#include "basemodal.h"

class OilDensityModal :
    public BaseModal
{
public:
    OilDensityModal();
    virtual ~OilDensityModal();
    void Clear();

    PROPERTY_INT(OilDensityID);
    PROPERTY_INT(CompanyID);
    PROPERTY_INT(OilTypeID);
    PROPERTY_DOUBLE(OilDensitySummer, DENSITY_DECIMALS);
    PROPERTY_DOUBLE(OilDensityWinter, DENSITY_DECIMALS);
};
