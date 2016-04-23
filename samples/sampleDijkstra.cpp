#include "dijkstra.h"
#include "graph.h"
#include <iostream>

using namespace std;


int main(){
	graph<int> *g = new graph<int>(5,7);

	g->insEdge(0,new edge<int>( 0, 1, 2));
	g->insEdge(1,new edge<int>( 0, 2, 5));
	g->insEdge(2,new edge<int>( 0, 4, 3));
	g->insEdge(3,new edge<int>( 1, 3, 0));
	g->insEdge(4,new edge<int>( 2, 3, 2));
	g->insEdge(5,new edge<int>( 2, 4, 1));
	g->insEdge(6,new edge<int>( 3, 4, 1));
	cout << "Input edges:" << endl;
	cout << "0 - 1 2 " << endl;
	cout << "0 - 2 5 " << endl;
	cout << "0 - 4 3 " << endl;
	cout << "1 - 3 0 " << endl;
	cout << "2 - 3 2 " << endl;
	cout << "2 - 4 1 " << endl;
	cout << "3 - 4 1\n\n Output marks:" << endl;

	dijkstra<int> *d = new dijkstra<int>(g, 0);
	for( int i = 0; i < g->n; i++)
		cout << d->marks[i]->index << " - " << d->marks[i]->markWeight << endl;
	getchar();

	delete d;
	delete g;
	return 1;
}