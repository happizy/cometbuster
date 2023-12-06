#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  int data;
  struct list_node * next;
} s_list_node_t, *list_ptr;


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

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
int list_head_sprite(list_ptr l)
{
  if(l == NULL) return 0;

  list_reverse(&l);  
  list_ptr tmp = l;

  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }

  int data = tmp->data;
  list_reverse(&l);

  return data;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
int list_pop_sprite(list_ptr * l)
{
  list_ptr tmp = *l;
  if(tmp == NULL) return 0;
  if(tmp->next == NULL) return tmp->data;
  while (tmp->next->next != NULL)
  {
    tmp = tmp->next;
  }
  
  int sprite = tmp->next->data;
  tmp->next = NULL;
  return sprite;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
  if (*l == NULL) {
    return;
  }

  if (*l == elt) {
    *l = elt->next;
    free(elt);
    return;
  }

  list_ptr prev = *l;
  list_ptr current = (*l)->next;

  while (current != NULL && current != elt) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) {
    return;
  }

  prev->next = current->next;
  free(current);
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  if (list == NULL) {
    return NULL;
  }

  list_ptr new_list = (list_ptr)malloc(sizeof(s_list_node_t));
  new_list->data = list->data;
  new_list->next = NULL;

  list_ptr current = list->next;
  list_ptr new_current = new_list;

  while (current != NULL) {
    list_ptr new_node = (list_ptr)malloc(sizeof(s_list_node_t));
    new_node->data = current->data;
    new_node->next = NULL;

    new_current->next = new_node;
    new_current = new_node;

    current = current->next;
  }

  return new_list;
}

void printlist(list_ptr l)
{
  list_ptr tmp = l;
  while (tmp != NULL)
  {
    printf("%d\n", tmp->data);
    tmp = tmp->next;
  }
  
}

int main(){
    list_ptr l = (list_ptr) malloc(sizeof(s_list_node_t));
    list_ptr l2 = (list_ptr) malloc(sizeof(s_list_node_t));
    list_ptr l3 = (list_ptr) malloc(sizeof(s_list_node_t));
    list_ptr l4 = (list_ptr) malloc(sizeof(s_list_node_t));
    l->data = 1;
    l2->data = 2;
    l3->data = 3;
    l4->data = 4;
    l->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = NULL;
    
    // printf("avant head : \n");
    // printlist(l);

    // printf("haut de liste : %d\n",list_head_sprite(l));

    // printf("après head, avant pop :\n");
    // printlist(l);
    
    // printf("pop fin de liste : %d\n", list_pop_sprite(&l));
    // printf("pop fin de liste : %d\n", list_pop_sprite(&l));

    // printf("après 2 pops :\n");
    // printlist(l);

    // list_reverse(&l);

    // printf("après reverse :\n");
    // printlist(l);

    // list_reverse(&l);

    // printf("après deuxième reverse : \n");
    // printlist(l);

    // printf("avant remove :\n");
    // printlist(l);

    // list_remove(l2,&l);

    // printf("après remove de 2 :\n");
    // printlist(l);

    printf("list original\n");
    printlist(l);

    list_ptr l6 = list_clone(l);

    printf("list clone\n");
    printlist(l6);
    

}