# Source, Includes
INCL   = trie.h trie_node.h posting_list.h posting.h utils.h query_result.h query_quicksort.h
SRC    = main.cpp trie.cpp trie_node.cpp posting_list.cpp posting.cpp utils.cpp query_result.cpp query_quicksort.cpp
OBJ    = $(SRC:.cpp=.o)
PROG   = serts

# Compiler, Linker Defines
CC      = g++ -lm
RM      = rm -f

# Compile and Assemble C++ Source Files into Object Files
%.o: %.cpp
	$(CC) -c $*.cpp

# Object Files into Binaries
$(PROG): $(OBJ)
	$(CC) -o $(PROG) $(OBJ)

# Objects depend on these Libraries
$(OBJ): $(INCL)

# Clean Up Exectuables
clean:
	$(RM) $(PROG)
