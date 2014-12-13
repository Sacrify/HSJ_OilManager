#include "StdAfx.h"
#include "Utils.h"

Utils::Utils(void)
{
}

Utils::~Utils(void)
{
}


CString Utils::Int2CString(int num)
{
    CString str(STR_EMPTY);
    str.Format(STR_INT, num);

    return str;
}

int Utils::CString2Int(CString& str)
{
    return _tstoi(str);
}

CString Utils::Double2CString(double num, int decimals)
{
    CString str(STR_EMPTY);

    switch (decimals)
    {
    case 3:
    default:
        str.Format(STR_FLOAT_3, num);
    }

    return str;
}

double Utils::CString2Double(CString& str)
{
    return _tstof(str);
}

CString Utils::CTime2CStringDay(CTime time)
{
    return time.Format(STR_CTIME_DAY);
}

CTime Utils::CString2CTimeDay(CString& str)
{
    int nYear = 0, nMonth = 0, nDay = 0;
    if (-1 != _stscanf_s(str, STR_CSTRING_DAY, &nYear, &nMonth, &nDay))
    {
        return CTime(nYear, nMonth, nDay, 0, 0, 0);
    }
    return GetCurrentTime();
}

CTime Utils::Variant2CTimeDay(_variant_t& vt)
{
    COleDateTime timeTmp(vt);
    SYSTEMTIME st;
    VariantTimeToSystemTime(timeTmp, &st);
    return CTime(st);
}

CString Utils::GetConnectionString()
{
	CString retStr = _T("");
	CString iniFile = AfxGetApp()->m_pszProfileName;

    TCHAR szSection[1025] = {0};
    DWORD dwSection = GetPrivateProfileString(NULL, NULL, NULL, szSection, 1024, iniFile);

    LPTSTR lpSection = szSection;
    while(*lpSection)
    {
		if (CString(lpSection).CompareNoCase(CString(_T("ConnectionInfo"))) == 0)
		{
			TCHAR szEntry[1025]={0};
			DWORD dwEntry = GetPrivateProfileString(lpSection, NULL, NULL, szEntry, 1024, iniFile);
			LPTSTR lpEntry = szEntry;

			while(*lpEntry)
			{
				TCHAR szVal[1204]={0};
				DWORD dwVal = GetPrivateProfileString(lpSection, lpEntry, NULL, szVal, 1024, iniFile);

				retStr += lpEntry;
				retStr += _T("=");
				retStr += szVal;
				retStr += _T(";");

				lpEntry += _tcslen(lpEntry) + 1;
			}
		}

		lpSection += _tcslen(lpSection) + 1;
	}

	return retStr;
}
