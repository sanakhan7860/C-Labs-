#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	int str1_len = strlen(str1); //find the length of str1
	int str2_len = strlen(str2); //find the length of str2
	int len = str1_len + str2_len;

	z = calloc(len + 1 , sizeof(char)); //allocate memory space for both strings including the null character found at the end

	/*write your implementation here*/
    int index=0;
    int character=0;

    for(character=0; index<str1_len; character++){
    	z[index] = str1[character];
    	index++;
    }
    for(character=0; character<str2_len; character++){
    	z[index] = str2[character];
    	index++;
    }

    z[index] = '\0';



	/* finally, return the string*/
	return z;
	
	free(z);


}
