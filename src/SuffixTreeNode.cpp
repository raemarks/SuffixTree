#include "SuffixTreeNode.h"

namespace suffixtree {

Node::Node(
	int id,
	Node *parent,
	int beg,
	int len,
	int depth
	):
	id(id),
	beg(beg),
	len(len),
	parent(parent),
	suffixLink(nullptr),
	stringDepth(depth)
{
}

std::vector<Node*>
Node::GetChildren() {
	return children;
}

void
Node::AddChild(Node *node) {
	children.push_back(node);
}

}

