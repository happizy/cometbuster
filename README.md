=========================
# Comet buster
=========================

1. Compiling & running
2. Sprites conventions
3. Playing
4. LinkedList Integration
5. Known Bugs
6. Tools Used
7. Future Development

=========================
## 1. Compiling & running
=========================

Compiling:
$> make

Running:
$> ./cometbuster

Cleaning:
$> make clean


=========================
## 2. Sprites conventions
=========================

Few sprites are provided (in sprites directory). Feel free to use your own
ones.

sprites sizes: 
  - spaceship 32x32
  - bullets: 4x4
  - comets: 64x64 (L) / 32x32 (M) / 16x16 (S)
  - screen: 640x480
  - nyancats: 32xYY (depends on the nyancat type)

spaceship rotation angle: 10° (for the moment)
 => 36 spaceships
 => 1152x32

Naming convention of sprites filenames:
Filename: <something understandable>-N_HxW.bmp
with N the number of frames in the sprite
     H the height of the sprite (usually 32 or 64)
     W the width of a frame

ex:
nyancat-technyancolor-left-12_32x51.bmp means that this sprite is:
  - the LSD nyancat flying to the left
  - composed of 12 frames
  - 32 px high
  - 51 px wide

=========================
## 3. Playing
=========================

Game control:
  - q or esc: quit the game
1st player:
  - up arrow: move forward
  - down arrow: move backward
  - left arrow: rotate left
  - right arrow: rotate right
  - space: fire

(TODO 2nd player, for instance:
  - w: move forward
  - s: move backward
  - a: rotate left
  - d: rotate right
  - left shift: fire)

Avoid, shoot, and explode comets by smart use of hyperspace and guns. Large
comets divide into medium comets, which divide into small ones. Be careful, ETs
protect the space, and they don't like intruders...

Hyperspace: up and down edges are connected, so do left and right ones. Fly to
the left, you will appear on the right. Asteroids and enemies also know the
secret of hyperspace...

=========================
## 4. LinkedList Integration
=========================

We have added LinkedList functionality to manage sprites in the game. Here are the new functions:

```c
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
    l = l -> next;
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

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  return l == NULL;
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
  if(l == NULL) return NULL;

  list_reverse(&l);  
  list_ptr tmp = l;

  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }

  sprite_t data = tmp->data;
  list_reverse(&l);

  return data;
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  if(l == NULL) return NULL;
  return l->next;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  list_ptr tmp = *l;
  if(tmp == NULL) return 0;
  if(tmp->next == NULL) return tmp->data;
  while (tmp->next->next != NULL)
  {
    tmp = tmp->next;
  }
  
  sprite_t sprite = tmp->next->data;
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
  current->next = NULL;
  sprite_free(current->data);
  free(current);
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
  list_ptr tmp;
  while (l != NULL)
  {
    tmp = l;
    l = l->next;
    sprite_free(tmp->data);
    free(tmp);
  }
}
```

=========================
## 5. Known Bugs
=========================
We encountered some bugs that are not yet fixed:

- Crashing the ship in an asteroid results in a segmentation fault. This is due to the list_remove() function trying to access protected memory in main.c.
- Using keys not planned for the gameplay will result in a segmentation fault. Should add a default case for unrecognized keys.

=========================
## 6. Tools Used
=========================
- GitHub (https://github.com/happizy/cometbuster) used for versioning and teamwork.
- Copilot was used in some cases for inspiration.
- Discord and git push notifications were the primary communication methods.

=========================
## 7. Future Development
=========================
We would have liked to add power-ups to the game like intangibleness and speed boosts. The scoring system did not get updated nor the multiplayer game mode.

Enjoy :)

========================================================
```
+      o     +              o   
    +             o     +       +
o          +
    o  +           +        +
+        o     o       +        o
-_-_-_-_-_-_-_,------,      o 
_-_-_-_-_-_-_-|   /\_/\  
-_-_-_-_-_-_-~|__( ^ .^)  +     +  
_-_-_-_-_-_-_-""  ""      
+      o         o   +       o
    +         +
o        o         o      o     +
    o           +
+      +     o        o      +  
```
