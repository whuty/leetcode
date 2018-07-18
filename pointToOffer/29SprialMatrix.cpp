
// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

#include <cstdio>

void PrintSprialMatrix(int** numbers, int cols, int rows) {
    if (numbers == nullptr || cols <= 0 || rows <= 0)
        return;
    for (int start = 0; cols > start * 2 && rows > start * 2; start++) {
        int endX = cols - 1 - start;
        int endY = rows - 1 - start;
        for (int i = start; i <= endX; i++) {
            printf("%d ", numbers[start][i]);
        }
        for (int i = start + 1; i <= endY; i++) {
            printf("%d ", numbers[i][endX]);
        }
        if (start < endX) {
            for (int i = endX - 1; i > start; i--) {
                printf("%d ", numbers[endY][i]);
            }
        }
        if (start < endY) {
            for (int i = endY; i > start; i--) {
                printf("%d ", numbers[i][start]);
            }
        }
    }
}

// ====================测试代码====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintSprialMatrix(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}
