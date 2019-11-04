#include <iostream>

using namespace std;

/*
A : 待排序数组指针
L : 数组左边界
R : 数组右边界， 前闭后开[L,R)
*/

void merge(int *A, int l, int m, int r)
{
    int *help = new int[r-l+1]; //开辟归并时用到的辅助空间
    int p1 = l; //左边序列起点
    int p2 = m+1; //右边序列起点
    int i=0; //辅助数组起点
    while(p1<m && p2<r){
        // 依次将两个数组的值有序的赋值到辅助空间.相等时取左边可以保证排序的稳定性
        help[i++] = A[p1]<=A[p2] ? A[p1++]:A[p2++];
    }
    // 赋值剩下的数值
    while(p1<m){
        help[i++] = A[p1++];
    }
    while(p2<r){
        help[i++] = A[p2++];
    }
    // 辅助空间拷贝回原空间
    for(int i=0;i<r-l+1;i++)
    {
        A[l+i] = help[i];
    }
    
    //释放空间
    delete [] help;
}

void MergeSort_(int *A, int L, int R)
{
    if(L==R)
        return ; //当只剩一个元素的时候递归返回
    int m = L + ((R-L)>>1); //计算中间位置
    MergeSort_(A, L, m); //对左边部分递归划分
    MergeSort_(A, m+1, R); //对右边递归划分
    merge(A, L, m, R); //合并两个有序的部分
}

void MergeSort(int *A, int L, int R)
{
    if(A == nullptr)
        return ;
    MergeSort_(A, L, R);
}