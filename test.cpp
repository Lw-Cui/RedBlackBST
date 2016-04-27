#include "gtest/gtest.h"
#include "RbBST.hpp"
#include <vector>
#include <set>
#include <random>
using namespace std;
TEST(BasicTest, InsertTest) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution{1, 1 << 30};
    auto dice = bind(distribution, generator);
	RedBlackBST tree;
	multiset<int> standard;
	for (int i = 0; i < 100000; i++) {
		int rand{dice()};
		tree.insert(rand);
		standard.insert(rand);
	}
	std::vector<int> v{tree.get_data()};
	auto rb_ite = v.begin();
	auto set_ite = standard.begin();
	while (rb_ite != v.end() && set_ite != standard.end())
		ASSERT_EQ(*set_ite++, *rb_ite++);
}

TEST(BasicTest, delTest) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution{1, 1 << 30};
    auto dice = bind(distribution, generator);
	RedBlackBST tree;
	multiset<int> standard;
	for (int i = 0; i < 100000; i++) {
		int rand = dice();
		tree.insert(rand);
		standard.insert(rand);
	}
	for (int i = 0; i < 10000; i++) {
		int rand{dice()};
		tree.del(rand);
		standard.erase(rand);
	}
	std::vector<int> v{tree.get_data()};
	auto rb_ite = v.begin();
	auto set_ite = standard.begin();
	while (rb_ite != v.end() && set_ite != standard.end())
		ASSERT_EQ(*set_ite++, *rb_ite++);
}