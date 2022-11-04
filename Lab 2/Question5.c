#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){

	//string variable indexes in the source array to get the string and also is used to index in the destination array
	int string=0;

	//loop iterates through to append each letter in the string to the destination array within the correct size n of the destination array
	//iterates through 1 less than n to ensure that the null character is included at the end to indicate the end of a string destination
	for(string=0; string<(n-1); string++){
		destination[string]=source[string];
	}
	

    
}
