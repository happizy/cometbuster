#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
  list_ptr list;
  list = NULL;
  return list;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
  list_ptr new = malloc(sizeof(s_list_node_t));
  new -> data = sprite;
  new -> next = list;
  return new;
}

/* Return the length of a list
 * */
int list_length(list_ptr l)
{
  int i= 0;
  if(l == NULL) return 0;
  do {
    i += 1;
    l = l -> next
  }while (l != NULL);  
  return i;
}

/* Reverse the order of a list
 * */
void list_reverse(list_ptr * l)
{
    list_ptr prev = NULL;
    list_ptr current = *l;
    list_ptr next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *l = prev;
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  return NULL;
}

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  return true;
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
  // if(l == NULL) return NULL;

  // list_ptr tmp = l;
  // list_reverse(&tmp);

  // while (tmp->next != NULL)
  // {
  //   tmp = tmp->next;
  // }
  
  // return tmp->data;
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  return NULL;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  // list_ptr tmp = *l;
  // if(tmp == NULL) return NULL;
  // if(tmp->next == NULL) return tmp->data;
  // while (tmp->next->next != NULL)
  // {
  //   tmp = tmp->next;
  // }
  
  // sprite_t sprite = tmp->next->data;
  // tmp->next = NULL;
  // return sprite;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
  // list_ptr tmp = *l;
  // if(tmp == NULL) return;

  // while (tmp->next != NULL)
  // {
  //   if(tmp == elt)
  //   {
  //     tmp = tmp->next;
  //     return;
  //   }
  // }
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
}
