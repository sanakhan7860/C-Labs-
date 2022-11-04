#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //isDiag is the flag that is returned to tell whether the mat is diagonally dominant
	//counter variable counts up each time the absolute value of the diagonal is larger than the absolute value of the sum on each row
	int isDiag=0, rows, columns, counter=0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise

	//for loop iterates through the given rows of the matrix
	for(rows=0; rows<N2; rows++){
        int row_sum = 0; //holds the sum of the values in each row excluding the value on the diagonal

		//inner for loop iterates through the given columns of the matrix
		for(columns=0; columns<N2; columns++){

			//condition which checks if the row and column index is that other than on the diagonal of the matrix
            //since the diagonal values are indexed at the same row and column value
			if(rows!=columns){
				//calculates the absolute sum of the row not including values on the diagonal
				row_sum += fabs(mat[rows][columns]);
			}

		}

		//condition checks if the absolute value in the row corresponding to the diagonal is larger
		//than the absolute value of the sum in the rest of the row
		if(fabs(mat[rows][rows]) > row_sum){
			counter++; // if condition passes, add one to the counter
		}


	}

	//checks if the counter is equal to the size of the matrix N2
	//this means that each row must have their absolute value of the diagonal larger than the absolute value of the rest of the row
	//since there are N2 rows, the counter must pass the above statement N2 times to prove diagonal dominance
	if(counter==N2){
		isDiag=1;
	}

	//if the counter is any other number that isn't N2, this means that the above condition is not satisfied and
	//the matrix is not diagonally dominant
	else{
		isDiag=0;
	}
	




    return isDiag;
}
