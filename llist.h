#define MAX_NAME_LEN 100

struct song_node
{
  char name[MAX_NAME_LEN];
  char artist[MAX_NAME_LEN];
  struct song_node *next;
};
// struct song_song_node * table[27];

// from previous assignment
void print_list(struct song_node * n);
void print_song_node(struct song_node *n);
struct song_node * insert_front(struct song_node * n, char *newname, char *newartist);
struct song_node * insert_order(struct song_node *n, char * name, char * artist);
struct song_node * free_list(struct song_node * n);
struct song_node * remove_song_node(struct song_node *front, char *newname, char *newartist);
struct song_node * first_song_by(struct song_node *n, char *newartist);
struct song_node * random_song(struct song_node *n);
