_Pragma("once")
#include <memory>
#include <vector>

struct Node;
using sptr = std::shared_ptr<Node>;
using wptr = std::weak_ptr<Node>;
enum class ctype {RED, BLACK};
struct Node {
public:
	Node(int d, wptr _p, sptr l, sptr r, ctype c = ctype::RED)
		:data{d}, p{_p}, left{l}, right{r}, color{c} {}
	Node(ctype c):color{c} {}
	sptr parent() {return p.lock();}
	int data;
	int count = 1;
	wptr p;
	sptr left, right;
	ctype color;
};


class RedBlackBST {
public:
	int length = 0;
	std::vector<int> get_data() {
		std::vector<int> v;
		get_data(root, v, 0);
		return std::move(v);
	}
	void get_data(sptr pos, std::vector<int> &v, int len) {
		if (pos == nil) {
			if (length == 0) length = len;
			else if (length != len) assert(false);
			return;
		}
		if (pos->color == ctype::BLACK) len++;
		get_data(pos->left, v, len);
		for (int i = 0; i < pos->count; i++)
			v.push_back(pos->data);
		get_data(pos->right, v, len);
	}
	RedBlackBST(): nil{new Node{ctype::BLACK}} {
		root = nil;
	}
	void insert(int d) {
		sptr y{nil}, x{root};
		while (x != nil) {
			y = x;
			if (d < x->data) {
				x = x->left;
			} else if (d > x->data) {
				x = x->right;
			} else {
				x->count++; return;
			}
		}
		sptr z{new Node{d, y, nil, nil, ctype::RED}};
		if (y == nil) root = z;
		else if (z->data < y->data) y->left = z;
		else y->right = z;
		insert_fixup(z);
	}

	void del(int k) {
		sptr y{nil}, x{root};
		while (x != nil) {
			y = x;
			if (k < x->data) x = x->left;
			else if (k > x->data) x = x->right;
			else break;
		}
		if (x != nil && !(--y->count)) del(y);
	}

	void del(sptr z) {
		sptr successor;
		sptr breaker; // the node that breaks the rule
		// the position of z will be replaced by breaker
		// So the breaker has two color (second_color and its original color)
		ctype second_color = z->color;
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
			// the position of successor now is replaced by breaker
		// So the breaker has two color (second_color and its original color)
			second_color = successor->color;
			breaker = successor->right;
			if (successor->parent() != z) {
				// if successor isn't adjacent to z
				transplant(successor, successor->right);
				successor->right = z->right;
				successor->right->p = successor;
			}
			transplant(z, successor);
			successor->left = z->left;
			successor->left->p = successor;
			successor->color = z->color;
		}
		if (second_color == ctype::BLACK)
			// we regard breaker has another "black" color,
			// which occupied the position of successor
			delete_fixup(breaker);
	}

