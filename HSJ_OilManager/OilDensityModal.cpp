#include "StdAfx.h"
#include "OilDensityModal.h"

OilDensityModal::OilDensityModal(void)
: m_OilDensityID(0)
, m_CompanyID(0)
, m_OilTypeID(0)
, m_OilDensitySummer(0)
, m_OilDensityWinter(0)
{
}

OilDensityModal::~OilDensityModal(void)
{
}


CString OilDensityModal::GetOilDensityID() const
{
    CString str = STR_EMPTY;
    str.Format(STR_INT, m_OilDensityID);

    return str;
}
    
CString OilDensityModal::GetCompanyID() const
{
    CString str = STR_EMPTY;
    str.Format(STR_INT, m_CompanyID);

    return str;
}

CString OilDensityModal::GetOilTypeID() const
{
    CString str = STR_EMPTY;
    str.Format(STR_INT, m_OilTypeID);

    return str;
}

CString OilDensityModal::GetOilDensitySummer() const
{
    CString str = STR_EMPTY;
    str.Format(STR_FLOAT_3, m_OilDensitySummer);

    return str;
}

CString OilDensityModal::GetOilDensityWinter() const
{
    CString str = STR_EMPTY;
    str.Format(STR_FLOAT_3, m_OilDensityWinter);

    return str;
}