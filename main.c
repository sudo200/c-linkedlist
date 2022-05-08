#include <stdio.h>
#include <string.h>

#include "linkedlist.h"

void foo(void *e)
{
    printf("%s\n", (char *)e);
}

int main()
{
  while(1)
  {
    linkedlist * list = linkedlist_new();

    char * str0 = (char *)malloc(sizeof(char) * 4),* str1 = (char *)malloc(sizeof(char) * 4),* str2 = (char *)malloc(sizeof(char) * 5);

    strcpy(str0, "foo");
    strcpy(str1, "bar");
    strcpy(str2, "boom");

    linkedlist_add(list, str0);
    linkedlist_add(list, str1);
    linkedlist_add(list, str2);

    linkedlist_foreach(list, free);
    linkedlist_destroy(list);
  }

  return 0;
}

