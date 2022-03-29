#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

// 在初始化时把头指针head初始化为NULL，表示空链表。
static link head = NULL;

link make_node(data)
{
	link p = malloc(sizeof *p);
	p->data = data;
	p->next = NULL;
	return p;
}

/**
 * @brief 指针p是节点类型的指针，指向某节点，现将该节点的指针域（p->next）指向头指针（head）所指向的节点，
 * 然后改变头指针（head）的指向, 使头指针（head）指向指针p所指向的节点。
 * 
 * @param p 
 */
void insert(link p)
{
	p->next = head;
	head = p;
}

/**
 * @brief 在链表p中查找某个节点，若找到，则返回指向该节点的指针，找不到就返回null
 * 
 * @param p 
 * @param val 
 * @return link 
 */
link search(link p, int val)
{
    // 使用 while 的写法，但不简洁，仅供参考
    // p = head;
    // while(p)
    // {
    //     if(p->data == val)
    //         return p;
    //     p = p->next;
    // }
    for(p = head; p; p = p->next)
        if(p->data == val)
            return p;
    return NULL;
}

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
    // 调用make_node创建几个节点，分别调用insert插入到链表中。
    link p = make_node(10);
    insert(p);
    p = make_node(15);
    insert(p);
    p = make_node(20);
    insert(p);
    p = make_node(25);
    insert(p);
    p = make_node(30);
    insert(p);
    p = make_node(35);
    insert(p);
    p = make_node(40);
    insert(p);

    print(p);

    printf("%d", search(p, 10)->data);

    return 0;
}