struct node{
  char name[100];
  char artist[100];
  struct node *next;
};
// struct song_node * table[27];

// from previous assignment
void print_list(struct node * n);
struct node * insert_front(struct node * n, char *newname, char *newartist);
struct node * free_list(struct node * n);
struct node * remove_node(struct node *front, char *newname, char *newartist);
struct node * first_song_by(struct node *n, char *newartist);
struct node * random_song(struct node *n);
