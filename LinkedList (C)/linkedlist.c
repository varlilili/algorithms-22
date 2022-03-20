#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

// 在初始化时把头指针head初始化为NULL，表示空链表。
static link head = NULL;

/**
 * @brief 创建节点
 * 
 * 声明一个节点类型指针，p。然后给其分配空间，空间大小为指针p所指向节点所占的字节大小。
 * 令指针p指向的节点的数据域的值为传入的data，指针域的指向为NULL，然后返回该指针p。
 * 
 * @param data 
 * @return link 
 */
link newNode(int data)
{
	link p = malloc(sizeof *p);
	p->data = data;
	p->next = NULL;
	return p;
}

/**
 * @brief 插入节点
 * 
 * 指针p是节点类型的指针，指向待插入的某节点。插入时，使指针p指向的待插入节点的指针域指向头指针（head）所指向的节点，
 * 然后使头指针（head）指向指针p所指向的待插入节点。
 * 
 * 在这里，可以将指针p理解为一个临时指针。
 * 
 * 图解见 ./linkedlist.insert.png
 * 
 * @param p 
 */
void insert(link p)
{
	p->next = head;
	head = p;
}

/**
 * @brief 查询节点
 * 
 * 指针p是节点类型的指针，指向头指针所指向的节点。
 * 遍历该链表中的所有节点，若某节点的数据域和待查询值val(value的缩写)一致，
 * 则返回指向该节点的指针p，否则则返回NULL。
 * 
 * @param p 
 * @param val 
 * @return link 
 */
link search(link p, int val)
{
    // 使用while的写法，没有使用for简洁，列出仅供参考。
    // p = head;
    // while(p)
    // {
    //     if(p->data == val)
    //         return p;
    //     p = p->next;
    // }

    // for循环中的判断条件是 p != NULL; 可以简写为 p;
    for(p = head; p; p = p->next)
        if(p->data == val)
            return p;
    return NULL;
}

/**
 * @brief 删除节点（用指向节点地址的指针）
 * 
 * @param p 
 */
void delete(link p)
{
    if(p == head)
    {
        head = p->next;
    }
    for(link prev = head; prev; prev = prev->next)
    {
        if(prev->next == p)
        {
            prev->next = p->next;
            p->next = NULL;
        }          
    }
}

/**
 * @brief 删除节点（用指向指针域指针地址的指针）
 * 
 * 定义一个指向指针的指针pnext，在for循环中pnext遍历的是指向链表中各节点的指针域，
 * 这样就把head指针和各节点的next指针统一起来了，可以在一个循环中处理。
 * 
 * *pnext 是指向节点的指针（存放节点的内存地址），而pnext是指向节点的指针的指针（存放指针的内存地址）
 * 
 * @param p 
 */
void deleteByPnext(link p)
{
    
    for(link *pnext = &head; *pnext; pnext = &((*pnext)->next))
        if(*pnext == p)
            *pnext = p->next;
    
}

void push(link p)
{
    insert(p);
}

void pop()
{
    delete(head);
}

/**
 * @brief 打印链表
 * 
 * @param p 
 */
void print(link p)
{
    printf("linked list:\n");
    for(p = head; p; p = p->next)
    {
        if(p->next != NULL)
            printf("%d -> ", p->data);
        else
            printf("%d\n", p->data);
    }
}

/**
 * @brief 测试用例
 * 
 * @return int 
 */
int main(void)
{
    link p;
    for(int i = 1; i <= 10; i++)
    {
        insert(newNode(i*5));
        print(p);
    }

    pop();
    print(p);

    return 0;
}