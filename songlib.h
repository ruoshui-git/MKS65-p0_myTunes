struct table{
  struct song_node *n[27];
};

struct song_node * add_song(struct table *t, char *newname, char *newartist);
// Add song nodes
struct song_node * search_song(struct table *t, char *newname, char *newartist);
// Search for a song given song and artist name (return a pointer).
struct song_node * search_artist(struct table *t, char *newartist);
// Search for an artist.
void print_letterlist(struct table *t, char c);
// Print out all the entries under a certain letter.
void print_artistlist(struct table *t, char *newartist);
// Print out all the songs of a certain artist

// Ruoshui's functions
void print_lib(struct table *t);
// Print out the entire library.
void shuffle(struct table *t);
// Shuffle - print out a series of randomly chosen songs.
struct song_node * delete(struct table *t, char *delname, char *delartist);
// Delete a song
struct song_node * clearlib(struct table *t);
// Clear the library.
