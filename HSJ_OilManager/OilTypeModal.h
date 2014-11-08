#pragma once
#include "basemodal.h"

class OilTypeModal :
    public BaseModal
{
public:
    OilTypeModal();
    virtual ~OilTypeModal();
    void Clear();

    PROPERTY_INT(OilTypeID);
    PROPERTY_CSTRING(OilTypeComments);
};
