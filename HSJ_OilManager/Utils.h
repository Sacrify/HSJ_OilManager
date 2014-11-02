#pragma once


class Utils
{
public:
    Utils(void);
    ~Utils(void);

    static CString Int2CString(int num);
    static int CString2Int(CString& str);

    static CString Double2CString(double num, int decimals);
    static double CString2Double(CString& str);

    static CString CTime2CStringDay(CTime time);
    static CTime CString2CTimeDay(CString& str);
};


#define PROPERTY_INT(X) int m_##X;          \
    CString Get##X() const                  \
    {                                       \
        return Utils::Int2CString(m_##X);   \
    }

#define PROPERTY_DOUBLE(X, Y) double m_##X;     \
    CString Get##X() const                      \
    {                                           \
        return Utils::Double2CString(m_##X, Y); \
    }

#define PROPERTY_CSTRING(X) CString m_##X;      \
    CString Get##X() const                      \
    {                                           \
        return m_##X;                           \
    }

#define PROPERTY_CTIME_DAY(X) CTime m_##X;          \
    CString Get##X() const                          \
    {                                               \
        return Utils::CTime2CStringDay(m_##X);      \
    }