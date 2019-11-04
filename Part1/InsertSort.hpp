#include <iostream>

using namespace std;

/*
A : 待排序数组指针
L : 数组左边界
R : 数组右边界， 前闭后开[L,R)
*/
void InsertSort(int *A, int L, int R)
{
    if(A==NULL)
        return ;
    for(int i=L; i<R; i++)
    {
        /*内存循环每次将i位置的元素和前一个元素比较，小于就交换.[0,i-1]位置上始终是有序的*/
        for(int j=i-1; j>=0 && A[j+1]<A[j];j--)
            swap(A[j], A[j+1]);
    }
}