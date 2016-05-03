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
  delete t;
}

TEST(Tree, throw_then_oversize)
{
	tree<int> *t = new tree<int>(1,2);

	int *a = new int;
	int *b = new int;
	t->insert(a);
	ASSERT_ANY_THROW(t->insert(b));

	delete a;
	delete b;
	delete t;
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

  delete t;
}

TEST(Tree, can_do_heap_from_1_element){
	tree<int> *t = new tree<int>();
	int *a = new int;
	*a = 5;
	t->insert(a);
	t->doHeap();
	EXPECT_EQ(*(t->deleteNode()), 5);

	delete a;
	delete t;
}

TEST(Tree, can_do_heap_1)
{
	tree<int> *t = new tree<int>();
	int *a = new int;
	int *b = new int;
	int *c = new int;
	int *d = new int;
	*a = 5;
	*b = 8;
	*c = 200;
	*d = 346;
	t->insert(a);
	t->insert(b);
	t->insert(c);
	t->insert(d);
	t->doHeap();
	for (int i = 1; i <= 3; i++)
		t->deleteNode();
	EXPECT_EQ(*(t->deleteNode()), 346);

	delete a;
	delete b;
	delete c;
	delete d;
	delete t;
}

TEST(Tree, can_do_heap_2)
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
  delete t;
}

TEST(Tree, can_do_heap_3)
{
	tree<int> *t = new tree<int>();
	int *a = new int;
	int *b = new int;
	int *c = new int;
	int *d = new int;
	*a = 346;
	*b = 200;
	*c = 8;
	*d = 4;
	t->insert(a);
	t->insert(b);
	t->insert(c);
	t->insert(d);
	t->doHeap();
	for (int i = 1; i <= 3; i++)
		t->deleteNode();
	EXPECT_EQ(*(t->deleteNode()), 346);
	delete a;
	delete b;
	delete c;
	delete d;
	delete t;
}

TEST(Tree, can_set_d)
{
	tree<int> *t = new tree<int>(100, 10);
	int **arr = new int*[50];
	for (int i = 0; i < 50; i++){
		arr[i] = new int;
		*arr[i] = i;
		t->insert(arr[i]);
	}
	// {0, 1, 2, ... ,49}
	t->doHeap();
	for (int i = 0; i < 49; i++)
		t->deleteNode();
	EXPECT_EQ(*(t->deleteNode()), 49);

	for (int i = 0; i < 50; i++)
		delete arr[i];
	delete []arr;
	delete t;
}







