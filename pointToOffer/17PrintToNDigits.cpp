
// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include <cstdio>

bool increment(char* number, int index) {
    if (index < 0)
        return false;
    if (number[index] < '9')
        number[index]++;
    else {
        number[index] = '0';
        return increment(number, index - 1);
    }
    return true;
}

void printToNDigitsRecursively(char* number,
                               int length,
                               int index,
                               int startIndex) {
    if (index == length - 1) {
        printf("%s ", number + startIndex);
        return;
    }
    number[index + 1] = '0';
    printToNDigitsRecursively(number, length, index + 1,
                              startIndex > index ? startIndex + 1 : startIndex);
    for (int i = 1; i < 10; i++) {
        number[index + 1] = i + '0';
        printToNDigitsRecursively(number, length, index + 1, startIndex);
    }
}

void PrintNumber(char* number, int length) {
    bool isBeginning0 = true;
    for (int i = 0; i < length; i++) {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if (!isBeginning0)
            printf("%c", number[i]);
    }
    printf("\t");
}

void PrintToNDigits(int n) {
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';
    for (int i = 0; i < n; i++)
        number[i] = '0';

    while (increment(number, n - 1)) {
        PrintNumber(number, n);
    }
    delete[] number;
}

void PrintToNDigits2(int n) {
    if (n <= 0)
        return;
    char* number = new char[n + 1];
    number[n] = '\0';
    number[0] = '0';
    printToNDigitsRecursively(number, n, 0, 1);
    for (int i = 1; i < 10; i++) {
        number[0] = i + '0';
        printToNDigitsRecursively(number, n, 0, 0);
    }
    delete[] number;
}

void PrintToNDigits3(int n) {
    if (n <= 0)
        return;
    char* number = new char[n + 1];
    number[n] = '\0';
    for (int i = 0; i < n - 1; i++)
        number[i] = '0';
    number[n - 1] = '1';
    while (number[0] < 10 + '0') {
        PrintNumber(number, n);
        int k = n - 1;
        number[k]++;
        while (k > 0 && number[k] == 10 + '0') {
            number[k] = '0';
            number[--k]++;
        }
    }
}

void Test(int n) {
    printf("Test for %d begins:\n", n);
    PrintToNDigits(n);
    PrintToNDigits2(n);
    PrintToNDigits3(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[]) {
    Test(1);
    Test(2);
    Test(3);

    Test(0);
    Test(-1);

    return 0;
}
