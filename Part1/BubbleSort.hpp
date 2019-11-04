#include <iostream>

using namespace std;

/*
A : 待排序数组指针
L : 数组左边界
R : 数组右边界， 前闭后开[L,R)
*/
void BubbleSort(int *A, int L, int R)
{
    if(A==nullptr)
        return ;
    for(int i=R-1;i>0;i--)
    {
        /*内存循环每次把[0，i]范围内最大的交换到i位置*/
        for(int j=0;j<i;j++)
        {
            if(A[j]>A[j+1])
                swap(A[j], A[j+1]);
        }
    }
}