# Change this to your file with main in it.
BASE_NAME = flashcard

# Where to find user code.
USER_DIR = .

# Flags passed to the C++ compiler.
CXXFLAGS = -g -Wall -Wextra -std=c++11

PRIMARY_FILE = $(BASE_NAME).cpp

OBJECTS = $(BASE_NAME).o

all : $(PRIMARY_FILE)

clean :
		rm -rf *.o *.dSYM *~ $(BASE_NAME)

$(BASE_NAME): $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $(BASE_NAME) $(OBJECTS)





