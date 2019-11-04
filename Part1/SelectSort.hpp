#include <iostream>

using namespace std;

/*
A : 待排序数组指针
L : 数组左边界
R : 数组右边界， 前闭后开[L,R)
*/
void SelectSort(int *A, int L, int R)
{
   if(A == NULL)
       return ;
   for(int i=L;i<R;i++)
   {
       for(int j=L+1;j<R;j++) //每轮内层循环结束，保证i位置上是最小值
       {
           if(A[j]<A[i])
               swap(A[j], A[i]);
       }
   }
}

