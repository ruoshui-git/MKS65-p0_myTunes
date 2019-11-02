struct song_node * table[27];

struct song_node * add_song(struct song_node * n, char *newname, char *newartist);
// Add song nodes
struct song_node * search_song(struct song_node * n, char *newname, char *newartist);
// Search for a song given song and artist name (return a pointer).
struct song_node * search_artist(struct song_node *n, char *newartist);
// Search for an artist.
void print_letterlist(struct song_node *n, char c);
// Print out all the entries under a certain letter.
void print_artistlist(struct song_node *n, char *newartist)
// Print out all the songs of a certain artist

// Ruoshui's functions
void print_lib(struct song_node *n);
// Print out the entire library.
void shuffle(struct song_node *n);
// Shuffle - print out a series of randomly chosen songs.
struct song_node * delete(struct song_node *n, char *delname, char *delartist);
// Delete a song
struct song_node * clearlib(struct song_node *n);
// Clear the library.
