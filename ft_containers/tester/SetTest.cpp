//
// Created by Alexis Lafrance on 12/9/21.
//

#include "tester.hpp"
#include "googleTestLike.cpp"
#include <set>
#include "../containers/set.hpp"

void TestConstructorSet() {
	library::set<int> first;

	first.insert(10);
	first.insert(30);
	first.insert(50);
	first.insert(70);
	library::set<int> second(first.begin(), first.end());

	library::set<int> third(second);

	library::set<int, std::less<int> > fourth;	// class as Compare

	EXPECT_EQ(first.size(), static_cast<size_t>(4));
	EXPECT_EQ(second.size(), static_cast<size_t>(4));
	EXPECT_EQ(third.size(), static_cast<size_t>(4));
	EXPECT_EQ(fourth.size(), static_cast<size_t>(0));
	global_error == 0 ? displayTestOk("Constructor") : displayTestError("Constructor");
	global_error = 0;
}

void TestSwapSet() {
	library::set<int> first;

	first.insert(1);
	first.insert(2);
	first.insert(3);
	first.insert(4);

	library::set<int> second;
	second.insert(90);
	second.insert(91);
	second.insert(92);
	second.insert(93);
	second.insert(94);

	first.swap(second);
	EXPECT_EQ(*first.find(90), 90);
	EXPECT_EQ(*second.find(1), 1);
	EXPECT_EQ(first.size(), static_cast<size_t>(5));
	EXPECT_EQ(second.size(), static_cast<size_t>(4));
	global_error == 0 ? displayTestOk("Swap") : displayTestError("Swap");
	global_error = 0;
}

void TestEmptyAndEraseSet() {
	library::set<int> myset;
	std::set<int> stdset;

	int sum = 0;
	int stdsum = 0;

	for (int i = 1; i <= 10; i++)
	{
		myset.insert(i);
		stdset.insert(i);
	}

	int i = 1;
	while (!myset.empty())
	{
		sum += *myset.find(i);
		myset.erase(i);
		i++;
	}
	i = 1;
	while (!stdset.empty())
	{
		stdsum += *stdset.find(i);
		stdset.erase(i);
		i++;
	}
	EXPECT_EQ(stdsum, sum);
	global_error == 0 ? displayTestOk("Empty") : displayTestError("Empty");
	global_error = 0;
}

void TestClearSet() {
	library::set<int> myset;

	myset.insert(1);
	myset.insert(2);
	myset.insert(3);
	myset.insert(4);
	myset.insert(5);

	myset.clear();
	EXPECT_EQ(static_cast<int>(myset.size()), 0);
	myset.insert(12);
	myset.insert(10);
	EXPECT_EQ(static_cast<int>(*myset.find(12)), 12);
	EXPECT_EQ(static_cast<int>(*myset.find(10)), 10);
	global_error == 0 ? displayTestOk("Clear") : displayTestError("Clear");
	global_error = 0;
}

void TestFindAndEraseSet() {
	library::set<int> myset;
	library::set<int>::iterator it;

	myset.insert(50);
	myset.insert(100);
	myset.insert(150);
	myset.insert(200);

	it = myset.find('b');
	if (it != myset.end())
		myset.erase (it);

	// print content
	EXPECT_EQ(*myset.find(50), 50);
	EXPECT_EQ(*myset.find(100), 100);
	EXPECT_EQ(*myset.find(150), 150);
	EXPECT_EQ(*myset.find(200), 200);
	global_error == 0 ? displayTestOk("Find") : displayTestError("Find");
	global_error = 0;
}

void TestIteratorSet() {
	library::set<int> myset;
	myset.insert(4);
	myset.insert(1);
	myset.insert(3);
	myset.insert(2);

	library::set<int>::iterator it = myset.begin();
	EXPECT_EQ(*it, 1);
	it++;
	EXPECT_EQ(*it, 2);
	it++;
	EXPECT_EQ(*it, 3);
	it++;
	EXPECT_EQ(*it, 4);
	global_error == 0 ? displayTestOk("Basic Test") : displayTestError("Basic Test");
	global_error = 0;
}

