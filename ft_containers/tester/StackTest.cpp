//
// Created by Alexis Lafrance on 09/12/2021.
//

#include "tester.hpp"
#include "googleTestLike.cpp"
#include "../containers/vector.hpp"
#include "../containers/stack.hpp"
#include <deque>
#include <vector>
#include <stack>

void TestConstructorAndSize() {
	std::deque<int> mydeque (2,200);        // vector with 2 elements

	library::stack<int> first;                    // empty stack

	library::stack<int,library::vector<int> > second;  // empty stack using vector
	library::stack<int,std::deque<int> > third (mydeque);
	EXPECT_EQ(static_cast<int>(first.size()), 0);
	EXPECT_EQ(static_cast<int>(second.size()), 0);
	EXPECT_EQ(static_cast<int>(third.size()), 3);
	global_error == 0 ? displayTestOk("Test Constructors And Size") : displayTestError("Test Constructors And Size");
	global_error = 0;

}

void TestEmptyPopAndPush() {
	ft::stack<int> mystack;
	ft::stack<int> stdstack;
	int sum = 0;
	int stdsum = 0;

	for (int i = 1; i <= 10; i++)
	{
		mystack.push(i);
		stdstack.push(i);
	}

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	while (!stdstack.empty())
	{
		stdsum += stdstack.top();
		stdstack.pop();
	}
	EXPECT_EQ(stdsum, sum);
	global_error == 0 ? displayTestOk("Empty, Pop and Push") : displayTestError("Empty, Pop and Push");
	global_error = 0;
}

void testAllStack() {
	displayPart("Stack");
//	displayShortPart("STACK FUNCTIONS");
	TestConstructorAndSize();
	TestEmptyPopAndPush();
}