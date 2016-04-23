#include <gtest.h>
#include "dijkstra.h"

TEST(Dijkstra, throw_then_bad_input_1){
    graph<int> *g = 0;
    ASSERT_ANY_THROW(dijkstra<int> *d = new dijkstra<int>(g, 0));
}

TEST(Dijkstra, can_calculate_for_1_edge){
    graph<int> *g = new graph<int>(2,1);
    g->insEdge(0,new edge<int>( 0, 1, 2));
    dijkstra<int> *d = new dijkstra<int>(g, 1);
    
	EXPECT_EQ( (d->marks[0]->markWeight == 2) && (d->parents[0] == 1), true);
    
    delete d;
    delete g;    
}

TEST(Dijkstra, can_calculate_for_0_edges){
    graph<int> *g = new graph<int>(2,0);
    dijkstra<int> *d = new dijkstra<int>(g, 0);
    
    EXPECT_EQ( (d->marks[1]->markWeight == INT_MAX) && (d->parents[1] == -1), true);
    
    delete d;
    delete g;    
}

TEST(Dijkstra, can_calculate_on_graph_from_Wiki){
    graph<int> *g = new graph<int>(7,9);
    
    g->insEdge(0,new edge<int>( 0, 1, 7));
	g->insEdge(1,new edge<int>( 0, 2, 9));
	g->insEdge(2,new edge<int>( 0, 5, 14));
    
	g->insEdge(3,new edge<int>( 2, 5, 2));
	g->insEdge(4,new edge<int>( 2, 3, 11));
	g->insEdge(5,new edge<int>( 2, 1, 10));
    
	g->insEdge(6,new edge<int>( 1, 3, 15));
	g->insEdge(7,new edge<int>( 3, 4, 6));
	g->insEdge(8,new edge<int>( 5, 4, 9));
    
    dijkstra<int> *d = new dijkstra<int>(g, 0);
    EXPECT_EQ( (d->marks[4]->markWeight == 20) && (d->parents[4] == 5), true);
    
    delete d;
    delete g;
    
} // [0..5] - connected, 6 - nave not edges

TEST(Dijkstra, can_calculate_for_single_way){
	graph<int> *g = new graph<int>(4, 3);

	g->insEdge(0, new edge<int>(0, 1, 1));
	g->insEdge(1, new edge<int>(1, 2, 1));
	g->insEdge(2, new edge<int>(2, 3, 1));

	dijkstra<int> *d = new dijkstra<int>(g, 0);

	EXPECT_EQ((d->marks[3]->markWeight == 3) && (d->parents[3] == 2), true);

	delete d;
	delete g;
}