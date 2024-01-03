//
// Created by Alexis Lafrance on 11/16/21.
//

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

		/* ----------------------------------------------------------------
								RANDOM ACCESS ITERATOR
		---------------------------------------------------------------- */
class random_access_iterator : virtual public iterators_traits< iterator<random_access_iterator_tag, T> > {
public:
	/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */

	/* -------  CANONICAL FORM ------- */
	random_access_iterator(): _p(0) {};

	~random_access_iterator() {};

	random_access_iterator(typename random_access_iterator::pointer a) {
		_p = a;
	}

	random_access_iterator(random_access_iterator const &src) {
	*this = src;
	}

	random_access_iterator &operator=(random_access_iterator const &inst) {
		_p = inst._p;
		return (*this);
	}
	/* -------  OPERATOR OVERLOAD ------- */

	/* 		-------  RELATIONAL ------- */

	bool operator==(random_access_iterator inst) const{
		return (_p == inst._p);
	}

	bool operator!=(random_access_iterator inst) const{
		return (_p != inst._p);
	}

	bool operator<(random_access_iterator inst) const{
		return (_p < inst._p);
	}

	bool operator<=(random_access_iterator inst) const{
		return (_p <= inst._p);
	}

	bool operator>(random_access_iterator inst) const{
		return (_p > inst._p);
	}

	bool operator>=(random_access_iterator inst) const{
		return (_p >= inst._p);
	}


	/* 		------- (INCRE/DECRE)MENT ------- */
	random_access_iterator &operator--() { //--a
		_p--;
		return (*this);
	}

	random_access_iterator operator--(int) {//a--
		random_access_iterator tmp(*this);
		this->_p--;
		return (tmp);
	}

	random_access_iterator &operator++() { //--a
		_p++;
		return (*this);
	}

	random_access_iterator operator++(int) {//a--
		random_access_iterator tmp(*this);
		this->_p++;
		return (tmp);
	}

	/* 		------- REFERENCE / DEREFERENCE ------- */
	typename random_access_iterator::reference operator* () const{
		return *_p;
	}

	typename random_access_iterator::pointer operator-> () const {
		return _p;
	}

	/* 		------- ARITHMETIC arithmetic ------- */
	friend random_access_iterator operator+ (typename random_access_iterator::difference_type a, random_access_iterator const& rhs) {
		return rhs._p + a;
	}
	random_access_iterator operator+ (typename random_access_iterator::difference_type a) const{
		return _p + a;
	}

	random_access_iterator operator- (typename random_access_iterator::difference_type a) const{
		return _p - a;
	}

	typename random_access_iterator::difference_type operator- (random_access_iterator it) const{
		return _p - it._p;
	}

	random_access_iterator operator+= (typename random_access_iterator::difference_type a){
		_p += a;
		return (*this);
	}

	random_access_iterator operator-= (typename random_access_iterator::difference_type a){
		_p -= a;
		return (*this);
	}

	typename random_access_iterator::value_type operator[] (typename random_access_iterator::difference_type a) const{
		return (_p[a]);
	}

	protected:
	typename random_access_iterator::pointer _p;
};

#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
