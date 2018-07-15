//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

// 1. 使用stack存储从头开始的节点,然后一个个pop出来
// 2.
// 使用递归,先递归输出后面的节点,然后输出自身,缺点是链表很长时有栈溢出的可能性

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void PrintListReversingly_Iteratively(ListNode* pHead) {
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while (pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    while (!nodes.empty()) {
        pNode = nodes.top();
        printf("%d\t", pNode->val);
        nodes.pop();
    }
}

void PrintListReversingly_Recursively(ListNode* pHead) {
    if (pHead == nullptr)
        return;
    if (pHead->next != nullptr)
        PrintListReversingly_Recursively(pHead->next);
    printf("%d\t", pHead->val);
}

void PrintList(ListNode* pHead) {
    if (pHead == nullptr)
        return;
    cout << pHead->val;
    ListNode* pNode = pHead->next;
    while (pNode != nullptr) {
        cout << "-" << pNode->val;
        pNode = pNode->next;
    }
    cout << endl;
}

// ====================测试代码====================
void Test(ListNode* pHead) {
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1() {
    printf("\nTest1 begins.\n");

    ListNode pNode1(1);
    ListNode pNode2(2);
    ListNode pNode3(3);
    ListNode pNode4(4);
    ListNode pNode5(5);

    pNode1.next = &pNode2;
    pNode2.next = &pNode3;
    pNode3.next = &pNode4;
    pNode4.next = &pNode5;

    Test(&pNode1);
}

// 只有一个结点的链表: 1
void Test2() {
    printf("\nTest2 begins.\n");

    ListNode pNode1(1);

    Test(&pNode1);
}

// 空链表
void Test3() {
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();

    return 0;
}