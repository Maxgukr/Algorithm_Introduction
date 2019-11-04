#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
A : 待排序数组指针
L : 数组左边界
R : 数组右边界， 前闭后开[L,R) 
*/

int partition(int *A, int L, int R)
{
    srand((unsigned)time(NULL)); //设置随机数种子
    swap(A[(random()%(R-L))+L], A[R-1]); //随机选一个数和最后一个数交换作为主元
    int i = L-1;
    for(int j=L;j<R;j++)
    {
        if(A[j]<=A[R-1]) //小于等于主元的元素
            swap(A[++i], A[j]); // [0,i]范围内的元素都是小于等于主元的，和i+1的元素交换
    }
    swap(A[i+1], A[R-1]); //把中元换到中间来，使主元左边的数都小于等于他，右边的数都大于他
    return i+1;
}

void QuickSort_(int *A, int L, int R)
{
    if(L<R){
        int q = partition(A, L, R); 
        QuickSort_(A, L, q);
        QuickSort_(A, q+1, R);
    }
}

void QuickSort(int *A, int L, int R)
{
    if(A==nullptr)
        return ;
    QuickSort_(A, L, R);
}