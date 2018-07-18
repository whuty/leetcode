
// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

#include <cstdio>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode* pNext;
    ListNode(int x) : val(x), pNext(nullptr) {}
};

ListNode* MeetingNode(ListNode* pHead) {
    if (pHead == nullptr)
        return nullptr;

    ListNode* pSlow = pHead->pNext;
    if (pSlow == nullptr)
        return nullptr;
    ListNode* pFast = pSlow->pNext;
    while (pFast != nullptr && pSlow != nullptr) {
        if (pFast == pSlow)
            return pFast;
        pSlow = pSlow->pNext;
        pFast = pFast->pNext;
        if (pFast != nullptr)
            pFast = pFast->pNext;
    }
    return nullptr;
}

ListNode* EntryOfLoop(ListNode* pHead) {
    ListNode* meetingNode = MeetingNode(pHead);
    if (meetingNode == nullptr)
        return nullptr;
    int nodesInLoop = 1;
    ListNode* pNode = meetingNode;
    while (pNode->pNext != meetingNode) {
        pNode = pNode->pNext;
        nodesInLoop++;
    }
    pNode = pHead;
    ListNode* pEntry = pHead;
    for (int i = 0; i < nodesInLoop; i++) {
        pNode = pNode->pNext;
    }

    while (pEntry != pNode) {
        pNode = pNode->pNext;
        pEntry = pEntry->pNext;
    }
    return pEntry;
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
// ==================== Test Code ====================
void Test(const char* testName, ListNode* pHead, ListNode* entryNode) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (EntryOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1() {
    ListNode* pNode1 = new ListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2() {
    ListNode* pNode1 = new ListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop
void Test3() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
void Test4() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
void Test5() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop
void Test6() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7() {
    Test("Test7", nullptr, nullptr);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}