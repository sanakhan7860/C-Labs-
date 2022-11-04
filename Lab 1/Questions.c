#include "Questions.h"



int Q1_for(){
	//sum holds the sum of the multiples
	//i is a counter
	//multiple holds the multiple values of 4
	int sum = 0, i;

	
	// calculate your sum below..this has to use for loop

	for (i=30; i<=1000;i++) // for loop iterates from 30 to 1000
	{
		if (i%4 == 0) // checks if the modulus 4 of the number gives an exact remainder of 0 therefore it is a multiple of 4
		{
			sum = sum + i; //add the value of the multiple to the total sum of multiples
		}


	}
	
	// here, we return the calculated sum:
	return sum;
}
int Q1_while(){
	//sum holds the sum of the multiples
	//i is a counter
	int sum = 0, i=30;

	// calculate your sum below..this has to use while loop
	
	while(i<=1000) //iterate through the loop starting at 30 and ending at 1000
		{

		if (i%4 == 0) //check if exact remainder of 0 is given when the value is divided by 4
			{
			sum = sum + i; //add value of multiple to the total sum of multiples
			i++;
			}
		i++; //increment counter if the if condition is not satisfied

		}
	
	// here, we return the calculated sum:
	return sum;
}
int Q1_do(){

	//sum holds the sum of multiples
	//i is a counter initiated at 29 to be incremented from 30 to 1000
	int sum = 0, i=29;
	
	// calculate your sum below..this has to use do-while loop

	//do loop checks if the each value between 30 to 1000 is a multiple of 4
	do{
		//checks if modulus 4 of the number gives a remainder of zero indicating that that value is a multiple of 4
		if (i%4 == 0)
		{
			sum = sum + i; //add value of multiple to the total sum of multiples
		}
		i++;
	}

	//while loop executes until it reaches a value of 1000
	while (i<=1000);

	  
	// here, we return the calculated sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit, num, counter=0;
	
	// Do your coding below to check

	num = Q2_input;
	if(num<0){ //checks if the user input is a negative value
		num = -num; //makes the value positive by multiplying the number by -1
	}
	while(num>0){ //this loop calculates the number of digits of the users number
		counter++; //counter will increment for each digit in the users number
		num /= 10; //dividing the number by 10 will allow us to move specific number of decimal places to know how many digits are in the number
	}
	if(counter==5){
		return IsFiveDigit = 1;
	}
	else{
		return IsFiveDigit = 0;
	}

	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program shouldreturn -1
*/	
	// this is the varaible that holds the out value to return
	float GPA, average;
	
	// Do your coding below to calculate the GPA variable value

	average = Q3_input;
	if (90<=average && average<=100){ //checks if the student average is between 90 to 100
		return GPA = 4;
	}
	else if (80<=average && average<=89){ //checks if the student average is between 80 to 89
		return GPA = 3;
	}
	else if (70<=average && average<=79){ //checks if the student average is between 70 to 79
		return GPA = 2;
	}
	else if (60<=average && average<=69){ //checks if the student average is between 60 to 69
		return GPA = 1;
	}
	else if (0<=average && average<=59){ //checks if the student average is between 0 to 59
		return GPA = 0;
	}
	else{
		return GPA = -1; //returns -1 if student average is abnormal ie. a negative average or an average greater than 100
	}

	 
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the variable that holds the pi value to return
	double pi=0, numerator=4, denominator=1, terms=0;
	
	
	// Do your coding below to calculate the pi value
	//executes the loop if the number of terms is smaller than the given user input
	while(terms<Q4_input)
	{
		pi += numerator/denominator; // pi variable holds the sum of the infinite series
		denominator += 2; //denominator increments by 2 with each addition
		numerator *= (-1); //multiply the numerator by -1 each time to account for the alternating + and - in the formula to calculate pi
		terms++; //increment the number of terms being added
	}

	
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0, side1, side2, hyp;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/
	//outermost for loop iterates from 1 to 400 for side 1
	for(side1=1; side1<=400; side1++){
		//middle for loop iterates from 1 to 400 for side 2
		for(side2=1; side2<=400; side2++){
			//last for loop iterates from 1 to 400 for the hypotenuse
			for(hyp=1; hyp<=400; hyp++){
				//if statement checks if the condition of a pythagorean triple is satisfied
				if ((side1<=side2) && (side1*side1 + side2*side2 == hyp*hyp)){
					totNumTribles++;//increase the count for the total number of triples

				}
			}
		}
	}
	
	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is the variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0, sum=0, value, factor;

	    //for loop iterates through the number of
	    for(value=2; value<=Q6_input; value++){
	    	sum = 0; //re-initialize the sum to 0 to ensure that the sum is calculated seperately for each iteration of the outermost for loop
	    	for(factor=1; factor<value; factor++){ //this loop calculates the factors of the given number in the first for loop
	    		if(value%factor == 0){ //if the remainder of the number being tested to be a perfect number is zero, then that value is a factor of that number
	    			sum += factor; //add the factor of the number to the total sum of factors
	    		}
	    	}

	    	if(sum == value){ //checks if the sum of the factors is equal to the number being tested to be perfect
	    		perfect[counts] = value; //append the perfect number to the perfect number array
	    		counts++; //increase the count of perfect numbers
	    		}

	    }

		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/


	   return counts;
}
//===============================================================================================
int Q7a(int Q7_input){
	

	int reversedInt=0, rem, num=Q7_input;
	
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer

	if(num<0){ //if statement ensures that if a negative number is passed in, it is turned into a postive value
		num = -num;
	}

	int val1 = num/1000000; //dividing the value by 1 million suggests that the number passed through is a 7 digit number
	int val2 = val1/10; //this calculation further validates the user number is a 7 digit value


    //if the conditions of a the if statement are met it proves that the user number is 7 digits since it is between 0 and 9
	if((val1>=1) && (val2 < 1)) {
		//while loop calculates the reverse of the number
		while(num!=0){
			rem = (num)%10; //take the remainder of the users number
	        reversedInt = (reversedInt*10) + rem; //add the remainder digit to the end of the reversed number
	        num = num/10; //remove the last digit from the user's number because it is already appended to the reversedInt variable

		}




}
	return reversedInt; //return the reversed number
}

int Q7b(int Q7b_input){
	int reversedInt=0;
	int rem=0, num= Q7b_input;

	//while loop calculates the reversed number while the condition is true
	while(num!=0){
		//if statement checks whether the user number is a negative value and changes it to a positive value if needed
		if(num<0){
			num = -num; //multiply the negative number by -1 to make it positive
		}
		rem = (num)%10;//take the remainder of the users number
		reversedInt = (reversedInt*10) + rem; //add the remainder digit to the end of the reversed number
		num = num/10; //remove the last digit from the user's number because it is already appended to the reversedInt variable
	}

	return reversedInt;// return the reversed number
}






	
	
