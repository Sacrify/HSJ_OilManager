#include "StdAfx.h"
#include "OilTypeModal.h"

OilTypeModal::OilTypeModal() : BaseModal()
{
}

OilTypeModal::~OilTypeModal()
{
}

void OilTypeModal::Clear()
{
    m_OilTypeID = 0;
    m_OilTypeComments.Empty();
}