#include "tree_bag.hpp"
#include <iostream>
tree_bag::tree_bag() : root(0) {}
tree_bag::tree_bag(const tree_bag &o) : root(copy(o.root)) {}
tree_bag &tree_bag::operator=(const tree_bag &o)
{
	if (this != &o) { destroy(root); root = copy(o.root); }
	return *this;
}
tree_bag::~tree_bag() { destroy(root); }
void tree_bag::insert(int n)
{
	node **p = &root;
	while (*p) {
		if (n == (*p)->value) return;
		p = n < (*p)->value ? &(*p)->left : &(*p)->right;
	}
	*p = new node; (*p)->value = n; (*p)->left = (*p)->right = 0;
}
void tree_bag::insert(int *a, int n) { for (int i = 0; a && i < n; ++i) insert(a[i]); }
void tree_bag::print() const { print(root); std::cout << '\n'; }
void tree_bag::clear() { destroy(root); root = 0; }
tree_bag::node *tree_bag::copy(node *p)
{
	if (!p) return 0;
	node *n = new node; n->value = p->value; n->left = copy(p->left); n->right = copy(p->right); return n;
}
void tree_bag::destroy(node *p) { if (p) { destroy(p->left); destroy(p->right); delete p; } }
void tree_bag::print(node *p) { if (p) { print(p->left); std::cout << p->value << ' '; print(p->right); } }
