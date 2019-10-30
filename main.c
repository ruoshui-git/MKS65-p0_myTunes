#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

void printbar(){
  printf("==================================================\n");
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
  for (i = 0; i < 10; i++){
    printf("%d\n", i);
    // printf("Adding song#%d:\n\n", i);
    songname = songnames[i];
    artistname = artistnames[i];
    // printf("\nAdding song '%s' by '%s' at %p: \n", songname, artistname, p0 );
    p0 = insert_front( p0, songname, artistname );
    print_list(p0);
  }


  printf("\nTesting remove_node: \n");
  printf("Removing 'overdose' by 'exo' (middle of list): \n");
  p0=remove_node(p0, "overdose", "exo");
  print_list(p0);
  printf("Address should not be different.\n\n");

  printf("Removing 'stay' by 'blackpink' (not in list)\n");
  p0=remove_node(p0, "stay", "blackpink");
  print_list(p0);
  printf("Address should not be different, neither should the list.\n\n");

  printf("Removing '22' by 'taylor swift' (end of list): \n");
  p0=remove_node(p0, "22", "taylor swift");
  print_list(p0);
  printf("Address should not be different.\n\n");

  printf("Removing 'hey stephen' by 'taylor swift' (beginning of list)\n");
  p0=remove_node(p0, "hey stephen", "taylor swift");
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
