

// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

// (二): 队列的最大值
// 定义一个队列并实现函数max得到队列里的最大值,要求函数max,push_back,pop_front的时间复杂度都是O(1)

#include <cstdio>
#include <exception>
#include <queue>

template <typename T>
class QueueWithMax {
   public:
    QueueWithMax() : currentIndex(0) {}

    void push_back(T number) {
        while (!maximums.empty() && number >= maximums.back().number) {
            maximums.pop_back();
        }
        InternalData internalData = {number, currentIndex};
        data.push_back(internalData);
        maximums.push_back(internalData);
        currentIndex++;
    }

    void pop_front() {
        if (maximums.empty())
            throw std::exception();
        if (maximums.front().index == data.front().index)
            maximums.pop_front();
        data.pop_front();
    }

    T max() const {
        if (maximums.empty())
            throw std::exception();
        return maximums.front().number;
    }

   private:
    struct InternalData {
        T number;
        int index;
    };
    std::deque<InternalData> data;
    std::deque<InternalData> maximums;
    int currentIndex;
};

// ====================测试代码====================
void Test(const char* testName, const QueueWithMax<int>& queue, int expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (queue.max() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[]) {
    QueueWithMax<int> queue;
    // {2}
    queue.push_back(2);
    Test("Test1", queue, 2);

    // {2, 3}
    queue.push_back(3);
    Test("Test2", queue, 3);

    // {2, 3, 4}
    queue.push_back(4);
    Test("Test3", queue, 4);

    // {2, 3, 4, 2}
    queue.push_back(2);
    Test("Test4", queue, 4);

    // {3, 4, 2}
    queue.pop_front();
    Test("Test5", queue, 4);

    // {4, 2}
    queue.pop_front();
    Test("Test6", queue, 4);

    // {2}
    queue.pop_front();
    Test("Test7", queue, 2);

    // {2, 6}
    queue.push_back(6);
    Test("Test8", queue, 6);

    // {2, 6, 2}
    queue.push_back(2);
    Test("Test9", queue, 6);

    // {2, 6, 2, 5}
    queue.push_back(5);
    Test("Test9", queue, 6);

    // {6, 2, 5}
    queue.pop_front();
    Test("Test10", queue, 6);

    // {2, 5}
    queue.pop_front();
    Test("Test11", queue, 5);

    // {5}
    queue.pop_front();
    Test("Test12", queue, 5);

    // {5, 1}
    queue.push_back(1);
    Test("Test13", queue, 5);

    return 0;
}