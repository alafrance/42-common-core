//
// Created by Alexis Lafrance on 11/9/21.
//

#include <gtest/gtest.h>
#include "../ft_containers/pair.hpp"
//
//TEST(PairTest, PairWorksWithMakePairAndWithConstructor) {
//	ft::pair<int, int> pair;
//
//	pair = ft::make_pair(15, 'a');
//	EXPECT_EQ(pair.first, 15);
//	EXPECT_EQ(pair.second, 97);
//
//	ft::pair<std::string, double> pair2("hello test", 21.5);
//
//	EXPECT_EQ(pair2.first, "hello test");
//	EXPECT_EQ(pair2.second, 21.5);
//}
//
//TEST(PairTest, OperatorEqual) {
//	ft::pair<std::string, int> planet, homeplanet;
//
//	planet = ft::make_pair("Earth", 6371);
//	homeplanet = planet;
//	EXPECT_EQ(planet.first, "Earth");
//	EXPECT_EQ(planet.second, 6371);
//	EXPECT_EQ(homeplanet.first, "Earth");
//	EXPECT_EQ(homeplanet.second, 6371);
//}
//
//TEST(PairTest, RelationalOperator) {
//	ft::pair<int, char> foo(10, 'z');
//	ft::pair<int, char> bar(90, 'a');
//
//	EXPECT_EQ((foo == bar), false);
//	EXPECT_EQ((foo == foo), true);
//	EXPECT_EQ((foo != foo), false);
//	EXPECT_EQ((foo > bar), false);
//	EXPECT_EQ((foo < bar), true);
//	EXPECT_EQ((foo >= bar), false);
//	EXPECT_EQ((foo <= bar), true);
//}
//
