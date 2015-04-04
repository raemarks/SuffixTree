#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H

#include <string>

#include "SuffixTreeNode.h"

#define panic(x) \
	printf("%s:%d " x "\n", __FILE__, __LINE__); exit(1);

#ifdef DEBUG
	#define TRACE(x, ...) \
		fprintf(stderr, "%s:%d\t%s\n", __FILE__, __LINE__, x, __VA_ARGS__);
#else 
	#define TRACE(x)
#endif

namespace suffixtree
{

class Tree
{
	private:
		Node *alloc_buf;
		int alloc_i;

		Node *root;
		std::string alphabet;
		int alphabetSize;
		std::string& input;
		int nextNodeId;
		int printCount;
		int B_i;

		//For tree statistics
		bool ranDFS;
		int nIntNodes;
		int nLeaves;
		Node *lowestIntNode;

		//Inserts a suffix into the tree and returns a pointer to the newly
		//created leaf node representing that suffix.
		Node *insertSuffix(
			Node *prevLeaf,
			int suffix
			);

		int assignId();

		//Returns the node hopped-to, newly created if necessary.
		Node *nodeHopToV(
			Node *start,
			int beta,
			int len
			);

		// Returns true if chars at i and j of original input string are equal,
		// false otherwise.
		bool areEqual(
			int i,
			int j
			);

		Node *getChildByLabelBeginning(
			Node *n,
			char c
			);


		void addChildToNode(
			Node *parent,
			Node *child
			);

		void replaceChild(
			Node *parent,
			Node *newChild
			);

		void recursiveEnumerateNodesDFS(
			Node *n
			);

		void recursiveEnumerateBWT(
			Node *n
			);

		Node *newNode(int id, Node *parent, int beg, int len);

	public:
		std::vector<char> B;

		Tree(
			std::string& input,
			std::string alphabet
			);

		// i is the index before which to break the edge of Node n and create
		// another internal node..
		Node *breakEdge(
			Node *n,
			int i
			);

		void Build();

		void DisplayChildren(
			Node *node
			);

		void EnumerateNodesDFS();

		//Returns a pointer to the newly created leaf node
		Node *findPathAndInsert(
			Node *node,
			int suffix,
			int beg,
			int len
			);

		void EnumerateBWT();

		Node *GetRoot() {return root;}

		void PrintLongestRepeatSeqInfo();
		void PrintNodeLabel(Node *n);
		void PrintSegment(int beg, int len);
		void printTreeRec(Node *nd, int depth);
		void PrintTree();
		void PrintTreeInfo();
};

}

#endif
