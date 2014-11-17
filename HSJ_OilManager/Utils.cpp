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