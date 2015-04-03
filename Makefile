CC=g++
SRC_DIR=src
OBJ_DIR=obj

CFLAGS=--std=c++11 -g #-O3 -march=native

SOURCES=src/SuffixTree.cpp src/SuffixTreeNode.cpp src/io.cpp
MAIN=src/main.cpp
TEST_MAIN=src/SuffixTree_test.cpp
TEST_OUTPUT=test.out
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

OUTPUT=suffix

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(MAIN) $(LIBS) $(CFLAGS) -o $(OUTPUT)

test: $(OBJECTS)
	$(CC) $(OBJECTS) $(TEST_MAIN) $(CFLAGS) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJECTS) $(OUTPUT)
