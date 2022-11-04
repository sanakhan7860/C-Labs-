#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){

	int index1=0; //index1 indexes into the pos1 and val1 arrays
    int index2=0; //index2 indexes into the pos2 and val2 arrays
	int index3=0; //index3 indexes into the pos3 and val3 arrays
	int temp; //temp is a temporary variable in place of val3 which will hold the sum of val1 and val2


	while(1){

        //if the statement is satisfied it means that we have reached the end of the array and the sum can no
		//longer be calculated so we break out of the loop
		if(index1==k1||index2==k2){
			break;
		}

		//checks if the value in pos1 is the same as pos2
		if(pos1[index1]==pos2[index2]){

			//since the above holds true, we can add the two values at that index from the val1 and val2
			//arrays to be temporarily stored in the resulting sum array temp
			temp = val1[index1] + val2[index2];

			//condition checks if the sum of the two values in the val array is not zero
			if(temp!=0){

				val3[index3] = temp; //append the temp sum to the specified index in the val3 sum array
				pos3[index3] = pos1[index1]; //append the position value of this sum from pos1 into the pos3 array
				index3++;
					}

			index1++;
			index2++;

		}

        //checks if the position value in pos1 is greater than the position value in pos2
		//pos2 is given precedence as the smaller value
		else if(pos1[index1] > pos2[index2]){

			val3[index3] = val2[index2]; //appends the value of val2 into val3
			pos3[index3] = pos2[index2]; //appends the values position in pos2 to pos3
			index2++;
			index3++;

				}


		//checks if the position value in pos1 is less than the position value in pos2
		//pos1 is given precedence since it is the smaller value
		else if(pos1[index1] < pos2[index2]){

			val3[index3] = val1[index1]; //appends the value in val1 to to val3
			pos3[index3] = pos1[index1]; //appends the values position in pos1 to pos3
			index1++;
			index3++;
		}

	}



	//The following two while loops are used to ensure that all the appropriate values are appended to the end of the
	//val3 and pos3 arrays after the end of one or both of the val1 and val2 arrays have been reached



	//loops while index1 related to the indexing of pos1 and val1 is less than k1 which holds the number of
	//non zero elements in vector 1
	while(index1<k1){
		val3[index3] = val1[index1]; //appends the value of val1 into val3
		pos3[index3] = pos1[index1]; //appends the values position in pos1 to pos3
		index1++;
		index3++;
	}



	//loops while index2 related to the indexing of pos2 and val2 is less than k2 which holds the number of
	//non zero elements in vector 2
	while(index2<k2){
		val3[index3] = val2[index2]; //appends the value of val2 into val3
		pos3[index3] = pos2[index2]; //appends the position of pos2 into pos3
		index2++;
		index3++;

	}




}
