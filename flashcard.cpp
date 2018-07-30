// cin with strings
#include "flashcard.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;


flashcard* init_flashcard(){
  flashcard* ret = new flashcard;
  ret->head1 = NULL;
  ret->head2 = NULL;
  return ret;
}



void add(flashcard* flashcards, bool currentHead, std::string question, std::string answer){

  node* retnode = new node;
  retnode->question = question;
  retnode->answer = answer;
  node* nextnode = new node;


  if (currentHead){ // head1
    if (flashcards->head1 == NULL){ // empty flashcard linkedList

      retnode->next = NULL; // circular path on itself.
      flashcards->head1 = retnode;
      return;
    }
    
    // head1 is not empty.

    nextnode = flashcards->head1;
    retnode->next = nextnode;
    flashcards->head1 = retnode;
    return;
  }

  //head 2
  if (flashcards->head2 == NULL){ // empty flashcard linkedList

    retnode->next = NULL; // circular path on itself.
    flashcards->head2 = retnode;
    return;
  }
  
  // head1 is not empty.

  nextnode = flashcards->head2;
  retnode->next = nextnode;
  flashcards->head2 = retnode;
  return;
}



void deleteNode(node** top, bool currentHead, std::string question){

  cout << endl;

  // Flashcard set is empty.
  if (*top == NULL){
    // empty flashcard set
    cout << "\nThere are no questions in this flashcard set.\n\n";
    return;
  }

  node* cursor = *top; // start at head.
  node* precursor = NULL;

  while(cursor != NULL){
    if (question.compare(cursor->question) == 0){


      if (precursor == NULL) { // head is being deleted.
        *top = cursor->next;
        delete cursor;
        return;
      }

      //precursor is not NULL - somewhere else in list is being deleted.
      precursor->next = precursor->next->next;
      delete cursor;
      return;

    }
    precursor = cursor; // cursor becomes previous node
    cursor = cursor->next; // next node becomes cursor
  }

  cout << "\nQuestion does not exist in flashcard set.\n\n";
  return;

}




void preview(node** top){
  
  if (*top == NULL){
    // empty flashcard set
    cout << "Flashcard set is empty.\n\n";
    return;
  }

  node* cursor = *top;

  while (true){
    cout << cursor->question << "\n" << cursor->answer << "\n\n";
    cursor = cursor->next;
    if(cursor == NULL){
      break;
    }
  }
  return;
}




int get_count(flashcard* flashcards, bool currentHead){
  int count = 0;

  node* cursor = flashcards->head1;

  if (!currentHead){
    cursor = flashcards->head2;
  }

  while (cursor != NULL){
    count++;
    cursor = cursor->next;
  }

  return count;
}




void study(flashcard* flashcards, bool currentHead){

  string mystr, currentQuestion, currentAnswer;
  int rounds, random, count;
  node* cursor;
  node** top;

  // how many rounds does user want to study for.
  while(true){
    cout << "How many rounds would you like to study for (limit 9 rounds) ?" << endl;
    getline (cin, mystr); cout << endl;

    if ((int)mystr[0] > 48 && (int)mystr[0] <= 57  && mystr.length() == 1){
      rounds = (int)mystr[0] - 48; // character representation of digits 0 - 48 / 9 - 57
      break;
    } else {
      cout << "Invalid number of rounds, provide integer.\n\n";
    }
  }

  // get number of questions
  int initialCount = get_count(flashcards, currentHead);
  

  // begin studying
  for(int i = 1; i <= rounds; i++){

    // which linked list holds the questions?
    if (currentHead){
      top = &flashcards->head1;
    } else{
      top = &flashcards->head2;
    }

    cout << "STARTING ROUND " << i << "\n\n";
    count = initialCount;
    // current round, round ends once all questions have been answered.
    while (count > 0){

      cursor = *top;
      random = rand() % count;

      // go to random question
      while (random > 0){
        cursor = cursor->next;
        random--;
      }

      currentQuestion = cursor->question;
      currentAnswer = cursor->answer;
      cout << currentQuestion << endl;
      getline (cin, mystr); cout << endl;

      // user was correct.
      if (currentAnswer.compare(mystr) == 0){
        // delete question from current linked list.
        deleteNode(top, currentHead, currentQuestion);
        add(flashcards, !currentHead, currentQuestion, currentAnswer);
        count--;
      } else {
        cout << "Incorrect answer, correct answer is:\n" << currentAnswer << "\n\n";
      }
    }
    
    currentHead = flashcards->currentLinkedList(); // flips to other head.
  
  }

  cout << "STUDY SESSION COMPLETE" << "\n\n";

  return;
}



