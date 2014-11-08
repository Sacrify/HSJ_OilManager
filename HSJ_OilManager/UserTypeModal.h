#pragma once
#include "basemodal.h"

class UserTypeModal :
    public BaseModal
{
public:
    UserTypeModal();
    virtual ~UserTypeModal();
    void Clear();

    PROPERTY_INT(UserTypeID);
    PROPERTY_CSTRING(UseTypeComments);
};
