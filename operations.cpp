/* @Author
Student Name: Ayse Betul Cetin
Student ID: 150180730
Date: 22.10.2019
*/
#include <iostream>  //allows program to perform input output
#include "operations.h"
#include <stdio.h>
#include <fstream>   //read from files
#include <cstdio>
using namespace std;

void stock::create(){  //creates the empty stock list
	head = NULL;
	
}
void stock::add_stock(int add_node){ //adds a pair a shoe 
	node *traverse;
	node *tail;
	traverse = head;
	node *newnode;
	newnode= new node;
	newnode->size = add_node;
    newnode->next = NULL;
	newnode->quantity = 0;
	
		if(head == NULL){			// Adding first shoe
		
			head = newnode;
			newnode->quantity =1;
		
		}else if(newnode->size == head->size){  //if the shoe size which added is equal to the head size 
			head->quantity ++;
		
		}else if((newnode->size) < (head->size)){ 	//if the shoe size which added is smaller than head size
			
			newnode->next = head;
			head =newnode;
		    newnode->quantity =1;
		
		}else if((newnode->size) > (head->size)){  
			
			while (traverse && (newnode->size > (traverse->size))){  //finding the right position
				tail = traverse;
                traverse = traverse->next;
				
				
				if((traverse != NULL) && newnode->size == traverse->size){  //if size is already exist 
					traverse->quantity ++;
					return;
				}
				
			}
            if (traverse){  //Adding into a position
                
				
				newnode->next = traverse;
                tail->next = newnode;
				newnode->quantity = 1;
            }
            else{        //Adding to end
				
			    tail->next = newnode;
				newnode->quantity = 1;
				}
		}
		
	}
	


void stock::sell(int sellnode){    //sell shoe function
	node *traverse;
	traverse = new node;
	node *tail;
	
	traverse = head;
		
			if((head->size) == (-sellnode)){   //if the shoe sold is equal to head size
				if(head->quantity > 1){  // decrease the quantity by one
					head->quantity--;
					return;
				}else if(head->quantity == 1){ // delete the head node
					head = head->next;
					traverse = NULL;
					delete traverse;
					return;
				}
				
			}else if(head == NULL){      //if list is empty 
		           cout << "NO_STOCK" << endl;
				   delete traverse;
				   return;
			     
			}else{
				
			
				while(traverse != NULL ){ //finding the right position
					tail = traverse;
					traverse = traverse->next;
					
					
					if(traverse == NULL){  //there is no stock for that shoe
						delete traverse;
						cout << "NO_STOCK" << endl;
						return;
					}
					
					if((-sellnode) == (traverse->size)){   //before this condition , we should checked that traverse is not null
						if(traverse->quantity > 1){     //decrease the quantity by one
							traverse->quantity --;
							return;
						}else if(traverse->quantity == 1){ //delete the node
							tail->next =traverse->next;
							delete traverse;
						    return;
						}
						
			       }
						
			
               }
			  
			  
			  
        }
		
}

void stock::current_stock(){  //prints the current stock list, command Zero(0)
	node *traverse;
	traverse=head;
	
	while(traverse != NULL){
		cout << traverse->size << ":" << traverse->quantity << endl ;
		traverse = traverse->next;
	}
	return;
	
}

void stock::clear(){   //deletes all of the nodes of the list 
	node *temp;
	temp = new node;
	while (head){
		temp = head;
		head = head->next;
		delete temp;
	}
	
}

