

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#include <cstdio>
#include <cstring>
using namespace std;
class CMyString {
   public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator=(const CMyString& str);

   private:
    char* m_pData;
};

CMyString::CMyString(const CMyString& str) {
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString& CMyString::operator=(const CMyString& str) {
    if (this == &str) {
        return *this;
    }
    delete[] m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

CMyString& CMyString::operator=(const CMyString& str) {
    if (this != &str) {
        CMyString strTemp(str);
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}
