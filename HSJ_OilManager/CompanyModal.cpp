#include "StdAfx.h"
#include "CompanyModal.h"

CompanyModal::CompanyModal() : BaseModal()
{
	
}

CompanyModal::~CompanyModal()
{

}

void CompanyModal::Clear()
{
    m_CompanyID = 0;
    m_CompanyName.Empty();
    m_CompanyTypeID = 0;
    m_CompanyParentID = 0;
}

