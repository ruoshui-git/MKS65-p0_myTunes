#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "llist.h"

// struct node{
//   char name[MAX_NAME_LEN];
//   char artist[MAX_NAME_LEN];
//   struct node *next;
// };

// Create the following functions:
void print_list(struct node * n){
  printf("Printing playlist at address %p: \n  ", n);
  struct node *current = n;
  int i = 0;
  while (current){
    printf("%s: %s | ", current->artist, current->name);
    current = current->next;
  }
  if (i == 0){
    printf("No songs in playlist.");
  }
  printf("\n");
}
// Should take a pointer to a node struct and print out all of the data in the list

struct node * insert_front(struct node * n, char *newname, char *newartist){
  // Make sure that there's enough memory to insert_front with malloc

  // printf("\nAdding song '%s' by '%s' at %p:\n", newname, newartist, n );

  struct node *current = malloc(sizeof(struct node));
  strcpy(current->name, newname);
  strcpy(current->artist, newartist);
  current->next = n;
  return current;
}
// Should take a pointer to the existing list and the data to be added, create a new node and put it at the beginning of the list.
// The second argument should match whatever data you contain in your nodes.
// Returns a pointer to the beginning of the list.

// insert nodes in order
// alphabetical by Artist then by Song
struct node * insert(struct node * n, char * name, char * artist)
{
    struct node * cur = malloc(sizeof(struct node));
    strcpy(cur->name, name);
    strcpy(cur->artist, artist);
    cur->next = NULL;
    if (!n)
    {
        return cur;
    }

    struct node * trav = n;
    struct node * prev = NULL;

    while (trav)
    {

        int cmp = strncmp(artist, trav->artist, MAX_NAME_LEN);


        if (cmp > 0)
        {
            // node should be inserted after this node
            prev = trav;
            trav = trav->next;
        }
        else if (cmp < 0)
        {
            // node should be inserted right here
            cur->next = trav;
            if (prev)
            {
                prev->next = cur;
            }
            else
            {
                // list head is changed, so point to new head
                n = cur;
            }

            // done inserting
            return n;
        }
        else
        {
            // compare by Song
            cmp = strncmp(name, trav->name, MAX_NAME_LEN);

            if (cmp > 0)
            {
                prev = trav;
                trav = trav->next;
            }
            else if (cmp < 0)
            {
                cur->next = trav;
                if (prev)
                {
                    prev->next = cur;
                }
                else
                {
                    // list head is changed, so point to new head
                    n = cur;
                }

                return n;
            }
            else
            {
                // song and artist names are equal, don't store
                return n;
            }
        }
        // by this point, we should be at the end of the list
        prev->next = cur;
        return n;
    }
}


struct node * free_list(struct node *n)
{
  struct node * current = n;
  while(n){
    printf("Freeing '%s' by '%s'...\n", n->name, n->artist);
    current = n->next;
    free(n);
    n = current;
  }
  return n; //should be NULL
}
// Should take a pointer to a list as a parameter and then go through the entire list freeing each node and return a pointer to the beginning of the list (which should be NULL by then).

struct node * remove_node(struct node *front, char *rname, char *rartist){
    if (front == NULL)
    {
      return front;
    }
    struct node *current = front;
    struct node *nextN = front->next;
    if (current == front && strcmp(current->name, rname) == 0 && strcmp(current->artist, rartist) == 0){
      //if in front
      free(current);
      return nextN;
    }
    while(nextN){
    if (strcmp(nextN->name, rname)==0 && current->artist){
          current->next = nextN->next; // set nextN's next to current's next
          free(nextN); // and free nextN
          return front;
      }
      current = nextN;
      nextN = nextN->next;
      //keep iterating through while loop
    }
  return front;
}
// Remove the node containing data from the list pointed to by front.
// If data is not in the list, nothing is changed.
// Returns a pointer to the beginning of the list.

//Ruoshui's functions
// insert nodes in order: alphabetical by Artist then by Song
// find and return a pointer to a node based on artist and song name


//Rachel's functions
// find and return a pointer to the first song of an artist based on artist name
// Return a pointer to random element in the list.
