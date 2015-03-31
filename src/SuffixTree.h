#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H

#include <string>

#include "SuffixTreeNode.h"

namespace suffixtree
{

class Tree
{
	private:
		Node *root;
		std::string alphabet;
		std::string& input;
		int nextNodeId;

		//Inserts a suffix into the tree and returns a pointer to the newly
		//created leaf node representing that suffix.
		Node *insertSuffix(
			Node *prevLeaf,
			int suffix
			);

		int assignId();

		//Returns a pointer to the newly created leaf node
		Node *findPathAndInsert(
			Node *node,
			int suffix,
			int beg,
			int len
			);

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

		Node *breakEdge(
			Node *n,
			int i
			);

		void addChildToNode(
			Node *parent,
			Node *child
			);

		void replaceChild(
			Node *parent,
			Node *newChild
			);

	public:
		Tree(
			std::string& input,
			std::string alphabet
			);

		void DisplayChildren(
			Node *node
			);

		void EnumerateNodesDFS();
};

}

#endif
