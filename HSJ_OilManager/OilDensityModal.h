#pragma once
#include "basemodal.h"

class OilDensityModal :
	public BaseModal
{
public:
	OilDensityModal(void);
	virtual ~OilDensityModal(void);

    CString GetOilDensityID() const;
    CString GetCompanyID() const;
    CString GetOilTypeID() const;
    CString GetOilDensitySummer() const;
    CString GetOilDensityWinter() const;

	int m_OilDensityID;
	int m_CompanyID;
	int m_OilTypeID;
	double m_OilDensitySummer;
	double m_OilDensityWinter;
};
