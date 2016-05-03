#include <gtest.h>
#include "plenty.h"

TEST(Plenty, can_create_plenty)
{
	ASSERT_NO_THROW(plenty *p = new plenty(10));
}

TEST(Plenty, can_make_singles)
{
	plenty *p = new plenty(10);
	for (int i = 0; i < 10; i++)
		p->makeSingle(i);
	ASSERT_TRUE(p->getPlenty(9) == 9);
}

TEST(Plenty, can_unite_1)
{
	plenty *p = new plenty(10);
	for (int i = 0; i < 10; i++)
		p->makeSingle(i);
	for (int i = 0; i < 9; i++)
		p->unite(i, i + 1);
	ASSERT_TRUE(p->getPlenty(9) == 9 && p->getPlenty(0) == 9);
}

TEST(Plenty, can_unite_2)
{
	plenty *p = new plenty(4);
	for (int i = 0; i < 4; i++)
		p->makeSingle(i);
	p->unite(0, 1);
	p->unite(2, 3);
	p->unite(1, 3);
	ASSERT_TRUE(p->getPlenty(1) == 3 && p->getPlenty(0) == 3);
}