
// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
// 译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
// 如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
// "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

// f(i) = f(i-1) + g(i-1,i)*f(i-2)
//当nums[i-1]和nums[i]拼接在[10,25]时,g(i-1,i) = 1,否则 = 0

#include <iostream>
#include <string>
using namespace std;
int GetTranslationCount(int number) {
    if (number < 0)
        return 0;
    string strNumber = to_string(number);
    int len = strNumber.size();
    int* counts = new int[len]{0};
    counts[0] = 1;
    for (int i = 1; i < len; i++) {
        int digit1 = strNumber[i - 1] - '0';
        int digit2 = strNumber[i] - '0';
        int converted = digit1 * 10 + digit2;
        if (converted >= 10 && converted <= 25) {
            if (i > 2)
                counts[i] = counts[i - 1] + counts[i - 2];
            else
                counts[i] = counts[i - 1] + 1;
        } else {
            counts[i] = counts[i - 1];
        }
    }
    int count = counts[len - 1];
    delete[] counts;
    return count;
}

// ====================测试代码====================
void Test(const string& testName, int strNumber, int expected) {
    if (GetTranslationCount(strNumber) == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void Test1() {
    int strNumber = 0;
    int expected = 1;
    Test("Test1", strNumber, expected);
}

void Test2() {
    int strNumber = 10;
    int expected = 2;
    Test("Test2", strNumber, expected);
}

void Test3() {
    int strNumber = 125;
    int expected = 3;
    Test("Test3", strNumber, expected);
}

void Test4() {
    int strNumber = 126;
    int expected = 2;
    Test("Test4", strNumber, expected);
}

void Test5() {
    int strNumber = 426;
    int expected = 1;
    Test("Test5", strNumber, expected);
}

void Test6() {
    int strNumber = 100;
    int expected = 2;
    Test("Test6", strNumber, expected);
}

void Test7() {
    int strNumber = 101;
    int expected = 2;
    Test("Test7", strNumber, expected);
}

void Test8() {
    int strNumber = 12258;
    int expected = 5;
    Test("Test8", strNumber, expected);
}

void Test9() {
    int strNumber = -100;
    int expected = 0;
    Test("Test9", strNumber, expected);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}