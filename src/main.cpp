#include <iostream>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "SuffixTree.h"

int main(int argc, char *argv[])
{
	//TODO: append $ to input string!
	//suffixtree::SuffixTree tree = new suffixtree::SuffixTree(params);

	if (argc < 3) {
		printf("Error, not enough arguments.\n");
		printf("Usage: '%s <input fasta file> {<alphabet>}'\n", argv[0]);
		return 1;
	}

	std::ifstream in(argv[1], std::ifstream::in);
	if (!in.good()) {
		printf("Error: file '%s' not valid.\n", argv[1]);
		return 2;
	}

	std::string name, input;
	ReadInputFasta(in, input, name);

	/*
	std::cout << "Name: " << name << std::endl;
	std::cout << "Input: " << input << std::endl;
	*/

	suffixtree::Tree *t = new suffixtree::Tree(input, "$ACGT");

	t->Build();
	t->EnumerateBWT();
}
