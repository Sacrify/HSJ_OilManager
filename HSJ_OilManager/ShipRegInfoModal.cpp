#include "StdAfx.h"
#include "ShipRegInfoModal.h"

ShipRegInfoModal::ShipRegInfoModal(void)
: m_Speed(0)
, m_LoadWeight(0)
, m_Draft(0)
, m_LlunSpeed(0)
, m_RlunSpeed(0)
, m_MaxGPS(0)
, m_CompanyID(0)
, m_OilType(0)
{
	memset(m_MMSI, 0, sizeof(m_MMSI));
	memset(m_ShipName, 0, sizeof(m_ShipName));
	memset(m_Memo, 0, sizeof(m_Memo));
	memset(m_DeviceID, 0, sizeof(m_DeviceID));
}

ShipRegInfoModal::~ShipRegInfoModal(void)
{
}
