/*
本题要求实现一个函数，在递增的整数序列链表（带头结点）中插入一个新整数，并保持该序列的有序性。

函数接口定义：
List Insert( List L, ElementType X );
其中List结构定义如下：

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; // 存储结点数据 
    PtrToNode   Next; // 指向下一个结点的指针
};
typedef PtrToNode List; // 定义单链表类型
L是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Insert要将X插入L，并保持该序列的有序性，返回插入后的链表头指针

输入样例：
5
1 2 4 5 6
3
输出样例：
1 2 3 4 5 6 
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Insert(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Insert(List L, ElementType X) {
    List head = L;
    while (L->Next && L->Next->Data < X)
        L = L->Next;
    List node = (List)malloc(sizeof(struct Node));
    node->Data = X;
    node->Next = L->Next;
    L->Next = node;

    return head;
}
