//
// Created by Alexis Lafrance on 12/9/21.
//

#include "../containers/map.hpp"
#include "tester.hpp"
#include "googleTestLike.cpp"
#include <map>

void TestConstructor() {
	library::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	library::map<char, int> second(first.begin(), first.end());

	library::map<char, int> third(second);

	library::map<char, int, std::less<int> > fourth;	// class as Compare

	EXPECT_EQ(first.size(), static_cast<size_t>(4));
	EXPECT_EQ(second.size(), static_cast<size_t>(4));
	EXPECT_EQ(third.size(), static_cast<size_t>(4));
	EXPECT_EQ(fourth.size(), static_cast<size_t>(0));
	global_error == 0 ? displayTestOk("Constructor") : displayTestError("Constructor");
	global_error = 0;
}

void TestSwapMap() {
	library::map<char, int> first;

	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;

	library::map<char, int> second;

	second['a'] = 90;
	second['b'] = 91;
	second['c'] = 92;
	second['d'] = 92;
	second['e'] = 93;

	first.swap(second);
	EXPECT_EQ(first['a'], 90);
	EXPECT_EQ(second['a'], 1);
	EXPECT_EQ(first['e'], 93);
	EXPECT_EQ(first.size(), static_cast<size_t>(5));
	EXPECT_EQ(second.size(), static_cast<size_t>(4));
	global_error == 0 ? displayTestOk("Swap") : displayTestError("Swap");
	global_error = 0;
}

void TestEmptyAndEraseMap() {
	library::map<char, int> mymap;
	std::map<char, int> stdmap;

	for (int i = 1; i <= 10; i++)
	{
		mymap['a' + i] = i;
		stdmap['a' + i] = i;
	}
	int i  = 0;
	while (!mymap.empty())
	{
		mymap.erase('a' + i);
		i++;
	}
	i = 0;
	while (!stdmap.empty())
	{
		stdmap.erase('a' + i);
		i++;
	}
	EXPECT_EQ(static_cast<int>(mymap.size()), 0);
	EXPECT_EQ(static_cast<int>(stdmap.size()), 0);
	global_error == 0 ? displayTestOk("Empty") : displayTestError("Empty");
	global_error = 0;
}

void TestClearMap() {
	library::map<char, int> mymap;

	mymap['a'] = 1;
	mymap['b'] = 2;
	mymap['c'] = 3;
	mymap['d'] = 4;
	mymap['e'] = 5;

	mymap.clear();
	EXPECT_EQ(static_cast<int>(mymap.size()), 0);
	mymap['a'] = 12;
	mymap['f'] = 10;
	EXPECT_EQ(static_cast<int>(mymap['a']), 12);
	EXPECT_EQ(static_cast<int>(mymap['f']), 10);
	global_error == 0 ? displayTestOk("Clear") : displayTestError("Clear");
	global_error = 0;
}

void TestFindAndEraseMap() {
	library::map<char,int> mymap;
	library::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content
	EXPECT_EQ(mymap.find('a')->second, 50);
	EXPECT_EQ(mymap.find('c')->second, 150);
	EXPECT_EQ(mymap.find('d')->second, 200);
	global_error == 0 ? displayTestOk("Find") : displayTestError("Find");
	global_error = 0;
}

void TestIteratorMap() {
	library::map<char,int> mymap;
	mymap['a'] = 1;
	mymap['d'] = 4;
	mymap['b'] = 2;
	mymap['c'] = 3;

	library::map<char,int>::iterator it = mymap.begin();
	EXPECT_EQ(it->first, 'a');
	EXPECT_EQ(it->second, 1);
	it++;
	EXPECT_EQ(it->first, 'b');
	it++;
	EXPECT_EQ(it->first, 'c');
	it++;
	library::pair<char, int> pair = *it;
	EXPECT_EQ(pair.first, 'd');
	EXPECT_EQ(pair.second, 4);

	global_error == 0 ? displayTestOk("Basic Test") : displayTestError("Basic Test");
	global_error = 0;
}

