CC=g++
SRC_DIR=src
OBJ_DIR=obj

SOURCES=src/SuffixTree.cpp src/SuffixTreeNode.cpp
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

OUTPUT=suffix

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	$(CC) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJECTS) $(OUTPUT)
