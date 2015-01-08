/*
SELECTION SORT
It finds the location of the smallest element in array and the swaps that element with with 1st element of array (Array[0]  <----> array[location])
At first pass of inner loop the smalest element will be at the first position , (n-1 comparissons)
At 2nd pass 2nd smallest element at 2nd  position , (n-2 comparrisions)
T(n) = (n-1) + (n-2) + (n-3) + .... + 1 .
=O(n^2) .  
Even if the array is already sorted it will take O(n^2) time .
*/

#include<stdio.h>


void main(){

int array[10] = {90,806,2,50,0,454,33,1,232,111};
int size = 10 , min , pos;

for(int i=0; i<size; i++){
min = array[i];
for(int j=i+1; j<size; j++ ){
if(array[j]<min){
min=array[j];
pos = j;
}
if(min != array[i]){
array[pos] = array[i];
array[i] = min;
}
}

}

printArray(array,size);
}

void printArray(int * a , int size){


for(int i = 0; i<size ; i++){

printf("  %d", a[i]);

}

}
