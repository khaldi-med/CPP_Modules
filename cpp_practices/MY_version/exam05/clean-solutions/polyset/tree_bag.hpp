#ifndef TREE_BAG_HPP
#define TREE_BAG_HPP
#include "bag.hpp"
class tree_bag : virtual public bag {
protected:
	struct node { int value; node *left, *right; };
	node *root;
	static node *copy(node *);
	static void destroy(node *);
	static void print(node *);
public:
	tree_bag();
	tree_bag(const tree_bag &);
	tree_bag &operator=(const tree_bag &);
	~tree_bag();
	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();
};
#endif
