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
void siftDown(Heap* h, int i);
void extractMax(Heap* h);

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

	for (int i = 0; i < 6; i++)
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

	free(heap->classes);
	free(heap);

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

	for ( i = (i - 2) / 2; i >= 0; i-- )
		siftDown(h, i);

	return h;
}

void siftDown(Heap* h, int i)
{
	int left, right, maxIdx;

    while ( 1 ) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        maxIdx = i;

        if ( left < h->size && h->classes[left].gain > h->classes[maxIdx].gain )
            maxIdx = left;
        if ( right < h->size && h->classes[right].gain > h->classes[maxIdx].gain )
            maxIdx = right;

        if ( maxIdx == i )
            break;

        Class temp = h->classes[i];
        h->classes[i] = h->classes[maxIdx];
        h->classes[maxIdx] = temp;

        i = maxIdx;
    }
}

void extractMax(Heap* h)
{
    h->classes[0].pass++;
    h->classes[0].total++;

    h->classes[0].gain = ((double)(h->classes[0].pass + 1) / (double)(h->classes[0].total + 1)) 
                        - ((double)h->classes[0].pass / (double)h->classes[0].total);

    siftDown(h, 0);
}
