#include <gtest.h>
#include "queue.h"

TEST(Queue, can_create_queue)
{
  ASSERT_NO_THROW(queue<int> *t = new queue<int>());
}

TEST(Queue, isEmpty_function_works)
{
  queue<int> *t = new queue<int>();
  EXPECT_EQ( t->isEmpty(), true);
}

TEST(Queue, can_insert)
{
  queue<int> *t = new queue<int>();
  int *a = new int;
  *a = 15;
  t->insert(a);
  EXPECT_EQ( *(t->getTop()), 15 );
}

TEST(Queue, can_copy_queue)
{
  queue<int> *t = new queue<int>();
  int *a = new int;
  int *b = new int;
  t->insert(a);
  t->insert(b);
  queue<int> *t2 = new queue<int>(*t);
  EXPECT_EQ( (t->getTop() == t2->getTop()), true );
}

TEST(Queue, insert_in_direct_order)
{
	queue<int> *t = new queue<int>();
	int *a = new int;
	int *b = new int;
	int *c = new int;
	int *d = new int;
	*a = 1;
	*b = 2;
	*c = 3;
	*d = 4;
	t->insert(a);
	t->insert(b);
	t->insert(c);
	t->insert(d);
	EXPECT_EQ(*(t->getTop()), 1);
}

TEST(Queue, insert_in_reverse_order)
{
	queue<int> *t = new queue<int>();
	int *a = new int;
	int *b = new int;
	int *c = new int;
	int *d = new int;
	*a = 4;
	*b = 3;
	*c = 2;
	*d = 1;
	t->insert(a);
	t->insert(b);
	t->insert(c);
	t->insert(d);
	EXPECT_EQ(*(t->getTop()), 1);
}

TEST(Queue, insert_in_random_order)
{
	queue<int> *t = new queue<int>();
	int *a = new int;
	int *b = new int;
	int *c = new int;
	int *d = new int;
	*a = 4;
	*b = 3;
	*c = 1;
	*d = 2;
	t->insert(a);
	t->insert(b);
	t->insert(c);
	t->insert(d);
	EXPECT_EQ(*(t->getTop()), 1);
}

