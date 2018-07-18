
// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include <cstdio>

bool isEven(int n) {
    return (n & 1) == 0;
}

void Reorder(int* pData, unsigned int length, bool (*func)(int)) {
    if (pData == nullptr || length == 0)
        return;
    int* pLeft = pData;
    int* pRight = pData + length - 1;

    while (pLeft < pRight) {
        while (pLeft < pRight && !func(*pLeft))
            pLeft++;
        while (pLeft < pRight && func(*pRight))
            pRight--;
        if (pLeft < pRight) {
            int tmp = *pLeft;
            *pLeft = *pRight;
            *pRight = tmp;
        }
    }
}

// ====================测试代码====================
void PrintArray(int numbers[], int length) {
    if (length < 0)
        return;

    for (int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(const char* testName, int numbers[], int length) {
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    int* copy = new int[length];
    for (int i = 0; i < length; ++i) {
        copy[i] = numbers[i];
    }

    PrintArray(numbers, length);
    Reorder(numbers, length, isEven);
    PrintArray(numbers, length);

    delete[] copy;
}

void Test1() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2() {
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3() {
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4() {
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5() {
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6() {
    Test("Test6", nullptr, 0);
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