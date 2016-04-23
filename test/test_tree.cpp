#include <gtest.h>
#include "tree.h"

TEST(Tree, can_create_tree)
{
  ASSERT_NO_THROW(tree<int> *t = new tree<int>());
}

TEST(Tree, can_insert)
{
  tree<int> *t = new tree<int>();
  int *a = new int;
  t->insert(a);

  EXPECT_EQ( t->deleteNode(), a );

  delete a;
}

TEST(Tree, throw_then_empty)
{
  tree<int> *t = new tree<int>();

  int *a = new int;
  int *b = new int;
  t->insert(a);
  t->insert(b);
  t->deleteNode();
  t->deleteNode();

  ASSERT_ANY_THROW( t->deleteNode() );
  delete a;
  delete b;
}

TEST(Tree, can_copy_tree)
{
  tree<int> *t = new tree<int>();

  int *a = new int;
  int *b = new int;
  t->insert(a);
  t->insert(b);

  tree<int> *t2 = new tree<int>(*t);

  EXPECT_EQ( t->deleteNode() == t2->deleteNode(), true );
}

TEST(Tree, can_do_heap)
{
  tree<int> *t = new tree<int>();

  int *a = new int;
  int *b = new int;
  int *c = new int;
  int *d = new int;
  *a = 5;
  *b = 346;
  *c = 200;
  *d = 8;

  t->insert(a);
  t->insert(b);
  t->insert(c);
  t->insert(d);

  t->doHeap();
  for( int i = 1; i <= 3; i++)
	  t->deleteNode();
  EXPECT_EQ( *(t->deleteNode()), 346 );
  delete a;
  delete b;
  delete c;
  delete d;

}











