/* @Author
Student Name: Ayse Betul Cetin
Student ID: 150180730
Date: 22.10.2019
*/
#include "node.h"

struct stock{
	node *head;
	void create();
	void add_stock(int);
	void sell(int);
	void current_stock();
	void clear();
};