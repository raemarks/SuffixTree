#include "SuffixTree.h"

namespace suffixtree
{

SuffixTree::SuffixTree(
	std::string& input,
	std::string alphabet
	):
	input(input),
	alphabet(alphabet)
{
}

SuffixTreeNode *
SuffixTree::createNode(
	int beg,
	int len,
	int id
	)
{
}

void
SuffixTree::insert(
	int suffix
	)
{
}


void
SuffixTree::DisplayChildren(
	SuffixTreeNode *node
	)
{
//node->GetChildren();
}

void
SuffixTree::EnumerateNodesDFS()
{
}

}
