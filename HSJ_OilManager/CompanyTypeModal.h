#pragma once
#include "basemodal.h"

class CompanyTypeModal :
    public BaseModal
{
public:
    CompanyTypeModal();
    virtual ~CompanyTypeModal();
    void Clear();

    PROPERTY_INT(CompanyTypeID);
    PROPERTY_CSTRING(CompanyTypeName);
};
