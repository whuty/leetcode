

// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

// reverse 前n位,得到bacdefg
// reverse 之后的位, bagfedc
// reverse 所有, 得到结果 cdefgab

#include <cstdio>
#include <cstring>

void Reverse(char* pBegin, char* pEnd) {
    if (pBegin == nullptr || pEnd == nullptr)
        return;
    while (pBegin < pEnd) {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++;
        pEnd--;
    }
}

char* LeftRotateString(char* pStr, int n) {
    if (pStr != nullptr) {
        int nLength = strlen(pStr);
        if (nLength > 0 && n > 0 && n < nLength) {
            Reverse(pStr, pStr + n - 1);
            Reverse(pStr + n, pStr + nLength - 1);
            Reverse(pStr, pStr + nLength - 1);
        }
    }
    return pStr;
}

// ====================测试代码====================
void Test(const char* testName,
          char* input,
          int num,
          const char* expectedResult) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if ((input == nullptr && expectedResult == nullptr) ||
        (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void Test1() {
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2() {
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3() {
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4() {
    Test("Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void Test5() {
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6() {
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}