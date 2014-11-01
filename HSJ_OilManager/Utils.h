#pragma once


class Utils
{
public:
    Utils(void);
    ~Utils(void);

    static CString Int2CString(int num);
    static int CString2Int(CString& str);

    static CString Double2CString(double num, int point);
};


#define PROPERTY_INT(X) int m_##X;          \
    CString Get##X() const                  \
    {                                       \
        return Utils::Int2CString(m_##X);   \
    }

#define PROPERTY_DOUBLE(X, Y) double m_##X;     \
    CString Get##X() const                      \
    {                                           \
        CString str(STR_EMPTY);                 \
        switch (Y)                              \
        {                                       \
        case 3:                                 \
        default:                                \
            str.Format(STR_FLOAT_3, m_##X);     \
        }                                       \
        return str;                             \
    }

#define PROPERTY_CSTRING(X) CString m_##X;      \
    CString Get##X() const                      \
    {                                           \
        return m_##X;                           \
    }