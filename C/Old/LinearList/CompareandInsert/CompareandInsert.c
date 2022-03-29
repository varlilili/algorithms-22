#include<stdio.h>
#define MAXMUM 40

// 线性表结构体
typedef struct LinearList {
    int arr[MAXMUM];
    int last;
} L;

// 比较插入算法
void insert(struct LinearList *L, int sn, int n)
{
    for(int i = L->last; i >= sn; i--)
        L->arr[i] = L->arr[i-1];
    L->arr[sn-1] = n;
    L->last++;
}

int main(void)
{
    // 初始化顺序表 va 并打印
    L va;
    va.last = 20;
    for(int i = 0; i < va.last; i++)
    {
        va.arr[i] = 3*i+2;
    }
    for(int i = 0; i < va.last; i++)
    {
        printf("%d\t", va.arr[i]);
    }

    // 比较并查找插入位置的索引，然后插入
    int n, index;
    printf("\n请输入要插入的元素：");
    scanf("%d", &n);
    for(int i = 0; i < va.last; i++)
    {
        if(n > va.arr[i])
            index = i;
    }
    insert(&va, index+2, n);

    // 输出
    for(int i = 0; i < va.last; i++)
    {
        printf("%d\t", va.arr[i]);
    }
}