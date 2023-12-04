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

// /* Search the first cel of the list & 
//  *  return the associated sprite 
//  * */
// int list_head_sprite(list_ptr l)
// {
//   if(l == NULL) return 0;

//   list_reverse(&l);  
//   list_ptr tmp = l;
//   list_reverse(&l);



//   while (tmp->next != 0)
//   {
//     tmp = tmp->next;
//   }

  
//   return tmp->data;
// }

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
  list_ptr tmp = *l;
  if(tmp == NULL) return;

  while (tmp->next != NULL)
  {
    if(tmp == elt)
    {
      tmp = tmp->next;
      return;
    }
  }
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
    
    printf("avant : \n");
    printlist(l);

    printf("apres head: \n");
    printlist(l);
    list_reverse(&l);
    printf("apres reverse: \n");
    printlist(l);
    list_reverse(&l);
    printf("apres reverse 2 : \n");
    printlist(l);

    printf("avant pop : \n");
    printlist(l);
    printf("dernier element et suppression : %d\n", list_pop_sprite(&l));

    printf("apres pop et avant remove : \n");
    printlist(l);
    list_remove(l2, &l);

    while (l != NULL)
    {
        printf("%d\n", l->data);
        l = l->next;
    }
    

}