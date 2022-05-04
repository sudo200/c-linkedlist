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
  list->next = (linkednode *)NULL;
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

