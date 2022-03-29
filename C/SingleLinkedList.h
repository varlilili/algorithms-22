#ifndef _SINGLELINKEDLIST_H
#define _SINGLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
// 为 int 类型定义一个别名，为 E(Element)
typedef int E;

// 为结构体及其指针分别定义别名
typedef struct node Node;
typedef Node *NodePtr;

// 定义链表节点结构体，包含两个字段：
// 1. data - 存储 E 数据类型的元素
// 2. next - 指向后继节点（下一个节点）的后向指针 🫵
struct node
{
    E data;
    NodePtr next;
};

// 定义一个结构体表示链表，该结构体包含两个指针：
// 1. head - 指向链表头节点
// 2. tail - 指向链表尾节点
typedef struct
{
    NodePtr head;
    NodePtr tail;
} List, *ListPtr;

/**
 * init 函数负责初始化链表，将头、尾指针置为 NULL，表示链表为空
 * @param l 链表指针
 */
void init(ListPtr l)
{
    l->head = l->tail = NULL;
}

/**
 * create 函数动态创建新链表，即为链表结构体分配内存并完成初始化
 * @return 链表指针
 */
ListPtr create()
{
    ListPtr l = malloc(sizeof(List));
    if(l != NULL)
        init(l);

    return l;
}

/**
 * isEmpty 函数判断链表是否为空，只需判断头指针是否为 NULL
 * @param l 链表指针
 * @return
 */
int isEmpty(ListPtr l)
{
    return l->head == NULL;
}

/**
 * head 函数返回链表头指针
 * @param l 链表指针
 * @return 链表头指针
 */
NodePtr head(ListPtr l)
{
    return l->head;
}

/**
 * tail 函数返回链表尾指针
 * @param l 链表指针
 * @return 链表尾指针
 */
NodePtr tail(ListPtr l)
{
    return l->tail;
}

typedef NodePtr Position;
Position find(ListPtr l, E x)
{
    Position p;
    for (p = l->head; p; p = p->next)
        if (p->data == x)
            return p;

    return NULL;
}

int add(ListPtr l, Position p, E x)
{
    // allocate memory for element node
    Position node = malloc(sizeof(Node));
    if (node == NULL)
        return -1;

    // fill element value
    node->data = x;

    if(p == NULL)
    {
        // add to head
        node->next = l->head;
        l->head = node;
    } else {
        node->next = p->next;
        p->next = node;
    }

    if (l->tail == p)
        l->tail = node;

    return 0;
}

void delete(ListPtr l, E x)
{
    // find x and trace previous one at the same time
    Position prev, p;
    for (prev = NULL, p = l->head; p; prev = p, p = p->next)
        if (p->data == x)
            break;

    if (p == NULL)
        return;

    if(p == head)
        l->head = p->next;
    if(p == tail)
        l->tail = prev;
    if(prev != NULL)
        prev->next = p->next;
    free(p);
}

typedef void (*NodeHandler)(NodePtr);
void traverse(ListPtr l, NodeHandler h)
{
    Position p = l->head;
    while (p)
    {
        Position temp = p;
        p = p->next;
        h(temp);
    }
}

void printNode(NodePtr n)
{
    printf("%d ", n->data);
}

void print(ListPtr l, char *hint)
{
    printf("%s[ ", hint);
    traverse(l, printNode);
    printf("]\n");
}

#endif