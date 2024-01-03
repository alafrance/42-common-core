#include <gtest/gtest.h>
#include "../ft_containers/stack.hpp"
#include "../ft_containers/vector.hpp"
#include <list>
TEST(StackTest, Constructor)
{
std::list<int> mylist(3, 100);		// deque with 3 elements
ft::vector<int> myvector(2, 200);	// vector with 2 elements

ft::stack<int, std::list<int> > first;			  // empty stack
ft::stack<int, std::list<int> > second(mylist);  // stack initialized to copy of deque

ft::stack<int, ft::vector<int> > third;  // empty stack using vector
ft::stack<int, ft::vector<int> > fourth(myvector);
EXPECT_EQ(first.size(), size_t(0));
EXPECT_EQ(second.size(), size_t(3));
EXPECT_EQ(third.size(), size_t(0));
EXPECT_EQ(fourth.size(), size_t(2));
}

TEST(StackTest, Empty)
{
ft::stack<int> mystack;
int sum(0);

for (int i = 1; i <= 10; i++)
mystack.push(i);

while (!mystack.empty())
{
sum += mystack.top();
mystack.pop();
}
EXPECT_EQ(sum, 55);
}

TEST(StackTest, Push)
{
ft::stack<int> mystack;

for (int i = 0; i < 5; ++i)
mystack.push(i);

int i = 4;
while (!mystack.empty())
{
EXPECT_EQ(mystack.top(), i--);
mystack.pop();
}
}

TEST(StackTest, Size)
{
ft::stack<int> myints;
EXPECT_EQ(myints.size(), size_t(0));
for (int i = 0; i < 5; i++)
myints.push(i);
EXPECT_EQ(myints.size(), size_t(5));
myints.pop();
EXPECT_EQ(myints.size(), size_t(4));
}

TEST(StackTest, Top)
{
ft::stack<int> mystack;

mystack.push(10);
mystack.push(20);

mystack.top() -= 5;

EXPECT_EQ(mystack.top(), 15);
}

TEST(StackTest, RelOp1)
{
ft::vector<int> a;
a.push_back(10);
a.push_back(20);
a.push_back(30);

ft::stack<int, ft::vector<int> > foo(a);
ft::stack<int, ft::vector<int> > bar(a);
ft::stack<int, ft::vector<int> > bob;
bob.push(30);
bob.push(20);
bob.push(10);
bar.push(0);

EXPECT_FALSE(bob == bar);
EXPECT_TRUE(bar != foo);
EXPECT_TRUE(bar != bob);
EXPECT_FALSE(foo > bar);
EXPECT_TRUE(foo < bar);
EXPECT_FALSE(foo >= bar);
EXPECT_TRUE(foo <= bar);
}

TEST(StackTest, RelOp2)
{
int array[5] = {0, 1, 2, 3, 4};
ft::stack<int, ft::vector<int> > stack(ft::vector<int>(array, array + 5));
ft::stack<int, ft::vector<int> > stack2(stack);

EXPECT_EQ(stack, stack2);
EXPECT_TRUE(stack >= stack2);
EXPECT_TRUE(stack <= stack2);

stack2.push(50);
EXPECT_TRUE(stack != stack2);
EXPECT_TRUE(stack < stack2);
EXPECT_TRUE(stack <= stack2);
EXPECT_TRUE(stack2 > stack);
EXPECT_TRUE(stack2 >= stack);

stack.push(200);
EXPECT_TRUE(stack != stack2);
EXPECT_TRUE(stack > stack2);
EXPECT_TRUE(stack >= stack2);
EXPECT_TRUE(stack2 < stack);
EXPECT_TRUE(stack2 <= stack);
}
