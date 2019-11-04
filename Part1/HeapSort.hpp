#include <iostream>
#include <vector>
using namespace std;

/*
A : 待排序数组指针
L : 数组左边界
R : 数组右边界， 前闭后开[L,R)
*/

/*向堆中添加一个元素, 元素放在末尾*/
void _push_heap(vector<int>& A, int pos)
{
    //从pos位置开始上浮
    int parent = (pos-1)/2;
    while(A[pos]>A[parent] && pos>0){
        swap(A[parent], A[pos]); //比父节点大，和父节点交换
        pos = parent; //更新新元素位置
        parent = (pos-1)/2; //更新父节点位置
    }
}

void push_heap(vector<int>& A, int x)
{
    // 插入新元素x
    A.push_back(x);
    _push_heap(A, (int)(A.size()-1));
}

void heapify(vector<int>& A, int i, int sz)
{
    //从位置i开始向下比较，维护堆的性质。
    int left = 2*i+1;//左孩子
    while(left<sz)
    {
        int largest  = left+1<=sz && A[left] > A[left+1] ? left+1 : left; //孩子中较大的那个
        largest = A[largest] > A[i] ? largest : i; //孩子中大的那个和父节点比较
        if(largest == i)
            break; //当父节点比两个孩子都大时，跳出
        swap(A[largest], A[i]); //交换孩子和父节点
        i = largest; //更新父节点位置
        left = 2*i + 1; //更新左孩子
    }
}

int pop_heap(vector<int>& A, int heapSize)
{
    swap(A[0], A[heapSize]); //第一个元素和最后一个元素交换
    int pop_value = A[heapSize];
    heapSize--;
    heapify(A, 0, heapSize); //调整堆性质
    return pop_value;
}

void HeapSort(vector<int>& A, int L, int R)
{
    //vector<int> heap;
    int heapSize = A.size();
    for(int i=A.size()/2;i>0;i--)
        heapify(A, i, (int)A.size()); //建堆
    for(int i=A.size()-1;i>=1;i--)
    {
        swap(A[i], A[0]);
        heapSize--;
        heapify(A, 0, heapSize);
    }
}