#define MAX_NAME_LEN 100

struct song_node
{
  char name[MAX_NAME_LEN];
  char artist[MAX_NAME_LEN];
  int length;
  struct song_node *next;
};


// from previous assignment
void print_list(struct song_node * n);
void print_song_node(struct song_node *n);
struct song_node * insert_front(struct song_node * n, char *newname, char *newartist);
struct song_node * insert_order(struct song_node *n, char * name, char * artist);
struct song_node * free_list(struct song_node * n);
struct song_node * remove_song_node(struct song_node *front, char *newname, char *newartist);
struct song_node * first_song_by(struct song_node *n, char *newartist);
struct song_node * random_song(struct song_node *n, int size);
// new
struct song_node * get_by_song_artist(struct song_node *front, char *song, char *artist);
struct song_node * insert(struct song_node * n, char * name, char * artist);

// helper

struct song_node * get_by_index(struct song_node * n, int i);
void print_list_without_len(struct song_node * current);
int songcmp(char *artist1, char *artist2, char *song1, char *song2);