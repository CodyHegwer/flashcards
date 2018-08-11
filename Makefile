# Base name of files
BASE_NAME = flashcard

# Flags passed to the C++ compiler.
CXXFLAGS = -g -Wall -Wextra -std=c++11

PRIMARY_FILE = $(BASE_NAME).cpp

all : $(PRIMARY_FILE)
		$(CXX) $(CXXFLAGS) -o $(BASE_NAME) $(PRIMARY_FILE)






