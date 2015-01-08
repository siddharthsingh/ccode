/*
INSERTION SORT (Inplace , Stable)
It sorts the element at the time of insertion .

*/
#include<stdio.h>

void main(){

int j , array[5] , size = 5 , temp;

for(int i=0; i<size; i++){
printf("\nEnter %d element" , i);
scanf("%d" , &array[i]);
j=i;
//we run the loop till j = 1 , so that the previous element to compare is at position 0
//we keep moving the elelment left(we are inserting) in the array till it is at right position
while( j > 0 ){
//compare with previous element if previous element is larger swap .
if(array[j] < array[j-1]){
temp = array[j];
array[j] = array[j-1];
array[j-1] = temp;

}
j--;
}
}


printArray(array,size);
}



void printArray(int * a , int size){
for(int i=0; i<size; i++){
printf("  %d",a[i]);

}

}
