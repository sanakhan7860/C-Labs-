#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below

	//loop calculates the addition of vector1 and vector2 to be stored in vector3
	//value variable indexes to each value in all three arrays
	//in the case of vector3, the sum of the two vectors is stored at the specific index
	for(int value=0; value<size; value++){
		vector3[value] = vector1[value] + vector2[value];

	}
	
	
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value

    //this loop calculates the scalar product of the two vectors
    //value variable indexes to each value in both arrays to be multiplied together
	for(int value=0; value<size; value++){
		prod += vector1[value] * vector2[value]; //the product at each index is added to prod to produce the scalar product
	}
    
	
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{

	//write your code here
	// you should call function scalar_prod().


	//L2 is the variable holding the L2 norm of the passed vector
	//scalar_product holds the value of the scalar product calculated in the function scalar_prod
	double L2;
	double scalar_product = scalar_prod(vector1, vector1, size);

	//once the value of the scalar product is retrieved, take the square root of it to get the norm
	L2 = sqrt(scalar_product);
    
	
	//finally, return the L2 norm 
    return L2;
}
