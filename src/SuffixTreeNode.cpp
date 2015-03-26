#include "SuffixTreeNode.h"

namespace suffixtree {
	SuffixTreeNode::SuffixTreeNode(int id, SuffixTreeNode *parent, int beg, int end) : id(id), beg(beg), end(end), parent(parent) {}
		std::vector<SuffixTreeNode*> SuffixTreeNode::GetChildren() {
			return children;
		}

		void SuffixTreeNode::AddChild(SuffixTreeNode *node) {
			children.push_back(node);
		}
}

