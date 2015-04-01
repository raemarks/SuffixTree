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
	Node *c_a = t->findPathAndInsert(t->GetRoot(), 0, 2, 5);
	Node *c_b = t->findPathAndInsert(t->GetRoot(), 0, 4, 3);

	printf("a label:\n");
	t->PrintNodeLabel(c_a);
	printf("b label:\n");
	t->PrintNodeLabel(c_b);

	Assert(c_a->len == 2, "Child has bad length: %d != %d", 2, c_a->len);

	


	return PASS;
}

int main(void) {
	RunTest(TestFindPathAndInsertBasic);
}
