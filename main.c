#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "llist.h"
#include "songlib.h"

void print_result(int cond)
{
  printf("result: %s\n", cond ? "passed" : "failed");
}
void printbar()
{
  printf("\n===================================================================\n\n");
}
int main(void)
{
  struct song_node * p0 = NULL;
  struct song_node * p1 = NULL;
  struct song_node * p2 = NULL;


  char *songname, *artistname;
  char *songnames[10] = {"22", "i want it that way", "photograph", "enchanted", "no surprise", "overdose", "jump and fall", "you belong with me", "eyes open", "hey stephen"};
  char *artistnames[10] = {"taylor swift", "backstreet boys", "ed sheeran", "taylor swift", "daughtry", "exo", "taylor swift", "taylor swift", "taylor swift", "taylor swift"};

  printbar();
  printf("LINKED LIST TESTS: \n");
  printbar();
  printf("Printing empty list (NULL): \n");
  print_list(p0);

  printbar();
  printf("Begin testing insert_front (Adding 10 songs):\n");
  int i;
  for (i = 0; i < 10; i++)
  {
    // printf("%d\n", i);
    // printf("Adding song#%d:\n\n", i);
    songname = songnames[i];
    artistname = artistnames[i];
    printf("\nAdding song '%s' by '%s' at %p: \n\t", songname, artistname, p0 );
    p0 = insert_front(p0, songname, artistname);
    print_list(p0);
    // printf("Length of list: %d\n", p0->length);
  }

  printbar();
  puts("Testing get_by_artist_song: ");

  puts("Get first song:");
  p1 = get_by_artist_song(p0, songnames[9], artistnames[9]);
  print_result(p0 == p1 && strncmp(p1->name, songnames[9], MAX_NAME_LEN) == 0 && strncmp(p1->artist, artistnames[9], MAX_NAME_LEN) == 0);

  puts("Get last song:");
  p1 = get_by_artist_song(p0, songnames[0], artistnames[0]);
  print_result(strncmp(p1->name, songnames[0], MAX_NAME_LEN) == 0 && strncmp(p1->artist, artistnames[0], MAX_NAME_LEN) == 0);

  char artist[100] = "ed sheeran";
  char song[100] = "photograph";
  printf("Get '%s' by '%s'\n", song, artist);
  p1 = get_by_artist_song(p0, song, artist);
  // printf("\t'%s' by '%s' found at %p\n", p1->name, p1->artist, p1);
  print_result(strncmp(p1->name, song, MAX_NAME_LEN) == 0 && strncmp(p1->artist, artist, MAX_NAME_LEN) == 0);


  printbar();
  printf("Testing first_song_by:\n");
  p2 = first_song_by(p1, "taylor swift");
  printf("Null playlist: First song by 'taylor swift' starting from %p: %p\n", p1, p2);
  if (p2){
    printf("Artist found!\n %s : %s |\n", p2->artist, p2->name);
  }
  else{
    printf("Artist not found :(\n");
  }
  p2 = first_song_by(p0, "daughtry");
  printf("In playlist: First song by 'daughtry' starting from %p: %p\n", p0, p2);
  if (p2){
    printf("Artist found!\n %s : %s |\n", p2->artist, p2->name);
  }
  else{
    printf("Artist not found :(\n");
  }
  p2 = first_song_by(p0, "taylor swift");
  printf("In playlist + multiple songs by artist: First song by 'taylor swift' starting from %p: %p\n", p0, p2);
  if (p2){
    printf("Artist found!\n %s : %s |\n", p2->artist, p2->name);
  }
  else{
    printf("Artist not found :(\n");
  }
  p2 = first_song_by(p0, "the fray");
  printf("Not in playlist: First song by 'the fray' starting from %p: %p\n", p0, p2);
  if (p2){
    printf("Artist found!\n %s : %s |\n", p2->artist, p2->name);
  }
  else{
    printf("Artist not found :(\n");
  }

  printbar();
  printf("Testing remove_song_node: \n");
  printf("Removing 'overdose' by 'exo' (middle of list): \n");
  p0 = remove_song_node(p0, "overdose", "exo");
  print_list(p0);
  // printf("Length of list: %d\n", p0->length);
  printf("Address should not be different.\n\n");


  printf("Removing 'stay' by 'blackpink' (not in list)\n");
  p0 = remove_song_node(p0, "stay", "blackpink");
  print_list(p0);
  // printf("Length of list: %d\n", p0->length);
  printf("Address should not be different, neither should the list.\n\n");

  printf("Removing '22' by 'taylor swift' (end of list): \n");
  p0 = remove_song_node(p0, "22", "taylor swift");
  print_list(p0);
  // printf("Length of list: %d\n", p0->length);
  printf("Address should not be different.\n\n");

  printf("Removing 'hey stephen' by 'taylor swift' (beginning of list)\n");
  p0 = remove_song_node(p0, "hey stephen", "taylor swift");
  print_list(p0);
  // printf("Length of list: %d\n", p0->length);
  printf("Address should be different.\n\n");

  printbar();
  printf("Testing random_song:\n");
  srand(time(NULL));
  for (i = 0; i < 5; i++){
    // printf("Length of p0: %d\n", p0->length);
    p2 = random_song(p0, p0->length);
    print_song_node(p2);
  }

  printbar();
  printf("Testing free_list: \n");

  p0 = free_list(p0);

  printf("\nPrinting the freed p0 (should be NULL)\n");
  print_list(p0);

  printbar();
  printf("Testing remove_song_node on NULL list: \n");
  printf("\nRemoving 'photograph' by 'ed sheeran' from NULL list: \n");
  p0 = remove_song_node(p0, "photograph", "ed sheeran");
  print_list(p0);
  printf("Address should not be different.\n");

// ================================================================================================
  printbar();
  printf("MUSIC LIBRARY TESTS\n");
  printbar();

  struct song_node *table[27];
  //table = malloc(27 * sizeof(struct song_node *));
  for (i = 0; i < 27; i++){
    table[i] = calloc(1, sizeof(struct song_node));
  }
  struct song_node *t0;
  // printf("table[0]: %p\n", table[0]);
  // printf("table: %p\n", table);
  // printf("Testing print_letterlist on NULL library: \n");
  // print_letterlist(table, 'a');
  // printf("Testing print_lib on NULL library: \n");
  // print_lib(table);

  char *newsongnames[12] = {"all too well", "here's to never growing up", "i'm with you", "enchanted", "complicated", "overdose", "jump and fall", "you belong with me", "eyes open", "hey stephen", "?insert random name?", "drops of jupiter"};
  char *newartistnames[12] = {"taylor swift", "avril lavigne", "avril lavigne", "taylor swift", "avril lavigne", "exo", "taylor swift", "taylor swift", "taylor swift", "taylor swift", "?insert random name?", "train"};


  printf("Testing add_song (12 songs) and print_letterlist: \n");
  for (i = 0; i < 12; i++){
    songname = newsongnames[i];
    artistname = newartistnames[i];
    printf("\nAdding song '%s' by '%s' at %p: \n", songname, artistname, p0 );
    add_song(table, songname, artistname);
    print_letterlist(table, artistname[0]);
  }
  printbar();
  printf("Testing print_lib\n");
  print_lib(table);

  printbar();
  printf("Testing search_song: \n");
  printf("Looking for 'complicated' by 'avril lavigne'...\n");
  p0 = search_song(table, "complicated", "avril lavigne");
  printf("\t'%s' by '%s' found at %p\n", p0->name, p0->artist, p0);

  printf("Looking for '?insert random name?' by '?insert random name?'...\n");
  p0 = search_song(table, "?insert random name?", "?insert random name?");
  printf("\t'%s' by '%s' found at %p\n", p0->name, p0->artist, p0);

  printf("Looking for 'nonexistent' by 'taylor swift'...\n");
  p0 = search_song(table, "nonexistent", "taylor swift");
  printf("\tShould be NULL: %p", p0);

  printbar();
  printf("Testing print_artistlist: \n");
  printf("Finding all songs by 'taylor swift'... \n");
  print_artistlist(table, "taylor swift");
  printf("Finding all songs by 'p!nk' (not in playlist)... \n");
  print_artistlist(table, "p!nk");
  printf("Finding all songs by '?' (not in playlist)\n");
  print_artistlist(table, "?");
  printf("Finding all songs by 'train'...\n");
  print_artistlist(table, "train");
  printf("Finding all songs by 'avril lavigne'\n");
  print_artistlist(table, "avril lavigne");
}
