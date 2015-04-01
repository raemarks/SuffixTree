#include "SuffixTree.h"
#include <string>

#define FAIL 0
#define PASS 1

#define RunTest(x) \
	do { \
	if (x() == FAIL) { printf("FAIL\t" #x "\n"); exit(1); } \
	else { printf("PASS\t" #x "\n"); } } while(0);

#define Assert(cond, failstring, ...) \
	do { if (!(cond)) { \
		fprintf(stderr, "ASSERT FAILURE: " failstring "\n", ##__VA_ARGS__); \
		return FAIL; } } while(0)

using suffixtree::Tree;
using suffixtree::Node;

int TestFindPathAndInsertBasic() {
	std::string s = "banana$";
	Tree *t = new Tree(s, "");

	// Basic insert
	Node *nchild = t->findPathAndInsert(t->GetRoot(), 0, 0, 7);
	Assert(nchild->beg == 0, "Child has wrong begin index");
	Assert(nchild->len == 7, "Child has incorrect length");

	// Now some splitting
	// insert "nana$"
	Node *c_a = t->findPathAndInsert(t->GetRoot(), 0, 2, 5);

	// insert "na$"
	Node *c_b = t->findPathAndInsert(t->GetRoot(), 0, 4, 3);

	Assert(c_a->len == 3, "Child has bad length: %d != %d", 3, c_a->len);
	Assert(s[c_a->beg] == 'n', "Wrong beginning index for c_a");

	Assert(c_b->len == 1, "Child has bad length: %d != %d", 1, c_b->len);
	Assert(s[c_b->beg] == '$', "Wrong char for node");

	return PASS;
}

int TestBreakEdgeBasic() {
	std::string s = "nana$";
	Tree *t = new Tree(s, "");
	Node *parent = t->GetRoot();
	Node *child = new Node(0, parent, 0, 5);

	Node *v = t->breakEdge(child, 2);

	Assert(v->beg == 0, "Middle node has wrong begin index");
	Assert(v->len == 2, "Middle node has wrong length");
	Assert(child->beg == 2, "Child node has wrong begin index");
	Assert(child->len == 3, "Child node has wrong length");

	return PASS;
}

int TestBuildBanana() {
	std::string s = "banana";
	Tree *t = new Tree(s, "");
	t->Build();
	t->EnumerateBWT();

	char expected[] = "annb$aa";
	for (int i = 0; i < t->B.size(); i++) {
		Assert(t->B[i] == expected[i], "BWT index %d was wrong.", i);
	}

	return PASS;
}

int TestBuildMississippi() {
	std::string s = "mississippi";
	Tree *t = new Tree(s, "");
	t->Build();
	t->EnumerateBWT();

	t->PrintTree();
	return PASS;
}

int main(void) {
	RunTest(TestBreakEdgeBasic);
	RunTest(TestFindPathAndInsertBasic);
	RunTest(TestBuildBanana);
	RunTest(TestBuildMississippi);
}
