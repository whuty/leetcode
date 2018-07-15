
// 面试题16：数值的整数次方
// 题目：实现函数double pow(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

// 这里讨论了关于异常处理的方法，当输入参数出错时，将全局变量g_InvalidInput 置１
// 个人认为　throw exception 应该是更好的方法

#include <limits>
#include <stdexcept>
#include <iostream>

bool g_InvalidInput = false;

bool equal(double num1, double num2) {
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

double pow(double base, int exponent) {
    g_InvalidInput = false;
    if (equal(base, 0.0) && exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
        // throw std::invalid_argument(
        //     "exponent can't be negative while base is zero!");
    }

    double ans = 1.0;
    double x = base;
    long p;
    if (exponent < 0)
        p = (-1L) * exponent;
    else
        p = exponent;
    while (p) {
        if (p & 1)
            ans *= x;
        x *= x;
        p >>= 1;
    }
    if (exponent < 0)
        ans = 1.0 / ans;
    return ans;
}

// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = pow(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);

    return 0;
}