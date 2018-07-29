
#include <iostream>
#include <string>

// Linked List Invariant: following the 'next' links in a linked list
// node must eventually lead to a NULL reference signifying the end of
// the list. (E.g. no circular references are allowed.)

// node is the basic node structure for a linked list.

struct node {
  node* next;  // next: pointer to the next node in the list, or NULL
  std::string question;
  std::string answer;
};

struct flashcard {
  int rounds;     // how many rounds the user wants to study for.
  node* head1;
  node* head2;
};

// init_node creates a new node structure from heap memory. It points
// to NULL and holds the provided integer. The function returns a
// pointer to that new node.

//flashcard* init_flashcard();

node* add(node* root, std::string question, std::string answer);


