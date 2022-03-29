#include<stdio.h>
// 线性查找算法：若在待查数组中查找到目标元素，则返回目标元素所对应的数组下标，否则返回-1
int search(int arr[], int length, int target)
{
    for(int i = 0; i < length; i++)
        if(arr[i] == target)
            return i;

    return -1;
}

int main(void)
{
    // 输入：待查数组 & 目标元素
    int data[] = {24, 18, 12, 9, 16, 66, 32, 4, 88};
    int target;
    int length = sizeof(data) / sizeof(data[0]);
    scanf("%d", &target);
    // 输出
    int res = search(data, length, target);
    if(res != -1)
        printf("data[%d] = %d\n", res, target);
    else
        printf("目标元素不存在。\n");
    return 0;
}

// 问题 1: 在一个循环遍历中，如何确定一个目标元素不存在并返回值 -> 使用函数
// 问题 2: 如何在函数中判断一个数组的长度？-> sizeof(&arr)/sizeof(arr[0])，但在子函数中不能这样用