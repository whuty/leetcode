
// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

// 通过归并排序,每次归并过程中可以计算两排序数组之间的逆序数

#include <cstdio>

int InversePairsCore(int* data, int* copy, int start, int end) {
    if (start == end) {
        copy[start] = data[start];
        return 0;
    }
    int mid = start + ((end - start) >> 1);
    int left = InversePairsCore(copy, data, start, mid);
    int right = InversePairsCore(copy, data, mid + 1, end);
    int i = mid;
    int j = end;
    int indexCopy = end;
    int count = 0;
    while (indexCopy >= start) {
        if (i < start) {
            copy[indexCopy--] = data[j--];
        } else if (j <= mid) {
            copy[indexCopy--] = data[i--];
        } else if (data[i] > data[j]) {
            copy[indexCopy--] = data[i--];
            count += j - mid;
        } else {
            copy[indexCopy--] = data[j--];
        }
    }
    return count + left + right;
}

int InversePairs(int* data, int length) {
    if (data == nullptr || length <= 0)
        return 0;
    int* copy = new int[length];
    for (int i = 0; i < length; i++) {
        copy[i] = data[i];
    }
    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;
    return count;
}

// ====================测试代码====================
void Test(const char* testName, int* data, int length, int expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1() {
    int data[] = {1, 2, 3, 4, 7, 6, 5};
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2() {
    int data[] = {6, 5, 4, 3, 2, 1};
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3() {
    int data[] = {1, 2, 3, 4, 5, 6};
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4() {
    int data[] = {1};
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递增排序
void Test5() {
    int data[] = {1, 2};
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6() {
    int data[] = {2, 1};
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7() {
    int data[] = {1, 2, 1, 2, 1};
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8() {
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
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

    return 0;
}
