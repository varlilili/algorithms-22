#include<stdio.h>

void swap(int arr[], int i, int j)
{
    int t;
    t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int main(void)
{
    // 输入
    int arr[] = {-1, 6, 4, 2, 3, -5, 99999, 1, 5, 100, -3};
    // 算法
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        for(int j = i; j - 1 >= 0 && arr[j] < arr[j-1]; j--)
            swap(arr, j, j-1);
    // 输出
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        printf("%d\t", arr[i]);
}