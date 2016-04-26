_Pragma("once")
#include <memory>

struct Node;
using sptr = std::shared_ptr<Node>;
using wptr = std::weak_ptr<Node>;
enum class ctype {RED, BLACK};
struct Node {
public:
	Node(int d, wptr p, sptr l, sptr r, ctype c = ctype::RED)
		:data{d}, parent{p}, left{l}, right{r}, color{c} {}
	Node(ctype c):color{c} {}
	int data;
	wptr parent;
	sptr left, right;
	ctype color;
};

class RedBlackBST {
public:
	RedBlackBST(): nil{new Node{ctype::BLACK}} {
		root = nil;
	}
	void insert(int d) {
		sptr y{nil}, x{root};
		while (x != nil) {
			y = x;
			if (d < x->data) x = x->left;
			else x = x->right;
		}
		sptr z{new Node{d, y, nil, nil}};
		if (y == nil) root = z;
		else if (z->data < y->data) y->left = z;
		else y->right = z;
		insert_fixup(z);
	}

	void del(sptr z) {
		sptr successor;
		sptr breaker; // the node that breaks the rule
		ctype origin_color = successor->color;
		if (z->left == nil) {
			// z only has rightson
			breaker = z->right;
			transplant(z, z->right);
		} else if (z->right == nil) {
			// z only has leftson
			breaker = z->left;
			transplant(z, z->left);
		} else {
			// z has two son
			successor = minimum(z->right);
			origin_color = successor->color;
			breaker = successor->right;
			sptr parent{successor->parent.lock()};
			if (parent != z) {
				// if successor isn't adjacent to z
				transplant(successor, successor->right);
				successor->right = z->right;
				successor->right->parent = successor;
			}
			transplant(z, successor);
			successor->left = z->left;
			successor->left->parent = successor;
			successor->color = z->color;
		}
		if (origin_color == ctype::BLACK)
			// we regard breaker has another "black" color,
			// which occupied the position of successor
			delete_fixup(breaker);
	}

private:
	void delete_fixup(sptr x) {

	}

	sptr minimum(sptr x) {
		while (x->left != nil) x = x->left;
		return x;
	}

	// use subtree v to replace subtree u
	void transplant(sptr u, sptr v) {
		sptr parent{u->parent.lock()};
		if (parent == nil) root = v;
		else if (u == parent->left) parent->left = v;
		else parent->right = v;
		v->parent = parent;
	}

	void insert_fixup(sptr z) {
		sptr zp{z->parent.lock()}; 
		while (zp->color == ctype::RED) {
			zp = z->parent.lock();
			sptr zpp{zp->parent.lock()};
			sptr uncle{zpp->right};
			if (zp == zpp->left) {
				// Case 1:the uncle node is red
				if (uncle->color == ctype::RED) {
					uncle->color = zp->color = ctype::BLACK;
					zpp->color = ctype::RED;
					z = zpp;
				} else {
				// Case 2/3:the uncle node of z is black
					if (z == zp->right) {
					// Case 2: ... and z is rightson
						z = zp; left_rotate(z);
					}
					// Case 3: ... and z is leftson
					zp->color = ctype::BLACK;
					zpp->color = ctype::RED;
					right_rotate(zpp);
				}
			} else {
			// same as clause with "right" and "left" exchanged
				// Case 1:the uncle node is red
				if (uncle->color == ctype::RED) {
					uncle->color = zp->color = ctype::BLACK;
					zpp->color = ctype::RED;
					z = zpp;
				} else {
				// Case 2/3:the uncle node of z is black
					if (z == zp->left) {
					// Case 2: ... and z is rightson
						z = zp; right_rotate(z);
					}
					// Case 3: ... and z is leftson
					zp->color = ctype::BLACK;
					zpp->color = ctype::RED;
					left_rotate(zpp);
				}
			}
		}
		root->color = ctype::BLACK;
	}

	void right_rotate(sptr x) {
		sptr y{x->left};
		// turn y's right subtree into x's left subtree
		x->left = y->right;
		// TODO: Could we cancel the condition (y->right != nil)?
		y->right->parent = x;
		// link x's parent to y
		y->parent = x->parent;
		sptr parent{x->parent.lock()};
		if (parent == nil) root = y;
		else if (x == parent->left) parent->left = y;
		else parent->right = y;
		y->right = x;
		x->parent = y;
	}

	void left_rotate(sptr x) {
		sptr y{x->right};
		// turn y's left subtree into x's right subtree
		x->right = y->left;
		y->left->parent = x;
		// link x's parent to y
		y->parent = x->parent;
		sptr parent{x->parent.lock()};
		if (parent == nil) root = y;
		else if (x == parent->left) parent->left = y;
		else parent->right = y;
		y->left = x;
		x->parent = y;
	}
	sptr root, nil;
};