//
// Created by Alexis Lafrance on 11/9/21.
//

#ifndef FT_CONTAINERS_METAFUNCTIONS_HPP
#define FT_CONTAINERS_METAFUNCTIONS_HPP
#include <iostream>
namespace ft{
	template <class U, class V>
	// ----- IS SAME -----
	struct is_same {
		static const bool value = false;
	};

	template <class U>
	struct is_same<U, U> {
		static const bool value = true;
	};

	template <bool b, typename Type>
	struct enable_if {
		typedef Type type;
	};

	template<class Type>
	struct enable_if<false, Type> {

	};

	// ----- TRUE AND FALSE TYPE -----
	struct false_type {
		static const bool value = false;
		typedef false_type type;

		operator bool() { return false; }
	};

	struct true_type {
		static const bool value = true;
		typedef true_type type;
		operator bool() { return true; }
	};

	template<typename T>
	struct is_integral : false_type {};
	template<>
	struct is_integral<bool>: true_type {};
	template<>
	struct is_integral<char>: true_type {};
	template<>
	struct is_integral<char16_t>: true_type {};
	template<>
	struct is_integral<char32_t>: true_type {};
	template<>
	struct is_integral<wchar_t>: true_type {};
	template<>
	struct is_integral<signed char>: true_type {};
	template<>
	struct is_integral<short int>: true_type {};
	template<>
	struct is_integral<int>: true_type {};
	template<>
	struct is_integral<long int>: true_type {};
	template<>
	struct is_integral<long long int>: true_type {};
	template<>
	struct is_integral<unsigned char>: true_type {};
	template<>
	struct is_integral<unsigned short int>: true_type {};
	template<>
	struct is_integral<unsigned int>: true_type {};
	template<>
	struct is_integral<unsigned long int>: true_type {};
	template<>
	struct is_integral<unsigned long long int>: true_type {};

}

#endif //FT_CONTAINERS_METAFUNCTIONS_HPP
