
// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。

#include <cstdio>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode* pNext;
    ListNode(int x) : val(x), pNext(nullptr) {}
};

void DelDup(ListNode** pHead) {
    if (pHead == nullptr || *pHead == nullptr)
        return;
    ListNode* pPreNode = nullptr;
    ListNode* pNode = *pHead;

    while (pNode != nullptr) {
        ListNode* pNext = pNode->pNext;
        bool needDel = false;
        if (pNext != nullptr && pNext->val == pNode->val) {
            needDel = true;
        }

        if (!needDel) {
            pPreNode = pNode;
            pNode = pNext;
        } else {
            int value = pNode->val;
            ListNode* pToBeDel = pNode;
            while (pToBeDel != nullptr && pToBeDel->val == value) {
                pNext = pToBeDel->pNext;
                delete pToBeDel;
                pToBeDel = nullptr;
                pToBeDel = pNext;
            }
            if (pPreNode == nullptr) {
                *pHead = pNext;
            } else {
                pPreNode->pNext = pNext;
            }
            pNode = pNext;
        }
    }
}
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
    if (!pListHead || !pToBeDeleted)
        return;

    if (pToBeDeleted->pNext != nullptr) {
        ListNode* pNext = pToBeDeleted->pNext;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->pNext = pNext->pNext;
        delete pNext;
        pNext = nullptr;
    } else if (*pListHead == pToBeDeleted) {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    } else {
        ListNode* pNode = *pListHead;
        while (pNode->pNext != pToBeDeleted && pNode->pNext != nullptr) {
            pNode = pNode->pNext;
        }
        pNode->pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
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
void Test(const char* testName,
          ListNode** pHead,
          int* expectedValues,
          int expectedLength) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    DelDup(pHead);

    int index = 0;
    ListNode* pNode = *pHead;
    while (pNode != nullptr && index < expectedLength) {
        if (pNode->val != expectedValues[index])
            break;

        pNode = pNode->pNext;
        index++;
    }

    if (pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 某些结点是重复的
void Test1() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(4);
    ListNode* pNode6 = new ListNode(4);
    ListNode* pNode7 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = {1, 2, 5};
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 没有重复的结点
void Test2() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);
    ListNode* pNode7 = new ListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 除了一个结点之外其他所有结点的值都相同
void Test3() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = {2};
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 所有结点的值都相同
void Test4() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    Test("Test4", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 所有结点都成对出现
void Test5() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(2);
    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode6 = new ListNode(3);
    ListNode* pNode7 = new ListNode(4);
    ListNode* pNode8 = new ListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    Test("Test5", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 除了两个结点之外其他结点都成对出现
void Test6() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode6 = new ListNode(4);
    ListNode* pNode7 = new ListNode(5);
    ListNode* pNode8 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = {2, 4};
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 链表中只有两个不重复的结点
void Test7() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = {1, 2};
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有一个结点
void Test8() {
    ListNode* pNode1 = new ListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode* pHead = pNode1;

    int expectedValues[] = {1};
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有两个重复的结点
void Test9() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    Test("Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 空链表
void Test10() {
    ListNode* pHead = nullptr;

    Test("Test10", &pHead, nullptr, 0);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

    return 0;
}