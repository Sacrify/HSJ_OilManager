#include "StdAfx.h"
#include "CompanyTypeModal.h"

CompanyTypeModal::CompanyTypeModal(void)
: m_CompanyTypeID(0)
{
	memset(m_CompanyTypeName, 0, sizeof(m_CompanyTypeName));
}

CompanyTypeModal::~CompanyTypeModal(void)
{
}
