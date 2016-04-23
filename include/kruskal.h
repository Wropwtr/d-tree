#pragma once
#include "graph.h"
#include "queue.h"
#include "plenty.h"

template <class weightType>
class kruskal{
public:
	edge<weightType> *carcase;
	int carcaseSize;

	kruskal(graph<weightType> *&g);
	~kruskal() { delete carcase; }
};

template <class weightType>
kruskal<weightType>::kruskal(graph<weightType> *&g){
    if ( !g || g->m == 0 ) 
        throw "Bad input";

	if (!g->isConnected())
		throw "Graph is not connected.";
        
	queue<edge<weightType>> *q = new queue<edge<weightType>>(g->m); 
	for( int i = 0; i < g->m; i++)
		q->insert(g->edges[i]);

	plenty *p = new plenty(g->n);
	for( int i = 0; i < g->n; i++)
		p->makeSingle(i);

	edge<weightType>   *e;
	int n, k;
	carcase = new edge<weightType>[(g->n)-1]; // m = n-1 edges in any case
	carcaseSize = 0;

	while(carcaseSize+1 < g->n && !q->isEmpty() ){
		e = q->getTop();
		n = p->getPlenty(e->s);
		k = p->getPlenty(e->e);
		if ( n != k ){
			p->unite(n, k);
			carcase[carcaseSize] = *e;
			carcaseSize++;
		}
	}

	delete q;
	delete p;	
}