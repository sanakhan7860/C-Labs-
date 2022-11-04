#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
//26 letters
//Latin ASCII values lower case --> 97-122
//Latin ASCII values upper case --> 65-90

   int index=0; //index is the variable used to index to each letter in the word array
   int letter=0; //letter stores each individual letter in the word array to be used to find its ASCII value
   int word_len = strlen(word); //word_len holds the length of the word array

   //loop iterates through each value in the word array to get the ASCII value of each letter
   //the ASCII value is then used to help determine the frequency of each letter in the word
   //including the frequency of upper and lower case values of the same letter to be added together
   for(index=0; index<word_len;){

	   //loop executes while ensuring that the character in the array is not a null character
	   while(word[index]!='\0'){

		   //letter updates to each individual character in the word array after each iteration in the while loop
		   //this is done by increasing the index in the word array
		   letter = word[index++];

		   //checks if the letter inclusively lies between the ASCII values of capital A to capital Z
		   if(letter >= 'A' && letter <= 'Z' ){
			   letter += 32; //adds 32 to the letter to convert the capital to a lower case which accounts for counting the frequency
			                 //of the same lower and upper case letters together
		   }

           //checks if the letter inclusively lies between the ASCII values of lower-case a to lower-case z
		   if(letter >= 'a' && letter <= 'z'){
			   freq[letter -'a']++; //gets the index to the freq array by getting the integer value of letter-a
			                        //counts the repeated number of times for each letter and stores it in the freq array

		   }
	   }
   }

   
}
