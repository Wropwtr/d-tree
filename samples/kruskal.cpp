#include <stdio.h>
#include <cstdio>
#include "graph.h"
#include "edge.h"
#include "kruskal.h"

void generate_and_apply(FILE *&f){
	int n, m;
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	graph<float> *g = new graph<float>(n,m);
	float wMin, wMax;
	fscanf(f,"%f",&wMin);
	fscanf(f,"%f",&wMax);
	try{
		g->create(wMin, wMax);
	}
	catch (...){
		fclose(f);
		remove("graph_input.txt");
		exit(-1);
	}
	fclose (f);

	f = fopen("graph_input.txt","w");
	fprintf(f,"%d %d\n", n, m);	
	for(int i = 0; i < m; i++)
		fprintf(f,"%d %d %.2f\n",g->edges[i]->s, g->edges[i]->e, g->edges[i]->w);
	fclose (f);
	/*if (!g->isConnected()) {
		remove("graph_output.txt");
		exit(-2);
	}*/
	kruskal<float> *k;
	try{
		k = new kruskal<float>(g);
	}
	catch (...){
		remove("graph_output.txt");
		exit(-2);
	}
	FILE *out = fopen("graph_output.txt","w");
	fprintf(out,"%d %d\n",n,k->carcaseSize);
	for(int i = 0; i < k->carcaseSize; i++)
		fprintf(out,"%d %d %.2f\n",k->carcase[i].s, k->carcase[i].e,k->carcase[i].w);
	fclose(out);

	delete k;
	delete g;
}

void copy_and_apply(FILE *&f){
	int n, m;
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	int s,e;
	float w;
	graph<float> *g = new graph<float>(n,m);
	for ( int i = 0; i < m; i++){
		fscanf(f,"%d",&s);
		fscanf(f,"%d",&e);
		fscanf(f,"%f",&w);
		g->insEdge(i,new edge<float>( s, e, w));
	}
	fclose (f);
	/*if (!g->isConnected()) {
		remove("graph_output.txt");
		exit(-2);
	}*/
	kruskal<float> *k;
	try{
		k = new kruskal<float>(g);
	}
	catch (...){
		remove("graph_output.txt");
		exit(-2);
	}
	FILE *out = fopen("graph_output.txt","w");
	fprintf(out,"%d %d\n",n,k->carcaseSize);
	for(int i = 0; i < k->carcaseSize; i++)
		fprintf(out,"%d %d %.2f\n",k->carcase[i].s, k->carcase[i].e,k->carcase[i].w);
	fclose(out);
	delete k;
	delete g;
}

int main(){
	FILE *f = fopen("graph_input.txt", "r+");
	if (f == NULL){
		system("dir");
		system("pause");
		return -1;
	}

	int flag; // 1 - сгенерировать, 0 - заполнить
	fscanf(f,"%d",&flag);
	if(flag == 1){
		generate_and_apply(f);
	}
	else{
		copy_and_apply(f);
	}
	
	return 1;
} // graph_input -> graph_output