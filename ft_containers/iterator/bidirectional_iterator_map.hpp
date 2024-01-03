//
// Created by Alexis Lafrance on 11/16/21.
//

#ifndef FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP
#define FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP
#include "../RedNWARTree.hpp"
#include "iterator.hpp"

class bidirectional_iterator : virtual public iterators_traits<iterator<bidirectional_iterator_tag, pair<const Key, T> > > {

typedef node<const Key, T> * nodePtr;
/* -------  ATTRIBUTES ------- */
protected:
nodePtr _node;
typename bidirectional_iterator::pointer _p;
public:
/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */

/* -------  CANONICAL FORM ------- */
bidirectional_iterator() : _node(NULL), _p(0) {};

~bidirectional_iterator() {};

bidirectional_iterator(nodePtr nodeCopy): _node(nodeCopy) {
		modifyValueType();
}

bidirectional_iterator(bidirectional_iterator const &src) {
*this = src;
}

bidirectional_iterator &operator=(bidirectional_iterator const &inst) {
	_p = inst._p;
	_node = inst._node;
	return (*this);
}

/* -------  OPERATOR OVERLOAD ------- */

/* 		-------  RELATIONAL ------- */

bool operator==(bidirectional_iterator inst) const {
	return (_p == inst._p);
}

bool operator!=(bidirectional_iterator inst) const {
	return (_p != inst._p);
}

/* 		------- (INCRE/DECRE)MENT ------- */
bidirectional_iterator &operator--() { //--a
	if (_node == NULL)
		return (*this);
	if (_node->left == NULL) {
		nodePtr parent = _node->parent;
		while (parent && _node == parent->left) {
			_node = parent;
			parent = parent->parent;
		}
		_node = parent;
		modifyValueType();
		return (*this);
	} else {
		_node = _node->left;
		while (_node && _node->right != NULL)
			_node = _node->right;
		modifyValueType();
	}
	return (*this);
}

bidirectional_iterator operator--(int) {//a--
	bidirectional_iterator tmp(*this);
	operator--();
	return (tmp);
}

bidirectional_iterator &operator++() { //++a
	if (_node == NULL)
		return (*this);
	if (_node->right == NULL) {
		nodePtr parent = _node->parent;
		while (parent && _node == parent->right) {
			_node = parent;
			parent = parent->parent;
		}
		_node = parent;
		modifyValueType();
		return (*this);
	} else {
		_node = _node->right;
		while (_node && _node->left != NULL)
			_node = _node->left;
		modifyValueType();
	}
	return (*this);
}

bidirectional_iterator operator++(int) {//a++
	bidirectional_iterator tmp(*this);
	operator++();
	return (tmp);
}

/* 		------- REFERENCE / DEREFERENCE ------- */
typename bidirectional_iterator::reference operator*() {
	return *_p;
}

typename bidirectional_iterator::pointer operator->() {
	return _p;
}
private:
/* 		------- UTILITY ------- */
void modifyValueType() {
	if (_node)
		_p = &_node->data;
	else
		_p = NULL;
}
};
#endif //FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP
