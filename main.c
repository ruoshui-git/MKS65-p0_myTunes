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
  for (i = 0; i < 11; i++){
    // printf("Adding song#%d:\n\n", i);
    songname = songnames[i];
    artistname = artistnames[i];
    // printf("\nAdding song '%s' by '%s' at %p: \n", songname, artistname, p0 );
    p0 = insert_front( p0, songname, artistname );
    print_list(p0);
  }
  // printf("\nAdding song '22', artist 'Taylor Swift' (testing insert_front and print_list): \n");
  // p0 = insert_front(p0, songname, artistname);
  // print_list(p0);
  //
  // printf("\nAdding song 'I Want It That Way', artist 'Backstreet Boys' (testing insert_front and print_list): \n");
  // p0 = insert_front(p0, songname, artistname);
  // print_list(p0);
  //
  // printf("\nTesting remove_node: \n");
  // printf("Removing 5 (middle of list): \n");
  // p0=remove_node(p0, 5);
  // print_list(p0);
  // printf("Address should not be different.\n\n");
  //
  // printf("Removing 4 (middle of list): \n");
  // p0=remove_node(p0, 4);
  // print_list(p0);
  // printf("Address should not be different.\n\n");
  //
  // printf("Removing 11 (not in list)\n");
  // p0=remove_node(p0, 11);
  // print_list(p0);
  // printf("Address should not be different, neither should the list.\n\n");
  //
  // printf("Removing 0 (end of list): \n");
  // p0=remove_node(p0, 0);
  // print_list(p0);
  // printf("Address should not be different.\n\n");
  //
  // printf("Removing 1 (end of list): \n");
  // p0=remove_node(p0, 1);
  // print_list(p0);
  // printf("Address should not be different.\n\n");
  //
  // printf("Removing 9 (beginning of list)\n");
  // p0=remove_node(p0, 9);
  // print_list(p0);
  // printf("Address should be different.\n\n");
  //
  // printf("Removing 8 (beginning of list)\n");
  // p0=remove_node(p0, 8);
  // print_list(p0);
  // printf("Address should be different.\n\n");
  //
  // printf("\nTesting free_list: \n");
  //
  // p0 = free_list(p0);
  //
  // printf("\nPrinting the freed p0 (should be NULL)\n");
  // print_list(p0);
  //
  // printf("\nRemoving 0 from empty list: \n");
  // remove_node(p0, 0);
  // print_list(p0);
  // printf("Address should not be different.\n");

  return 0;
}
