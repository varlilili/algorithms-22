#include<stdio.h>
#define null 0

typedef struct node{
    int data;
    struct node *next;
} linkedlist;

linkedlist* get(struct node *head, int i)
{
    int j = 0;
    linkedlist *p;
    p = head;
    while(j < i && p->next != null)
    {
        p = p->next;
        j++;
    }
    if(j == i)
        return p;
    else
        return null;
}

int main(void)
{
    linkedlist n0, n1, n2, n3, n4, n5;
    
    n0.data = 0;
    n0.next = &n1;
    n1.data = 1;
    n1.next = &n2;
    n2.data = 2;
    n2.next = &n3;
    n3.data = 3;
    n3.next = &n4;
    n4.data = 4;
    n4.next = &n5;
    n5.data = 10;
    n5.next = null;

    printf("%d", get(&n0, 5)->data);
}