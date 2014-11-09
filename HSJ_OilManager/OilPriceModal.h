#pragma once
#include "basemodal.h"

class OilPriceModal :
    public BaseModal
{
public:
    OilPriceModal();
    virtual ~OilPriceModal();
    void Clear();

    PROPERTY_INT(OilPriceID);
    PROPERTY_CTIME_DAY(Stime);
    PROPERTY_DOUBLE(Price, PRICE_DECIMALS);
    PROPERTY_INT(OilTypeID);
};
