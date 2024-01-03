//
// Created by Alexis Lafrance on 10/8/21.
//
#include <gtest/gtest.h>
#include "../ft_containers/containers/vector.hpp"
#include <vector>
#include <array>
#include <deque>

using namespace ::testing;

class MyVectorTestEmpty: public Test {
public:
	ft::vector<int> myvector;
	std::vector<int> vector;
};


template<typename T>
void testContentOfVector(T content, size_t size, ft::vector<T> a) {
	size_t count = 0;
	T *array;
	if (std::is_integral<T>::value)
		array = new T[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = content;
	for (typename ft::vector<T>::iterator it = a.begin(); it < a.end(); it++) {
		if (count > size)
			break;
		EXPECT_EQ(*it, array[count]);
		count++;
	}
	EXPECT_EQ(count, size);
	if (std::is_integral<T>::value)
		delete[] array;
}

template<typename T>
void testContentOfVector(T content, size_t size) {
	size_t count = 0;
	ft::vector<T> a(size, content);
	T *array = nullptr;
	if (std::is_integral<T>::value)
		array = new T[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = content;
	for (typename ft::vector<T>::iterator it = a.begin(); it < a.end(); it++) {
		if (count > size)
			break;
		EXPECT_EQ(*it, array[count]);
		count++;
	}
	EXPECT_EQ(count, size);
	if (std::is_integral<T>::value)
		delete[] array;
	if (size != 0)
		EXPECT_FALSE(a.empty());
	else
		EXPECT_TRUE(a.empty());
}

//TODO: -Deep copy operator=
//		-SIZE=0 et capacity=? quand tu clear et apres utilise les getters

TEST(MyVector, ConstructorAndOperatorEqualTestWithDifferentsTypes) {

	ft::vector<int> g;

	EXPECT_EQ(g.empty(), true);
	EXPECT_EQ(g.size(), (size_t)0);
	EXPECT_EQ(g.capacity(), (size_t)0);

	size_t size_a = 1000;
	ft::vector<char> a(size_a, 'b');
	testContentOfVector('b', size_a, a);

	const ft::vector<char>& c(a);
	EXPECT_EQ(a, c);
	const ft::vector<char>& d = a;
	EXPECT_EQ(a, d);
	testContentOfVector(1, 4200);
	testContentOfVector("blablou", 0);
	testContentOfVector(true, 4200);
	testContentOfVector(static_cast<unsigned long long int>(199), 100);
	ft::vector<std::string> testVec(2, "coucou");
	EXPECT_EQ(static_cast<std::string>(*testVec.begin()), "coucou");
	std::string end = *(testVec.end() - 1);
	EXPECT_EQ(end, "coucou");
	EXPECT_NE(*testVec.end(), "coucou");

	int myints[] = {1, 2, 3, 4};
	ft::vector<int> john(myints, myints + 5);
	std::deque<int> Deque(2, 4);
}


// VECTOR TEST (NOT MINE)
#include <gtest/gtest.h>
//
TEST(VectorTest, ReverseIterator)
{
	ft::vector<int> vector;  // three ints with a value of 100
	std::vector<int> svector;         // three ints with a value of 100
	for (int i = 0; i < 10000; ++i)
	{
		vector.push_back(i);
		svector.push_back(i);
		vector.push_back(i);
		svector.push_back(i);
	}
	ft::vector<int>::reverse_iterator rit = vector.rbegin();
	std::vector<int>::reverse_iterator srit = svector.rbegin();
	int r = rit[10];
	int sr = srit[10];
	EXPECT_EQ(r, sr);

	EXPECT_EQ(*(rit - 5), *(srit - 5));
	EXPECT_EQ(*(rit + 205), *(srit + 205));
	while (rit != vector.rend())
		EXPECT_EQ(*srit++, *rit++);
	int r2 = rit[-10];
	int sr2 = srit[-10];
	EXPECT_EQ(r2, sr2);
	EXPECT_EQ(rit.base(), vector.begin());

	EXPECT_EQ(*(rit -= 5), *(srit -= 5));
	EXPECT_EQ(*rit--, *srit--);
	EXPECT_EQ(*--rit, *--srit);
	EXPECT_EQ(rit, rit);
	EXPECT_FALSE(rit < rit);
	EXPECT_TRUE(rit <= ++rit);
	EXPECT_TRUE(rit < (rit + 1));
	EXPECT_TRUE(rit > (rit - 1));
	EXPECT_FALSE(rit != rit);
	EXPECT_TRUE(rit != (rit + 1));
}
TEST(VectorTest, ReverseConstIterator)
{
	ft::vector<int> vector;  // three ints with a value of 100
	std::vector<int> svector;         // three ints with a value of 100
	for (int i = 0; i < 10000; ++i)
	{
		vector.push_back(i);
		svector.push_back(i);
		vector.push_back(i);
		svector.push_back(i);
	}
	ft::vector<int>::const_reverse_iterator rit;
	ft::vector<int>::const_reverse_iterator rit2(rit);
	std::vector<int>::const_reverse_iterator srit;

	srit = svector.rbegin();
	rit = vector.rbegin();
	while (rit != vector.rend())
	{
		// *rit += 5;
		EXPECT_EQ(*srit++, *rit++);
	}
	rit2 = vector.rbegin();
	rit = rit2;
	// rit2 = rit;
}

TEST(VectorTest, ConstIterator)
{
	ft::vector<int> vector(3, 100);  // three ints with a value of 100
	ft::vector<int>::const_iterator it;
	ft::vector<int>::const_iterator it3(it);
	ft::vector<int>::iterator it2;

	for (it = vector.begin(); it != vector.end(); ++it)
	{
		// *it += 5;
	}
	it2 = --vector.end();
	it = it2;
	it3 = it2;
	// it2 = it;
}
//
TEST(VectorTest, Glagan)
{
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	std::vector<int> stdvector;
	std::vector<int>::iterator sit;

	it = myvector.end();
	sit = stdvector.end();
	for (int i = 0; i < 20; ++i)
	{
		it = myvector.insert(it, i);
		sit = stdvector.insert(sit, i);
	}
	EXPECT_EQ(myvector.back(), *(--(myvector.end())));
}

TEST(VectorTest, IteratorOP1)
{
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	std::vector<int> stdvector;
	std::vector<int>::iterator stdit;

	for (int i = 0; i < 20; ++i)
	{
		myvector.push_back(i);
		stdvector.push_back(i);
	}
	EXPECT_EQ(myvector.front(), stdvector.front());
	EXPECT_EQ(myvector.back(), stdvector.back());
	EXPECT_EQ(myvector.size(), stdvector.size());

	it = myvector.begin();
	stdit = stdvector.begin();
	EXPECT_EQ(*it, *stdit);
	it += 10;
	stdit += 10;
	EXPECT_EQ(*it, *stdit);
	it -= 5;
	stdit -= 5;
	EXPECT_EQ(*it, *stdit);
	it -= 5;
	stdit -= 5;
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(*(it + 10), *(stdit + 10));
	EXPECT_EQ(it[10], stdit[10]);
}
//
TEST(VectorTest, IteratorOP2)
{
	ft::vector<std::pair<int, int> > myvector2;
	ft::vector<std::pair<int, int> >::iterator it2;
	std::vector<std::pair<int, int> > stdvector2;
	std::vector<std::pair<int, int> >::iterator stdit2;

	std::pair<int, int> p(1, 2);
	myvector2.push_back(p);
	stdvector2.push_back(p);
	it2 = myvector2.begin();
	stdit2 = stdvector2.begin();
	EXPECT_EQ(it2->first, stdit2->first);
	EXPECT_EQ(it2->second, stdit2->second);
}
TEST(VectorTest, IteratorOP3)
{
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	ft::vector<int>::const_iterator cit;
	std::vector<int> stdvector;
	std::vector<int>::iterator stdit;
	std::vector<int>::const_iterator cstdit;

	for (int i = 0; i < 10; ++i)
	{
		myvector.push_back(i);
		stdvector.push_back(i);
	}
	it = myvector.begin();
	stdit = stdvector.begin();
	cit = myvector.begin();
	cstdit = stdvector.begin();
	EXPECT_EQ(*(5 + it), *(5 + stdit));
	EXPECT_EQ(*(5 + cit), *(5 + cstdit));
	EXPECT_EQ(cit, it);
	EXPECT_EQ(it, cit);
}

TEST(VectorTest, RelationalOperators)
{
	int myint[] = {0, 1, 2, 3, 4};
	ft::vector<int> foo(3, 100);                          // three ints with a value of 100
	ft::vector<int> bar(2, 200);                          // two ints with a value of 200
	ft::vector<int> three(myint, myint + 3);  // three ints with a value of 100
	ft::vector<int> four(myint, myint + 4);   // two ints with a value of 200

	EXPECT_FALSE(foo == bar);
	EXPECT_TRUE(foo != bar);
	EXPECT_FALSE(foo > bar);
	EXPECT_TRUE(foo < bar);
	EXPECT_FALSE(foo >= bar);
	EXPECT_TRUE(foo <= bar);
	EXPECT_FALSE(three == four);
	EXPECT_TRUE(three != four);
	EXPECT_FALSE(three > four);
	EXPECT_TRUE(three < four);
	EXPECT_FALSE(three >= four);
	EXPECT_TRUE(three <= four);
}
//
TEST(VectorTest, Clear)
{
	ft::vector<int> myvector;
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	myvector.clear();
	myvector.push_back(1101);
	myvector.push_back(2202);

	EXPECT_EQ(myvector.front(), 1101);
	EXPECT_EQ(myvector.back(), 2202);
	EXPECT_EQ(myvector.size(), size_t(2));
}
//
TEST(VectorTest, Swap)
{
	ft::vector<int> foo(3, 100);  // three ints with a value of 100
	ft::vector<int> bar(5, 200);  // five ints with a value of 200

	EXPECT_EQ(foo.size(), size_t(3));
	EXPECT_EQ(bar.size(), size_t(5));
	foo.swap(bar);
	EXPECT_EQ(foo.size(), size_t(5));
	EXPECT_EQ(bar.size(), size_t(3));
}
//
TEST(VectorTest, Erase)
{
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	// erase the 6th element
	myvector.erase(myvector.begin() + 5);
	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);
	int resultarr[] = {4, 5, 7, 8, 9, 10};
	for (size_t i = 0; i < myvector.size(); ++i)
 		EXPECT_EQ(myvector[i], resultarr[i]) << "i = " << i;
}

TEST(VectorTest, Insert)
{
	ft::vector<int> myvector(3, 100);
	ft::vector<int>::iterator it;

//	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it, 2, 300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = {501, 502, 503};
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	// 503, 502, 501, 300, 300, 400, 400, 200, 100, 100, 100,
	int resultarr[] = {501, 502, 503, 300, 300, 400, 400, 200, 100, 100, 100};
	for (size_t i = 0; i < myvector.size(); ++i)
		// std::cout << myvector[i] << ", ";
		EXPECT_EQ(myvector[i], resultarr[i]);
}

TEST(VectorTest, InsertPos)
{
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	std::vector<int> stdvector;
	std::vector<int>::iterator sit;

	it = myvector.end();
	sit = stdvector.end();
	for (int i = 0; i < 20; ++i)
	{
		it = myvector.insert(it, i);
		sit = stdvector.insert(sit, i);
	}
	it = myvector.insert(myvector.begin(), -1);
	sit = stdvector.insert(stdvector.begin(), -1);
	ASSERT_EQ(myvector.size(), stdvector.size());
	ASSERT_EQ(*it, *sit);
	for (int i = 0; i < 20; ++i)
		ASSERT_EQ(myvector[i], stdvector[i]);
}

TEST(VectorTest, InsertN)
{
	ft::vector<int> myvector(3, 100);
	std::vector<int> stdvector(3, 100);

	for (int i = 0; i < 20; ++i)
	{
		myvector.insert(myvector.end(), 3, i);
		stdvector.insert(stdvector.end(), 3, i);
	}
	myvector.insert(myvector.begin(), 10, 200);
	stdvector.insert(stdvector.begin(), 10, 200);
	ASSERT_EQ(myvector.size(), stdvector.size());
	for (int i = 0; i < 20; ++i)
		ASSERT_EQ(myvector[i], stdvector[i]);
}

TEST(VectorTest, InsertRange)
{
	ft::vector<int> myvector, myvector2;
	ft::vector<int>::iterator it;
	std::vector<int> stdvector, stdvector2;

	for (int i = 0; i < 100; ++i)
	{
		myvector.insert(myvector.end(), 3, i);
		stdvector.insert(stdvector.end(), 3, i);
	}
	myvector2.insert(myvector2.begin(), myvector.begin(), myvector.begin() + 20);
	stdvector2.insert(stdvector2.begin(), stdvector.begin(), stdvector.begin() + 20);
	ASSERT_EQ(myvector.size(), stdvector.size());
	for (int i = 0; i < 20; ++i)
		ASSERT_EQ(myvector[i], stdvector[i]);

	myvector2.insert(myvector2.end(), myvector.end() - 40, myvector.end());
	stdvector2.insert(stdvector2.end(), stdvector.end() - 40, stdvector.end());
	ASSERT_EQ(myvector.size(), stdvector.size());
	for (int i = 0; i < 20; ++i)
		ASSERT_EQ(myvector[i], stdvector[i]);
}

TEST(VectorTest, PopBack)
{
	ft::vector<int> myvector;
	int sum(0);
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	EXPECT_EQ(sum, 600);
}

TEST(VectorTest, PushBack)
{
	ft::vector<int> first;
	ft::vector<int> second(1000, 5);
	ft::vector<int> third(second.begin(), second.begin() + 100);

	for (int i = 0; i < 3000; ++i)
	{
		first.push_back(i);
		second.push_back(i);
		third.push_back(i);
	}
	EXPECT_EQ(first.size(), size_t(3000));
	EXPECT_EQ(second.size(), size_t(4000));
	EXPECT_EQ(third.size(), size_t(3100));
}

TEST(VectorTest, Assign)
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign(7, 100);  // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1);      // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3);  // assigning from array.

	EXPECT_EQ(first.size(), size_t(7));
	EXPECT_EQ(second.size(), size_t(5));
	EXPECT_EQ(third.size(), size_t(3));
}

