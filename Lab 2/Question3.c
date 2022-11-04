#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){

	int count, index=0;

	//the following loop calculates the diagonal pattern of accessing the elements in the matrix mat rom the top left of the matrix
	//the values are appended to the array arr[]
	//this calculates for the top half of the matrix
	for(int count=0; count<N3; count++){
		//initialize the values of row and cols each time there is a new iteration of the for loop
		int row=count, cols=0;

		//this while loop ensures that matrix array is scanned diagonally by indexing to the correct position in the matrix
		//and those ordered values at each index are appended to the array arr[]
		while(row>=0 && cols<N3){
			arr[index]= mat[row][cols];
			row--;   //post-decrement value of rows
			cols++;  //post-increment value of columns
			index++; //increase the index value to move to the next position in array arr[]
		}
	}

	//this loop calculates the diagonal pattern of accessing the elements in the matrix for the bottom half of the matrix
	//these remaining values are appended to the array arr[]
	for(count=1; count<N3; count++){
		int row=N3-1, cols=count;

		//this while loop ensures that matrix array is scanned diagonally by indexing to the correct position in the matrix
	    //and those ordered values are appended to the array arr[]
		while(row>=0 && cols<N3){
			arr[index]= mat[row][cols];
			row--;
			cols++;
			index++;
		}
	}


}
