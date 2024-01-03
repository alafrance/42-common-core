//
// Created by Alexis Lafrance on 11/17/21.
//

#ifndef FT_CONTAINERS_REDNWARTREE_HPP
#define FT_CONTAINERS_REDNWARTREE_HPP
#include "utility.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include "pair.hpp"

enum e_color {
	black, red
};
enum e_direction {
	left, right
};
namespace ft {
	template<typename T, typename U>
	// NODE
	struct node {
		ft::pair<const T, U> data;
		e_color color;
		node *left;
		node *right;
		node *parent;

		// CONSTRUCTOR
		node(pair<const T, U> &data): data(data) {
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->color = red;
		}

		~node() {}
	};

	template<typename T, typename U, typename Alloc = std::allocator<ft::pair<T, U> >, typename Compare = std::less<T> >
	class RNWARTree {
	public:
		// TYPEDEF
		typedef typename Alloc::template rebind<node<const T, U> >::other node_alloc_type;
		typedef node<const T, U> *nodePtr;
	// ---------------- ATTRIBUTES  ----------------
		// ---------------- SWAP (NEED FOR MAP AND SET)  ----------------
		void swap(RNWARTree &tree) {
			node_alloc_type _allocTmp = _alloc;
			nodePtr rootTmp = root;
			Compare _compTmp = _comp;

			_alloc = tree._alloc;
			root = tree.root;
			_comp = tree._comp;

			tree._alloc = _allocTmp;
			tree.root = rootTmp;
			tree._comp = _compTmp;
		}

	private:
		node_alloc_type _alloc;
		nodePtr root;
		Compare _comp;
	public:
		// ---------------- CANONICAL FORM ----------------
		RNWARTree() : _alloc(Alloc()), root(NULL), _comp(Compare()) {}

		explicit RNWARTree(ft::pair<T, U> pair) : _alloc(Alloc()),
												  root(_alloc.allocate(1)), _comp(Compare()) {
			_alloc.construct(root, node<T, U>(pair));
			root->color = black;
		}

		RNWARTree(RNWARTree const &tree) : _alloc(std::allocator<node<const T, U> >()), root(NULL), _comp(std::less<T>()) {
			*this = tree;
		}

		~RNWARTree() {
			deleteTree(root);
		}

		void copyTree(nodePtr node) {
			if (node == NULL)
				return;
			insert(node->data);
			copyTree(node->right);
			copyTree(node->left);
		}

		RNWARTree &operator=(RNWARTree const &tree) {
			deleteTree(root);
			copyTree(tree.root);
			return (*this);
		}
		// ---------------- UTILITY COPY / CREATE ----------------

		nodePtr createNode(ft::pair<const T, U> pair) {
			nodePtr tmp = _alloc.allocate(1);
			_alloc.construct(tmp, node<const T, U>(pair));
			return (tmp);
		}

		// ---------------- GETTER  ----------------
		nodePtr getRoot() const {
			return root;
		}

		// ---------------- HELPER ----------------

		nodePtr insert(ft::pair<T, U> pair) {
			return(insert(root, createNode(pair)));
		}

		void displayOrder() const {
			iter(root, &RNWARTree::displayNode);
		};

		void display() const {
			printHelper(root, "", true);
		}

		// ---------------- DISPLAY ----------------

		void postOrderDisplay(nodePtr node, int depth) const {
			if (node == NULL) {
				return;
			}
			displayTree(node->left, depth + 1);
			displayTree(node->right, depth + 1);
			std::cout << node->data << " ";
		}

