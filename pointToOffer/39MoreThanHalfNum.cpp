
// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

// 1. Partition, O(n)
// 2.
// 遍历数组，如果下一个数与保存的数相同，次数加一，否则减一，如果次数为０保存下一个数
//    因为要找的数字出现次数比其他数加起来多，所以最后保存的数字就是要找的数

#include <cstdio>
#include <stdexcept>

void swap(int* num1, int* num2) {
    if (num1 == num2)
        return;
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Partition(int nums[], int length, int start, int end) {
    if (nums == nullptr || length <= 0 || start < 0 || end >= length)
        throw std::invalid_argument("invalid arguments");

    int index = rand() % (end - start + 1) + start;
    swap(&nums[index], &nums[start]);
    int pivot = start;
    int v = nums[start];
    for (int i = start + 1; i <= end; i++) {
        if (nums[i] < v) {
            pivot++;
            swap(&nums[i], &nums[pivot]);
        }
    }
    swap(&nums[pivot], &nums[start]);
    return pivot;
}

int MoreThanHalfNum_Solution1(int* nums, int length) {
    if (nums == nullptr || length <= 0)
        throw std::invalid_argument("invalid arguments");
    if(length == 1) return nums[0];
    int mid = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(nums, length, start, end);
    while (index != mid) {
        if (index > mid) {
            end = index - 1;
            index = Partition(nums, length, start, end);
        } else {
            start = index + 1;
            index = Partition(nums, length, start, end);
        }
    }
    int result = nums[mid];
    return result;
}

int MoreThanHalfNum_Solution2(int* nums, int length) {
    if (nums == nullptr || length <= 0)
        throw std::invalid_argument("invalid arguments");
    int result = nums[0];
    int times = 1;
    for (int i = 1; i < length; i++) {
        if (times == 0) {
            result = nums[i];
            times = 1;
        } else if (nums[i] == result) {
            times++;
        } else {
            times--;
        }
    }
    return result;
}

// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = MoreThanHalfNum_Solution1(numbers, length);
    if(result == expectedValue)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    result = MoreThanHalfNum_Solution2(copy, length);
    if(result == expectedValue)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}



// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

void Test5()
{
   int numbers[] = {1};
   Test("Test5", numbers, 1, 1, false);
}


int main(int argc, char* argv[])
{
    Test1();
    Test3();
    Test4();
    Test5();

    return 0;
}