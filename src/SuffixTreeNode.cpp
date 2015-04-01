#include "SuffixTreeNode.h"

namespace suffixtree {

Node::Node(
	int id,
	Node *parent,
	int beg,
	int len
	):
	id(id),
	beg(beg),
	len(len),
	parent(parent),
	suffixLink(nullptr),
	child(nullptr),
	sibling(nullptr)
{
	if (parent != nullptr) {
		stringDepth = parent->stringDepth + len;
	}
}

}

