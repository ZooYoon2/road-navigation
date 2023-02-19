#pragma once
#include "pgh.h"
typedef struct JC {
	int number;
	int part;
	struct road* adj[5];
	bool select;
	int distance;
	int time;
	int stopover;
	int path[30];
}JC;

typedef struct road {
	int distance;
	double traffic;
	JC* end;
}road;

typedef struct Heap {
	JC* Heaps[Max_JC];
	int Heapsize;
}Heap;
