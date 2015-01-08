#include<stdio.h>


void main(){


int heap[8] = {10 , 60 , 80 , 25 , 45 , 50 , 30 , 20 };
//printf("%d \n",sizeof(heap));

//size of array 
int size = 8;

//printing the heap before applying heapify
printHeap(heap , size); 

//position of node where we want to apply heapify
int pos = 0;

heapify(heap , pos , size);

printHeap(heap, size);
}

void printHeap(int a[] , int size){
//integer array is passed as pointers so if we use sizeof on 'a' we get the sizeof the pointer . which is 8 (in 64 bit m/c)
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

if(a[leftChild] > a[pos] &&  leftChild < heapSize){
max = leftChild;

}

if(a[rightChild] > a[max] && rightChild < heapSize){

	max = rightChild;
}
if(max != pos){

	int temp = a[pos];
	a[pos] = a[max];
	a[max] = temp;

}

//we only apply heapify to non leaf elements  and in a heap number of number of non leaf elements are from o - n/2 (n=size of heap)
if(max <= heapSize/2 && max != pos ){

heapify(a, max , heapSize);

}

}
