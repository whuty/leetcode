
// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。

#include <cstdio>

int NumberOf1Between1AndN(int n) {
    int count = 0;
    int i = 1;
    int current = 0, after = 0, before = 0;
    while (n / i != 0) {
        current = (n / i) % 10;
        before = n / (i * 10);
        after = n - (n / i) * i;

        if (current > 1) {
            count = count + (before + 1) * i;
        } else if (current == 0) {
            count = count + before * i;
        } else if (current == 1) {
            count = count + before * i + after + 1;
        }

        i *= 10;
    }
    return count;
}

// ====================测试代码====================
void Test(const char* testName, int n, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    int count = NumberOf1Between1AndN(n);
    printf("%d\n",count);
    if(count == expected)
        printf("Solution passed.\n");
    else{
        printf("Solution failed.\n"); }
    

    printf("\n");
}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
}

int main(int argc, char* argv[])
{
    Test();

    return 0;
}
