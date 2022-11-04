#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){

	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/

	//initialize the row and column parameters within the constructor
	rowsNum = row;
	colsNum = col;


	//set row and column value to 3 if the row and column value passed in is invalid
	if(row<=0){
		rowsNum = 3;
	}

	if(col<=0){
		colsNum = 3;
	}

	matrixData = NULL;
	matrixData = (int**)malloc(rowsNum*sizeof(int*)); //allocate the memory required for all the rows in the matrix


	int i=0,j=0;

	for (i = 0 ; i < rowsNum ; ++i )
	    {
	       matrixData[i] = (int*) malloc(colsNum*sizeof(int)); //allocate the memory required for all the columns in the matrix
	    }

	for(i=0;i<rowsNum;i++){
		for(j=0;j<colsNum;j++){
			matrixData[i][j] = 0; //set each element in the matrix to zero
		}


}
}


Matrix::Matrix(int row, int col, int** table){

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/

	//initialize the row and column parameters within the constructor
	rowsNum = row;
	colsNum = col;
	matrixData = NULL;

	matrixData = (int**)malloc(rowsNum*sizeof(int*)); //allocate the memory required for all the rows in the matrix

	int i=0,j=0;

	for (int i = 0 ; i < rowsNum ; ++i )
	{
		matrixData[i] = (int*) malloc(colsNum*sizeof(int)); //allocate the memory required for all the columns in the matrix
	}


	//iterates through each column and row which are the size of the table array
	//this creates the matrix array to have the same dimensions as the table array
	for(i=0;i<rowsNum;i++){
		for(j=0;j<colsNum;j++){
			matrixData[i][j] = table[i][j]; //set each element in the matrix array to the same elements in the table array
		}
			}


}

int Matrix::getElement(int i, int j){

	int element=0; //holds the element in the matrix array

	//checks if the row and column indexes sent in is out of range of size of the matrix array
	if(i<0 || i>rowsNum || j<0 || j>colsNum){
		throw std::out_of_range( "Invalid indexes." ); //throws exception if the above statement is true
		}

	element = matrixData[i][j]; //if the indexes i and j are within the range, element is assigned the value at the specific index in the array

	return element;



}

bool Matrix::setElement(int x, int i, int j){

    //statement checks if the row i and column j is within the range/size of the matrix array
	if(i<0 || i>rowsNum || j<0 || j>colsNum){

		return false;
	}

	matrixData[i][j] = x; //the matrix at the specific row and column is set to the value of x

	return true; //row and column indexes are within the range


}


Matrix Matrix::copy(){

	/* fix the code and write your implementation below */

    Matrix copy = Matrix(rowsNum,colsNum, matrixData); //deep copy of matrix is implemented by calling the third Matrix constructor which copies
                                                       //the matrixData size and elements to the copy array

    return  copy;
}


void Matrix::addTo( Matrix m ){

	//checks if the number of rows or columns of the m array do not match those of the matrixData array
	if((m.getsizeofrows() != rowsNum) || (m.getsizeofcols() != colsNum)){
		throw std::invalid_argument( "Invalid operation" );//throws exception if the above statement is true
	}

	//iterate through the matrixData array
	for(int i=0;i<rowsNum;i++){
		for(int j=0;j<colsNum;j++){
			matrixData[i][j] += m.matrixData[i][j]; //add the element in the m array to the element in the matrixData array at the specific index
			                                        //the m array has been initialized
		}

	}
	
}


Matrix Matrix::subMatrix(int i, int j){

	/* The exception detail message should read: "Submatrix not defined"*/

	/* fix the code and write your implementation below */

	//since i and j are the indexing values, we need ensure that the size of the sub matrix is 1 more larger than i and j to ensure that the
	//indexes  i and j are included within the range of the array
	Matrix subM = Matrix (i+1,j+1);

	//checks if the row or column value is less than 0 which means that index is negative which is incorrect
	//checks if the row or column value is greater than the row and column value of the matrixData array, meaning the indexes are out of range
	if(i<0||i>=rowsNum||j<0||j>=colsNum){
		throw out_of_range("Submatrix not defined"); //throws exception is the above is true
	}


	//produces a sub matrix array the size of i+1 rows and j+1 columns to include the index of 0 to i within the rows and 0 to j within the columns
	for(int a=0;a<=i;a++){
		for(int b=0;b<=j;b++){
			subM.matrixData[a][b] = matrixData[a][b]; //assign the element in matrixData to the sub matrix at the specific index
		}
	}

    return  subM;
}


int Matrix::getsizeofrows(){


	// return the number of rows in the array which are already known
	return rowsNum;
}


int Matrix::getsizeofcols(){


	// return the number of columns in the array which are already known
    return colsNum;
}


bool Matrix::isUpperTr(){

	/* write your implementation here and update return accordingly */


	//iterates through each element below the main diagonal in the matrix
	for(int i=1;i<rowsNum;i++){
		for(int j=0;j<i;j++){

			//checks if the elements in the matrix below the main diagonal are not zero
			if(matrixData[i][j] != 0){
				return false; //not an upper triangular matrix
			}
		}
	}

	  return true; //returns true if all values below the main diagonal are zeros
}

string Matrix::toString()
{

	string output_m = ""; //holds the whole matrix as a string

    //iterate through the rows and columns of the array to access each element
	for(int i=0;i<rowsNum;i++){
		for(int j=0;j<colsNum;j++){
			output_m += to_string(matrixData[i][j]) + " "; //convert each integer to a string using the built in function to_string and add a white space after each element
		}
		output_m += "\n"; //move to a new line after each row
	}

	return output_m;
}
