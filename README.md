# Flashcards by Cody Hegwer
---------------------------------------------
### Description
---------------------------------------------
Flashcards is a simple tool to be run on command line. It utilizes two linked lists to store questions/answer pairs. As questions are answered correctly, they are popped from one linked list into the other.

Users can load in a list of questions with corresponding answers in a '.txt' file, and can add/delete questions as they see fit within the program. You can then proceed to start a study session with the flashcards. Users also have the ability to save their current flashcard list to a '.txt' file for later use.  

### Flashcard guide
---------------------------------------------
Ensure you are in the correct directory and run './flashcard'. (only works in unix terminals in current version). Try loading in 'example.txt' using the load command within the program.

**add** - 
Adds a question to your flashcards. Questions must end in a question mark '?'. Answers must end in a period '.'. If these are not satisfied, program will not add question and return you to input prompt.

**delete** - 
Deletes a question from your flashcards. User must provide question exactly as it was typed. Program then finds question in current linked list and removes it.

**preview** - 
Program will display all available questions that user has added or loaded in.

**load** - 
User has the option to load in a '.txt' file with question/answer pairs. Load will continue to load in questions if they are written in the correct format. Correct format will look something like:

    How are you doing?
    I am fine.

Parsing will ignore empty lines, and skip until a question is found on a new line, however answers MUST BE on the following line after a question. Questions must end in a '?'. Answers must end in a '.'.

User must write entire name of file being loaded, including the '.txt' or program will not find it.

**save** - 
Saves all question/answer pairs to a '.txt' file. Users do not need to write the '.txt' here as they do in load. Simply provide the desired filename you wish to write to.

**study** - 
Users can study the flashcards they have assembled. Users can specify how many rounds they would like to study for. A 'round' finishes once the user has answered all of their questions correctly. As questions are answered correctly, they are popped from the list and added to the other linked list in the flashcard class. Users cannot leave study session early without terminating program in current version. Studying will finish once user has completed all rounds.

**exit** - 
Terminates program and returns user back to shell/command line.

### Makefile
---------------------------------------------
If user changes any functionality in flashcard.cpp or flashcard.h, they can recompile program by typing 'make' in commandline. './flashcard' will be rewritten, but will remain as the standard executable file.

### Github repository link
---------------------------------------------
[Github link](https://github.com/CodyHegwer/flashcards)