#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "llist.h"
#include "songlib.h"
// struct song_node * table[27];

// Rachel's functions
struct song_node * add_song(struct table *t, char *newname, char *newartist)
{
  char c;
  for (c = 'a'; c < 'z'; c++){
    if (c == newartist[0]){
      return insert_order(t->n[c - 97], newname, newartist);
    }
  }
  return insert_order(t->n[27], newname, newartist);
}
// // Add song nodes

// struct song_node * search_song(struct table *t char *newname, char *newartist);
// // Search for a song given song and artist name (return a pointer).
// struct song_node * search_artist(strutable *t, char *newartist);
// // Search for an artist.
void print_letterlist(struct table *t, char c){
  printf("Printing all songs under '%c': \n", c);
  if (t == NULL){
    printf("No songs found.\n");
    return;
  }
  if (c >= 'a' && c <= 'z'){
    printf("%c: \n", c);
    print_list(t->n[c-97]);
  }
  else {
    printf("?: \n");
    print_list(t->n[27]);
  }
}
// Print out all the entries under a certain letter.
// void print_artistlist(structable *t, char *newartist);
// Print out all the songs of a certain artist
void print_lib(struct table *t){
  if (t == NULL){
    printf("No songs found in library.\n");
    return;
  }
  char c;
  for (c = 'a'; c < 'z' + 1; c++){
    printf("Printing whole library: \n");
    print_letterlist(t, c);
  }
}
// Print out the entire library.

// Ruoshui's functions
// Shuffle - print out a series of randomly chosen songs.
// Delete a song
// Clear the library.
