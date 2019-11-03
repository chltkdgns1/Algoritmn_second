#include <iostream>
using namespace std;
class tree {
public:
	tree *left, *right;
	int data;
	tree(int data) : data(data) { left = NULL; right = NULL; }
};
void makeRoot(tree *t, int data) {
	if (t->data < data) {
		if (t->right == NULL) t->right = new tree(data);
		else makeRoot(t->right, data);
	}
	else {
		if (t->left == NULL) t->left = new tree(data);
		else makeRoot(t->left, data);
	}
}
void trevalTree(tree *node) {
	if (node == NULL) return;
	trevalTree(node->left);
	trevalTree(node->right);
	cout << node->data << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,root;
	cin >> root;
	tree t(root);
	while (cin >> n) {
		makeRoot(&t, n);
	}
	trevalTree(&t);
}
