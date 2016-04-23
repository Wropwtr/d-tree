#include "graph.h"
#include "edge.h"
#include "kruskal.h"


int main(){
	graph<int> *g = new graph<int>(5,7);

	g->insEdge(0,new edge<int>( 0, 1, 2));
	g->insEdge(1,new edge<int>( 0, 2, 5));
	g->insEdge(2,new edge<int>( 0, 4, 3));
	g->insEdge(3,new edge<int>( 1, 3, 0));
	g->insEdge(4,new edge<int>( 2, 3, 2));
	g->insEdge(5,new edge<int>( 2, 4, 1));
	g->insEdge(6,new edge<int>( 3, 4, 1));


	kruskal<int> *k = new kruskal<int>(g);
	for( int i = 0; i < k->carcaseSize; i++)
		k->carcase[i].printEdge();
	getchar();

	delete k;
	delete g;
	return 1;
}