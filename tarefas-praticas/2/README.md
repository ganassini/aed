
# 1792. Maximum Average Pass Ratio
## Guilherme Ganassini - M1

There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array ```classes```, where ```classes[i] = [pass_i, total_i]```. You know beforehand that in the ```ith``` class, there are ```total_i``` total students, but only ```pass+i``` number of students will pass the exam.

You are also given an integer ```extraStudents```. There are another ```extraStudents``` brilliant students that are ***guaranteed*** to pass the exam of any class they are assigned to. You want to assign each of the ```extraStudents``` students to a class in a way that maximizes the average pass ratio across all the classes.

The ***pass ratio*** of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. ***The average pass ratio*** is the sum of pass ratios of all the classes divided by the number of the classes.

*Return the ***maximum*** possible average pass ratio after assigning the ```extraStudents``` students. Answers within ```10^-5``` of the actual answer will be accepted.*

----------------------

### Links
[Heaps, heapsort, and priority queues - Inside code](https://www.youtube.com/watch?v=pLIajuc31qk) <br>
[C Program to implement max heap](https://www.geeksforgeeks.org/c-program-to-implement-max-heap/)

-----------------------
#### maxHeap

* parent(i) = (i - 1) / 2  <br>
* leftChild(i) = (2 * i) + 1 <br>
* rightChild(i) = (2 * i) + 2 

##### buildHeap

```c
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
		siftDown(h, i);
		i--;
	}

	return h;
}
```

```c
void siftDown(Heap* h, int i)
{
    while ( 1 ) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxIdx = i;

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
```

```c
void extractMax(Heap* h)
{
    h->classes[0].pass++;
    h->classes[0].total++;

    h->classes[0].gain = ((double)(h->classes[0].pass + 1) / (double)(h->classes[0].total + 1)) 
                        - ((double)h->classes[0].pass / (double)h->classes[0].total);

    siftDown(h, 0);
}
```
