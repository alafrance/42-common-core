//
// Created by Alexis Lafrance on 11/9/21.
//

#include <gtest/gtest.h>
#include "../ft_containers/metafunctions/is_integral.hpp"
//#include "../ft_containers/vector.hpp"

//class MetaFunctions: public ::testing::Test{
//public:
//	class A {};
//	template<typename T>
//	void testIntegralFundamentalsTypes(T a) {
//		(void)a;
//		bool b = ft::is_integral<T>::value;
//		EXPECT_EQ(b, true);
//	}
//};
//
//TEST(MetaFunctionsWithoutFixture, TestEnableIfWithSimplesConditions) {
//	class A {};
//	ft::enable_if<ft::is_integral<int>::value, int>::type a;
//	(void)a;
//	ft::enable_if<!ft::is_integral<A>::value, int>::type c;
//	(void)c;
//	ft::enable_if<!ft::is_integral<A*>::value, int>::type d;
//	(void)d;
//	ft::enable_if<!ft::is_integral<int*>::value, int>::type e;
//	(void)e;
//	SUCCEED();
//}
//
//
//bool fctEqual(int i, int j) {
//	return (i == j);
//}
//
//TEST(MetaFunctionsWithoutFixture, EqualFunctionsWithIteratorAndString) {
//	int myints[] = {20, 40, 60, 80, 100};
//	int myints2[] = {20, 40, 60, 82, 100};
//
//	std::vector<int> myvector(myints, myints + 5);
//
//	EXPECT_EQ(ft::equal(myvector.begin(), myvector.end(), myints), true);
//	EXPECT_EQ(ft::equal(myvector.begin(), myvector.end(), myints, fctEqual), true);
//	EXPECT_EQ(ft::equal(myvector.begin(), myvector.end(), myints2), false);
//}
//
//bool mycomp (char c1, char c2) { return std::tolower(c1)<std::tolower(c2); }
//
//TEST(MetaFunctionsWithoutFixture, LexicographicalCompareTestCplusplusreference) {
//	char foo[]="Apple";
//	char bar[]="apartment";
//
//	EXPECT_EQ(ft::lexicographical_compare(foo,foo+5,bar,bar+9), true);
//	EXPECT_EQ(ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp), false);
//
//	char foo2[]="Apple";
//	char bar2[]="apple";
//	EXPECT_EQ(ft::lexicographical_compare(foo2,foo2+5,bar2,bar2+5), true);
//	EXPECT_EQ(ft::lexicographical_compare(foo2,foo2+5,bar2,bar2+5,mycomp), false);
//
//	char foo3[]="geeksforgeeks";
//	char bar3[]="Indeed";
//	EXPECT_EQ(ft::lexicographical_compare(foo3,foo3+5,bar3,bar3+3), false); // false
//	EXPECT_EQ(ft::lexicographical_compare(foo3,foo3+5,bar3,bar3+3,mycomp), true); // false
//}
//
//TEST_F(MetaFunctions, TestValueTypeIsTrueWithFundamentalTypes) {
//	unsigned char a = 0;
//	testIntegralFundamentalsTypes(a);
//	bool b = false;
//	testIntegralFundamentalsTypes(b);
//	char c = 0;
//	testIntegralFundamentalsTypes(c);
//	char16_t d = 0;
//	testIntegralFundamentalsTypes(d);
//	char32_t e = 0;
//	testIntegralFundamentalsTypes(e);
//	wchar_t f = 0;
//	testIntegralFundamentalsTypes(f);
//	signed char g = 0;
//	testIntegralFundamentalsTypes(g);
//	short int h = 0;
//	testIntegralFundamentalsTypes(h);
//	int i = 0;
//	testIntegralFundamentalsTypes(i);
//	long int j = 0;
//	testIntegralFundamentalsTypes(j);
//	long long int k = 0;
//	testIntegralFundamentalsTypes(k);
//	unsigned short int l = 0;
//	testIntegralFundamentalsTypes(l);
//	unsigned int m = 0;
//	testIntegralFundamentalsTypes(m);
//	unsigned long int n = 0;
//	testIntegralFundamentalsTypes(n);
//	unsigned long long int o = 0;
//	testIntegralFundamentalsTypes(o);
//}