struct node
{

  char name[100];
  char artist[100];
  struct node *next;

};

// from previous assignment
void print_list(struct node * n);
struct node * insert_front(struct node * n, int data);
struct node * free_list(struct node * n);
struct node * remove_node(struct node *front, int data);
