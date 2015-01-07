#include<stdio.h>


void main(){

//int heap[9] = {20,100,80,60,45,50,30,25,10};
int heap[8] = {10 , 60 , 80 , 25 , 45 , 50 , 30 , 20 };
//printf("%d \n",sizeof(heap));
int size = 8;

printHeap(heap , size); 

heapify(heap , 0 , size);

printHeap(heap, size);
}

void printHeap(int a[] , int size){
//integer array is passed as pointers so if we use size of on a we get the pointer size . which is 8 (in 64 bit mc)
//int arraySize = sizeof(a);
//printf("%d \n",sizeof(int));
printf("\nHeap :  ");
for(int i = 0 ; i< size; i++){
	printf("%d  ",a[i]);
}

}

void heapify(int * a , int pos , int arraySize){

int leftChild = 2*pos + 1;
int rightChild = 2*pos + 2;
int max = pos;
//int arraySize = sizeof(a)/sizeof(int); cannot be used here as arrays are passed as pointer .

if(a[leftChild] > a[pos] &&  leftChild < arraySize){
max = leftChild;

}

if(a[rightChild] > a[max] && rightChild < arraySize){

	max = rightChild;
}
if(max != pos){

	int temp = a[pos];
	a[pos] = a[max];
	a[max] = temp;

}


if(max <= arraySize/2 && max != pos ){
heapify(a, max , arraySize);
}

}