void TestReverseIteratorMap() {
	library::map<char,int> mymap;
	mymap['a'] = 1;
	mymap['d'] = 4;
	mymap['b'] = 2;
	mymap['c'] = 3;

	library::reverse_iterator<library::map<char,int>::iterator> revit = mymap.rbegin();
	mymap.rbegin();
	library::map<char, int>::reverse_iterator revit2 = mymap.rbegin();

	// WITH FT::REVERSE_ITERATOR
	EXPECT_EQ(revit->first, 'd');
	EXPECT_EQ(revit->second, 4);
	revit++;
	EXPECT_EQ(revit->first, 'c');
	revit++;
	EXPECT_EQ(revit->first, 'b');
	revit++;
	library::pair<char, int> pair = *revit;
	EXPECT_EQ(pair.first, 'a');
	EXPECT_EQ(pair.second, 1);

	// WITH FT::MAP::REVERSE_ITERATOR

	EXPECT_EQ(revit2->first, 'd');
	EXPECT_EQ(revit2->second, 4);
	revit2++;
	EXPECT_EQ(revit2->first, 'c');
	revit2++;
	EXPECT_EQ(revit2->first, 'b');
	revit2++;
	library::pair<char, int> pair2 = *revit2;
	EXPECT_EQ(pair2.first, 'a');
	EXPECT_EQ(pair2.second, 1);

	global_error == 0 ? displayTestOk("Reverse Iterator") : displayTestError("Reverse Iterator");
	global_error = 0;
}

void TestInsertIteratorMap() {
	library::map<char, int> map;
	map['a'] = 1;
	map['b'] = 2;
	map['c'] = 3;
	map['d'] = 4;

	library::map<char, int> map2;

	map2.insert(map.begin(), map.end());
	library::map<char, int>::iterator it = map.begin();
	EXPECT_EQ(it->first, 'a');
	EXPECT_EQ(it->second, 1);
	it++;
	EXPECT_EQ(it->first, 'b');
	EXPECT_EQ(it->second, 2);
	global_error == 0 ? displayTestOk("Insert with range of iterators") : displayTestError("Insert with range of iterators");
	global_error = 0;
}

void TestInsertMap() {
	library::map<char, int> map;
	map['a'] = 5;


	// ALREADY EXISTS
	library::pair<library::map<char, int>::iterator, bool > pair;
	pair = map.insert(library::pair<char, int>('a', 1));

	EXPECT_EQ(pair.first->first, 'a');
	EXPECT_EQ(pair.first->second, 5);
	EXPECT_FALSE(pair.second);

	library::pair<library::map<char, int>::iterator, bool > pair2;
	pair2 = map.insert(library::pair<char, int>('b', 1));

	EXPECT_EQ(pair2.first->first, 'b');
	EXPECT_EQ(pair2.first->second, 1);
	EXPECT_TRUE(pair2.second);

	global_error == 0 ? displayTestOk("Insert") : displayTestError("Insert");
	global_error = 0;
}


void TestEqualUpperLowerBounds() {
	library::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['e']=40;

	library::pair<library::map<char,int>::iterator,library::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	EXPECT_EQ(ret.first->first, 'b');
	EXPECT_EQ(ret.first->second, 20);

	EXPECT_EQ(ret.second->first, 'c');
	EXPECT_EQ(ret.second->second, 30);

	ret = mymap.equal_range('g');
	ret = mymap.equal_range('d');
	EXPECT_EQ(ret.first->first, 'e');
	EXPECT_EQ(ret.first->second, 40);
	EXPECT_EQ(ret.second->first, 'e');
	EXPECT_EQ(ret.second->second, 40);
	global_error == 0 ? displayTestOk("All The Tests For Bounds") : displayTestError("All The Tests For Bounds");
}

void TestMaxSizeMap() {
	library::map<int, int> mymap;
	std::map<int, int> stdmap;
	EXPECT_EQ(mymap.max_size(), stdmap.max_size());
	library::map<double, double> mymap2;
	std::map<double, double> stdmap2;
	EXPECT_EQ(mymap2.max_size(), stdmap2.max_size());
	library::map<char, char> mymap3;
	std::map<char, char> stdmap3;
	EXPECT_EQ(mymap3.max_size(), stdmap3.max_size());
	global_error == 0 ? displayTestOk("Max size") : displayTestError("Max size");
	global_error = 0;
}

void testAllMap() {
	displayPart("Map");

	TestConstructor();

	TestIteratorMap();
	TestReverseIteratorMap();

	TestMaxSizeMap();

	TestSwapMap();
	TestEmptyAndEraseMap();
	TestClearMap();
	TestInsertMap();
	TestInsertIteratorMap();

	TestFindAndEraseMap();

	TestEqualUpperLowerBounds();
}