#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "llist.h"
#include "songlib.h"
// struct song_node * table[27];

// Rachel's functions
void add_song(struct song_node *table[27], char *newname, char *newartist)
/*
{
  char c = 'a';
  struct song_node **p0; //points to beginning of table
  struct song_node *temp;
  if (newartist[0] == 'a')
  { //in case we're adding to the front
    p0 = &table[0];
    temp = p0[0];
    // printf("address of temp: %p || address of p0[0]: %p\n", temp, p0[0]);
    temp = insert_order(p0[0], newname, newartist);
    // printf("new address of temp: %p\n");
    // printf("old address of t[0]: %p\n", table[0]);
    if (temp != p0[0])
    {
      table[0] = temp;
    }
    return;
    // printf("new address of t[0]: %p\n", table[0]);
  }
  //printf("%c\n", newartist[0]);
  for (c = 'b'; c < 'z'; c++)
  {
    if (c == newartist[0])
    {
      //printf("%c || %d\n", c, c - 97);
      p0 = &table[c - 97];                                     //points to beginning of the correct letter list
      table[c - 97] = insert_order(p0[0], newname, newartist); //insert at correct letter list
      return;
    }
  }
  // miscellaneous character
  p0 = &table[26];
  table[26] = insert_order(p0[0], newname, newartist);
  return;
}
*/

{
  char code = get_table_index(newartist);
  table[code] = insert_order(table[code], newname, newartist);
}
// // Add song nodes

struct song_node *search_song(struct song_node *table[27], char *newname, char *newartist)
{
  int i = newartist[0] - 'a';
  struct song_node **p0;
  if (i < 26 && i >= 0)
  {
    p0 = &table[i]; //points to beginning of the correct letter list
    // return get_by_song_artist(table[i], newname, newartist);
  }
  else
  {
    p0 = &table[26];
  }
  return get_by_song_artist(p0[0], newname, newartist);
}
// // Search for a song given song and artist name (return a pointer).

struct song_node *search_artist(struct song_node *table[27], char *newartist)
{
  int i = newartist[0] - 97;
  struct song_node **p0;
  if (i < 26 && i >= 0)
  {
    p0 = &table[i];
  }
  else
  {
    p0 = &table[26];
  }
  return first_song_by(p0[0], newartist);
}
// Search for an artist.

void print_letterlist(struct song_node *t[27], char c)
{
  if (t == NULL)
  {
    printf("Not a music table.\n");
    return;
  }
  struct song_node *p0 = t[get_table_index(&c)];
  // if (c >= 'a' && c <= 'z')
  // {
  //   // printf("%c: \n", c);
  //   p0 = t[c - 'a'];
  // }
  // else
  // {
  //   // printf("?: \n");
  //   p0 = t[26];
  // }
  if (p0 != NULL && p0->length != 0)
  {
    if (c >= 'a' && c <= 'z')
    {
      printf("Printing all songs under '%c': \n", c);
    }
    else
    {
      printf("Printing all songs under '?'\n");
    }
    // printf("Length of p0: %d\n", p0->length);
    print_list(p0);
  }
  // else{
  //   printf("No songs found.\n");
  // }
}
// Print out all the entries under a certain letter.

void print_artistlist(struct song_node *table[27], char *newartist)
{
  int i = newartist[0] - 97;
  struct song_node **p0;
  if (i < 26 && i >= 0)
  {
    p0 = &table[i]; //points to beginning of the correct letter list
    // return get_by_song_artist(table[i], newname, newartist);
  }
  else
  {
    p0 = &table[26];
  }
  struct song_node *temp = first_song_by(p0[0], newartist);
  // char * str = "\t";
  if (temp)
  {
    printf("Artist '%s' found!\n\t", newartist);
  }
  else
  {
    printf("Artist '%s' not found :(\n", newartist);
    return;
  }
  while (temp != NULL)
  {
    // str = strcat(str, temp->artist);
    // str = strcat(str, ": ");
    // str = strcat(str, temp->name);
    // str = strcat(str, " |");
    printf("%s: %s | ", temp->artist, temp->name);
    // print_song_node(temp);
    temp = first_song_by(temp->next, newartist);
  }
  printf("\n");
}
// Print out all the songs of a certain artist

void print_lib(struct song_node *t[27])
{
  printf("Printing whole library: \n");
  if (t == NULL)
  {
    printf("No songs found in library.\n");
    return;
  }
  char c;
  for (c = 'a'; c < 'z' + 2; c++)
  {
    print_letterlist(t, c);
  }
}
// Print out the entire library.

// Ruoshui's functions
// Shuffle - print out a series of randomly chosen songs.
// Delete a song
// Clear the library.

void shuffle(struct song_node *t[27])
// Shuffle - print out a series of randomly chosen songs.
{
  int i;
  for (i = 0; i < 27; i++)
  {
    if (t[i])
    {
      print_song_node(random_song(t[i], t[i]->length));
    }
  }
}
/*
{
  int total = 0, i;
  for (i = 0; i < 27; i++)
  {
    i += t[i]->length;
  }
  int num_songs = total > 2? (total / 3) : (1);
  i = 0;
  int j = 0;
  struct song_node * tmp = NULL;
  while (i < num_songs)
  {
    for (;j < 27; j++)
    {
      tmp = random_song(t[j], t[j]->length);
      if (tmp)
      {
        print_song_node(tmp);
        i++;
      }
      if (i >= num_songs)
      {
        return;
      }
    }
  }
}
*/
void delete (struct song_node *t[27], char *song, char *artist)
// Delete a song
{
  struct song_node * tmp = search_song(t, song, artist);
  if (tmp)
  {
    // found song, delete it
    int i = get_table_index(artist);
    t[i] = remove_song_node(t[i], song, artist);
  }
  else 
  {
    // null pointer, do nothing
  }
}

void clearlib(struct song_node *t[27])
// Clear the library.
{
  char i;
  for (i = 0; i < 27; i++)
  {
    if (t[i])
    {
      free_list(t[i]);
    }
  }
}

int get_table_index(char* s)
{
  char c = s[0] - 'a';
  if (c < 0 || c > 26)
  {
    return 26;
  }
  return c;
}