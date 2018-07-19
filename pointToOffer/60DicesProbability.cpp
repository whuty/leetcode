

// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。

#include <algorithm>
#include <cstdio>

void PrintProbability(int number) {
    const int dice = 6;
    if (number < 1)
        return;
    int* pProbabilities[2];
    pProbabilities[0] = new int[dice * number + 1];
    pProbabilities[1] = new int[dice * number + 1];
    for (int i = 0; i < dice * number + 1; i++) {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }
    int flag = 0;

    for (int i = 1; i <= dice; i++) {
        pProbabilities[flag][i] = 1;
    }
    for (int k = 2; k <= number; k++) {
        for (int i = 0; i < k; i++) {
            pProbabilities[1 - flag][i] = 0;
        }
        for (int i = k; i <= dice * k; i++) {
            pProbabilities[1 - flag][i] = 0;
            for (int j = 1; j <= i && j <= dice; j++) {
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
            }
        }
        flag = 1 - flag;
    }

    double total = pow((double)dice, number);
    for (int i = number; i <= dice * number; i++) {
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}

// ====================测试代码====================
void Test(int n) {
    printf("Test for %d begins:\n", n);

    printf("Test for solution\n");
    PrintProbability(n);

    printf("\n");
}

int main(int argc, char* argv[]) {
    Test(1);
    Test(2);
    Test(3);
    Test(4);

    Test(11);

    Test(0);

    return 0;
}