/*
本题要求将任一给定元素插入从大到小排好序的数组中合适的位置，以保持结果依然有序。

函数接口定义：
bool Insert( List L, ElementType X );
其中List结构定义如下：

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; //保存线性表中最后一个元素的位置
};
L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，并且题目保证传入的数据是递减有序的。
函数Insert要将X插入Data[]中合适的位置，以保持结果依然有序（注意：元素从下标0开始存储）。
但如果X已经在Data[]中了，就不要插入，返回失败的标记false；如果插入成功，则返回true。
另外，因为Data[]中最多只能存MAXSIZE个元素，所以如果插入新元素之前已经满了，也不要插入，而是返回失败的标记false
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

/* 你的代码将被嵌在这里 */
bool Insert(List L, ElementType X) {
    
    if (L->Last + 1 >= MAXSIZE) 
        return false;

    int i = 0;
    while (X < L->Data[i])
        i++;

    if (L->Data[i] == X)
        return false;

    for (int k = L->Last; k >= i; k--)
        L->Data[k + 1] = L->Data[k];

    L->Data[i] = X;
    L->Last++;
    return true;
}