		void printHelper(nodePtr root, std::string indent, bool last) const {
			if (root != NULL) {
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "   ";
				} else {
					std::cout << "L----";
					indent += "|  ";
				}
				if (root->color == red)
					std::cout << "\e[0;31m";
				else
					std::cout << "\e[0;37m";
				std::cout << root->data.first << "\e[0m" << ", val: " << root->data.second << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		void displayNode(nodePtr node) {
			std::cout << "color: " << node->color << ", data : " << node->data << std::endl;
		}

		void iter(nodePtr pRoot, void (RNWARTree<T, U, Alloc>::*fct)(nodePtr)) {
			if (pRoot == NULL)
				return;
			iter(pRoot->left, fct);
			(this->*fct)(pRoot);
			iter(pRoot->right, fct);
		};

		// ---------------- SEARCH ----------------

		nodePtr search_key(T key) {
			return (search_key(root, key));
		}

		nodePtr search_key(nodePtr node, T key) {
			nodePtr find = NULL;
			if (node == NULL)
				return NULL;
			if (key == node->data.first)
				return node;
			if (_comp(key, node->data.first))
				find = search_key(node->left, key);
			else
				find = search_key(node->right, key);
			return find;
		}

		nodePtr minimum() {
			return (minimum(root));
		}
		nodePtr maximum() {
			return (maximum(root));
		}

	private:
		nodePtr minimum(nodePtr node) {
			if (node == NULL)
				return (NULL);
			if (node->left == NULL)
				return (node);
			else
				return (minimum(node->left));
		}

		nodePtr maximum(nodePtr node) {
			if (node == NULL)
				return (NULL);
			if (node->right == NULL)
				return (node);
			else
				return (maximum(node->right));
		}

	public:

		// ---------------- INSERT  ----------------
		nodePtr insert(nodePtr node, nodePtr add) {
//			if (search_key(add->data.first)) {
//				std::cerr << "KEY UNIQUE : " << add->data.first << std::endl;
//				return (NULL);
//			}
			if (root == NULL) {
				root = add;
				root->color = black;
				return (add);
			}
			if (add == NULL || node == NULL)
				return (NULL);
			if (_comp(add->data.first, node->data.first)) {
				if (node->left == NULL) {
					node->left = add;
					node->left->parent = node;
					insertFix(node->left);
				} else
					insert(node->left, add);
			} else {
				if (node->right == NULL) {
					node->right = add;
					node->right->parent = node;
					insertFix(node->right);
				} else
					insert(node->right, add);
			}
			return (add);
		}

		// ---------------- INSERT UTILITIES ----------------
	private:
		void rotate(nodePtr node, e_direction direction) {
			if (node == NULL || node->parent == NULL)
				return;
			nodePtr gp = node->parent->parent;
			nodePtr p = node->parent;
			nodePtr *gpLink = NULL;
			if (gp)
				gpLink = (gp->left == p) ? &gp->left : &gp->right;
			if ((p->right == node && direction == right) ||
				(p->left == node && direction == left)) {
				return;
			}
			// ROTATE PARENT CHILD AND NODE CHILD LEFT
			if (direction == left) {
				p->right = node->left;
				if (node->left)
					node->left->parent = p;
				node->left = p;
			} else { // ROTATE PARENT CHILD AND NODE CHILD RIGHT
				p->left = node->right;
				if (node->right)
					node->right->parent = p;
				node->right = p;
			}
			// MODIFY POINTER OF GP AND MAKE NODE AS PARENT IF NECESSARY
			if (gp == NULL)
				root = node;
			else
				*gpLink = node;
			// MODIFY THE PARENT
			p->parent = node;
			node->parent = gp;
		}

		void insertFix(nodePtr node) {
			if (node == NULL)
				return;
			if (node->parent == NULL) {
				node->color = black;
				return;
			}
			if (node->parent->parent == NULL)
				return;
			e_direction gp_to_p_direction;
			while (node->parent->color == red) {
				if (node->parent == node->parent->parent->left) // CHOOSE GPLINK DIRECTION
					gp_to_p_direction = left;
				else
					gp_to_p_direction = right;
				// FIND THE GOOD UNCLE WITH THE GPLINK DIRECTION
				nodePtr uncle = (gp_to_p_direction == left) ? node->parent->parent->right : node->parent->parent->left;
				// CASE 1 UNCLE IS RED : MODIFY THE CHILD OF GRAND PARENT BLACK AND GRAND PARENT RED, AND GO TO GP
				if (uncle &&
					uncle->color == red) { // CASE IF UNCLE RED => COLOR BLACK PARENTS OF GP AND GP TO RED, GO TO GP
					node->parent->color = black;
					uncle->color = black;
					node->parent->parent->color = red;
					node = node->parent->parent;
				} else {
					// NO UNCLE RED OR NO UNCLE TRY TO ROTATE IF POSSIBLE
					if ((gp_to_p_direction == right && node == node->parent->left)
						|| (gp_to_p_direction == left && node == node->parent->right)) {
						nodePtr tmp = node->parent;
						rotate(node, gp_to_p_direction);
						node = tmp;
					}
					// MODIFY PARENT COLOR AND GRAND PARENT COLOR AND ROTATE
					if (node->parent)
						node->parent->color = black;
					if (node->parent && node->parent->parent)
						node->parent->parent->color = red;
					rotate(node->parent, (gp_to_p_direction == left) ? right : left);
				}
				// LOOK IF WE ARE INTO ROOT OR IF WE HAVE NULLPTR
				if (node == root || node == NULL || node->parent == NULL
					|| node->parent->parent == NULL) {
					root->color = black; // MAKE ROOT BLACK (FIRST PROPERTIES OF R-D-TREE)
					break;
				}
			}
		}

	public:

		// ---------------- DELETE  ----------------

		void deleteNode(T key) {
			deleteNode(search_key(key));
		}

		void ft_delete(nodePtr node) {
			_alloc.destroy(node);
			_alloc.deallocate(node,1);
			node = NULL;
		}

		void deleteTree(nodePtr node) {
			if (node == NULL) {
				return;
			}
			deleteTree(node->left);
			deleteTree(node->right);
			ft_delete(node);
			root = NULL;
		}

	public:
		void deleteNode(nodePtr node) {
			if (node == NULL)
				return;
			nodePtr nodeDeleteFix, nodeDeleteFixParent, nodeMin = NULL;
			e_color nodeMin_originalColor = node->color;
			if (node->left == NULL) {
				nodeDeleteFix = node->right;
				nodeDeleteFixParent = node->parent;
				transplant(node, node->right);
			} else if (node->right == NULL) {
				nodeDeleteFix = node->left;
				nodeDeleteFixParent = node->parent;
				transplant(node, node->left);
			} else {
				// CHANGE MINIMUM IN BRANCH RIGHT
				nodeMin = minimum(node->right);
				// STOCK ORIGINAL COLOR TO KNOW IF WE NEED TO
				// CALL DELETE FIX
				nodeMin_originalColor = nodeMin->color;
				nodeDeleteFix = nodeMin->right;
				// IF NODE MIN IS NOT CHILD OF NODE WE NEED TO REMOVE NODE MIN
				// AND MODIFY RIGHT NODEMIN TO NODE RIGHT AND PARENT NODE TO NODEMIN
				if (nodeMin->parent == node) {
					nodeDeleteFixParent = nodeMin;
				} else {
					nodeDeleteFixParent = nodeMin->parent;
					transplant(nodeMin, nodeMin->right);
					nodeMin->right = node->right;
					nodeMin->right->parent = nodeMin;
				}
				// WE CAN, FINALLY, REMOVE NODE AND PUT NODE MIN
				// AND WE CAN MODIFY LEFT NODE MIN TO OLD NODE LEFT AND NODE LEFT CHANGE PARENT
				transplant(node, nodeMin);
				nodeMin->left = node->left;
				nodeMin->left->parent = nodeMin;
				nodeMin->color = node->color;
			}
			// WE CAN DELETE THE NODE AND LOOK IF IS NECESSARY TO CALL DELETE FIX
			if (nodeMin_originalColor == black && nodeDeleteFixParent != NULL)
				deleteFix(nodeDeleteFix, nodeDeleteFixParent);
			if (root)
				root->color = black;
			ft_delete(node);
		}

	private:
		// ---------------- DELETE UTILITIES  ----------------

		void deleteFix(nodePtr node, nodePtr nodeParent) {
			nodePtr nodeTmp;
			while (node != root && nodeParent != NULL && node_is_black(node)) {
				e_direction direction = (node == nodeParent->left) ? left : right;
				nodeTmp = (direction == left) ? nodeParent->right : nodeParent->left;
				if (nodeTmp && nodeTmp->color == red) {
					nodeTmp->color = black;
					nodeParent->color = red;
					rotate(nodeTmp, direction);
					nodeTmp = (direction == left) ? nodeParent->right : nodeParent->left;
				}
				if (nodeTmp && node_is_black(nodeTmp->left) && node_is_black(nodeTmp->right)) {
					nodeTmp->color = red;
					node = nodeParent;
					nodeParent = nodeParent->parent;
				} else {
					if (nodeTmp && ((direction == left && node_is_black(nodeTmp->right))
									|| (direction == right && node_is_black(nodeTmp->left)))) { // DIFF HERE
						nodeTmp->color = red;
						if (direction == left && nodeTmp->left) {
							nodeTmp->left->color = black;
							rotate(nodeTmp->left, right); // DIFF HERE
						} else if (direction == right && nodeTmp->right) {
							nodeTmp->right->color = black;
							rotate(nodeTmp->right, left); // DIFF HERE
						}
						nodeTmp = (direction == left) ? nodeParent->right : nodeParent->left; // DIFF HERE
					}
					if (nodeTmp)
						nodeTmp->color = nodeParent->color;
					nodeParent->color = black;
					if (nodeTmp && direction == left && nodeTmp->right)
						nodeTmp->right->color = black;
					else if (nodeTmp && direction == right && nodeTmp->left)
						nodeTmp->left->color = black;
					rotate((direction == left) ? nodeParent->right : nodeParent->left, direction);
					node = root;
					nodeParent = NULL;
				}
			}
			if (node)
				node->color = black;
		}

		bool node_is_black(nodePtr node) {
			return (node == NULL || (node != NULL && node->color == black));
		}

		void transplant(nodePtr uncle, nodePtr node) {
			if (uncle == NULL)
				std::cerr << "Transplant no uncle or uncle invalid" << std::endl;
			else if (uncle->parent == NULL)
				root = node;
			else if (uncle == uncle->parent->left)
				uncle->parent->left = node;
			else if (uncle == uncle->parent->right)
				uncle->parent->right = node;
			if (node != NULL)
				node->parent = uncle->parent;
		}
	};
};
#endif //FT_CONTAINERS_REDNWARTREE_HPP