private:
	void delete_fixup(sptr x) {
		// x has extra black color
		while (x != root && x->color == ctype::BLACK) {
		// If x->color == RED then it means x is a red-black node.
		// We could break the loop and set it to black
			sptr brother;
			if (x == x->parent()->left) {
			// x is leftson
				brother = x->parent()->right;
				if (brother->color == ctype::RED) {
				// Case 1: x's brother is red. It could transfer to Case 2/3/4.
					brother->color = ctype::BLACK;
					x->parent()->color = ctype::RED;
					left_rotate(x->parent());
					brother = x->parent()->right;
				}
				if (brother->left->color == ctype::BLACK 
					&& brother->right->color == ctype::BLACK) {
				// Case 2: black brother and black brotherson.
					brother->color = ctype::RED;
					x = x->parent();
				} else {
				// Case 3/4: black brother and one or two red brotherson.
					if (brother->right->color == ctype::BLACK) {
					// Case 3: black rightson and red leftson
						brother->left->color = ctype::BLACK;
						brother->color = ctype::RED;
						right_rotate(brother);
					}
					// Case 4: black brother and red left brotherson.
					brother = x->parent()->right;
					brother->color = x->parent()->color;
					x->parent()->color = ctype::BLACK;
					brother->right->color = ctype::BLACK;
					left_rotate(x->parent());
					x = root;
				}
			} else {
			// x is leftson, same as above clause.
				brother = x->parent()->left;
				if (brother->color == ctype::RED) {
				// Case 1: x's brother is red. It could transfer to Case 2/3/4.
					brother->color = ctype::BLACK;
					x->parent()->color = ctype::RED;
					right_rotate(x->parent());
					brother = x->parent()->left;
				}
				if (brother->left->color == ctype::BLACK 
					&& brother->right->color == ctype::BLACK) {
				// Case 2: black brother and black brotherson.
					brother->color = ctype::RED;
					x = x->parent();
				} else {
				// Case 3/4: black brother and one or two red son.
					if (brother->left->color == ctype::BLACK) {
					// Case 3: black leftson and red rightson
						brother->right->color = ctype::BLACK;
						brother->color = ctype::RED;
						left_rotate(brother);
					}
					// Case 4: black brother and red left brotherson.
					brother = x->parent()->left;
					brother->color = x->parent()->color;
					x->parent()->color = ctype::BLACK;
					brother->left->color = ctype::BLACK;
					right_rotate(x->parent());
					x = root;
				}
			}
		}
		x->color = ctype::BLACK;
	}

	sptr minimum(sptr x) {
		while (x->left != nil) x = x->left;
		return x;
	}

	// use subtree v to replace subtree u
	void transplant(sptr u, sptr v) {
		if (u->parent() == nil) root = v;
		else if (u == u->parent()->left) u->parent()->left = v;
		else u->parent()->right = v;
		v->p = u->parent();
	}

	void insert_fixup(sptr z) {
		while (z->parent()->color == ctype::RED) {
			if (z->parent() == z->parent()->parent()->left) {
				// Case 1:the uncle node is red
				sptr uncle{z->parent()->parent()->right};
				if (uncle->color == ctype::RED) {
					uncle->color = z->parent()->color = ctype::BLACK;
					z->parent()->parent()->color = ctype::RED;
					z = z->parent()->parent();
				} else {
				// Case 2/3:the uncle node of z is black
					if (z == z->parent()->right) {
					// Case 2: ... and z is rightson
						z = z->parent(); left_rotate(z);
					}
					// Case 3: ... and z is leftson
					z->parent()->color = ctype::BLACK;
					z->parent()->parent()->color = ctype::RED;
					right_rotate(z->parent()->parent());
				}
			} else {
			// same as clause with "right" and "left" exchanged
				// Case 1:the uncle node is red
				sptr uncle{z->parent()->parent()->left};
				if (uncle->color == ctype::RED) {
					uncle->color = z->parent()->color = ctype::BLACK;
					z->parent()->parent()->color = ctype::RED;
					z = z->parent()->parent();
				} else {
				// Case 2/3:the uncle node of z is black
					if (z == z->parent()->left) {
					// Case 2: ... and z is rightson
						z = z->parent(); right_rotate(z);
					}
					// Case 3: ... and z is leftson
					z->parent()->color = ctype::BLACK;
					z->parent()->parent()->color = ctype::RED;
					left_rotate(z->parent()->parent());
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
		y->right->p = x;
		// link x's parent to y
		y->p = x->p;
		if (x->parent() == nil) root = y;
		else if (x == x->parent()->left) x->parent()->left = y;
		else x->parent()->right = y;
		y->right = x;
		x->p = y;
	}

	void left_rotate(sptr x) {
		sptr y{x->right};
		// turn y's left subtree into x's right subtree
		x->right = y->left;
		y->left->p = x;
		// link x's parent to y
		y->p = x->p;
		if (x->parent() == nil) root = y;
		else if (x == x->parent()->left) x->parent()->left = y;
		else x->parent()->right = y;
		y->left = x;
		x->p = y;
	}
	sptr root, nil;
};
