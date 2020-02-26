/* @Author
Student Name: Ayse Betul Cetin
Student ID: 150180730
Date: 19.10.2019
*/
#include <iostream> // allows program to perform input and output
#include <stdlib.h> // contains function prototypes for memory allocation 
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include "operations.h"

using namespace std; // enables the program to use all the names in any included standard C++ header 

stock Stock_list;

int main(int argc, char *argv[]){
	char *filename = argv[1];
	int temp;
	Stock_list.create();  //empty list created
	FILE *filepointer;
	filepointer = fopen(filename, "r+");
	fseek(filepointer , 0 , SEEK_SET);   
	while(!feof(filepointer)){
		fscanf(filepointer,"%d",&temp);
		if(temp > 0){               //adding operation
		    Stock_list.add_stock(temp);
		}else if(temp < 0){        //selling operation
			Stock_list.sell(temp);
		}else if(temp == 0){      //printing the current stock
			Stock_list.current_stock();
		}else{
			cout << " error " << endl;
		}
	}
	
	fclose(filepointer);  
	Stock_list.clear();  //clear all of the nodes and delete them
	return EXIT_SUCCESS;
}