
// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

#include <cstdio>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode* pNext;
    ListNode(int x) : val(x), pNext(nullptr) {}
};

ListNode* FindKthToTail(ListNode* pHead, unsigned int k) {
    if (pHead == nullptr || k == 0)
        return nullptr;
    ListNode* pAhead = pHead;
    ListNode* pBehind = nullptr;

    for (unsigned int i = 0; i < k - 1; i++) {
        if (pAhead->pNext != nullptr) {
            pAhead = pAhead->pNext;
        } else
            return nullptr;
    }
    pBehind = pHead;
    while (pAhead->pNext != nullptr) {
        pAhead = pAhead->pNext;
        pBehind = pBehind->pNext;
    }
    return pBehind;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
    if (pCurrent == nullptr) {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->pNext = pNext;
}

void PrintListNode(ListNode* pNode) {
    if (pNode == nullptr) {
        printf("The node is nullptr\n");
    } else {
        printf("The key in node is %d.\n", pNode->val);
    }
}

void PrintList(ListNode* pHead) {
    printf("PrintList starts.\n");

    ListNode* pNode = pHead;
    while (pNode != nullptr) {
        printf("%d\t", pNode->val);
        pNode = pNode->pNext;
    }

    printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead) {
    ListNode* pNode = pHead;
    while (pNode != nullptr) {
        pHead = pHead->pNext;
        delete pNode;
        pNode = pHead;
    }
}
// ====================测试代码====================
// 测试要找的结点在链表中间
void Test1() {
    printf("=====Test1 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void Test2() {
    printf("=====Test2 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode* pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的头结点
void Test3() {
    printf("=====Test3 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode* pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试空链表
void Test4() {
    printf("=====Test4 starts:=====\n");
    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(nullptr, 100);
    PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5() {
    printf("=====Test5 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试输入的第二个参数为0
void Test6() {
    printf("=====Test6 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
