
// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。

#include <cstdio>

char FirstNotRepeatingChar(const char* pString) {
    if(pString == nullptr) return '\0';
    const int talbleSize = 256;
    unsigned int hashTable[talbleSize];
    for(int i = 0;i<talbleSize;i++){
        hashTable[i] = 0;
    }
    const char* pHashKey = pString;
    while(*pHashKey != '\0') {
        hashTable[*(pHashKey++)]++;
    }
    pHashKey = pString;
    while(*pHashKey != '\0'){
        if(hashTable[*pHashKey] == 1) {
            return *pHashKey;
        }
        pHashKey++;
    }
    return '\0';
}

// ====================测试代码====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(nullptr, '\0');

    return 0;
}