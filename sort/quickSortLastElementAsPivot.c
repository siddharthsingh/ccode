/*
 * QUICK SORT USING Last Element As Pivot
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
	
	
	int pivot = a[high] , i=low-1 , temp;
	//we only compare elements till position of pivot-1
	for(int x=low; x<=high-1; x++){
		
		
		if(a[x]<=pivot && x>i ){
			//printf("  swapping %d and %d " , a[i+1] , a[x]);
			i++;
			//swap a[i] <--> a[x]
			temp = a[i];
			a[i] = a[x];
			a[x] = temp;
			}
		
		
		}
	//all the elements till a[i] are smaller than pivot 
	// swap a[i+1] and pivot
	temp = a[high];
	a[high] = a[i+1];
	a[i+1] = temp;

//printArray(a,10);
//printf("   pivot = %d\n\n\n",i+1);

	//return position of pivot
	
	return i+1;
	
	
	}
