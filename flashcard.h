
#include <iostream>
#include <string>



class node {
  public:
  node* next;  // next: pointer to the next node in the list, or points to NULL.
  std::string question;
  std::string answer;
};

class flashcard {
  public:
  node* head1;
  node* head2;

  bool currentLinkedList(){ // true will represent head1, false will represent head2
    if (head2 == NULL){
      //std::cout << "we are in head1" << std::endl;
      return true;
    }
    //std::cout << "we are in head2" << std::endl;
    return false;
  }
};


