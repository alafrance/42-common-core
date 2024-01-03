//
// Created by Alexis Lafrance on 12/9/21.
//
#define USE_STD 0
#include "../containers/vector.hpp"
#include "tester.hpp"
#include <vector>
#include "googleTestLike.cpp"

// ------------------ UTILITY TEST ------------------

template<typename T>
void testContentOfVector(T content, size_t size, library::vector<T> a) {
	size_t count = 0;
	T *array;
	if (std::is_integral<T>::value)
		array = new T[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = content;
	for (typename library::vector<T>::iterator it = a.begin(); it < a.end(); it++) {
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
	library::vector<T> a(size, content);
	T *array = nullptr;
	if (std::is_integral<T>::value)
		array = new T[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = content;
	for (typename library::vector<T>::iterator it = a.begin(); it < a.end(); it++) {
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

// ------------------ TEST CONSTRUCTOR ------------------

void testConstructorWithDifferentsTypes() {
	library::vector<int> g;
	EXPECT_EQ(g.empty(), true);
	EXPECT_EQ(g.size(), (size_t)0);
	EXPECT_EQ(g.capacity(), (size_t)0);

	size_t size_a = 1000;
	library::vector<char> a(size_a, 'b');
	testContentOfVector('b', size_a, a);
	const library::vector<char>& c(a);
	EXPECT_EQ(a, c);
	const library::vector<char>& d = a;
	EXPECT_EQ(a, d);

	testContentOfVector(1, 4200);
	testContentOfVector("blablou", 0);
	testContentOfVector(static_cast<unsigned long long int>(199), 100);

	library::vector<std::string> testVec(2, static_cast<std::string>("coucou"));
	EXPECT_EQ(static_cast<std::string>(*testVec.begin()), static_cast<std::string>("coucou"));
	std::string end = *(testVec.end() - 1);
	EXPECT_EQ(end, static_cast<std::string>("coucou"));

	int myints[] = {1, 2, 3, 4};
	library::vector<int> john(myints, myints + 3);
	global_error == 0 ? displayTestOk("Differents Types") : displayTestError("Differents Types");
	global_error = 0;
}

// ------------------ TEST REVERSE_ITERATOR ------------------

void TestReverseIteratorForVector() {
	library::vector<int> vector;   // three ints with a value of 100
	std::vector<int> svector; // three ints with a value of 100
	for (int i = 0; i < 10000; ++i)
	{
		vector.push_back(i);
		svector.push_back(i);
		vector.push_back(i);
		svector.push_back(i);
	}
	library::vector<int>::reverse_iterator rit = vector.rbegin();
	std::vector<int>::reverse_iterator srit = svector.rbegin();
	int r = rit[10];
	int sr = srit[10];
	EXPECT_EQ(r, sr);

	EXPECT_EQ(*(rit + 5), *(srit + 5));
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
	global_error == 0 ? displayTestOk("Basic Test") : displayTestError("Basic Test");
	global_error = 0;

}

void TestReverseConstIterator() {
	library::vector<int> vector;  // three ints with a value of 100
	std::vector<int> svector;         // three ints with a value of 100
	for (int i = 0; i < 10000; ++i)
	{
	vector.push_back(i);
	svector.push_back(i);
	vector.push_back(i);
	svector.push_back(i);
	}
	library::vector<int>::const_reverse_iterator rit;
	std::vector<int>::const_reverse_iterator srit;

	srit = svector.rbegin();
	rit = vector.rbegin();
	while (rit != vector.rend())
		EXPECT_EQ(*srit++, *rit++);
	global_error == 0 ? displayTestOk("Const Reverse Iterator") : displayTestError("Const Reverse Iterator");
	global_error = 0;
}

// ------------------ TEST ITERATORS ------------------



void TestIteratorAllOperators()
{
	library::vector<int> myvector;
	library::vector<int>::iterator it;
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
	global_error == 0 ? displayTestOk("Test Iterator All Operators") : displayTestError("Test Iterator All Operators");
	global_error = 0;
}

void TestIteratorWithPairs()
{
	library::vector<std::pair<int, int> > myvector2;
	library::vector<std::pair<int, int> >::iterator it2;
	std::vector<std::pair<int, int> > stdvector2;
	std::vector<std::pair<int, int> >::iterator stdit2;

	std::pair<int, int> p(1, 2);
	myvector2.push_back(p);
	stdvector2.push_back(p);
	it2 = myvector2.begin();
	stdit2 = stdvector2.begin();
	EXPECT_EQ(it2->first, stdit2->first);
	EXPECT_EQ(it2->second, stdit2->second);
	global_error == 0 ? displayTestOk("Test Iterator With Pairs") : displayTestError("Test Iterator With Pairs");
	global_error = 0;
}

void TestIteratorsWithInverseOperators() {

	library::vector<int> myvector;
	library::vector<int>::iterator it;
	library::vector<int>::const_iterator cit;
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
//	stditEXPECT_EQ(it, cit);
	global_error == 0 ? displayTestOk("Test Iterator With Inverse Operators") : displayTestError("Test Iterator With Inverse Operators");
	global_error = 0;
}

void TestRelationalOperator() {

	int myint[] = {0, 1, 2, 3, 4};
	library::vector<int> foo(3, 100);                          // three ints with a value of 100
	library::vector<int> bar(2, 200);                          // two ints with a value of 200
	library::vector<int> three(myint, myint + 3);  // three ints with a value of 100
	library::vector<int> four(myint, myint + 4);   // two ints with a value of 200

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
	global_error == 0 ? displayTestOk("Basic Test") : displayTestError("Basic Test");
	global_error = 0;
}
void TestClear() {
	library::vector<int> myvector;
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	myvector.clear();
	myvector.push_back(1101);
	myvector.push_back(2202);

	EXPECT_EQ(myvector.front(), 1101);
	EXPECT_EQ(myvector.back(), 2202);
	EXPECT_EQ(myvector.size(), size_t(2));
	global_error == 0 ? displayTestOk("Clear") : displayTestError("Clear");
	global_error = 0;
}

void TestSwap() {
	library::vector<int> myvector;
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	myvector.clear();
	myvector.push_back(1101);
	myvector.push_back(2202);

	EXPECT_EQ(myvector.front(), 1101);
	EXPECT_EQ(myvector.back(), 2202);
	EXPECT_EQ(myvector.size(), size_t(2));
	global_error == 0 ? displayTestOk("Swap") : displayTestError("Swap");
	global_error = 0;
}

void TestErase() {
	library::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	// erase the 6th element
	myvector.erase(myvector.begin() + 5);
	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);
	int resultarr[] = {4, 5, 7, 8, 9, 10};
	for (size_t i = 0; i < myvector.size(); ++i)
		EXPECT_EQ(myvector[i], resultarr[i]);
	global_error == 0 ? displayTestOk("Erase") : displayTestError("Erase");
	global_error = 0;
}

void TestInsert() {
	library::vector<int> myvector(3, 100);
	library::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it, 2, 300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	library::vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = {501, 502, 503};
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	// 503, 502, 501, 300, 300, 400, 400, 200, 100, 100, 100,
	int resultarr[] = {501, 502, 503, 300, 300, 400, 400, 200, 100, 100, 100};
	for (size_t i = 0; i < myvector.size(); ++i)
		// std::cout << myvector[i] << ", ";
		EXPECT_EQ(myvector[i], resultarr[i]);
	global_error == 0 ? displayTestOk("Insert") : displayTestError("Insert");
	global_error = 0;
}

void TestInsertWithIterators()
{
	library::vector<int> myvector;
	library::vector<int>::iterator it;
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
	global_error == 0 ? displayTestOk("Insert With Iterators") : displayTestError("Insert With Iterators");
	global_error = 0;
}

void TestInsertNnumbers() {

	library::vector<int> myvector(3, 100);
	std::vector<int> stdvector(3, 100);

	for (int i = 0; i < 20; ++i)
	{
	myvector.insert(myvector.end(), 3, i);
	stdvector.insert(stdvector.end(), 3, i);
	}
	myvector.insert(myvector.begin(), 10, 200);
	stdvector.insert(stdvector.begin(), 10, 200);
	EXPECT_EQ(myvector.size(), stdvector.size());
	for (int i = 0; i < 20; ++i)
		EXPECT_EQ(myvector[i], stdvector[i]);
	global_error == 0 ? displayTestOk("Insert With N numbers") : displayTestError("Insert With N numbers");
	global_error = 0;
}

void TestInsertRange() {
	library::vector<int> myvector, myvector2;
	library::vector<int>::iterator it;
	std::vector<int> stdvector, stdvector2;

	for (int i = 0; i < 100; ++i)
	{
		myvector.insert(myvector.end(), 3, i);
		stdvector.insert(stdvector.end(), 3, i);
	}
	myvector2.insert(myvector2.begin(), myvector.begin(), myvector.begin() + 20);
	stdvector2.insert(stdvector2.begin(), stdvector.begin(), stdvector.begin() + 20);
	EXPECT_EQ(myvector.size(), stdvector.size());
	for (int i = 0; i < 20; ++i)
		EXPECT_EQ(myvector[i], stdvector[i]);

	myvector2.insert(myvector2.end(), myvector.end() - 40, myvector.end());
	stdvector2.insert(stdvector2.end(), stdvector.end() - 40, stdvector.end());
	EXPECT_EQ(myvector.size(), stdvector.size());
	for (int i = 0; i < 20; ++i)
		EXPECT_EQ(myvector[i], stdvector[i]);
	global_error == 0 ? displayTestOk("Insert With range") : displayTestError("Insert With range");
	global_error = 0;
}


void TestPushBack() {
	library::vector<int> first;
	library::vector<int> second(1000, 5);
	library::vector<int> third(second.begin(), second.begin() + 100);

	for (int i = 0; i < 3000; ++i)
	{
		first.push_back(i);
		second.push_back(i);
		third.push_back(i);
	}
	EXPECT_EQ(first.size(), size_t(3000));
	EXPECT_EQ(second.size(), size_t(4000));
	EXPECT_EQ(third.size(), size_t(3100));
	global_error == 0 ? displayTestOk("Push Back") : displayTestError("Push Back");
	global_error = 0;
}

void TestPopBack() {
	library::vector<int> myvector;
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
	global_error == 0 ? displayTestOk("Pop back") : displayTestError("Pop back");
	global_error = 0;
}

void TestAssign() {
	library::vector<int> first;
	library::vector<int> second;
	library::vector<int> third;

	first.assign(7, 100);  // 7 ints with a value of 100

	library::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1);      // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3);  // assigning from array.

	EXPECT_EQ(first.size(), size_t(7));
	EXPECT_EQ(second.size(), size_t(5));
	EXPECT_EQ(third.size(), size_t(3));
	global_error == 0 ? displayTestOk("Assign") : displayTestError("Assign");
	global_error = 0;
}

void TestFrontBack() {
	library::vector<int> myvector;

	myvector.push_back(78);
	EXPECT_EQ(myvector.front(), myvector.back());
	myvector.push_back(16);

	// now front equals 78, and back 16
	EXPECT_EQ(myvector.front(), 78);
	myvector.front() -= myvector.back();
	EXPECT_EQ(myvector.front(), 62);
	EXPECT_EQ(myvector.back(), 16);
	global_error == 0 ? displayTestOk("Front back") : displayTestError("Front back");
}



void TestAt() {
	library::vector<int> myvector(10);      // 10 zero-initialized ints
	bool is_catch = false;
	// assign some values:
	for (size_t i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

	for (size_t i = 0; i < myvector.size(); i++)
		EXPECT_EQ(myvector.at(i), int(i));
	try {
		myvector.at(20);
	}
	catch (std::exception &e) {
		is_catch = true;
	}
	EXPECT_TRUE(is_catch);
	global_error == 0 ? displayTestOk("At") : displayTestError("At");
	global_error = 0;
}

void TestOperatorBracket() {
	library::vector<int> myvector(10);      // 10 zero-initialized elements
	std::vector<int> stdvector(10);         // 10 zero-initialized elements

	library::vector<int>::size_type sz = myvector.size();

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
	global_error == 0 ? displayTestOk("Bracket Operator") : displayTestError("Bracket Operator");
	global_error = 0;
}

void TestReserve() {
	library::vector<int> bar;
	std::vector<int> stdbar;
	bar.reserve(100);
	stdbar.reserve(100);
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		stdbar.push_back(i);
	}
	EXPECT_EQ(bar.size(), stdbar.size());
	bar.reserve(50);
	stdbar.reserve(50);
	EXPECT_EQ(bar.size(), stdbar.size());
	bar.push_back(10);
	stdbar.push_back(10);
	EXPECT_EQ(bar.size(), stdbar.size());

	library::vector<int> bar2(10, 100);
	std::vector<int> stdbar2(10, 100);
	EXPECT_EQ(bar2.size(), stdbar2.size());
	bar2.push_back(10);
	stdbar2.push_back(10);
	EXPECT_EQ(bar2.size(), stdbar2.size());
	global_error == 0 ? displayTestOk("Test Reserve") : displayTestError("Test Reserve");
	global_error = 0;
}

void TestEmpty() {
	library::vector<int> myvector;
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
	global_error == 0 ? displayTestOk("Empty") : displayTestError("Empty");
	global_error = 0;
}

void TestResize() {
	library::vector<int> myvector;

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
	global_error == 0 ? displayTestOk("Resize") : displayTestError("Resize");
	global_error = 0;
}


void TestMaxSize() {
	library::vector<int> myvector;
	std::vector<int> stdvector;
	EXPECT_EQ(myvector.max_size(), stdvector.max_size());
	library::vector<double> myvector2;
	std::vector<double> stdvector2;
	EXPECT_EQ(myvector2.max_size(), stdvector2.max_size());
	library::vector<char> myvector3;
	std::vector<char> stdvector3;
	EXPECT_EQ(myvector3.max_size(), stdvector3.max_size());
	global_error == 0 ? displayTestOk("Max size") : displayTestError("Max size");
	global_error = 0;
}

void testAllVector() {
	displayPart("VECTOR");

//	displayShortPart("CONSTRUCTOR");
	testConstructorWithDifferentsTypes();

//	displayShortPart("REVERSE ITERATOR");
	TestReverseIteratorForVector();
	TestReverseConstIterator();

//	displayShortPart("ITERATORS");
	TestIteratorAllOperators();
	TestIteratorWithPairs();
	TestIteratorsWithInverseOperators();

//	displayShortPart("RELATIONAL OPERATORS");
	TestRelationalOperator();

//	displayShortPart("FUNCTIONS : ELEMENT ACCESS");
	TestPopBack();
	TestPushBack();
	TestFrontBack();
	TestAssign();
	TestAt();
	TestOperatorBracket();

//	displayShortPart("FUNCTIONS : MODIFIERS DELETE");
	TestClear();
	TestErase();

//	displayShortPart("FUNCTIONS : INSERTS");
	TestInsert();
	TestInsertWithIterators();
	TestInsertNnumbers();
	TestInsertRange();

//	displayShortPart("FUNCTIONS : CAPACITY");
	TestSwap();
	TestReserve();
	TestEmpty();
	TestResize();
	TestMaxSize();
}