#pragma once
#include "struct.h"

void Heap_init(Heap* h) {
	h->Heapsize = 0;
}
void insert_heap(Heap* h,JC* A) {
	int i = ++(h->Heapsize);
	while ((i != 1) && (A->time < h->Heaps[i / 2]->time)) {
		h->Heaps[i] = h->Heaps[i / 2];
		i /= 2;
	}
	h->Heaps[i] = A;
}

JC* delete_heap(Heap* h) {
	JC* value = h->Heaps[1];
	return value;
}
