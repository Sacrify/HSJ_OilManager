#include "StdAfx.h"
#include "ShipRegInfoModal.h"

ShipRegInfoModal::ShipRegInfoModal() : BaseModal()
{
}

ShipRegInfoModal::~ShipRegInfoModal()
{
}

void ShipRegInfoModal::Clear()
{
    m_MMSI.Empty();
    m_ShipName.Empty();
    m_Speed = 0;
    m_LoadWeight = 0;
    m_Draft = 0;
    m_LlunSpeed = 0;
    m_RlunSpeed = 0;
    m_Memo.Empty();
    m_DeviceID.Empty();
    m_MaxGPS = 0;
    m_CompanyID = 0;
    m_OilType = 0;
}