/*
给定一个顺序存储的线性表，请设计一个函数删除所有值大于min而且小于max的元素。删除后表中剩余元素保持顺序存储，并且相对位置不能改变。

函数接口定义：
List Delete( List L, ElementType minD, ElementType maxD );
其中List结构定义如下：

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较；minD和maxD分别为待删除元素的值域的下、上界。
函数Delete应将Data[]中所有值大于minD而且小于maxD的元素删除，同时保证表中剩余元素保持顺序存储，并且相对位置不变，最后返回删除后的表

输入样例：
10
4 -8 2 12 1 5 9 3 3 10
0 4
输出样例：
4 -8 12 5 9 10 

*/

#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L); /* 裁判实现，细节不表 */
List Delete(List L, ElementType minD, ElementType maxD);

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete(L, minD, maxD);
    PrintList(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
/*
del 0~4
4 -8 2 12 1 5 9 3 3 10
0  0 1 0  1 0 0 1 1 0
找到第一个标记1的位置，将此后的标记0的元素依次拷贝，注意Last的更新
*/
List Delete(List L, ElementType minD, ElementType maxD) {
    ElementType flags[MAXSIZE];
    int cnt = 0;
    for (int i = 0; i <= L->Last; i++) {
        if (L->Data[i] > minD && L->Data[i] < maxD) {
            flags[i] = 1;
            cnt++;
        }
        else
            flags[i] = 0;
    }
    
    int k = 0;
    while (!flags[k])
        k++;
    for (int i = k + 1; i <= L->Last; i++) {
        if (!flags[i])
            L->Data[k++] = L->Data[i];
    }
    L->Last -= cnt;

    return L;
}
