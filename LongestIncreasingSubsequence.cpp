#include <bits/stdc++.h>
//#include<iostream>
#include <vector> 

using namespace std;

// void printArray(int arr[], int size)
// {

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

int getlis(int arr[], int size)
{
    int lis[size];

    lis[0] = 1;
    for (int i = 1; i < size; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis, lis + size);
}

int cielIndex(std::vector<int> &arr, int startIndex, int endIndex, int element)
{

    while (endIndex - startIndex > 1)
    {
        int mid = startIndex + (endIndex - startIndex) / 2;
        if (arr[mid] >= element)
        {
            endIndex = mid;
        }
        else
        {
            startIndex = mid;
        }
    }
    return endIndex;
}

int longestIncreasingSubsequence(std::vector<int> &v)
{
    if (v.size() == 0)
    {
        return 0;
    }

    if (v.size() == 1)
    {
        return 1;
    }

    std::vector<int> tail(v.size(), 0);

    tail[0] = v[0];
    int length = 1;
    for (int i = 1; i < v.size(); i++)
    {

        if (tail[0] > v[i])
        {
            tail[0] = v[i];
        }
        else if (tail[length - 1] < v[i])
        {      
            tail[length++] = v[i];
        }
        else
        {
            
            tail[cielIndex(tail,-1,length-1,v[i])]=v[i];
        }
    }

    for(int i=0;i<length;i++){
        printf("%d ",tail[i]);
    }
    printf("\n");

    return length;
}

int main()
{

    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int size = sizeof(arr) / sizeof(int);
    printf("size of Lis is %d \n", getlis(arr, size));

    std::vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};
    printf("Size of the array is ::%lu \n", v.size());
    printf("size of Lis is %d", longestIncreasingSubsequence(v));

    return 0;
}