TEST(VectorTest, FrontBack)
{
	ft::vector<int> myvector;

	myvector.push_back(78);
	EXPECT_EQ(myvector.front(), myvector.back());
	myvector.push_back(16);

	// now front equals 78, and back 16
	EXPECT_EQ(myvector.front(), 78);
	myvector.front() -= myvector.back();
	EXPECT_EQ(myvector.front(), 62);
	EXPECT_EQ(myvector.back(), 16);
}

TEST(VectorTest, At)
{
	ft::vector<int> myvector(10);      // 10 zero-initialized ints

	// assign some values:
	for (size_t i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

	for (size_t i = 0; i < myvector.size(); i++)
		EXPECT_EQ(myvector.at(i), int(i));
	EXPECT_ANY_THROW(myvector.at(20));
}

TEST(VectorTest, BracketOperator)
{
	ft::vector<int> myvector(10);      // 10 zero-initialized elements
	std::vector<int> stdvector(10);         // 10 zero-initialized elements

	ft::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (size_t i = 0; i < sz; i++)
	{
		myvector[i] = i;
		stdvector[i] = i;
	}
	// reverse vector using operator[]:
	for (size_t i = 0; i < sz / 2; i++)
	{
		int temp;
		temp = myvector[sz - 1 - i];
		myvector[sz - 1 - i] = myvector[i];
		myvector[i] = temp;
		temp = stdvector[sz - 1 - i];
		stdvector[sz - 1 - i] = stdvector[i];
		stdvector[i] = temp;
	}

	for (size_t i = 0; i < sz; i++)
		EXPECT_EQ(myvector[i], stdvector[i]);
}

TEST(VectorTest, Reserve)
{
	ft::vector<int> bar;
	std::vector<int> stdbar;
	bar.reserve(100);
	stdbar.reserve(100);
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		stdbar.push_back(i);
	}
	EXPECT_EQ(bar.size(), stdbar.size());
	EXPECT_EQ(bar.capacity(), stdbar.capacity());
	bar.reserve(50);
	stdbar.reserve(50);
	EXPECT_EQ(bar.size(), stdbar.size());
	EXPECT_EQ(bar.capacity(), stdbar.capacity());
	bar.push_back(10);
	stdbar.push_back(10);
	EXPECT_EQ(bar.size(), stdbar.size());
	EXPECT_EQ(bar.capacity(), stdbar.capacity());

	ft::vector<int> bar2(10, 100);
	std::vector<int> stdbar2(10, 100);
	EXPECT_EQ(bar2.size(), stdbar2.size());
	EXPECT_EQ(bar2.capacity(), stdbar2.capacity());
	bar2.push_back(10);
	stdbar2.push_back(10);
	EXPECT_EQ(bar2.size(), stdbar2.size());
	EXPECT_EQ(bar2.capacity(), stdbar2.capacity());
}

