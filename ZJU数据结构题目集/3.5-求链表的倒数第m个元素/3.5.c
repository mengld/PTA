/*
请设计时间和空间上都尽可能高效的算法，在不改变链表的前提下，求链式存储的线性表的倒数第m（>0）个元素。

函数接口定义：
ElementType Find( List L, int m );
其中List结构定义如下：

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; // 存储结点数据
    PtrToNode   Next; // 指向下一个结点的指针 
};
typedef PtrToNode List; // 定义单链表类型
L是给定的带头结点的单链表；函数Find要将L的倒数第m个元素返回，并不改变原链表。如果这样的元素不存在，则返回一个错误标志ERROR

输入样例：
5
1 2 4 5 6
3
输出样例：
4
1 2 4 5 6
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

ElementType Find(List L, int m);

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */

// L是给定的带头结点的单链表；函数Find要将L的倒数第m个元素返回，并不改变原链表。如果这样的元素不存在，则返回一个错误标志ERROR
// 方法：首先计算链表长度length，再对m的合法性进行检验，若不合法，则返回ERROR，然后将倒数第m转换为正数第 Length - m + 1
ElementType Find(List L, int m) {
    List head = L;
    int length = 0;
    L = L->Next;
    while (L) {
        L = L->Next;
        length++;
    }
    
    if (m < 1 || m > length)
        return ERROR;

    int n = length - m + 1;
    int i = 1;
    L = head->Next;

    while (i < n) {
        L = L->Next;
        i++;
    }
    
    return L->Data;
}
