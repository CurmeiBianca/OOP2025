#include "pch.h"
#include "Header.h"
#include <vector>

using namespace std;

TEST(SuitaMeaDeTest, Test) 
{
	myClass<int> sorter;
	vector<int> v = { 17, 18, 11, 2, 21 };
	
	sorter.sortList(v);

	EXPECT_TRUE(isSorted(v));
	EXPECT_EQ(v[0], 21);
	EXPECT_EQ(v[1], 18);
	EXPECT_EQ(v[2], 17);
	EXPECT_EQ(v[3], 11);
	EXPECT_EQ(v[4], 2);
}