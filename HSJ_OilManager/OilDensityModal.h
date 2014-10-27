#pragma once
#include "basemodal.h"

class OilDensityModal :
	public BaseModal
{
public:
	OilDensityModal(void);
	virtual ~OilDensityModal(void);

    CString GetOilDensityID();
    CString GetCompanyID();
    CString GetOilTypeID();
    CString GetOilDensitySummer();
    CString GetOilDensityWinter();

	int m_OilDensityID;
	int m_CompanyID;
	int m_OilTypeID;
	double m_OilDensitySummer;
	double m_OilDensityWinter;
};
