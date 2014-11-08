#pragma once
#include "basemodal.h"

class ShipRegInfoModal :
    public BaseModal
{
public:
    ShipRegInfoModal();
    virtual ~ShipRegInfoModal();
    void Clear();

    PROPERTY_CSTRING(MMSI);
    PROPERTY_CSTRING(ShipName);
    PROPERTY_DOUBLE(Speed, SPEED_DECIMALS);
    PROPERTY_DOUBLE(LoadWeight, WEIGHT_DECIMALS);
    PROPERTY_DOUBLE(Draft, DRAFT_DECIMALS);
    PROPERTY_INT(LlunSpeed);
    PROPERTY_INT(RlunSpeed);
    PROPERTY_CSTRING(Memo);
    PROPERTY_CSTRING(DeviceID);
    PROPERTY_DOUBLE(MaxGPS, GPS_DECIMALS);
    PROPERTY_INT(CompanyID);
    PROPERTY_INT(OilType);
};
