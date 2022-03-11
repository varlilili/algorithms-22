#include<stdio.h>
int main(void)
{
    int arr_1[6] = {6, 4, 2, 3, 1, 5};
    int arr_2[6] = {0};
    int min;
    // 在 arr_1[0,5]中，遍历查找最小的元素，将其放在arr_2[0]上
    // 然后在arr_1[1,5]中，遍历查找最小的元素，将其放在arr_2[1]上
    // 外层循环 i, arr_2, i->[0,5]
    // 内层循环 j, arr_1
    for(int i = 0; i <= 5; i++)
    {
        // 在数组 arr_1 中遍历查找最小的元素，将该元素的值存放到变量 min 当中
        min = arr_1[i];
        for(int j = i; j <= 5; j++)
        {
            if(arr_1[j] < min)
                min = arr_1[j];
        }
        arr_2[i] = min;
    }
    for(int i = 0; i < 6; i++)
    {
        printf("%d\n", arr_2[i]);
    }
}