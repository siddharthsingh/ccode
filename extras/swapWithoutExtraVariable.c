//Swap 2 variables without extra variable.

#include<stdio.h>

void main(){
	
	int x = 100;
	int y = 200;
	//swapping using addition
	//overflow can occur if variables are very large
	x=x+y;
	y=x-y;
	x=x-y;
	printf("x = %d \ny = %d \n",x,y);
	
	//swapping using multiplication
	//will not work if either x or y is 0
	x = 100;
	y = 200;
	x = x*y;
	y = x/y;
	x = x/y;
	
	printf("x = %d \ny = %d \n",x,y);
	}
