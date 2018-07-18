
// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

#include <algorithm>
#include <cstdio>
#include <queue>
#include <stdexcept>
using namespace std;
template <typename T>
class DynamicArray {
   public:
    void Insert(T num) {
        if (((min.size() + max.size()) & 1) == 0) {
            if (max.size() > 0 && num < max.top()) {
                max.push(num);
                num = max.top();
                max.pop();
            }
            min.push(num);
        } else {
            if (min.size() > 0 && num > min.top()) {
                min.push(num);
                num = min.top();
                min.pop();
            }
            max.push(num);
        }
    }
    T GetMedian() {
        int size = min.size() + max.size();
        if (size == 0)
            throw invalid_argument("No numbers");
        T median = 0;
        if ((size & 1) == 0)
            median = (min.top() + max.top()) / 2;
        else
            median = min.top();
        return median;
    }

   private:
    priority_queue<T, vector<T>, greater<T> > min;
    priority_queue<T, vector<T>, less<T> > max;
};

// ====================测试代码====================
void Test(const char* testName,
          DynamicArray<double>& numbers,
          double expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (abs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[]) {
    DynamicArray<double> numbers;

    printf("Test1 begins: ");
    try {
        numbers.GetMedian();
        printf("FAILED.\n");
    } catch (const exception&) {
        printf("Passed.\n");
    }

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}