
// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

//  如果只有一个数字只出现一次,其余出现两次,那么所有数异或得到只出现一次的数
// 两个数只出现一次,那么所有数异或之后得到这两个数的异或 resultExclusiveOR
// resultExclusiveOR 中为1 的位就是这两数不同的位
// 将所有数分成两组,分别求异或,得解

// n & (n - 1) 等同于将n最右边的1置0;
// n & (~n + 1) 取n最右边的1, 例如 n = 010110, 得000010

#include <cstdio>

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {
    if (data == nullptr || length < 2)
        return;
    int resultExclusiveOR = 0;
    for (int i = 0; i < length; i++) {
        resultExclusiveOR ^= data[i];
    }
    int p = resultExclusiveOR & (~resultExclusiveOR + 1);
    *num1 = *num2 = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] & p) {
            *num1 ^= data[i];
        } else {
            *num2 ^= data[i];
        }
    }
}

// ====================测试代码====================
void Test(const char* testName,
          int data[],
          int length,
          int expected1,
          int expected2) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    int result1, result2;
    FindNumsAppearOnce(data, length, &result1, &result2);

    if ((expected1 == result1 && expected2 == result2) ||
        (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1() {
    int data[] = {2, 4, 3, 6, 3, 2, 5, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2() {
    int data[] = {4, 6};
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3() {
    int data[] = {4, 6, 1, 1, 1, 1};
    Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();

    return 0;
}