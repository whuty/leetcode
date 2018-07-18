
// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。

#include <cstdio>
#include <stack>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void MirrorRecursively(BinaryTreeNode* pNode) {
    if (pNode == nullptr)
        return;
    if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
        return;
    BinaryTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if (pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);
    if (pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}

void MirrorIteratively(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr)
        return;
    std::stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(pRoot);
    while (!nodeStack.empty()) {
        BinaryTreeNode* pNode = nodeStack.top();
        nodeStack.pop();
        BinaryTreeNode* pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pLeft = pTemp;

        if (pNode->m_pLeft)
            nodeStack.push(pNode->m_pLeft);
        if (pNode->m_pRight)
            nodeStack.push(pNode->m_pRight);
    }
}

// ====================辅助测试代码====================
BinaryTreeNode* CreateBinaryTreeNode(double dbValue) {
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = dbValue;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent,
                      BinaryTreeNode* pLeft,
                      BinaryTreeNode* pRight) {
    if (pParent != nullptr) {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}
void PrintTreeNode(BinaryTreeNode* pNode) {
    if (pNode != nullptr) {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if (pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n",
                   pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");

        if (pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n",
                   pNode->m_pRight->m_nValue);
        else
            printf("right child is null.\n");
    } else {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot) {
    PrintTreeNode(pRoot);

    if (pRoot != nullptr) {
        if (pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if (pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}
void DestroyTree(BinaryTreeNode* pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1() {
    printf("=====Test1 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    PrintTree(pNode8);

    printf("=====Test1: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test1: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7
//        6
//      5
//    4
void Test2() {
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, nullptr);
    ConnectTreeNodes(pNode7, pNode6, nullptr);
    ConnectTreeNodes(pNode6, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode4, nullptr);

    PrintTree(pNode8);

    printf("=====Test2: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test2: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7
//              6
//               5
//                4
void Test3() {
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, nullptr, pNode7);
    ConnectTreeNodes(pNode7, nullptr, pNode6);
    ConnectTreeNodes(pNode6, nullptr, pNode5);
    ConnectTreeNodes(pNode5, nullptr, pNode4);

    PrintTree(pNode8);

    printf("=====Test3: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test3: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test4() {
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = nullptr;

    PrintTree(pNode);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode);
    PrintTree(pNode);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode);
    PrintTree(pNode);
}

// 测试只有一个结点的二叉树
void Test5() {
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

    PrintTree(pNode8);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
