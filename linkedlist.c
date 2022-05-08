#include "linkedlist.h"

typedef struct linkednode linkednode;
struct linkednode
{
  void * value;
  linkednode * next;
};

struct linkedlist
{
  linkednode * next;
};


linkedlist * linkedlist_new(void)
{
  linkedlist * list = (linkedlist *)malloc(sizeof(linkedlist));
  list->next = NULL;
  return list;
}

size_t linkedlist_length(linkedlist * list)
{
  if(list == NULL)
    return 0;

  size_t i = 0;
  for(
	linkednode * node = list->next;
	*(int *)node;
	node = node->next, i++
     );
  return i;
}

linkedlist * linkedlist_add(linkedlist * list, void * element)
{
  if(list == NULL)
    return NULL;

  linkednode * node = list->next;

  if(node == NULL)
  {
    node = list->next = (linkednode *)malloc(sizeof(linkednode));
    node->value = element;
    node->next = NULL;
    return list;
  }

  for(
        linkednode * lastnode = node;
        (lastnode = lastnode->next);
        node = lastnode
     );

  node = node->next = (linkednode *)malloc(sizeof(linkednode));
  node->value = element;
  node->next = NULL;

  return list;
}

void * linkedlist_get(linkedlist * list, size_t index)
{
  if(list == NULL)
    return NULL;

  linkednode * node = list->next;
  if(node == NULL)
    return NULL;

  for(size_t i = 0; i < index; ++i)
    if(!(node = node->next))
      return NULL;

  return node->value;
}

void * linkedlist_remove(linkedlist * list, size_t index)
{
  if(list == NULL)
    return NULL;

  linkednode * node = list->next;
  linkednode * lastnode = node;
  node = node->next;
  if(node == NULL)
    return NULL;

  if(index == 0)
  {
      linkednode * node1 = list->next;
      list->next = node1->next;
      void * value = node1->value;
      free(node1);
      return value;
  }

  for(size_t i = 0; i < (index - 1); ++i)
  {
      lastnode = node;
      if(!(node = node->next))
          return NULL;
  }

  void * value = node->value;
  lastnode->next = node->next;

  free(node);
  return value;
}

linkedlist * linkedlist_foreach(linkedlist * list, void (*func)(void *))
{
    if(list == NULL)
        return NULL;

    if(func == NULL)
        return list;

    if(list->next == NULL)
        return list;

    for(linkednode * node = list->next; node; node = node->next)
        func(node->value);
    return list;
}

void linkedlist_destroy(linkedlist * list)
{
    if(list == NULL)
        return;

    if(list->next == NULL)
        goto freelist;

    linkednode *nextnode = list->next, *node = nextnode;
    while((node = nextnode))
    {
        nextnode = node->next;
	free(node);
    }

    freelist:
    free(list);
}
