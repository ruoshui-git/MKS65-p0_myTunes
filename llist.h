#define MAX_NAME_LEN 100

struct node
{
  char name[MAX_NAME_LEN];
  char artist[MAX_NAME_LEN];
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
// new
struct node * get_by_artist_song(struct node * n, char * song, char * artist)
struct node * insert(struct node * n, char * name, char * artist)
