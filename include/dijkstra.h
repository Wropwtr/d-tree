#pragma once
#include "graph.h"
#include "queue.h"
#include "mark.h"
#include <limits.h>
#include <stdlib.h>

template <class weightType>
class dijkstra{
public:
	int *parents;
	mark<weightType> **marks;
	int size;

	dijkstra(graph<weightType> *&g, int startPeak);
	~dijkstra() { delete []parents; 
				  for( int i = 0; i < size; i++){
					if(marks[i]) delete marks[i]; 
				  }
				  delete []marks;
	}
};

template <class weightType>
dijkstra<weightType>::dijkstra(graph<weightType> *&g, int startPeak){
	if (!g || startPeak >= g->n || startPeak < 0 )
		throw "Not correct start peak.";

	parents = new int[g->n];
	marks = new mark<weightType>*[g->n];
	size = g->n;

	queue<mark<weightType>> *q = new queue<mark<weightType>>(g->n);
	for( int i = 0; i < startPeak; i++){
		parents[i] = -1;
		marks[i] = new mark<weightType>( i, (weightType)(INT_MAX) );
		q->insert( marks[i] );
	}
	for( int i = startPeak + 1; i < g->n; i++){
		parents[i] = -1;
		marks[i] = new mark<weightType>( i, (weightType)(INT_MAX) );
		q->insert( marks[i] );
	}
	marks[startPeak] = new mark<weightType>(startPeak , 0 );
    parents[startPeak] = startPeak;
	q->insert(marks[startPeak]);
	while( !q->isEmpty() ){
		mark<weightType> *bufMark = q->getTop();
		for( int i = 0; i < g->m; i++){
			if ( g->edges[i]->s == bufMark->index ){
				if (marks[g->edges[i]->e]->markWeight > bufMark->markWeight + g->edges[i]->w){
					marks[g->edges[i]->e]->markWeight = bufMark->markWeight + g->edges[i]->w;
					parents[g->edges[i]->e] = bufMark->index;
					q->rebalance();
					continue;
				}
			}
			if( g->edges[i]->e == bufMark->index){
				if ( marks[g->edges[i]->s]->markWeight > bufMark->markWeight + g->edges[i]->w){
					marks[g->edges[i]->s]->markWeight = bufMark->markWeight + g->edges[i]->w;
					parents[g->edges[i]->s] = bufMark->index;
					q->rebalance();
					continue;
				}
			}
		}
	}

	delete q;
}