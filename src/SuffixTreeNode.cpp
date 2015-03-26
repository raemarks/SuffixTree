#include "SuffixTreeNode.h"

namespace suffixtree {
		std::vector<SuffixTreeNode*> SuffixTreeNode::GetChildren() {
			return children;
		}

		void SuffixTreeNode::AddChild(SuffixTreeNode *node) {
			children.push_back(node);
		}
}

