/**
 *【问题描述】
 * 定义一个数组，长度为20，其中的数据为1，2，…，10。
 * 请编写线性表的插入算法，分别在第3位插入11，在第5位插入12，并删除第2位数据元素。
 * 
 * @version 1.0
 * @date 2022-03-10 23:23
*/

#include<stdio.h>
#define MAXMUM 20 // 控制线性表数组长度

// 线性表结构体
    // arr[MAXMUM] 用来存放数组元素
    // last 最后一个元素的自然序列编号（是第几个元素就编号为几）
typedef struct LinearList {
    int arr[MAXMUM];
    int last;
} L;

// 插入算法
    // sn = serial number 待插入位置的自然序列编号（serial number 序列号、编号的意思，起始数字为自然数字，即从1开始，1，2，3……）
    // v = value 待插入的数据元素的值
void insert(struct LinearList *L, int sn, int v)
{
    // 自然序列范围 (用集合表示)：[sn, last]，如[3, 11]
    // 对应数组下标范围（用集合表示）：[sn-1, last-1]，如[2, 10]
    // 循环的自然序列范围：[sn+1, last+1] -> 对应数组下标范围：[sn, last]
    // i = index，表示数组下标
    for(int i = L->last; i >= sn; i--)
        L->arr[i] = L->arr[i-1];
    // sn = 3，表示数组中的第三个元素，该元素对应的下标则是 sn-1 = 2，
    // 在第三个元素前插入一个元素，则被插入的元素变成第三个元素，存放该元素的数组下标就是 sn-1 = 2；
    L->arr[sn-1] = v;
    // 插入后数组长度加一
    L->last++;
}

// 删除算法
void delete (struct LinearList *L, int x)
{
    // x 表示待删除元素的自然序列编号
    // 循环的自然序列范围：[x, last-1] -> 对应的数组下标范围：[x-1, last-2]
    for(int j = x-1; j <= L->last-2; j++)
        L->arr[j] = L->arr[j+1];
    // 删除后数组长度减一
    L->last--;
}

// 入口
int main(void)
{
    // 声明一个线性表 l
    L l;

    // 向线性表输入数据
    l.last = 10;
    for(int i = 0; i < 10; i++)
    {
        l.arr[i] = i+1;
    }

    // 进行插入和删除操作
    insert(&l, 3, 11);
    insert(&l, 5, 12);
    delete(&l, 2);

    //输出结果
    for (int i = 0; i < l.last; i++)
    {
        printf("%d\t", l.arr[i]);
    }
    return 0;
}