/*
 * QUICK SORT First element as pivot
 * divide and conquer method
 * Inplace , Not stable
 * */
#include<stdio.h>

void main(){
	int a[10] = {12,34,10,123,12,2,1211,15,2,0};
	printf("\nUnsorted Array => ");
	printArray(a,10);
	quickSort(a,0,9);
	printf("\nSorted Array => ");
	printArray(a,10);
	}

void printArray(int * a , int size){
	for(int i=0;i<size;i++){
		printf("  %d ",a[i]);
		}
	
	}

void quickSort(int * a , int low , int high ){
			
		if(low<high){
		int pivot  = partition(a , low , high);
		
		quickSort(a , low , pivot-1);
		quickSort(a , pivot+1 , high);
		}
	}
		
int partition(int * a , int low , int high ){
	
	
	int  i = low  , pivot = low  , j = high , temp;
	if(i>=j){return pivot;}
	//we only compare 
	 while(i<j)
  {
   while((a[i]<=a[pivot])&&(i<high))
   {
    i++;
   }

   while(a[j]>a[pivot])
   {
    j--;
   }

   if(i<j)
   { 
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
   }
  }

	
	
	//all the elements till a[i] are smaller than pivot 
	// swap a[i+1] and pivot
	temp = a[pivot];
	a[pivot] = a[j];
	a[j] = temp;

//printArray(a,10);
//printf("   pivot = %d\n\n\n",pivot);

	//return position of pivot
	
	return j;
	
	
	}