TEST(VectorTest, Empty)
{
	ft::vector<int> myvector;
	std::vector<int> stdvector;

	int sum = 0;
	int stdsum = 0;

	for (int i = 1; i <= 10; i++)
	{
		myvector.push_back(i);
		stdvector.push_back(i);
	}

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	while (!stdvector.empty())
	{
		stdsum += stdvector.back();
		stdvector.pop_back();
	}
	EXPECT_EQ(stdsum, sum);
}

TEST(VectorTest, Capacity)
{
	ft::vector<int> myvector;
	std::vector<int> stdvector;

	// set some content in the vector:
	for (int i = 0; i < 65; i++)
	{
		myvector.push_back(i);
		stdvector.push_back(i);
		EXPECT_EQ(myvector.capacity(), stdvector.capacity());
	}
	EXPECT_EQ(myvector.size(), stdvector.size());
}

TEST(VectorTest, Resize)
{
	ft::vector<int> myvector;

	// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);

	EXPECT_EQ(myvector.size(), size_t(9));
	myvector.resize(5);
	EXPECT_EQ(myvector.size(), size_t(5));
	myvector.resize(8, 100);
	EXPECT_EQ(myvector.size(), size_t(8));
	myvector.resize(12);
	EXPECT_EQ(myvector.size(), size_t(12));

	int myarr[] = {1, 2, 3, 4, 5, 100, 100, 100, 0, 0, 0, 0};
	for (size_t i = 0; i < myvector.size(); ++i)
		EXPECT_EQ(myvector[i], myarr[i]);
}

