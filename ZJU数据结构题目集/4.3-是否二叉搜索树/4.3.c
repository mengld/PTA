/*
本题要求实现函数，判断给定二叉树是否二叉搜索树。

函数接口定义：
bool IsBST ( BinTree T );
其中BinTree结构定义如下：

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
函数IsBST须判断给定的T是否二叉搜索树，即满足如下定义的二叉树：

定义：一个二叉搜索树是一棵二叉树，它可以为空。如果不为空，它将满足以下性质：

非空左子树的所有键值小于其根结点的键值。
非空右子树的所有键值大于其根结点的键值。
左、右子树都是二叉搜索树。
如果T是二叉搜索树，则函数返回true，否则返回false
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST(BinTree T);

int main()
{
    BinTree T;

    T = BuildTree();
    if (IsBST(T)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
/* 你的代码将被嵌在这里 */

// 一个错解
/*
bool IsBST(BinTree T) {
    // 该节点为空或为叶节点，符合二叉搜索树定义
    if (!T || !T->Left && !T->Right)
        return true;

    bool result = IsBST(T->Left) && IsBST(T->Right);
    
    if (result) {
        if (!T->Right)
            return result && (T->Left->Data < T->Data);
        if (!T->Left)
            return result && (T->Data < T->Right->Data);
   
        return result && (T->Left->Data < T->Data && T->Data < T->Right->Data);
    }
    
}
*/
/*
该递归判定法，仅能保证当前节点的左节点、右节点都是二叉搜索树，且左节点的值<当前节点值<右节点的值，没有完全符合二叉搜索树的定义（非空左子树的所有键值小于其根结点的键值）
因此，可能出现左子树的最大值小于根，或者右子树的最小值大于根
*/

// 正确的解，思路：中序遍历，得到序列，若为正序，则为二叉搜索树，否则不是，进一步简化，可以在遍历中对当前节点与前一个节点进行比较，若逆序则判定失败，遍历完成则判断成功
// 注，该法需补一个头文件
#include <limits.h>
bool IsBST(BinTree T) {
    static int prev = INT_MIN;

    if (T) {
        if (!IsBST(T->Left))
            return false;

        if (prev != INT_MIN && T->Data <= prev)
            return false;

        prev = T->Data;

        return IsBST(T->Right);
    }

    return true;
}
