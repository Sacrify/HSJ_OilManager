#include "StdAfx.h"
#include "UserStateModal.h"

UserStateModal::UserStateModal(void)
: m_StateID(0)
{
	memset(m_StateComments, 0, sizeof(m_StateComments));
}

UserStateModal::~UserStateModal(void)
{
}
