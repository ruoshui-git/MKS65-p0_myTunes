void add_song(struct song_node *t[27], char *newname, char *newartist);
// Add song nodes
struct song_node *search_song(struct song_node *t[27], char *newname, char *newartist);
// Search for a song given song and artist name (return a pointer).
struct song_node *search_artist(struct song_node *t[27], char *newartist);
// Search for an artist.
void print_letterlist(struct song_node *t[27], char c);
// Print out all the entries under a certain letter.
void print_artistlist(struct song_node *t[27], char *newartist);
// Print out all the songs of a certain artist

// Ruoshui's functions
void print_lib(struct song_node *t[27]);
// Print out the entire library.
void shuffle(struct song_node *t[27]);
// Shuffle - print out a series of randomly chosen songs.
void delete (struct song_node *t[27], char *song, char *artist);
// Delete a song
void clearlib(struct song_node *t[27]);
// Clear the library.

// get the index for table
int get_table_index(char* s);