void save(node** top){
  ofstream f;
  string filename;

  cout << "Please enter a file name to write: ";
  getline( cin, filename );
  filename = filename + ".txt";

  f.open( filename.c_str() );
  node* cursor = *top;
  while(cursor != NULL){
    f << cursor->question << endl;
    f << cursor->answer << endl;
    cursor = cursor->next;
  }
  f.close();
  return;
}



void load(string filename, flashcard* flashcards, bool currentHead){
  string line, currentQuestion, currentAnswer;
  ifstream myfile (filename.c_str());

  if (myfile.is_open())
  {
    while ( getline (myfile, line) )
    {
      currentQuestion = line;
      getline (myfile, line);
      currentAnswer = line;
      add(flashcards, currentHead, currentQuestion, currentAnswer);
    }
    myfile.close();
    cout << "Load completed.\n\n";
  }

  else cout << "Unable to open file\n\n"; 
  return;
}




int main ()
{

  // initialize flashcards

  string mystr ("beginning");
  flashcard* FLASHCARDS = init_flashcard();
  string FILENAME;
  string QUESTION;
  string ANSWER;
  bool CURRENTHEAD;
  node** TOP;

  // continuous loop until user types 'exit'.

  while (true){

    CURRENTHEAD = FLASHCARDS->currentLinkedList();

    if (CURRENTHEAD){ 
      TOP = &FLASHCARDS->head1;
    } else {
      TOP = &FLASHCARDS->head2;
    }

    cout << "Following options:"<< endl;
    cout << "'add' - Add a question to your flashcards." << endl;
    cout << "'delete' - Deletes a question from your flashcards." << endl;
    cout << "'preview' - Preview all questions and answers in flashcards." << endl;
    cout << "'load' - Loads a text document saved with flashcards." << endl;
    cout << "'save' - Saves your current flashcards to a text document in current directory." << endl;
    cout << "'study' - Begins a study session with current flashcards." << endl;
    cout << "'exit' - Exits out of program.\n\n";
    getline (cin, mystr); cout << endl;
    
    //////////////
    // add
    //////////////

    if (mystr.compare("add") == 0){

      cout << "Provide question:\n";
      getline (cin, QUESTION);
      //check for valid question - valid questions end in '?'
      if (QUESTION[QUESTION.length()-1] != '?'){
        cout << "Invalid question - questions need to end with '?'\n\n";
        continue;
      }

      cout << "Provide answer:\n";
      getline (cin, ANSWER);
      //check for valid answer - valid answers end in '.'
      if (ANSWER[ANSWER.length()-1] != '.'){
        cout << "Invalid answer - answers need to end with '.'\n\n";
        continue;
      }

      add(FLASHCARDS, CURRENTHEAD, QUESTION, ANSWER); cout << endl;
      continue;
    }

    //////////////
    // delete
    //////////////

    if (mystr.compare("delete") == 0){
      cout << "Provide question:\n";
      getline (cin, QUESTION);
      //check for valid question - valid questions end in '?'
      if (QUESTION[QUESTION.length()-1] != '?'){
        cout << "Invalid question - questions need to end with '?'\n\n";
        continue;
      }
      deleteNode(TOP, CURRENTHEAD, QUESTION);
      continue;
    }

    //////////////
    // preview
    //////////////

    if (mystr.compare("preview") == 0){
      preview(TOP);
      continue;
    }

    //////////////
    // study
    //////////////

    if (mystr.compare("study") == 0){
      study(FLASHCARDS, CURRENTHEAD);
      continue;
    }
    
    //////////////
    // save
    //////////////

    if (mystr.compare("save") == 0){
      save(TOP);
      continue;
    }
    
    //////////////
    // load
    //////////////

    if (mystr.compare("load") == 0){
      cout << "What is the name of your file: ";
      getline (cin, FILENAME); cout << endl;
      load(FILENAME, FLASHCARDS, CURRENTHEAD);
      continue;
    }

    if (mystr.compare("exit") == 0){
      return 0;
    }

    cout << "Invalid option.\n\n";
  }

  return 0;
}