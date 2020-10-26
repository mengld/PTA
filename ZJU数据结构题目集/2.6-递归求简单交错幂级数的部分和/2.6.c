/*
本题要求实现一个函数，计算下列简单交错幂级数的部分和：

f(x,n)=x−x^2+x^3−x^4+⋯+(−1)^n−1 x^n

函数接口定义：
double fn( double x, int n );
其中题目保证传入的n是正整数，并且输入输出都在双精度范围内。函数fn应返回上述级数的部分和。建议尝试用递归实现
*/

#include <stdio.h>

double fn(double x, int n);

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x, n));

    return 0;
}

/* 你的代码将被嵌在这里 */
double fn(double x, int n) {
    if (n == 1)
        return x;

    if (n % 2 == 0)
        return fn(x, n - 1) - pow(x, n);
    return fn(x, n - 1) + pow(x, n);
}
