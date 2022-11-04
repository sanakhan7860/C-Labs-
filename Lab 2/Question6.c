#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){

	//index represents the index value into the source array
	//index2 represents the index value into the pos and val array
	int index=0, index2=0;

	//loop goes through each element in the source array
	for(index=0; index<size; index++){

		//checks if the value at the given index is not zero
		if(source[index] != 0){

			val[index2]=source[index]; //appends the non zero value from the source array to the val array
			pos[index2]=index; //appends the position/index of the non zero value in the source array to the pos array
			index2++; //increase the count of the index for the val and pos array to store the next set of values
		}
	}

}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

	//sindex represents the index value into the source array
	//index1 represents the index value into the pos and val array
	int sindex,index1;

	//outer loop iterates through each value in the source array
	//m represents the size of the source array
	for(sindex=0;sindex<m;sindex++){

		//inner loop iterates through each value in the pos and val arrays
		//n is the size of the val and pos arrays
		for(index1=0;index1<n;index1++){

			//checks if the specific index of the source array is equal to the index value stored in the pos array
			//if sindex is larger than index1, then the rest of the elements in the source array are replaced with a zero
			if(sindex==pos[index1]){

				//reconstructs the source array by changing the values within the source array to those stored in the val array
				source[sindex]=val[index1];//updates value of source at specific index to a value in the val array
				break;
			}
		}
	}


    
	

}
