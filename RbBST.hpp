_Pragma("once")
#include <memory>

struct Node;
using sptr = std::shared_ptr<Node>;
using wptr = std::weak_ptr<Node>;
struct Node {
public:
	int data;
	enum class ColorType {RED, BLACK} color;
	sptr left, right;
	wptr parent;
};

class RedBlackBST {
public:
private:
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