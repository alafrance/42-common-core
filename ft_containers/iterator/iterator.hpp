//
// Created by Alexis Lafrance on 11/4/21.
//

#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP
#include <cstddef>
#include <iostream>
namespace ft {
	// TODO Add iterators_traits
	struct random_access_iterator_tag {
	};
	struct bidirectional_iterator_tag {
	};
	template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T *, typename Reference = T &>
	struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};
	template<typename Iterator>
	struct iterators_traits {
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};
	template<typename T>
	struct iterators_traits<T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef random_access_iterator_tag iterator_category;
	};
	template<typename T>
	struct iterators_traits<const T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef random_access_iterator_tag iterator_category;
	};

	/* ----------------------------------------------------------------
						REVERSE ITERATOR
	---------------------------------------------------------------- */
	template<typename Iterator>
	class reverse_iterator : public iterators_traits<Iterator> {
	public:
		typedef Iterator iterator_type;
		typedef typename iterators_traits<Iterator>::reference reference;
		typedef typename iterators_traits<Iterator>::difference_type difference_type;
		typedef typename iterators_traits<Iterator>::pointer pointer;

		reverse_iterator() : current() {}

		~reverse_iterator() {}

		explicit reverse_iterator(Iterator it) : current(it) {}

		reverse_iterator(const reverse_iterator<Iterator> &rev_it) : current(rev_it.current) {}

		Iterator base() const {
			return (current);
		}
		reference operator*() const {
			Iterator tmp(current);
			return (*--tmp);
		}

		// ******* OPERATOR + *******
		reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(current - n);
		}

		reverse_iterator &operator++() { //++a
			--current;
			return (*this);
		}

		reverse_iterator operator++(int) {//a++
			reverse_iterator<Iterator> tmp(current);
			current--;
			return (tmp);
		}

		reverse_iterator &operator+=(difference_type n) {
			current -= n;
			return (*this);
		}

		// ******* OPERATOR - *******
		reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(current + n);
		}

		reverse_iterator &operator--() { //--a
			++current;
			return (*this);
		}

		reverse_iterator operator--(int) {//a--
			reverse_iterator<Iterator> tmp(current);
			current++;
			return (tmp);
		}

		reverse_iterator &operator-=(difference_type n) {
			current += n;
			return (*this);
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[](difference_type n) const {
			return *(*this + n);
		}

		friend bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
			return rhs.current != lhs.current;
		}

		friend bool operator==(const reverse_iterator<Iterator> &lhs,
							   const reverse_iterator<Iterator> &rhs) {
			return (rhs.current == lhs.current);
		}

		friend bool operator<(const reverse_iterator<Iterator> &lhs,
							  const reverse_iterator<Iterator> &rhs) {
			return (rhs.current < lhs.current);
		}

		friend bool operator<=(const reverse_iterator<Iterator> &lhs,
							   const reverse_iterator<Iterator> &rhs) {
			return (rhs.current <= lhs.current);
		}

		friend bool operator>(const reverse_iterator<Iterator> &lhs,
							  const reverse_iterator<Iterator> &rhs) {
			return (rhs.current > lhs.current);
		}

		friend bool operator>=(const reverse_iterator<Iterator> &lhs,
							   const reverse_iterator<Iterator> &rhs) {
			return (rhs.current >= lhs.current);
		}

		friend reverse_iterator<Iterator> operator+(difference_type n, const reverse_iterator<Iterator> &rev_it) {
			return (rev_it.current - n);
		}

		friend difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
			return (rhs.current - lhs.current);
		}

	protected:
		Iterator current;
	};
}
#endif //FT_CONTAINERS_ITERATOR_HPP
