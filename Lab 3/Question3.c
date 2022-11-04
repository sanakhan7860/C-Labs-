#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){

	
    char **word_list;

    /*write your implementation here*/

    FILE * stringptr;
    stringptr = fopen(input_filename,"r");
    fscanf(stringptr,"%d", nPtr);


    word_list = (char**)malloc(*nPtr * sizeof(char *));
    char str[1000];

    for(int i = 0; i<*nPtr; i++){
    	fscanf(stringptr, "%s", str);
    	int str_len = strlen(str);
    	word_list[i] = calloc(str_len + 1, sizeof(char));
    	strcpy(word_list[i],str);
    }

    return word_list;

}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	/*write your implementation here and update the return accordingly*/

	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	int minimum;

	if(str1_len<str2_len){
		minimum = str2_len;
	}

	else{
		minimum = str2_len;
	}

	for(int index = 0; index<minimum; index++){
		if(str1[index]<str2[index]){
			return 1;
		}

		else if(str1[index]>str2[index]){
			return 0;
		}
	}

	if(minimum == str1_len){
		return 1;
	}

	else{
		return 0;
	}

    
}

void sort_words(char **words, int size){
   
	/*write your implementation here*/


	int index, j;
	char *key;
	for(index=1; index<size; index++){
		key = words[index];
		j = index-1;

		while(j>=0){
			if(compare_str(words[j],key)==1){
				break;
			}
			words[j+1] = words[j];
			j -= 1;

		}
		words[j+1] = key;
	}




}

void swap(char **str1, char **str2){
 
	/*this is a helper function that you can implement and use to facilitate your development*/
	char *temp;
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;



}

void sort2_words(char **words, int size){


	/*write your implementation here*/

	int index, j, min_index;
	for(index=0; index<size; index++){
		min_index = index;
		for(j=index+1; j<size; j++){
			if(compare_str(words[j],words[min_index])){
				min_index = j;
				}
			}
		printf("The words are: words[%d] = %s\n", min_index, words[min_index]);
		swap(words[min_index], words[index]);

		}



}
