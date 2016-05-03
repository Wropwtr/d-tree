#pragma once
#include <gtest.h>
#include "kruskal.h"

TEST(Kruskal, throw_then_graph_is_not_exist){
    graph<int> *g = 0;
    ASSERT_ANY_THROW(kruskal<int> *k = new kruskal<int>(g));
}

TEST(Kruskal, throw_then_graph_is_not_connected_1){
	graph<int> *g = new graph<int>(12, 9);
	ASSERT_ANY_THROW(kruskal<int> *k = new kruskal<int>(g));
}

TEST(Kruskal, throw_then_graph_is_not_connected_2){
	graph<int> *g = new graph<int>(12, 0);
	ASSERT_ANY_THROW(kruskal<int> *k = new kruskal<int>(g));
}

TEST(Kruskal, throw_then_graph_is_not_connected_3){
	graph<int> *g = new graph<int>(1, 0);
	ASSERT_ANY_THROW(kruskal<int> *k = new kruskal<int>(g));
}

TEST(Kruskal, can_create_carcase_from_1_edge){
    graph<int> *g = new graph<int>(2,1);
    g->insEdge(0,new edge<int>( 0, 1, 2));
    kruskal<int> *k = new kruskal<int>(g);
    
    EXPECT_EQ( (k->carcase[0].w == 2) && (k->carcaseSize == 1), true);
    
    delete k;
    delete g;
}

TEST(Kruskal, can_create_carcase_from_5_edges){
    graph<int> *g = new graph<int>(6,9);
    
    g->insEdge(0,new edge<int>( 0, 1, 7));
	g->insEdge(1,new edge<int>( 0, 2, 9));
	g->insEdge(2,new edge<int>( 0, 5, 14));
    
	g->insEdge(3,new edge<int>( 2, 5, 2));
	g->insEdge(4,new edge<int>( 2, 3, 11));
	g->insEdge(5,new edge<int>( 2, 1, 10));
    
	g->insEdge(6,new edge<int>( 1, 3, 15));
	g->insEdge(7,new edge<int>( 3, 4, 6));
	g->insEdge(8,new edge<int>( 5, 4, 9));
    
    kruskal<int> *k = new kruskal<int>(g);

    EXPECT_EQ(k->carcaseSize, 5);
    
    delete k;
    delete g;
}

TEST(Kruskal, tree_carcase_for_itself){
	graph<int> *g = new graph<int>(6, 5);

	g->insEdge(0, new edge<int>(0, 1, 7));
	g->insEdge(1, new edge<int>(1, 2, 9));
	g->insEdge(2, new edge<int>(2, 3, 14));

	g->insEdge(3, new edge<int>(3, 4, 4));
	g->insEdge(4, new edge<int>(4, 5, 1));

	kruskal<int> *k = new kruskal<int>(g);

	EXPECT_EQ(k->carcaseSize, 5);
	delete k;
	delete g;
}


