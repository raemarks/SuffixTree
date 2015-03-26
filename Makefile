CC=g++
SRC_DIR=src
OBJ_DIR=obj

CFLAGS=--std=c++11 -g -O2

SOURCES=src/SuffixTree.cpp src/SuffixTreeNode.cpp src/io.cpp src/main.cpp
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

OUTPUT=suffix

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(OUTPUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJECTS) $(OUTPUT)
