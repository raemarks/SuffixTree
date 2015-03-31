#include "SuffixTree.h"

namespace suffixtree
{

Tree::Tree(
	std::string& input,
	std::string alphabet
	):
	input(input),
	alphabet(alphabet)
{
	nextNodeId = input.length();
	root = new Node(assignId(), nullptr, 0, 0, 0);

	Node *n = root;
	for (int i = 0; i < input.length(); i++) {
		n = insertSuffix(n, i);
	}
}

Node *
Tree::findPathAndInsert(
	Node *node,
	int suffix,
	int beg,
	int len
	)
{

}

bool
Tree::areEqual(
	int i,
	int j
	)
{
	return input[i] == input[j];
}

int
Tree::assignId()
{
	return nextNodeId++;
}

Node*
Tree::insertSuffix(
	Node *prevLeaf,
	int suffix
	)
{

	if (prevLeaf == nullptr) {
		//Just insert first suffix as a leaf to root.
		//return it
	}

	Node *u = prevLeaf->parent;
	if (u->suffixLink != nullptr) {
		//Case 1: u already existed at the start of iteration (suffix-1).
		Node *v = u->suffixLink;
		//u->stringDepth is equivalent to the length of alpha
		return findPathAndInsert(v, suffix, suffix + v->stringDepth,
			input.length() - suffix - v->stringDepth);

	} else if (u->parent != root) {
		//Case 2A: u was created during iteration (suffix-1), and u' is not root
		Node *uprime = u->parent;
		Node *vprime = uprime->suffixLink;
		int beta = u->beg;

	} else {
		//Case 2B: u was created during iteration (suffix-1), and u' is the root
	}
}

Node *
Tree::nodeHopToV(
	Node *start,
	int beta,
	int len
	)
{
	int i = 0, remaining;
	char c;
	Node *n1 = start, *n2;

	while (true) {
		remaining = len - i;
		c = input[beta + i];
		n2 = getChildByLabelBeginning(n1, c);

		if (n2->len > remaining) {
			//break edge right before index 'remaining' of the edge.


		} else if (n2->len == remaining) {
			//Beta is perfectly consumed, we have found V.
			return n2;

		} else {
			//Travel edge, consume part of beta
			i += n2->len;
			n1 = n2;
		}
	}
}

//TODO: move comment to header.
// i is the index before which to break the edge of Node n.
Node *
Tree::breakEdge(
	Node *n,
	int i
	)
{
	Node *parent, *newNode;

	parent = n->parent;

	//Make new node
	newNode = new Node(assignId(), parent, n->beg, i, parent->stringDepth + i);
	//Remove n from parent's children, replace with new node.
	parent->ReplaceChild(newNode);

	//Insert n under new node
	newNode->AddChild(n);
	//Alter n
	n->parent = newNode;
	n->len = n->len - i;
}

Node *
Tree::getChildByLabelBeginning(
	Node *n,
	char c
	)
{
	std::vector<Node *> children = n->GetChildren();

	for (Node *child : children)
	{
		if (input[child->beg] == c)
			return child;
	}
	return nullptr;
}

void
Tree::DisplayChildren(
	Node *node
	)
{
//node->GetChildren();
}

void
Tree::EnumerateNodesDFS()
{
}

}
