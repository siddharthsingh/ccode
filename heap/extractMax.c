#include<stdio.h>


void main(){

int heap[9] = {100,20,80,60,45,50,30,25,10};
//printf("%d \n",sizeof(heap));

printHeap(heap , 9);

heapify(heap , 1 , 9);
printHeap(heap,9);
for(int i=0; i<9; i++){
	extractMax(heap,9-i);
	

}


}

void extractMax(int * a , int size){
 printf("\nmax = %d",a[0]);

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



void heapify(int * a , int pos , int arraySize){

int leftChild = 2*pos + 1;
int rightChild = 2*pos + 2;
int max = pos;
//int arraySize = sizeof(a)/sizeof(int); cannot be used here as arrays are passed as pointer .

if(a[leftChild] > a[pos] &&  leftChild <= arraySize){

max = leftChild;
}

if(a[rightChild] > a[max] && rightChild <= arraySize){

	max = rightChild;


}
if(max != pos){

	int temp = a[pos];
	a[pos] = a[max];
	a[max] = temp;

}

if(max <= arraySize/2 && max != pos){
heapify(a, max , arraySize);
}

}
