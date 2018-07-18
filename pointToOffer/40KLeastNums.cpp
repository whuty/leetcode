

// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

// 1. Partition, O(n), 需改变输入的数组
// 2. 最大堆, O(nlogk), 空间使用很小,适用于大量数据,可用multiset,
// 红黑树,保存最小的k个数,priority_queue

#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

std::vector<int> GetLeastNumbers_Solution1(const std::vector<int>& nums,
                                           int k) {
    std::vector<int> pq;
    if (k < 1 || nums.size() < k)
        return pq;
    for (int i : nums) {
        if (pq.size() < k) {
            pq.push_back(i);
            std::push_heap(pq.begin(), pq.end());
        } else {
            std::pop_heap(pq.begin(), pq.end());
            if (i < pq.back()) {
                pq.pop_back();
                pq.push_back(i);
            }
            std::push_heap(pq.begin(), pq.end());
        }
    }
    return pq;
}

typedef std::multiset<int, std::greater<int>> intSet;
typedef std::multiset<int, std::greater<int>>::iterator setIterator;

void GetLeastNumbers_Solution2(const std::vector<int>& nums,
                               intSet& leastNumbers,
                               int k) {
    leastNumbers.clear();
    if (k < 1 || nums.size() < k)
        return;
    for (int i : nums) {
        if (leastNumbers.size() < k)
            leastNumbers.insert(i);
        else {
            setIterator iterGreatest = leastNumbers.begin();
            if (i < *iterGreatest) {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(i);
            }
        }
    }
}

// ====================测试代码====================
void Test(const char* testName, int* data, int n, int* expectedResult, int k) {
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    std::vector<int> vectorData;
    for (int i = 0; i < n; ++i)
        vectorData.push_back(data[i]);

    if (expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else {
        printf("Expected result: \n");
        for (int i = 0; i < k; ++i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution1:\n");
    std::vector<int> output = GetLeastNumbers_Solution1(vectorData, k);
    if (expectedResult != nullptr) {
        for (int i : output)
            printf("%d\t", i);
        printf("\n");
    }

    printf("Result for solution2:\n");
    intSet leastNumbers;
    GetLeastNumbers_Solution2(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end();
         ++iter)
        printf("%d\t", *iter);
    printf("\n\n");
}

// k小于数组的长度
void Test1() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected,
         sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected,
         sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected,
         sizeof(expected) / sizeof(int));
}

// k等于0
void Test5() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6() {
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected,
         sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7() {
    int* expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
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