void TestIterator2Set() {
	int myints[] = {75,23,65,42,13};
	library::set<int> myset (myints,myints+5);
	std::set<int> set (myints,myints+5);

	library::set<int>::iterator it = myset.begin();
	std::set<int>::iterator it2 = set.begin();
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(*it, *it2);
		it++;
		it2++;
	}

	global_error == 0 ? displayTestOk("Basic Test 2") : displayTestError("Basic Test 2");
	global_error = 0;
}

void TestReverseIteratorSet() {
	library::set<int> myset;
	myset.insert(1);
	myset.insert(2);
	myset.insert(3);
	myset.insert(4);

	library::set<int>::reverse_iterator rit = myset.rbegin();
	EXPECT_EQ(*rit, 4);
	rit++;
	EXPECT_EQ(*rit, 3);
	rit++;
	EXPECT_EQ(*rit, 2);
	rit++;
	EXPECT_EQ(*rit, 1);

	global_error == 0 ? displayTestOk("Reverse Iterator") : displayTestError("Reverse Iterator");
	global_error = 0;
}

void TestInsertIteratorSet() {
	library::set<int> myset;
	myset.insert(4);
	myset.insert(1);
	myset.insert(3);
	myset.insert(2);

	library::set<int> myset2;

	myset2.insert(myset.begin(), myset.end());
	library::set<int>::iterator it = myset.begin();
	EXPECT_EQ(*it, 1);
	it++;
	EXPECT_EQ(*it, 2);
	global_error == 0 ? displayTestOk("Insert with range of iterators") : displayTestError("Insert with range of iterators");
	global_error = 0;
}

void TestInsertSet() {
	library::set<int> myset;
	myset.insert(5);

	// ALREADY EXISTS
	library::pair<library::set<int>::iterator, bool > pair;
	pair = myset.insert(5);

	EXPECT_EQ(*pair.first, 5);
	EXPECT_FALSE(pair.second);

	library::pair<library::set<int>::iterator, bool > pair2;
	pair2 = myset.insert(1);

	EXPECT_EQ(*pair2.first, 1);
	EXPECT_TRUE(pair2.second);

	global_error == 0 ? displayTestOk("Insert") : displayTestError("Insert");
	global_error = 0;
}


void TestEqualUpperLowerBoundsSet() {
	library::set<int> myset;
	myset.insert(10);
	myset.insert(20);
	myset.insert(30);
	myset.insert(40);
	myset.insert(60);

	library::pair<library::set<int>::iterator,library::set<int>::iterator> ret = myset.equal_range(20);

	EXPECT_EQ(*ret.first, 20);

	EXPECT_EQ(*ret.second, 30);

	ret = myset.equal_range(70);

	ret = myset.equal_range(50);
	EXPECT_EQ(*ret.first, 60);
	EXPECT_EQ(*ret.second, 60);
	global_error == 0 ? displayTestOk("All The Tests For Bounds") : displayTestError("All The Tests For Bounds");
	global_error = 0;
}
void testAllSet() {
	global_error = 0;
	displayPart("Set");

//	displayShortPart("Constructor");
	TestConstructorSet();

//	displayShortPart("Iterators");
	TestIteratorSet();
	TestIterator2Set();
	TestReverseIteratorSet();

//	displayShortPart("Functions : Modifiers");
	TestSwapSet();
	TestEmptyAndEraseSet();
	TestClearSet();
	TestInsertSet();
	TestInsertIteratorSet();

//	displayShortPart("Functions : Operations");
	TestFindAndEraseSet();
//	displayShortPart("Functions : Equal-Upper-Lower Bounds");
	TestEqualUpperLowerBoundsSet();
}