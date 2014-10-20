#pragma once

#include <comdef.h>
#include <icrsint.h>
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "ADOEOF")

#include <afxtempl.h>

#include "BaseModal.h"
#include "OilDensityModal.h"
#include "CompanyModal.h"
#include "CompanyTypeModal.h"
#include "OilTypeModal.h"
#include "UserModal.h"
#include "UserStateModal.h"
#include "UserTypeModal.h"
#include "ShipRegInfoModal.h"

typedef CMap<int, int, CompanyTypeModal, CompanyTypeModal> CompanyTypeMap;
typedef CMap<int, int, CompanyModal, CompanyModal> CompanyMap;

class DBHelper
{
private:
	DBHelper(void);
	static DBHelper* m_pInstance;

	_ConnectionPtr m_pConnection; 
	_RecordsetPtr m_pRecordset;

	CompanyTypeMap* m_CompanyTypeMap;
	CompanyMap* m_CompanyMap;

public:
	~DBHelper(void);

public:
	static DBHelper* GetInstance();

	bool InitInstance();
	bool OpenDB();

	void ReloadAll();
	void ReloadCompanyTypeMap();
	void ReloadCompanyMap();



};
