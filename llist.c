#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "llist.h"

// struct song_node{
//   char name[MAX_NAME_LEN];
//   char artist[MAX_NAME_LEN];
//   struct song_node *next;
// };

//Ruoshui's functions
// insert song_nodes in order: alphabetical by Artist then by Song
// find and return a pointer to a song_node based on artist and song name

// insert song_nodes in order
// alphabetical by Artist then by Song

struct song_node *insert_order(struct song_node *n, char *name, char *artist)
{
  struct song_node *cur = malloc(sizeof(struct song_node));
  strncpy(cur->name, name, MAX_NAME_LEN);
  strncpy(cur->artist, artist, MAX_NAME_LEN);
  cur->next = NULL;
  cur->length = 1;
  if (!n) // first song_node being added
  {
    return cur;
  }

  struct song_node *trav = n;
  struct song_node *prev = n;

  while (trav)
  {
    int cmp = songcmp(artist, trav->artist, name, trav->name);
    if (cmp > 0)
    {
      // song_node should be inserted after this song_node
      trav->length++;
      prev = trav;
      trav = trav->next;
    }
    else if (cmp < 0)
    {
      // song_node should be inserted right here
      cur->next = trav;
      cur->length = trav->length + 1;
      if (prev != n)
      {
        prev->next = cur;
      }
      else
      {
        // list head is changed, so point to new head
        cur->next = n;
        n = cur;
      }

      // done inserting
      return n;
    }
    else
    {
      // song and artist names are equal, don't store
      // fix the length fields
      struct song_node *tmp = n;
      while (tmp != trav)
      {
        tmp->length--;
        tmp = tmp->next;
      }
      return n;
    }
  }
  // now we are at the end of the list
  prev->next = cur;
  return n;
}
/*
{
  {

    int cmp = strncmp(artist, trav->artist, MAX_NAME_LEN);

    if (cmp > 0)
    {
      // song_node should be inserted after this song_node
      trav->length++;
      prev = trav;
      trav = trav->next;
    }
    else if (cmp < 0)
    {
      // song_node should be inserted right here
      cur->next = trav;
      cur->length = trav->length + 1;
      if (prev != n)
      {
        prev->next = cur;
      }
      else
      {
        // list head is changed, so point to new head
        cur->next = n;
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
        trav->length++;
        prev = trav;
        trav = trav->next;
      }
      else if (cmp < 0)
      {
        cur->next = trav;
        cur->length = trav->length + 1;
        if (prev != n)
        {
          prev->next = cur;
        }
        else
        {
          // list head is changed, so point to new head
          cur = n->next;
          n = cur;
        }

        return n;
      }
      else
      {
        // song and artist names are equal, don't store
        // fix the length fields
        struct song_node *tmp = n;
        while (tmp != trav)
        {
          tmp->length--;
          tmp = tmp->next;
        }
        return n;
      }
    }
  }
  // by this point, we should be at the end of the list
  prev->next = cur;
  return n;
}
*/

int songcmp(char *artist1, char *artist2, char *song1, char *song2)
{
  int cmp = strncmp(artist1, artist2, MAX_NAME_LEN);
  if (cmp)
  {
    // cmp isn't 0 -> artists aren't the same
    return cmp;
  }
  else
  {
    // cmp == 0, artists are the same, compare songs
    return strncmp(song1, song2, MAX_NAME_LEN);
  }
}

struct song_node *free_list(struct song_node *n)
{
  struct song_node *current = n;
  n->length = 0;
  while (n)
  {
    printf("Freeing '%s' by '%s'...\n", n->name, n->artist);
    current = n->next;
    free(n);
    n = current;
  }
  return n; //should be NULL
}
// Should take a pointer to a list as a parameter and then go through the entire list freeing each song_node and return a pointer to the beginning of the list (which should be NULL by then).

