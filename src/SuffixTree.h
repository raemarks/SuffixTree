#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H

#include <string>

#include "SuffixTreeNode.h"

namespace suffixtree
{

class SuffixTree
{
	private:
		SuffixTreeNode *root;
		std::string alphabet;
		std::string& input;

		SuffixTreeNode *createNode(
			int beg,
			int len,
			int id
			);

		void insert(
			int suffix
			);

	public:
		SuffixTree(
			std::string& input,
			std::string alphabet
			);

		void DisplayChildren(
			SuffixTreeNode *node
			);
		//node->GetChildren();

		void EnumerateNodesDFS();
};

}

#endif
