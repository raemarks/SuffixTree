#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H

#include <string>

#include "SuffixTreeNode.h"

#define panic(x) \
	printf(x); exit(1);

namespace suffixtree
{

class Tree
{
	private:
		Node *root;
		std::string alphabet;
		std::string& input;
		int nextNodeId;
		int printCount;
		std::vector<int> B;

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
	public:
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

		void PrintNodeLabel(Node *n);
		void PrintSegment(int beg, int len);
};

}

#endif
