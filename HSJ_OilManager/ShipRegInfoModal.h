#pragma once
#include "basemodal.h"

class ShipRegInfoModal :
	public BaseModal
{
public:
	ShipRegInfoModal(void);
	virtual ~ShipRegInfoModal(void);

	CString m_MMSI;
	CString m_ShipName;
	double m_Speed;
	double m_LoadWeight;
	double m_Draft;
	int m_LlunSpeed;
	int m_RlunSpeed;
	CString m_Memo;
	CString m_DeviceID;
	double m_MaxGPS;
	int m_CompanyID;
	int m_OilType;
};
