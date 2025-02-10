#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double gain;
	int pass;
	int total;
} Class;

typedef struct {
	Class* classes;
	int size;
	int capacity;
} Heap;

double maxAverageRatio(int** classes, int classesSize, int extraStudents);
Heap* buildHeap(int** classes, int classesSize);
void heapify(Heap* h, int i);
void extractMax(Heap* h);
void insert(Heap* h, double val);
void insertHelper(Heap* h, int i);

int main(void)
{
	int values[6][2] = {
		{583,868},
		{783,822},
		{65,262},
		{121,508},
		{461,780},
		{484,668}
	};

	int** classes = (int**)malloc(6 * sizeof(int*));

	for (int i = 0; i < 6; i++) {
		classes[i] = (int*)malloc(2 * sizeof(int));
		
		for (int j = 0; j < 2; j++)
			classes[i][j] = values[i][j];
	}

	printf("%lf\n", maxAverageRatio(classes, 6, 8));

	for (int i = 0; i < 4; i++)
		free(classes[i]);

	free(classes);

	return 0;
}

double maxAverageRatio(int** classes, int classesSize, int extraStudents) {
	Heap* heap = buildHeap(classes, classesSize);
	double sum = 0;


	for ( int i = 0; i < extraStudents; i++ )
		extractMax(heap);
	
	for ( int i = 0; i < classesSize; i++ )
		sum += (double)heap->classes[i].pass / (double)heap->classes[i].total;

	return sum / (double)classesSize;
}

Heap* buildHeap(int** classes, int classesSize)
{
	Heap* h = (Heap*)malloc(sizeof(Heap));

	if ( !h ) {
		printf("Failed to allocate memory.\n");
		return NULL;
	}

	h->size = 0;
	h->capacity = classesSize;
	h->classes = (Class*)malloc(h->capacity * sizeof(Class));

	if ( !h->classes ) {
		printf("Failed to allocate memory.\n");
		return NULL;
	}

	int i;
	for ( i = 0; i < h->capacity; i++ ) {
		h->classes[i].pass = classes[i][0];
		h->classes[i].total = classes[i][1];
		h->classes[i].gain = ((double)(h->classes[i].pass + 1) / (double)(h->classes[i].total + 1)) - 
							 ((double)h->classes[i].pass / (double)h->classes[i].total);
	}

	h->size = i;
	i = (h->size - 2) / 2;
	while ( i >= 0 ) {
		heapify(h, i);
		i--;
	}

	return h;
}

void heapify(Heap* h, int i)
{
	int leftChild = (i * 2) + 1;
	int rightChild = (i * 2) + 2;
	int max = i;

	if ( leftChild >= h->size || leftChild < 0)
		leftChild = -1;
	if ( rightChild >= h->size || rightChild < 0 )
		rightChild = -1;

	if ( leftChild != -1 && h->classes[leftChild].gain > h->classes[max].gain )
		max = leftChild;
	if ( rightChild != -1 && h->classes[rightChild].gain > h->classes[max].gain )
		max = rightChild;

	if ( max != i ) {
		Class tmp = h->classes[max];
		h->classes[max] = h->classes[i];
		h->classes[i] = tmp;

		heapify(h,max);
	}
}

void extractMax(Heap* h)
{
	h->classes[0].pass++;
	h->classes[0].total++;
	h->classes[0].gain = ((double)(h->classes[0].pass + 1) / (double)(h->classes[0].total + 1)) 
						 - ((double)h->classes[0].pass / (double)h->classes[0].total);

	Class tmp = h->classes[h->size - 1];
	h->classes[h->size - 1] = h->classes[0];
	h->classes[0] = tmp;

	heapify(h, 0);
}
