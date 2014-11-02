#include "StdAfx.h"
#include "CompanyTypeModal.h"

CompanyTypeModal::CompanyTypeModal() : BaseModal()
{
}

CompanyTypeModal::~CompanyTypeModal()
{
}

void CompanyTypeModal::Clear()
{
    m_CompanyTypeID = 0;
    m_CompanyTypeName.Empty();
}