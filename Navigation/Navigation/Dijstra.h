#include "pgh.h"
#include "struct.h"
#include "Data.h"
#include "Heap.h"

JC Dijstra(int start,int end){

	Heap* Heaps = (Heap*)malloc(sizeof(Heap));
	int adj_number = 0;
	JC* adj_JCs[Max_JC];
	JC* adj_JC,*V;
	JC** Graph= Setting_Map(start);
	JC* Start = Graph[start];
	Start->select = true;
	for (int i = 0; i < Start->part; i++) {
		adj_JC = Start->adj[i]->end;
		adj_JC->distance = Start->adj[i]->distance;
		adj_JC->path[(adj_JC->stopover)++] = Start->number;
		adj_JC->time = ((Start->adj[i]->distance/80.0))*60*Start->adj[i]->traffic;
		adj_JCs[adj_number++] = adj_JC;
	}
	
	while (1) {
		Heap_init(Heaps);
		for (int i = 0; i < adj_number; i++) {
			if (!(adj_JCs[i]->select)) {
				insert_heap(Heaps, adj_JCs[i]);
			}
		}
		V=delete_heap(Heaps);
		V->select = true;
		for (int i = 0; i <V->part; i++){
			adj_JC = V->adj[i]->end;
			if (!(adj_JC->select)) {
				if (adj_JC->stopover == 0) {
					adj_JCs[adj_number++] = adj_JC;
				}
				if (V->distance+V->adj[i]->distance<adj_JC->distance) {
					adj_JC->distance = V->distance + V->adj[i]->distance;
					adj_JC->time = V->time + (V->adj[i]->distance / 80.0) * 60 * V->adj[i]->traffic;
					for (int i = 0; i < V->stopover; i++) {
						adj_JC->path[i] = V->path[i];
					}
					adj_JC->stopover = V->stopover;
					adj_JC->path[(adj_JC->stopover)++] = V->number;
					if (adj_JC->number == end) {
						JC Stop = *adj_JC;
						free(Graph);
						return Stop;
					}
				}
				
			}
		}
	}
}