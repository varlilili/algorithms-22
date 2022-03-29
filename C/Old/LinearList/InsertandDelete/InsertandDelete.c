/**
 *【问题描述】
 * 定义一个数组，长度为20，其中的数据为1，2，…，10。
 * 请编写线性表的插入算法，分别在第3位插入11，在第5位插入12，并删除第2位数据元素。
 * 
 * @version 2.0
 * @date 2022-03-13 17:00
*/

#include<stdio.h>
// CAPACITY 控制数组数据元素的容量
#define CAPACITY 20

/**
 * @brief 线性表结构体
 * 
 */
typedef struct LinearList {
    int array[CAPACITY];
    // size 记录数组实际存在元素的数量 (size = index + 1)
    int size;
} L;

// sn = serial number 待插入位置的自然排序编号（serial number 序列号、编号的意思，起始数字从1开始，1，2，3……）

/**
 * @brief 插入算法
 * 
 * @param L 需要插入元素的线性表结构体
 * @param sn 待插入元素的位置（自然排序编号，非索引排序编号）
 * @param e 待插入元素
 */
void insert(struct LinearList *L, int sn, int e)
{
    for(int i = L->size; i >= sn; i--)
        L->array[i] = L->array[i-1];
    L->array[sn-1] = e;
    L->size++;
}

/**
 * @brief 删除算法
 * 
 * @param L 需要删除元素的线性表结构体
 * @param sn 待删除元素的位置（自然排序编号，非索引排序编号）
 */
void delete (struct LinearList *L, int sn)
{
    for(int j = sn; j <= L->size-1; j++)
        L->array[j-1] = L->array[j];
    L->size--;
}

/**
 * @brief 测试用例
 * 
 * @return int 
 */
int main(void)
{
    // 声明一个线性表 l
    L l;

    // 输入
    l.size = 10;
    for(int i = 0; i < l.size; i++)
    {
        l.array[i] = i+1;
    }

    // 进行插入和删除操作
    insert(&l, 3, 11);
    insert(&l, 5, 12);
    delete(&l, 2);

    //输出
    printf("array, size = %d \n [", l.size);
    for (int i = 0; i < l.size; i++)
    {
        printf("%d", l.array[i]);
        if(i != l.size - 1)
            printf(", ");
    }
    printf("]");

    return 0;
}