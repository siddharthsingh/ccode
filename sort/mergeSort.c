/*
MERGE SORT
Based on divide and conquer approach.
Array is divided into 2 equal halves
Merge function is a function to produce a sorted array from already sorted subarrays
T(n) = O(nlogn)
*/


#include<stdio.h>

#define size 10
// we cannot use 'int size = 10;' here  . If we do , we will get error: variably modified 'b' at file scope
//An array such as b[size] will be called a variable length array (if we use int size = 10;)
//This means that you cannot declare an array whose size varies with the needs of the program as it runs
int b[size];

void main(){


int array[10] = {12,24,11 ,34 ,0 ,3234,342 ,90,232 ,10};
mergeSort(array , 0 , 9);
printArray(array);


}

void printArray(int * a ){
for(int i=0; i<size; i++ ){
printf("  %d",a[i]);

}
}

void mergeSort(int * a , int low , int high){

if(low != high){

//we cannot use mid1 because low/2 + low/2 is evaluated as taking the floor of low/2 and adding it with the floor of high/2 .
//e.g. int x = 3/2 + 3/2;  value of 'x' will be '2' not '3' .
//int mid1 = low/2 + high/2;

int mid = (low+ high)/2;

mergeSort(a , low , mid );
mergeSort(a , mid+1 , high);
merge(a , low , mid , high);
}

}


void merge(int * a,  int low , int mid ,int high ){
int l=low , m = mid+1 ,  k =low ;

while( l <= mid && m <= high){
if(a[l] < a[m]){
b[k]=a[l];
l++;
k++;
}
else{
b[k]=a[m];
m++;
k++;
}


}

if(l == mid+1 ){ // 1st subarray finished so add al the remaining elements of 2nd subarray
while(m <= high){
b[k] = a[m];
m++;
k++;
}
}

if(m == high + 1 ){  // 2nd subarray finished .
while(l <= mid){
b[k] = a[l];
l++;
k++;
}
}



for(int x=low; x<=high; x++){
//copy to original array
a[x] = b[x];

}

}
