// cin with strings
#include "flashcard.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


flashcard* init_flashcard(){
  flashcard* ret = new flashcard;
  ret->rounds = 1;
  ret->head1 = NULL;
  ret->head2 = NULL;
  return ret;
}

node* add(node* root, std::string question, std::string answer){

}


int main ()
{

  // start
  ifstream inFile;

  string mystr ("beginning");
  string exitstr ("exit");
  string addstr ("add");
  string delstr ("delete");
  string loadstr ("load");
  string savestr ("save");
  string studystr ("study");

  flashcard* FLASHCARDS = init_flashcard();

  while (mystr.compare(exitstr) != 0){
    cout << "Following options:"<< endl;
    cout << "'add' - Add a question to your flashcards." << endl;
    cout << "'delete' - Deletes a question from your flashcards." << endl;
    cout << "'load' - Loads a text document saved with flashcards." << endl;
    cout << "'save' - Saves your current flashcards to a text document in current directory." << endl;
    cout << "'study' - Begins a study session with current flashcards." << endl;
    cout << "'exit' - Exits out of program.\n\n";
    getline (cin, mystr); cout << endl;

    // add
    if (mystr.compare(addstr) == 0){
      cout << "wtf?";
    }
  }

  return 0;
}