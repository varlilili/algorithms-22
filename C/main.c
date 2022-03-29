#include <stdio.h>
#include "SingleLinkedList.h"

int main() {
    ListPtr l = create();
    if (l == NULL)
    {
        return -1;
    }

    print(l, "after init: ");

    add(l, NULL, 1);
    add(l, NULL, 2);
    add(l, NULL, 3);
    print(l, "after add 1, 2, 3 to head: ");

    add(l, NULL, 4);
    add(l, NULL, 5);
    add(l, NULL, 6);
    print(l, "after add 4, 5, 6 to head: ");

    add(l, find(l, 5), 10);
    print(l, "after add 10 after 5: ");

    delete(l, 4);
    print(l, "after delete 4: ");

}
