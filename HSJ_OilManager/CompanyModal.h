#pragma once
#include "basemodal.h"

class CompanyModal :
    public BaseModal
{
public:
    CompanyModal();
    virtual ~CompanyModal();
    void Clear(); 

    PROPERTY_INT(CompanyID);
    PROPERTY_CSTRING(CompanyName);
    PROPERTY_INT(CompanyTypeID);
    PROPERTY_INT(CompanyParentID);
};

