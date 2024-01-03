//
// Created by Alexis Lafrance on 11/9/21.
//

#ifndef FT_CONTAINERS_PAIR_HPP
#define FT_CONTAINERS_PAIR_HPP
#include <iostream>
namespace ft {
	template<typename T1, typename T2>
	class pair
	{
	public:
		pair(): first(), second() {};

		template<typename V, typename W>
		pair(const pair<V, W> &pr) : first(pr.first), second(pr.second) {}

		pair(T1 const &first, T2 const &second) : first(first), second(second) {}

		pair& operator=(pair const& p) {
			first = p.first;
			second = p.second;
			return *this;
		}

		bool operator==(ft::pair<T1, T2> const &inst) {
			return this->first == inst.first && this->second == inst.second;
		}

		bool operator!=(ft::pair<T1, T2> &inst) {
			return !(*this == inst);
		}

		bool operator<(ft::pair<T1, T2> &inst) {
			return this->first < inst.first ||
				   (!(inst.first < this->first) && this->second < inst.second);
		}

		bool operator<=(ft::pair<T1, T2> &inst) {
			return !(inst < *this);
		}

		bool operator>(ft::pair<T1, T2> &inst) {
			return inst < *this;
		}

		bool operator>=(ft::pair<T1, T2> &inst) {
			return !(*this < inst);
		}

	public:
		T1 first;
		T2 second;
	};

	template<typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return pair<T1, T2>(x, y);
	}
}
#endif //FT_CONTAINERS_PAIR_HPP
