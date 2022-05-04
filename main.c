#include <stdio.h>

#include "linkedlist.h"

int main()
{
  linkedlist * list = linkedlist_new();

  linkedlist_add(list, "foo");
  linkedlist_add(list, "bar");
  linkedlist_add(list, "boom");

  return 0;
}

