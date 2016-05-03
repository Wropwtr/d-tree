#include <gtest.h>
#include "graph.h"

TEST(Graph, can_create_graph_pointer)
{
	graph<int> *g = new graph<int>(3,2);
  ASSERT_NO_THROW(graph<int> *g = new graph<int>(3,2));
}

TEST(Graph, can_insert_edges)
{
	graph<int> *g = new graph<int>(3, 2);
	edge<int> *a = new edge<int>(1, 2, 1);
	g->insEdge(0, new edge<int>(0, 1, 2));
	g->insEdge(1, a);
	EXPECT_EQ(a, g->edges[1]);
}

TEST(Graph, can_create_graph)
{
  graph<int> *g = new graph<int>(3,2);
  g->create(0,10);
  int has_no_loops_and_good_weight = 1;
  for( int i = 0; i < g->m; i++)
	  if( g->edges[i]->e == g->edges[i]->s || 
		  g->edges[i]->w < 0 || g->edges[i]->w > 10 )
		  has_no_loops_and_good_weight = 0;
  EXPECT_EQ( has_no_loops_and_good_weight, 1);
}

TEST(Graph, isConnected_works_1)
{
	graph<int> *g = new graph<int>(3, 2);
	g->insEdge(0, new edge<int>(0, 1, 0));
	g->insEdge(1, new edge<int>(2, 1, 2));
	EXPECT_EQ(g->isConnected(), true);
}

TEST(Graph, isConnected_works_2)
{
	graph<int> *g = new graph<int>(3, 1);
	g->insEdge(0, new edge<int>(0, 1, 0));
	EXPECT_EQ(g->isConnected(), false);
}

TEST(Graph, isConnected_works_3)
{
	graph<int> *g = new graph<int>(20, 18);
	g->create(0, 50);
	EXPECT_EQ(g->isConnected(), false);
}

TEST(Graph, isConnected_works_4)
{
	graph<int> *g = new graph<int>(100, 1);
	g->create(0, 20);
	EXPECT_EQ(g->isConnected(), false);
}

TEST(Graph, isConnected_works_5)
{
	graph<int> *g = new graph<int>(7, 9);

	g->insEdge(0, new edge<int>(0, 1, 7));
	g->insEdge(1, new edge<int>(0, 2, 9));
	g->insEdge(2, new edge<int>(0, 5, 14));

	g->insEdge(3, new edge<int>(2, 5, 2));
	g->insEdge(4, new edge<int>(2, 3, 11));
	g->insEdge(5, new edge<int>(2, 1, 10));

	g->insEdge(6, new edge<int>(1, 3, 15));
	g->insEdge(7, new edge<int>(3, 4, 6));
	g->insEdge(8, new edge<int>(5, 4, 9));

	EXPECT_EQ(g->isConnected(), false);
}

TEST(Graph, isConnected_works_with_one_node)
{
	graph<int> *g = new graph<int>(1, 0);
	EXPECT_EQ(g->isConnected(), false);
}




