#include "StdAfx.h"
#include "OilPriceModal.h"

OilPriceModal::OilPriceModal(void)
: m_OilPriceID(0)
, m_Stime(CTime::GetCurrentTime())
, m_Price(0)
, m_OilType(0)
{
}

OilPriceModal::~OilPriceModal(void)
{
}