TEST(VectorTest, MaxSize)
{
	ft::vector<int> myvector;
	std::vector<int> stdvector;
	EXPECT_EQ(myvector.max_size(), stdvector.max_size());
	ft::vector<double> myvector2;
	std::vector<double> stdvector2;
	EXPECT_EQ(myvector2.max_size(), stdvector2.max_size());
	ft::vector<char> myvector3;
	std::vector<char> stdvector3;
	EXPECT_EQ(myvector3.max_size(), stdvector3.max_size());
}

TEST(VectorTest, Size)
{
	ft::vector<int> myints;
	EXPECT_EQ(myints.size(), size_t(0));
	for (int i = 0; i < 10; i++)
		myints.push_back(i);
	EXPECT_EQ(myints.size(), size_t(10));

	myints.insert(myints.end(), 10, 100);
	EXPECT_EQ(myints.size(), size_t(20));
	myints.pop_back();
	EXPECT_EQ(myints.size(), size_t(19));
}

TEST(VectorTest, ReverseBegin)
{
	ft::vector<int> myvector(5);  // 5 default-constructed ints

	int i = 0;

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit != myvector.rend(); ++rit)
		*rit = ++i;

	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	{
		EXPECT_EQ(*it, i--);
	}
}

TEST(VectorTest, Begin)
{
	ft::vector<int> myvector;
	for (int i = 1; i <= 5; i++)
		myvector.push_back(i);

	int i = 1;
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	{
		EXPECT_EQ(*it, i++);
	}
}

TEST(VectorTest, AssignOperator)
{
	ft::vector<int> foo(3, 0);
	ft::vector<int> bar(5, 0);

	bar = foo;
	foo = ft::vector<int>();

	EXPECT_EQ(foo.size(), size_t(0));
	EXPECT_EQ(bar.size(), size_t(3));
}

TEST(VectorTest, Constructors)
{
	// constructors used in the same order as described above:
	ft::vector<int> first;                                                                        // empty vector of ints
	ft::vector<int> second(4, 100);                                               // four ints with value 100
	ft::vector<int> third(second.begin(), second.end() - 1);  // iterating through second
	ft::vector<int> fourth(third);                                                        // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16, 2, 77, 29, 5, 100};
	ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	EXPECT_EQ(first.size(), size_t(0));
	EXPECT_EQ(second.size(), size_t(4));
	EXPECT_EQ(third.size(), size_t(3));
	EXPECT_EQ(fourth.size(), size_t(3));
	EXPECT_EQ(fifth.size(), size_t(6));

	EXPECT_EQ(third[2], 100);
	EXPECT_EQ(fifth.front(), 16);
	std::cout << std::endl;
	EXPECT_EQ(fifth.back(), 100);
}

