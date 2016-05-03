#pragma once

#include "edge.h"
#include "mark.h"
#include "plenty.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

template <class weightType>
class graph{
public:
	int n;
	int m;
	edge<weightType> **edges;

	graph(int nn = 10, int mm = 20);
	~graph() { for( int i = 0; i < m; i++)
			       if( edges[i] ) delete edges[i];
			   delete []edges; 
			 }

	void create(weightType min, weightType max);
	void insEdge(int position, edge<weightType> *e);

	int isConnected();
};

template <class weightType>
graph<weightType>::graph(int nn, int mm){
	if (nn < 0 || mm < 0) 
		throw "Not correct size";
	n = nn;
	m = mm;
	edges = new edge<weightType>*[m];
	for ( int i = 0; i < m; i++)
		edges[i] =new edge<weightType>(0, 0, 0);
}

template <class weightType>
void graph<weightType>::create(weightType min, weightType max){
	int i, j;
	int edgeRetry;
	time_t  timev;
	time(&timev);
	
	srand((int)timev); 
	for (int k = 0; k < m; k++){	
		do{
			i = rand() % n;
			j = i;
			int hj = 0;
			while( i == j && hj < 100 ){
				j = rand() % n;
				hj++;
			}
			if( hj >= 100 )
				throw "Bad input or random";

			edgeRetry = 0;
			for (int l = 0; l < k; l++){
				int s = edges[l]->s;
				int e = edges[l]->e;
				if ( (e==i && s==j) || (e==j && s==i) ){
					edgeRetry = 1;
					break;
				}
			} // search for equals edges
		} while (edgeRetry);
		weightType w = (weightType)( (rand() % (int)(max-min)) + min + ((double) rand() / (RAND_MAX)) ); 
		// min < w < max
		if(edges[k])  delete edges[k];
		edges[k] = new edge<weightType>(i, j, w);
	}	
}

template <class weightType>
void graph<weightType>::insEdge(int position, edge<weightType> *e){
	if ( position < 0 || position >= m )
		throw "Not correct position";
	edges[position] = e;
}

template <class weightType>
int graph<weightType>::isConnected(){
	if (m == 0)
		return 0;
	plenty *p = new plenty(n);
	for( int i = 0; i < n; i++){
		p->makeSingle(i);
	}
	for( int i = 0; i < m; i++){
		if ( edges[i]->s == edges[i]->e ){
			throw "Graph has loops";
		}
		p->unite(edges[i]->s, edges[i]->e);
	}
	for( int i = 0; i < n; i++){
		if( p->getPlenty(i) != p->getPlenty(0) ){
			delete p;
			return 0;
		}
	}
	delete p;
	return 1;
} // Connetced and without loops
