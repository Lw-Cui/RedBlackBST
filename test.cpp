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
    uniform_int_distribution<int> distribution{1, 1000};
    auto dice = bind(distribution, generator);
	RedBlackBST tree;
	multiset<int> standard;
	set<int> con;
	for (int i = 0; i < 100000; i++) {
		int rand = dice();
		if (!con.count(rand)) {
			con.insert(rand);
			tree.insert(rand);
			standard.insert(rand);
		}
	}
	std::vector<int> v1{tree.get_data()};
	for (int i = 0; i < 100000; i++) {
		int rand{dice()};
		tree.del(rand);
		standard.erase(rand);
		std::vector<int> v2{tree.get_data()};
		v2.clear();
	}
	std::vector<int> v{tree.get_data()};
	auto rb_ite = v.begin();
	auto set_ite = standard.begin();
	while (rb_ite != v.end() && set_ite != standard.end())
		ASSERT_EQ(*set_ite++, *rb_ite++);
}