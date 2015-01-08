/*
BUBBLE SORT
Compare 2 elements and place the bigger one towards the right .
At first pass of inner loop the largest element will be at the last position , (n-1 comparissons)
At 2nd pass 2nd largest element at 2nd  last position , (n-2 comparrisions)
T(n) = (n-1) + (n-2) + (n-3) + .... + 1 .
=O(n^2) .  
If the array is already sorted , 'sorted' will remain '1' after execution of inner for loop and the outer for loop will break.
 */

#include<stdio.h>


void main(){

	int array[10] = {90,806,2,50,0,454,33,1,232,111};
	int size = 10 , sorted = 1 ;
	int temp ;
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i-1; j++ ){
			if(array[j]>array[j+1]){
				temp = array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				sorted = 0;
			}
		}

		if(sorted == 1){
			break;
		}
	}

	printArray(array,size);
}

void printArray(int * a , int size){


	for(int i = 0; i<size ; i++){

		printf("  %d", a[i]);

	}

}
