
// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

#include <cstdio>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode* pNext;
    ListNode(int x) : val(x), pNext(nullptr) {}
};

ListNode* ReverseList(ListNode* pHead) {
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;
    while (pNode != nullptr) {
        ListNode* pNext = pNode->pNext;
        if (pNext == nullptr)
            pReversedHead = pNode;
        pNode->pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
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
ListNode* Test(ListNode* pHead) {
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2() {
    ListNode* pNode1 = new ListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3() {
    Test(nullptr);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();

    return 0;
}
