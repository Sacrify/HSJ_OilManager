#pragma once
#include "basemodal.h"

class ShipRegInfoModal :
	public BaseModal
{
public:
	ShipRegInfoModal(void);
	virtual ~ShipRegInfoModal(void);

	TCHAR m_MMSI[DEF_STR_SIZE];
	TCHAR m_ShipName[DEF_STR_SIZE];
	float m_Speed;
	float m_LoadWeight;
	float m_Draft;
	int m_LlunSpeed;
	int m_RlunSpeed;
	TCHAR m_Memo[MAX_PATH];
	TCHAR m_DeviceID[DEF_STR_SIZE];
	float m_MaxGPS;
	int m_CompanyID;
	int m_OilType;
};
