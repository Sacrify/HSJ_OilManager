#pragma once
#include "basemodal.h"

class OilPriceModal :
	public BaseModal
{
public:
	OilPriceModal(void);
	virtual ~OilPriceModal(void);

	int m_OilPriceID;
    CTime m_Stime;
	float m_Price;
	int m_OilType;
};