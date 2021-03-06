/*
本题要求实现带头结点的链式表操作集。

函数接口定义：
List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );
其中List结构定义如下：

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
各个操作函数的定义为：

List MakeEmpty()：创建并返回一个空的线性表；

Position Find( List L, ElementType X )：返回线性表中X的位置。若找不到则返回ERROR；

bool Insert( List L, ElementType X, Position P )：将X插入在位置P指向的结点之前，返回true。如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回false；

bool Delete( List L, Position P )：将位置P的元素删除并返回true。若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回false。

输入样例：
6
12 2 4 87 10 2
4
2 12 87 5
输出样例：
2 is found and deleted.
12 is found and deleted.
87 is found and deleted.
Finding Error: 5 is not in.
5 is inserted as the last element.
Wrong Position for Insertion
Wrong Position for Deletion
10 4 2 5 
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */
// 创建并返回一个空的线性表
List MakeEmpty() {
    List head = (List)malloc(sizeof(struct LNode));
    head->Next = NULL;
    return head;
}

// 返回线性表中X的位置。若找不到则返回ERROR
Position Find(List L, ElementType X) {
    L = L->Next;
    while (L) {
        if (L->Data == X) {
            return L;
        }
        L = L->Next;
    }
    return ERROR;
}

// 将X插入在位置P指向的结点之前，返回true。如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回false
bool Insert(List L, ElementType X, Position P) {

    while (L) {
        if (L->Next == P) {
            List newNode = (List)malloc(sizeof(struct LNode));
            newNode->Data = X;
            newNode->Next = P;
            L->Next = newNode;
            return true;
        }
        L = L->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}

// 将位置P的元素删除并返回true。若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回false
bool Delete(List L, Position P) {
    while (L) {
        if (L->Next == P) {
            List nextNode = P->Next;
            L->Next = nextNode;
            free(P);
            return true;
        }
        L = L->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}
