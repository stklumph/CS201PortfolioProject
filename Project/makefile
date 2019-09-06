CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-Wall
SOURCES=main.c allocateArray.c deallocateArray.c DFS.c generateBoggle.c getMaxPossibleScore.c getUserInput.c getWordScore.c HashTable.c loadDictionary.c PrintPuzzle.c PrintWordList.c processUserInput.c solveBoggle.c startGame.c Trie.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=Boggle
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
