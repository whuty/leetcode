

// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

// 1. flag = 1 , 循环左移 & n , 之所以不右移n 是为了避免负数导致的死循环
// 2. n = n & (n - 1) 相当于去除n最右边的1

#include <cstdio>

int numberOf1_solution1(int n) {
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (n & flag) {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

int numberOf1_solution2(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

// ====================测试代码====================
void Test(int number, unsigned int expected)
{
    int actual = numberOf1_solution1(number);
    if (actual == expected)
        printf("Solution1: Test for %d passed.\n", number);
    else
        printf("Solution1: Test for %d failed.\n", number);

    actual = numberOf1_solution2(number);
    if (actual == expected)
        printf("Solution2: Test for %d passed.\n", number);
    else
        printf("Solution2: Test for %d failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}