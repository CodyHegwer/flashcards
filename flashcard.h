
#include <iostream>
#include <string>



class node { // Nodes hold question/answer combos and are stored in flashcard
  public:
  node* next;  // next: pointer to the next node in the list, or points to NULL.
  std::string question; // question, must end in '?'
  std::string answer; // answer, must end in '.'
};

class flashcard {
  public:
  node* head1; // flashcard class works by transferring questions between
  node* head2; // two linked lists during study sessions.

  // method checks which linked list we are currently in. default is head 1.
  // true will represent head1, false will represent head2
  bool currentLinkedList(){ 
    if (head2 == NULL){
      //std::cout << "we are in head1" << std::endl;
      return true;
    }
    //std::cout << "we are in head2" << std::endl;
    return false;
  }
};


