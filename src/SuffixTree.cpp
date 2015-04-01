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
	root = new Node(assignId(), nullptr, 0, 0);
}

void Tree::Build() {
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
	printf("= findPathAndInsert: ");
	PrintSegment(beg, len);

	Node *child = getChildByLabelBeginning(node, input[beg]);

	// No child by that label
	if (child == nullptr) {
		Node *nchild = new Node(assignId(), node, beg, len);
		addChildToNode(node, nchild);
		return nchild;
	}

	for (int i = 1; i < len; i++) {
		if (i >= child->len) {
			return findPathAndInsert(child, suffix, beg + i, len - i);
		}
		if (input[beg + i] != input[child->beg + i]) {
			// SPLIT
			Node *mid = breakEdge(child, i);
			printf("= splitting:\n");
			PrintNodeLabel(mid);
			return findPathAndInsert(mid, suffix, (beg + i) - 1, (len - i) + 1);
		}
	}

	return nullptr;
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
		//Beta is the edge label between u and uprime.
		int beta = u->beg;
		int betalen = u->len;

		Node *v = nodeHopToV(vprime, beta, betalen);

		return findPathAndInsert(v, suffix, suffix + v->stringDepth,
			input.length() - suffix - v->stringDepth);

	} else {
		//Case 2B: u was created during iteration (suffix-1), and u' is the root
		Node *uprime = u->parent; // root
		Node *vprime = uprime->suffixLink; // also the root
		int betaprime = u->beg + 1; // beta = x betaprime
		int betaprimelen = u->len - 1;

		Node *v = nodeHopToV(vprime, betaprime, betaprimelen);

		return findPathAndInsert(v, suffix, suffix + v->stringDepth,
			input.length() - suffix - v->stringDepth);
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
			return breakEdge(n2, remaining);

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

Node *
Tree::breakEdge(
	Node *n,
	int i
	)
{
	printf("= breakEdge(%d)\n", i);
	Node *parent, *newNode;

	parent = n->parent;

	//Make new node
	newNode = new Node(assignId(), parent, n->beg, i);
	//Remove n from parent's children, replace with new node.
	replaceChild(parent, newNode);

	//Insert n under new node
	addChildToNode(newNode, n);

	//Alter n
	n->parent = newNode;
	n->len = n->len - i;

	return newNode;
}

Node *
Tree::getChildByLabelBeginning(
	Node *n,
	char c
	)
{
	Node *cur = n->child;

	while (cur != nullptr)
	{
		if (input[cur->beg] == c)
			return cur;
		cur = cur->sibling;
	}
	return cur;
}

void 
Tree::addChildToNode(
	Node *parent,
	Node *child
	)
{
	Node *cur = parent->child;
	if (cur == nullptr) {
		parent->child = child;
		return;
	}

	char k = input[child->beg];
	if (k == '$') {
		if (cur != nullptr && input[cur->beg] == '$') {
			panic("shouldnt already have child with this label");
		}

		child->sibling = cur;
		parent->child = child;
		return;
	}

	Node *prev = nullptr;
	while(cur != nullptr) {
		if (k < input[cur->beg]) {
			child->sibling = cur;
			if (prev == nullptr) {
				parent->child = child;
			} else {
				prev->sibling = child;
			}
			return;
		}

		prev = cur;
		cur = cur->sibling;
	}
	prev->sibling = child;
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

void Tree::replaceChild(Node *parent, Node *node) {
	Node *prev = nullptr;
	Node *cur = parent->child;
	char k = input[node->beg];

	while (cur != nullptr) {
		if (k == input[cur->beg]) {
			node->sibling = cur->sibling;
			if (prev == nullptr) {
				parent->child = node;
			} else {
				prev->sibling = node;
			}
			return;
		}

		prev = cur;
		cur = cur->sibling;
	}
}

void Tree::PrintNodeLabel(Node *n) {
	PrintSegment(n->beg, n->len);
}

void Tree::PrintSegment(int beg, int len) {
	for (int i = 0; i < len; i++) {
		printf("%c", input[beg + i]);
	}
	printf("\n");
}

}
