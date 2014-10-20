#include "StdAfx.h"
#include "ShipRegInfoModal.h"

ShipRegInfoModal::ShipRegInfoModal(void)
: m_MMSI("")
, m_ShipName("")
, m_Speed(0)
, m_LoadWeight(0)
, m_Draft(0)
, m_LlunSpeed(0)
, m_RlunSpeed(0)
, m_Memo("")
, m_DeviceID("")
, m_MaxGPS(0)
, m_CompanyID(0)
, m_OilType(0)
{
}

ShipRegInfoModal::~ShipRegInfoModal(void)
{
}
