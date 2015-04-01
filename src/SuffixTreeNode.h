#ifndef SUFFIX_TREE_NODE_H_
#define SUFFIX_TREE_NODE_H_
#include <string>
#include <vector>

namespace suffixtree {

class Tree;

class Node {

	friend Tree;

	public:
		Node(int id, Node *parent, int beg, int len);

		void AddChild(Node *node);

		Node *parent;
		Node *child;
		Node *sibling;

		Node *suffixLink;

		//Equivalent to the "edge label". Beg is the index of the first element
		//of the substring described by the edge in the original input string.
		//len is the length of the edge label and consequently the substring.
		int beg, len;

		int id;

		int stringDepth;
};

}
#endif
