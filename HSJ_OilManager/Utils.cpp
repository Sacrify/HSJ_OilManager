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
    return _ttoi(str);
}

CString Utils::Double2CString(double num, int point)
{
    CString str(STR_EMPTY);

    switch (point)
    {
    case 3:
    default:
        str.Format(STR_FLOAT_3, num);
    }

    return str;
}
