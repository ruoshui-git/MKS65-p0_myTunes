#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

void printbar(void)
{
  puts("==================================================");
}
void print_result(int cond)
{
  printf("result: %s\n", cond ? "passed" : "failed");
}

int main(void)
{
  struct node *p0 = NULL;
  char *songname, *artistname;
  char *songnames[10] = {"22", "i want it that way", "photograph", "enchanted", "no surprise", "overdose", "jump and fall", "you belong with me", "eyes open", "hey stephen"};
  char *artistnames[10] = {"taylor swift", "backstreet boys", "ed sheeran", "taylor Swift", "daughtry", "exo", "taylor swift", "taylor swift", "taylor swift", "taylor swift"};

  printbar();
  printf("Begin testing for linkedlist: \n");
  printbar();
  printf("Printing empty list (NULL): \n");
  print_list(p0);

  printbar();
  printf("Begin testing insert_front (Adding 10 songs):\n");
  printbar();
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

  struct node *p1 = NULL;
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

  printf("\nTesting remove_node: \n");
  printf("Removing 'overdose' by 'exo' (middle of list): \n");
  p0 = remove_node(p0, "overdose", "exo");
  print_list(p0);
  printf("Address should not be different.\n\n");

  printf("Removing 'stay' by 'blackpink' (not in list)\n");
  p0 = remove_node(p0, "stay", "blackpink");
  print_list(p0);
  printf("Address should not be different, neither should the list.\n\n");

  printf("Removing '22' by 'taylor swift' (end of list): \n");
  p0 = remove_node(p0, "22", "taylor swift");
  print_list(p0);
  printf("Address should not be different.\n\n");

  printf("Removing 'hey stephen' by 'taylor swift' (beginning of list)\n");
  p0 = remove_node(p0, "hey stephen", "taylor swift");
  print_list(p0);
  printf("Address should be different.\n\n");

  printf("\nTesting free_list: \n");

  p0 = free_list(p0);

  printf("\nPrinting the freed p0 (should be NULL)\n");
  print_list(p0);

  printf("\nRemoving 'try' by 'p!nk' from empty list: \n");
  remove_node(p0, "try", "pink");
  print_list(p0);
  printf("Address should not be different.\n");

  return 0;
}
