#include <stdio.h>

#include "linkedlist.h"

void foo(void *e)
{
    printf("%s\n", (char *)e);
}

int main()
{
    while(1)
        linkedlist_destroy(linkedlist_add(linkedlist_new(), NULL));

  return 0;
}

