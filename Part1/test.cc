#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>
#include "BubbleSort.hpp"
#include "CountSort.hpp"
#include "HeapSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "InsertSort.hpp"
#include "SelectSort.hpp"

using namespace std;

int * generateRandomArrays(int maxSize, int maxValue)
{
    srand((unsigned)time(NULL));
    int len = random()%(maxSize+1); //长度随机
    int *arr = new int[len];
    //int len = sizeof(arr)/sizeof(int);
    for(int i=0;i<len;i++)
    {
        arr[i] = random()%(maxValue+1);//值随机
    }
    return arr;
}

int * copyArray(int *arr, int len)
{
    if(arr==nullptr)
        return nullptr;
    int *res = new int[len];
    for(int i=0;i<len;i++)
    {
        res[i] = arr[i];
    }
    return res;
}

bool isEqual(int arr1 [],  int arr2 [])
{
    
    if(arr1==nullptr && arr2!=nullptr || arr1!=nullptr && arr2==nullptr)
        return false;
    if(arr1 == nullptr && arr2 == nullptr)
        return true;
    int len1 = sizeof(arr1)/sizeof(int);
    int len2 = sizeof(arr2)/sizeof(int);
    if(len1 != len2)
        return false;

    for(int i=0;i<len1;i++)
    {
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}

int main()
{
    int testTime = 100;
    int maxValue = 100;
    int maxSize = 100;

    bool succeed = false;

    for(int i=0;i<testTime;i++)
    {
        int *arr1 = generateRandomArrays(maxSize,maxValue);
        int len = sizeof(arr1)/sizeof(int);
        int *arr2 = copyArray(arr1, len);
        //vector<int> arr2(arr1, arr1+len);
        // 一个使用自己的方法
        MergeSort(arr1, 0, len-1);
        // 一个用简单的方法
        SelectSort(arr2, 0, len-1);
        if(!isEqual(arr1, arr2))
        {
            cout<<"error"<<endl;
            break;
        }
    }
    cout<<"nice! passed all samples!"<<endl;

}