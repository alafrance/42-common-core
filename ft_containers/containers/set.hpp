//
// Created by Alexis Lafrance on 12/2/21.
//

#ifndef FT_CONTAINERS_SET_HPP
#define FT_CONTAINERS_SET_HPP
//
// Created by Alexis Lafrance on 11/16/21.
//
#include <iostream>
#include "../iterator/iterator.hpp"
#include "../metafunctions.hpp"
#include "../pair.hpp"
#include "../RedNWARTree.hpp"

namespace ft {
	template<class T, class Compare = std::less<T>, class Alloc = std::allocator<T > >
	class set : public iterators_traits<iterator<bidirectional_iterator_tag, T> > {
		/* -------  ITERATOR ------- */
		#include "../iterator/bidirectional_iterator_set.hpp"
	public:
		/* -------  TYPEDEF ------- */

		typedef T value_type;
		typedef T key_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename iterators_traits<iterator<bidirectional_iterator_tag, T> >::difference_type difference_type;
		typedef size_t size_type;
		typedef bidirectional_iterator iterator;
		typedef bidirectional_iterator const_iterator;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;

		/* -------  ATTRIBUTES ------- */
	protected:
		typedef node<const  T, T> * nodePtr;
		size_type _size;
		RNWARTree<T, T, Alloc> tree;
		Alloc _alloc;
		Compare _comp;
		nodePtr nodeRend;
	public:
		/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */
		explicit set(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : _size(0),_alloc(alloc), _comp(comp), nodeRend(NULL) {
		}

		template<class InputIterator>
		set(typename enable_if<(is_same<InputIterator, pointer>::value
								|| is_same<InputIterator, iterator>::value), InputIterator>::type first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()): _size(0),_alloc(alloc), _comp(comp), nodeRend(NULL) {
			insert(first, last);
		}

		set(const set &x) : _size(x._size),tree(x.tree), _alloc(x._alloc), _comp(x._comp), nodeRend(NULL) {
		}

		~set() {
			if (nodeRend) {
				tree.ft_delete(nodeRend);
				nodeRend = NULL;
			}
		}

		/* ------- ITERATORS ------- */

		iterator begin() {
			return (tree.minimum());
		}

		const_iterator begin() const {
			return (tree.minimum());
		}

		iterator end() {
			return (NULL);
		}

		const_iterator end() const {
			return (NULL);
		}

		reverse_iterator rbegin() {
			if (nodeRend)
				tree.ft_delete(nodeRend);
			nodeRend = tree.createNode(ft::pair<T, T>(0, 0));
			nodeRend->parent = tree.maximum();
			iterator it(nodeRend);
			return (reverse_iterator(it));
		}

		const_reverse_iterator rbegin() const {
			nodePtr node = tree.createNode(ft::pair<T, T>(0, 0));
			node->parent = tree.maximum();
			iterator it(node);
			return (reverse_iterator(it));
		}

		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const {
			return (reverse_iterator(begin()));
		}

		/* ------- CAPACITY ------- */

		bool empty() const {
			return (tree.getRoot() == NULL);
		}

		size_type size() const {
			return (_size);
		}

		size_type max_size() const {
			return (std::numeric_limits<size_t>::max() / sizeof(node<T, T>));
		}

		/* ------- MODIFIERS ------- */


		pair<iterator,bool> insert(const value_type& val) {
			nodePtr node = tree.search_key(val);

			if (node)
				return (make_pair(node, false));
			else {
				_size++;
				return (make_pair(tree.insert(make_pair(val, val)), true));
			}
		}

		iterator insert(iterator position, const value_type& val) {
			(void)position;
			nodePtr node = tree.search_key(val);
			if (node)
				return (node);
			_size++;
			return(tree.insert(make_pair(val, val)));
		}

		template <class InputIterator>
		void insert(InputIterator first, typename enable_if<(ft::is_same<InputIterator, typename bidirectional_iterator::pointer>::value || is_same<InputIterator, bidirectional_iterator>::value) && !ft::is_integral<InputIterator>::value, InputIterator>::type last) {
			for (InputIterator i = first; i != last; i++) {
				if (!tree.search_key(*i)) {
					nodePtr node = tree.search_key(*i);
					if (!node) {
						_size++;
						tree.insert(make_pair(*i, *i));
					}
				}
			}
		}

		void erase (iterator position) {
			if (position == NULL)
				return ;
			nodePtr node = tree.search_key(*position);

			if (node) {
				_size--;
				tree.deleteNode(node);
			}
		}

		size_type erase (const value_type& k) {
			nodePtr node = tree.search_key(k);

			if (node) {
				tree.deleteNode(node);
				_size--;
				return (1);
			}
			return (0);
		}

		void erase (iterator first, iterator last) {
			iterator it = first;
			while (it != last) {
				iterator tmp = it;
				tmp++;
				erase(it);
				it = tmp;
			}
		}

		void clear() {
			tree.deleteTree(tree.getRoot());
			_size = 0;
		}

		void swap (set& x) {
			tree.swap(x.tree);
			size_type _sizeTmp = _size;
			Alloc _allocTmp = _alloc;
			Compare _compTmp = _comp;

			_size = x._size;
			_alloc = x._alloc;
			_comp = x._comp;

			x._size = _sizeTmp;
			x._alloc = _allocTmp;
			x._comp = _compTmp;
		}

		/* ------- OBSERVERS ------- */
		class value_compare {
		protected:
			typedef T value_type;
			Compare comp;
		public:
			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x, y);
			}

			value_compare (Compare c) : comp(c) {}
		};

		key_compare key_comp() const {
			return (_comp);
		}

		value_compare value_comp() const {
			return (value_compare(_comp));
		}


		/* ------- OPERATIONS ------- */
		iterator find (const value_type& k) {
			return (tree.search_key(k));
		}

		const_iterator find (const value_type& k) const {
			return (tree.search_key(k));
		}

		size_type count (const value_type& k) const {
			return ((tree.search_key(k) == NULL) ? 0 : 1);
		}

		iterator lower_bound(const value_type& k) {
			iterator it = begin();
			while (it != end() && _comp(*it, k))
				it++;
			return (it);
		}

		const_iterator lower_bound(const value_type& k) const {
			const_iterator it = begin();
			while (it != end() && _comp(*it, k))
				it++;
			return (it);
		}

		iterator upper_bound(const value_type& k) {
			iterator it = begin();
			while (it != end() && (_comp(*it, k) || *it == k))
				it++;
			return (it);
		}

		const_iterator upper_bound (const value_type& k) const {
			const_iterator it = begin();
			while (it != end() && (_comp(*it, k) || *it == k))
				it++;
			return (it);
		}

		pair<const_iterator,const_iterator>    equal_range(const value_type& k) const {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		pair<iterator,iterator>    equal_range(const value_type& k) {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		/* ------- GETTERS ------- */
		allocator_type get_allocator() const {
			return (_alloc);
		}

	};
}
#endif //FT_CONTAINERS_SET_HPP
