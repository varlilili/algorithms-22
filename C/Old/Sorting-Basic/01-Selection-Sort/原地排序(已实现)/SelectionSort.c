#include<stdio.h>

void swap(int arr[], int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int main(void)
{
    // 输入
    int arr[7] = {6, 4, 2, 3, 1, 5, -999};

    // 算法
    // arr[0…i) 是有序的，arr[i…n) 是无序的
    for(int i = 0; i < 7; i++)
    {
        // 选择 arr[i…n) 中最小值的索引
        int minIndex = i;
        for(int j = i; j < 7; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        // 直接交换 arr[i] 和 arr[minIndex]
        // int t = arr[i];
        // arr[i] = arr[minIndex];
        // arr[minIndex] = t;

        // 利用 swap() 交换 arr[i] 和 arr[minIndex]
        swap(arr, i, minIndex);
    }

    // 输出
    for(int i = 0; i < 7; i++)
    {
        printf("%d\t", arr[i]);
    }
}