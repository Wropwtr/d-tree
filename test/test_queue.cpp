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

