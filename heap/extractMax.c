/*
1.Extract max value from the heap .
2.First element of heap (root node) = last element of heap 
3.Apply heapify on the root node with size of the heap decrementented by 1 .
 */

#include<stdio.h>


void main(){

	int heap[9] = {100,20,80,60,45,50,30,25,10};
	//printf("%d \n",sizeof(heap));

	int heapSize = 9;
	printHeap(heap , heapSize);

	//element 1 is at wrong position so we apply heapify at position 1 .
	heapify(heap , 1 , heapSize);

	printHeap(heap,heapSize);

	//extract max element from the heap
	for(int i=0; i<heapSize; i++){
		//size of the heap decrements by 1 each time we extract max element
		extractMax( heap , heapSize-i );


	}


}

void extractMax(int * a , int size){

	printf("\nmax = %d",a[0]);

	//if size of heap is 'x', last element is at position 'x-1' .
	size--;
	a[0] = a[size];
	if(size != 0){
		heapify(a , 0 ,size);
		printHeap(a,size);
	}
}


void printHeap(int * a , int size){
	//integer array is passed as pointers so if we use sizeof(a) we get the pointer size . which is 8 (in 64 bit mc)
	//int arraySize = sizeof(a);
	//printf("%d \n",sizeof(int));
	printf("\nHeap :  ");
	for(int i = 0 ; i< size; i++){
		printf("%d  ",a[i]);
	}

}



void heapify(int * a , int pos , int heapSize){

	int leftChild = 2*pos + 1;
	int rightChild = 2*pos + 2;
	int max = pos;
	//int arraySize = sizeof(a)/sizeof(int); cannot be used here as arrays are passed as pointer .

	if(a[leftChild] > a[pos] &&  leftChild <= heapSize){

		max = leftChild;
	}

	if(a[rightChild] > a[max] && rightChild <= heapSize){

		max = rightChild;


	}
	if(max != pos){

		int temp = a[pos];
		a[pos] = a[max];
		a[max] = temp;

	}

	if(max <= heapSize/2 && max != pos){
		heapify(a, max , heapSize);
	}

}
