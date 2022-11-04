#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	


	/*write your implementation here*/

	FILE *input_file = fopen(filename, "r");//open the file containing the student information for reading

	int index;

	student **class_list;

	if(input_file == NULL){
		printf("Error: Could not open file: %s\n", filename);
		exit(1);
	}

	fscanf(input_file, "%d", sizePtr); //scan the file and store the number of students in sizePtr pointer



	sizePtr = malloc(sizeof(int));

	class_list = (student **)malloc(*sizePtr * sizeof(student *)); //allocate memory required to store the list of students

	//for loop used to iterate through each student in the list to be able to access their data
	for(index=0; index<*sizePtr; index++){

		class_list[index] = malloc(sizeof(student)); //allocate memory for the data of each student

		//scans the file for each students student id, first name, and last name to be initialized in the student structure
		fscanf(input_file, "%d %s %s", &class_list[index]->student_id, class_list[index]->first_name, class_list[index]->last_name);

		//project1, project2, and final grades for each student is initialized to zero
		class_list[index]->project1_grade = 0;
		class_list[index]->project2_grade = 0;
		class_list[index]->final_grade = 0;
	}

	fclose(input_file); //close the file



	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	
	/*write your implementation here and update the return accordingly*/

	int index; //index value accesses each pointer in the array of pointers

	//loop used to iterate through the array of pointers (class list) which are de-refrenced to access each students student id
	//which is compared to the given id number to see if it matches
	for(index=0;index<size;index++){

		//checks if students id number for each student in the class list matches the id number given
		if(list[index]->student_id == idNo){
			return index; //return the index position of the id number
			break;
		}

	}
	return -1; //return this only if student id number isn't found
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/

	//index holds the value of the position of the id number in the class list
	//idNo holds the id number
	//grade1 holds the project 1 grade
	//grade2 holds the project 2 grade
	int index, idNo, grade1, grade2,i=0;

	FILE *input_file = fopen(filename,"r"); //open the file containing the student grades for reading

	if(input_file == NULL){
		printf("Error: Could not open file: %s\n", filename);
		exit(1);
	}

	//iterate through each line in the file
	for(i=0;i<size;i++){

		fscanf(input_file,"%d",&idNo); //read the id number from the file
		index = find(idNo,list,size); //find the position of the id number in the class list array

		fscanf(input_file,"%d", &grade1); //get project 1 grade from file
		fscanf(input_file,"%d", &grade2); //get project 2 grade from file

		list[index]->project1_grade = grade1; //input project 1 grade for the student
		list[index]->project2_grade = grade2; //input project 2 grade for the student
	}

	fclose(input_file); //close the file

}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	int index; //variable used as index value to access the class list in the array of pointers

	//loop iterates through the class list and accesses student's info
	//to be able to assign the final grade for each student in the list
	for(index=0;index<size;index++){

		//assigns the final grade by taking the average of the project 1 and project 2 grades
		list[index]->final_grade = (list[index]->project1_grade + list[index]->project2_grade)/2.0;
	}

}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
	FILE *output_file = fopen(filename, "w"); //creates file to write in the total students, student id, and final grades

	int index; //variable used as index value to access the class list in the array of pointers

	fprintf(output_file, "%d\n", size); //the size of the class is written to into the text file

	//loop iterates through each student in the class list and accesses their student id and final grade to be written to the text file
	for(index=0;index<size;index++){
		fprintf(output_file, "%d %.2f\n",list[index]->student_id,list[index]->final_grade);
	}

	fclose(output_file); //close the file

}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	//index is used as index value to access the class list in the array of pointers
	//found acts as a flag which indicates whether a student id has been found or not
	int index = 0, found = 0;

	//loop iterates through each students information and accesses the student id to compare to the given student id
	for(index=0; index<*sizePtr; index++){

		//checks if the given student id is found within the students information in the class list
		if(list[index]->student_id == idNo){
			found = 1; //indicates the student id has been found
			break; //break out of the loop since we no longer need to search for the student id
		}
	}

    //indicates that the student id was found
	if(found)
	{
		for(index+=1; index<*sizePtr; index++){
			list[index-1] = list[index]; //shift each student in the list left 1 position between the vacated spot and the end of the array
		}

		free(list[index]); //free the allocated memory of that students information

		*sizePtr = *sizePtr - 1; //reduce the number of students in the class by 1

		printf("Student ID: %d was withdrawn\n", idNo);
		printf("The number of students in the class is: %d\n", *sizePtr);
	}

	else{

		printf("Student ID: %d was not found\n", idNo);
	}


}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/

	int index; //variable used as index value to access the class list in the array of pointers


	for(index=0;index<*sizePtr;index++){
		free(list[index]); //free the memory allocated for student information of each student

	}

	free(list); //free's the memory allocated for the class list (array of pointers)
	*sizePtr = 0; //sets the value of the pointer pointing the number of students in the class to zero since
			      //no students in a class list and their info no longer exists

}