struct song_node *remove_song_node(struct song_node *front, char *rname, char *rartist)
{
  if (front == NULL)
  {
    return front;
  }
  int size = front->length;
  front->length = front->length - 1;
  struct song_node *current = front;
  struct song_node *nextN = front->next;
  if (current == front && strcmp(current->name, rname) == 0 && strcmp(current->artist, rartist) == 0)
  {
    //if in front
    free(current);
    return nextN;
  }
  while (nextN)
  {
    current->length = nextN->length; // reduce the length
    if (strcmp(nextN->name, rname) == 0 && strcmp(current->artist, rartist))
    {
      current->next = nextN->next; // set nextN's next to current's next
      free(nextN);                 // and free nextN
      return front;
    }
    current = nextN;
    nextN = nextN->next;
    //keep iterating through while loop
  }
  // not found, fix all the lengths
  current = front;
  while (size)
  {
    current->length = size;
    size = size - 1;
    current = current->next;
  }
  return front;
}

/** find and return a pointer to a song_node based on artist and song name */
struct song_node *get_by_song_artist(struct song_node *front, char *song, char *artist)
{
  struct song_node *trav = front;
  while (trav)
  {
    if (strncmp(song, trav->name, MAX_NAME_LEN) == 0 && strncmp(artist, trav->artist, MAX_NAME_LEN) == 0)
    {
      return trav;
    }
    trav = trav->next;
  }

  // if not found, return NULL, or trav
  return NULL;
}

// Remove the song_node containing data from the list pointed to by front.
// If data is not in the list, nothing is changed.
// Returns a pointer to the beginning of the list.

//Rachel's functions
// Create the following functions:
void print_list(struct song_node *n)
{
  // printf("Printing playlist at address %p: \n  ", n);
  if (n == NULL || n->length == 0)
  {
    printf("No songs in playlist.\n");
    return;
  }
  struct song_node *current = n;
  int i = n->length;
  // printf("n's length: %d\n", i);
  while (i)
  {
    printf("%s: %s | ", current->artist, current->name);
    current = current->next;
    i = i - 1;
  }
  printf("\n");
}
// Should take a pointer to a song_node struct and print out all of the data in the list

void print_list_without_len(struct song_node *current)
{
  while (current)
  {
    printf("%s: %s | ", current->artist, current->name);
    current = current->next;
  }
  printf("\n");
}

void print_song_node(struct song_node *n)
{
  // printf("Printing song_node at address %p\n", n);
  if (n == NULL)
  {
    printf("No song_node found.\n");
    return;
  }
  printf("%s: %s |\n", n->artist, n->name);
}

struct song_node *insert_front(struct song_node *n, char *newname, char *newartist)
{
  // Make sure that there's enough memory to insert_front with malloc

  // printf("\nAdding song '%s' by '%s' at %p:\n", newname, newartist, n );
  struct song_node *current = malloc(sizeof(struct song_node));
  strcpy(current->name, newname);
  strcpy(current->artist, newartist);
  current->next = n;
  if (n)
  {
    current->length = n->length + 1;
  }
  else
  {
    current->length = 1;
  }
  return current;
}
// Should take a pointer to the existing list and the data to be added, create a new song_node and put it at the beginning of the list.
// The second argument should match whatever data you contain in your song_nodes.
// Returns a pointer to the beginning of the list.

// find and return a pointer to the first song of an artist based on artist name
struct song_node *first_song_by(struct song_node *n, char *newartist)
{
  if (n == NULL)
  { //in case playlist is empty
    return NULL;
  }
  struct song_node *current = n;
  while (current->next)
  {
    if (strcmp(current->artist, newartist) == 0)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

struct song_node *random_song(struct song_node *n, int size)
{
  if (n == NULL)
  {
    return NULL;
  }
  struct song_node *current = n;
  int i;
  // //find length of list
  // while (current)
  // {
  //   current = current->next;
  //   i++;
  // }
  int x = rand() * 1000 % size; //mod by size of song list
  //start up loop again
  current = n;
  i = 0; //use i as counter
  while (i < x)
  {
    current = current->next;
    i++;
  }
  return current;
}
// Return a pointer to random element in the list.

struct song_node *get_by_index(struct song_node *n, int i)
{
  struct song_node *trav = n;
  int c;
  for (c = 0; c < i; c++)
  {
    trav = trav->next;
  }
  return trav;
}