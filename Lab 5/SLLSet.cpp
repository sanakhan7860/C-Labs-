/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0; //initialize the size of the set to zero
	head = NULL; //initialize the set to be empty
}
SLLSet::SLLSet(int sortedArray[], int arrSize)
{

	SLLNode *current = head; //pointer which points to the head node which is the first value in 'this' set
	SLLNode *node = NULL; //empty node
	size = arrSize; //initialize the array size

	//check if the array size is 0
	//this means that the array is empty
	if(arrSize == 0){
		head = NULL; //the head is now NULL since there is no first element
		current = head; //current pointer is also NULL since there are no elements in the array
	}

	//this is the case where the array is not empty
	else{

		head = new SLLNode(sortedArray[0],NULL);//initialize the head to point to the first node in the new set which holds the first value in the array
		current = head; //current is updated and now points to head at the new value

		//iterate through the input array and add each element to the new set
		for(int i=1;i<arrSize;i++){
			node = new SLLNode(sortedArray[i],NULL); //create a new node in the LL for each element in the array
			current->next = node; //the next node in the set is assigned the new node value from the array after each iteration --> here the links for each node are made for the set
			current = current->next; //move to the next node in the set

			}
	}


}
int SLLSet::getSize()
{
	
	return size; //returns the size of the LL
}
SLLSet SLLSet::copy()
{

	SLLSet newCopy; //create a new set to hold the copy of the 'this' set
	newCopy.size = size; //get the size of the set
	SLLNode *current = head; //pointer which points to the head node which is the first value in 'this' set
	SLLNode *copycurr = newCopy.head; //pointer which points to the first value in the newCopy set
	
	//loop through each node in 'this' set to copy each element in it into the newCopy set
	for(int i=0;i<size;i++){

		SLLNode *node = new SLLNode(current->value, NULL); //create a new node for each element in the newCopy set

		//checks if the copycurr node is empty
		if(copycurr == NULL){
			newCopy.head = node; //assigns the head in the newCopy set to the first node in the set
			copycurr = newCopy.head; //the pointer pointing to the newCopy set now points to the updated head value
		}

		//in this case the head has been initialized and the remaining elements must be added to the copy set
		else{
			copycurr->next = node; //the next node in the copied set is assigned the value of the new node obtained from 'this' set at each iteration of the loop
			copycurr= copycurr->next; //copycurr moves to the next node in the copied set
		}
		current = current->next; //current moves to the next node in 'this' set to get the new value to be copied
	}

	return newCopy; //return the copied set



}
bool SLLSet::isIn(int v)
{
	SLLNode *current = head; //pointer which points to the head node which is the first value in 'this' set

	//loop over the set until we reach the end of the LL or the NULL
	while(current!=NULL){

		//checks if the value v has been found within 'this' set
		if(current->value == v){
			return true;}//v was found

		//checks if the value in the set is greater than v which means that the value v cannot be found since the LL is in increasing order of values
		else if(current->value > v){
			return false; //v was not found
			}
		current = current->next; //current moves to the next node in the LL
	}

	return false; //returns false in this case where the list is empty and therefore v cannot be found
}
void SLLSet::add(int v)
{
	SLLNode *current = head; //pointer which points to the head node which is the first value in 'this' set
	SLLNode *prev = NULL; //an empty pointer used to add the node containing v into the set


    //this is the case where v is found so we do nothing
	//iterates through the set if its not empty and the value at each node is less than v
	//if the value in the node is equal to v then the while loop terminates and that means that v is already in the set
	while(current != NULL && current->value<v){
		prev = current; //the current node is stored in previous to keep track of the nodes
		current = current->next; //current moves to the next node
	}

	//v is not found in the LL
	if(current == NULL || (current!= NULL && current->value!=v)){
		SLLNode *node = new SLLNode(v,current); //create a new node for the v value

		//this accounts for the case where the value needs to be added in the first/head node
		if(prev == NULL){
			head = node; //assigns head the first node in the set
			size++; //increase the size of the LL after adding the node
			return;
		}

		//the value needs to be added anywhere in the LL except at the first/head node
		else{
			prev->next = node; //insert the new node after the previous node which is a smaller value to ensure that the LL is still in increasing order
			size++; //increase the size of the LL after adding the node

		}
	}



    
}
void SLLSet::remove(int v)
{
	SLLNode *current = head; //pointer which points to the head node which is the first value in 'this' set
	SLLNode *temp = NULL; //temporary variable which will hold the current value

	//this is the case where the set is not empty and the value v to be removed is the first value in the set (head node)
	while(current!=NULL && current->value == v){
        head = current->next; //assign the head node to the next node in the LL
        size--; //reduce the size of the LL after removing the desired node with the value v
        return;
	}


	//iterate through the set while it is not empty and the value v has not been found
	//if v is not found do nothing
	while(current!=NULL && current->value!=v){
		temp = current; //stores the current node in the temporary node variable to keep track of each node to help with unlinking the node with the value v if it is found in the LL
		current = current->next; //move current to the next node
	}

	//this is the case where the list is empty and so we do nothing since there is no v
	if(current == NULL){
		return;
	}


	//this statement ensures that the links in the LL are not broken
	temp->next = current->next; //unlink the desired node to be removed that contains v by putting it in the temp variable which creates links with the node before or the links with the node after the desired node to be removed
	size--; //reduce the size of the list after removing the node


}
SLLSet SLLSet::setUnion(SLLSet s)
{
	SLLSet result; //result set which holds the union of 'this' set and 's' set
	SLLNode *current = head; //pointer which points to the head node which is the first value in 'this' set
	SLLNode *sCurrent = s.head; //pointer which points to the head node which is the first value in 's' set

	SLLNode *resultcurr = result.head; //points to the head (first node) of the result set
	SLLNode *node; //node pointer will hold the node which contains the union value between the two sets to be added to the result set

	//executes while 'this' set and 's' set are not empty
	while(current!=NULL && sCurrent!=NULL){

		//checks if the current value in 'this' set is less than the sCurrent value in 's' set
		if(current->value<sCurrent->value){
			node = new SLLNode(current->value, NULL); //creates a new node with the current value
			current = current->next; //current moves to the next node in 'this' set to compare with the value in 's' set again
		}

		//checks if the current value in 'this' set is greater than the sCurrent value in 's' set
		else if(current->value > sCurrent->value){
			node = new SLLNode (sCurrent->value, NULL); //create a new node with sCurrent value
			sCurrent = sCurrent->next; //move sCurrent to the next node in 's' set to compare with the value in 'this' set again
		}

		//this is the case where the current value and sCurrent value are equal
		else{
			node = new SLLNode(current->value, NULL); //creates a node for that single value using the current value (doesn't matter if you use sCurrent or curent since it is the same value)
			current = current->next; //move current to the next node in 'this' set
			sCurrent = sCurrent->next; //move sCurrent to the next node in 's' set
		}

		//if the head of the result set is empty, we need to assign it the first node value
		if(resultcurr==NULL){
			result.head = node; //assign head the first node in the result set
			resultcurr = node; //the pointer to the result set is updated to point to the head node with the new node value
		}

		//if the head node has a value then add the rest of the nodes to the result set
		else{
			resultcurr->next = node; //the next node in the set is assigned the new node value
			resultcurr = resultcurr->next; //resultcurr moves to the next node in the result set
		}
		result.size++; //increase the size of the result set after adding a node to it

	}

	//this accounts for the case where there is no 's' set so 'this' set is copied to the result set and returned
	//iterate through 'this' set while it is not NULL
	while(current!=NULL){

		//the head of the result set is empty
		if(resultcurr == NULL){
			result.head = new SLLNode(current->value, NULL); //assign head to point to the first node with the current value in the result set
			resultcurr = result.head; //resultcurr points to the updated value of the head  which points to the head in the result set
		}

		//if the head is not empty keep adding each node in the 'this' set to the result set
		else{
			resultcurr->next = new SLLNode(current->value, NULL); //create a new node with the current value in 'this' set for the result set
			resultcurr = resultcurr->next; //move to the next node in the result set
		}
		result.size++; //increase the size of the result set after adding each node
		current = current->next; //the current pointer moves to the next node in 'this' set
	}

	//this accounts for the case where there is no 'this' set so 's' set is copied to the result set and returned
	//iterate through 's' set while it is not NULL
	while(sCurrent!=NULL){

		//the head of the result set is empty
		if(resultcurr == NULL){
			result.head = new SLLNode(sCurrent->value,NULL); //assign head to point to the first node with the sCurrent value in the result set
			resultcurr = result.head; //the pointer to the result set is updated to point to the head node with the new node value
		}

		//if the head is not empty keep adding each node in the 's' set to the result set
		else{
			resultcurr->next = new SLLNode(sCurrent->value, NULL); //create a new node with the sCurrent value in 's' set for the result set
			resultcurr = resultcurr->next; //move to the next node in the result set
		}
		result.size++; //increase the size of the result set after adding each node
		sCurrent = sCurrent->next; //the sCurrent pointer moves to the next node in 's' set
	}


	return result; //return the result set containing the union of 'this' set and input 's' set
}
SLLSet SLLSet::intersection(SLLSet s)
{

	SLLSet result; //a new set which holds the intersection between 'this' set and the input 's' set

	SLLNode *current = head; //pointer which points to the head node which is the first value in 'this' set
	SLLNode *sCurrent = s.head; //pointer which points to the head node which is the first value in 's' set
	SLLNode *tail = NULL; //temporary variable which stores the temp node
	SLLNode *temp; //holds each node value that is an intersection between the two sets to be added to the result set

	//iterate through 'this' set and 's' set while they are not NULL
	while(current!=NULL && sCurrent!=NULL){
		temp = NULL; //initialize the temporary pointer to be empty

		//check if the current value in 'this' set is less than the sCurrent value in 's' set
		if(current->value<sCurrent->value){
			current = current->next; //move to the next node in 'this' set to compare that value with the same value in 's' set again
		}

		//check if the sCurrent value in 's' set is less than the current value in 'this' set
		else if(sCurrent->value<current->value){
			sCurrent = sCurrent->next; //move to the next node in 's' set to compare that value with the same value in 'this' set again
		}

		//this is the case that the value in 'this' set is equal to the value in 's' set
		else{
			temp = new SLLNode(current->value,NULL); //create a new node for that value
			current = current->next; //current moves to the next node in 'this' set
			sCurrent = sCurrent->next; //sCurrent moves to the next node in 's' set
		}

		//checks if the first node (head node) in the new result set is empty and that the temporary node variable contains a value
		if(result.head == NULL && temp!=NULL){
			result.head = temp; //assign the temp node to the head node of the result set
			tail = temp; //the tail node is assigned the temp node to keep track of it
			result.size++; //increase the size of the result set after adding the node
		}

		//this condition is executed when an intersection has been found and a new node has been created that needs to be added to the result set
		else if(temp!=NULL){
			tail->next = temp; //the next node in the result set is assigned the temp node
			tail = temp; //the tail temporarily holds the temp node to keep track of it
			result.size++; //increase the size of the result set after adding the node
		}
	}

	return result; //return the result set with the intersection between 'this' set and 's' set
}
SLLSet SLLSet::difference(SLLSet s)
{
	SLLSet result = this->copy(); //create a copy of 'this' set and store it in result so that the elements in 'this' set are not changed
	SLLNode *current = s.head; //pointer which points to the head of 's' set

	//if both the current pointer and head are null, then return a result of 'this' set copy meaning that there is no value in 'this' set that
	//is different from the 's' set
	if(current == NULL || head == NULL){
		return result; //return a copy of 'this' set --> no modifications made to it
	}


	//loops through each node in 's' set and deletes elements in 'this' set that are found in the 's' set
	while(current!=NULL){

		//the isIn function checks if the value in the 's' set is found in 'this' set
		if(result.isIn(current->value)){
			result.remove(current->value); //if that value is found in both the sets, that value is passed into the remove function to be removed from the copied version of 'this' set
		}

		current = current->next; //move to the next node in 's' set
	}

	 return result; //returns this new set which represents the difference between 'this' set and input set 's'
}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	SLLSet result; //create a new set which will hold the union of all the sets in the input array

   //loop through the sArray which contains a set at each index
	for(int i=0;i<size;i++){
		result = result.setUnion(sArray[i]); //call the setUnion function to create a union for all the sets in sArray
	}

	 return result; //return the result set containing the union of all the sets in the input sArray
}
string SLLSet::toString()
{

	SLLNode* current = head; //pointer which points to the head node which is the first value in 'this' set
	string list_str = ""; //empty list which will hold the string representation of all the values in the LL

	//checks if the set is empty--> if it is, an empty string is returned
	if(current == NULL){
		return "";
	}


	else{

        //iterate through the list subtracting 1 from the size of list_str so that the loop ends at the second last element
		for(int i=0;i<size-1;i++){
			list_str += std::to_string(current->value); //add each value in the LL to the string list
			list_str += ", "; //seperate each value with a coma and a space
			current = current->next; //move to the next node in 'this' set
		}
		list_str += std::to_string(current->value); //add the final value in the set after the for loop because we don't want a coma after the final value
		                                            //for this reason, the for loop terminated at size-1

	}


	return list_str; //return the string representation of the LL
}
