/*
本题要求实现一个函数，将给定的单链表逆转。

函数接口定义：
List Reverse( List L );
其中List结构定义如下：

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; 
    PtrToNode   Next; 
};
typedef PtrToNode List; 
L是给定单链表，函数Reverse要返回被逆转后的链表。

裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); 
void Print( List L ); 

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}


输入样例：
5
1 3 4 5 2
输出样例：
1
2 5 4 3 1
*/

List Reverse(List L) {

    List p, q;
    p = L;
    L = NULL;
    while (p != NULL) {
        q = p;
        p = p->Next;
        q->Next = L;
        L = q;
    }
    return L;
}
