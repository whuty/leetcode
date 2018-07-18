
// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

#include <cstdio>
#include <stack>

bool isPopOrder(const int* pPush, const int* pPop, int nLength) {
    if (pPush == nullptr || pPop == nullptr || nLength <= 0)
        return false;
    const int* pNextPush = pPush;
    const int* pNextPop = pPop;

    std::stack<int> stackData;

    while (pNextPop - pPop < nLength) {
        while (stackData.empty() || stackData.top() != *pNextPop) {
            if (pNextPush - pPush == nLength)
                return false;
            stackData.push(*pNextPush);
            pNextPush++;
        }
        if (stackData.top() != *pNextPop)
            return false;
        stackData.pop();
        pNextPop++;
    }
    if (stackData.empty() && pNextPop - pPop == nLength)
        return true;
    return false;
}

// ====================测试代码====================
void Test(const char* testName,
          const int* pPush,
          const int* pPop,
          int nLength,
          bool expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (isPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};

    Test("Test1", push, pop, nLength, true);
}

void Test2() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};

    Test("Test2", push, pop, nLength, true);
}

void Test3() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};

    Test("Test3", push, pop, nLength, false);
}

void Test4() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};

    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5() {
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6() {
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7() {
    Test("Test7", nullptr, nullptr, 0, false);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
