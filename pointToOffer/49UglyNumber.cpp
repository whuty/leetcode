
// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

// 用一个数组存储已经找到的丑数,用三个指针分别指向*2,*3,*5后可能指向下个丑数的数

#include <algorithm>
#include <cstdio>
int GetUglyNumber(int index) {
    if (index <= 0)
        return 0;
    int* pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;

    int* pMultiply2 = pUglyNumbers;
    int* pMultiply3 = pUglyNumbers;
    int* pMultiply5 = pUglyNumbers;

    while (nextUglyIndex < index) {
        pUglyNumbers[nextUglyIndex] = std::min(
            std::min(*pMultiply2 * 2, *pMultiply3 * 3), *pMultiply5 * 5);
        while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
            pMultiply2++;
        while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
            pMultiply3++;
        while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
            pMultiply5++;
        nextUglyIndex++;
    }
    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete[] pUglyNumbers;
    return ugly;
}

// ====================测试代码====================
void Test(int index, int expected) {
    if (GetUglyNumber(index) == expected)
        printf("solution passed\n");
    else
        printf("solution failed\n");
}

int main(int argc, char* argv[]) {
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}
