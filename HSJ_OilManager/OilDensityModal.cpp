#include "StdAfx.h"
#include "OilDensityModal.h"

OilDensityModal::OilDensityModal() : BaseModal()
{
}

OilDensityModal::~OilDensityModal()
{
}

void OilDensityModal::Clear()
{
    m_OilDensityID = 0;
    m_CompanyID = 0;
    m_OilTypeID = 0;
    m_OilDensitySummer = 0;
    m_OilDensityWinter = 0;
}
