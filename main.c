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
  char *artistnames[10] = {"taylor swift", "backstreet boys", "ed sheeran", "taylor Swift", "daughtry", "exo", "taylor swift", "taylor swift", "taylor swift", "taylor swift"};

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
    printf("%d\n", i);
    // printf("Adding song#%d:\n\n", i);
    songname = songnames[i];
    artistname = artistnames[i];
    // printf("\nAdding song '%s' by '%s' at %p: \n", songname, artistname, p0 );
    p0 = insert_front(p0, songname, artistname);
    print_list(p0);
  }

  printbar();
  puts("Testing get_by_artist_song: ");

  puts("Get first song:");
  p1 = get_by_artist_song(p0, artistnames[9], songnames[9]);
  print_result(p0 == p1 && strncmp(p1->name, songnames[9], MAX_NAME_LEN) == 0 && strncmp(p1->artist, artistnames[9], MAX_NAME_LEN) == 0);

  puts("Get last song:");
  p1 = get_by_artist_song(p0, artistnames[0], songnames[0]);
  print_result(strncmp(p1->name, songnames[0], MAX_NAME_LEN) == 0 && strncmp(p1->artist, artistnames[0], MAX_NAME_LEN) == 0);

  char artist[100] = "ed sheeran";
  char song[100] = "photograph";
  printf("Get '%s' by '%s'\n", song, artist);
  p1 = get_by_artist_song(p0, artist, song);
  print_result(strncmp(p1->name, song, MAX_NAME_LEN) == 0 && strncmp(p1->artist, artist, MAX_NAME_LEN));


  printbar();
  printf("Testing first_song_by:\n");
  p2 = first_song_by(p1, "taylor swift");
  printf("Null playlist: First song by 'taylor swift' starting from %p: %p\n", p1, p2);
  p2 = first_song_by(p0, "daughtry");
  printf("In playlist: First song by 'daughtry' starting from %p: %p\n", p0, p2);
  p2 = first_song_by(p0, "taylor swift");
  printf("In playlist + multiple songs by artist: First song by 'taylor swift' starting from %p: %p\n", p0, p2);
  p2 = first_song_by(p0, "the fray");
  printf("Not in playlist: First song by 'the fray' starting from %p: %p\n", p0, p2);

  printbar();
  printf("Testing remove_song_node: \n");
  printf("Removing 'overdose' by 'exo' (middle of list): \n");
  p0 = remove_song_node(p0, "overdose", "exo");
  print_list(p0);
  printf("Address should not be different.\n\n");

  printf("Removing 'stay' by 'blackpink' (not in list)\n");
  p0 = remove_song_node(p0, "stay", "blackpink");
  print_list(p0);
  printf("Address should not be different, neither should the list.\n\n");

  printf("Removing '22' by 'taylor swift' (end of list): \n");
  p0 = remove_song_node(p0, "22", "taylor swift");
  print_list(p0);
  printf("Address should not be different.\n\n");

  printf("Removing 'hey stephen' by 'taylor swift' (beginning of list)\n");
  p0 = remove_song_node(p0, "hey stephen", "taylor swift");
  print_list(p0);
  printf("Address should be different.\n\n");

  printbar();
  printf("Testing random_song:\n");
  srand(time(NULL));
  p2 = random_song(p0);
  print_list(p2);

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

  printbar();
  printf("MUSIC LIBRARY TESTS\n");
  printbar();

  struct table *t0 = NULL;
  printf("Testing print_letterlist on NULL library: \n");
  print_letterlist(t0, 'a');
  printf("Testing print_lib on NULL library: \n");
  print_lib(t0);
}
