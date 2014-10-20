#include "StdAfx.h"
#include "OilTypeModal.h"

OilTypeModal::OilTypeModal(void)
: m_OilTypeID(0)
{
	memset(m_OilTypeComments, 0, sizeof(m_OilTypeComments));
}

OilTypeModal::~OilTypeModal(void)
{
}
