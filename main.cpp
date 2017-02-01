//
//  main.cpp
//  car_lists
//
//  Created by Alyxandra Spikerman on 12/4/16.
//  Copyright © 2016 Embedded Design. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "carLists.h"

using namespace std;

int main() {
	//declares main list
	struct carData* head = (struct carData*) malloc(sizeof(struct carData));
	head = NULL; //initializes main list to equal NULL
	records list; //declares records value
	string a, b, c, d; //declares strings to be used in getting data from text
	
	/*
	 opens the file "carFile.txt" and stores each string in a variable (a,b,c,d)
	 and then creates a new node and adds it to the head linked list until the 
	 end of the file is reached
	 */
	ifstream carFile("carFile.txt");
	string lines;
	if (carFile.is_open()){
		while (getline(carFile, lines)){
			carFile >> a >> b >> c >> d;
			head = list.addData(head, a, b, c, d);
		}
	} else { //if the file fails to open, notifies the user
		cout << "carFile.txt failed to open." << endl;
	}
	
	//prints the list sorted years ascending
	cout << "\nYear Ascending: " << endl;
	list.yearAscendSort(&head);
	list.display(head);
	
	//prints the list sorted the years descending
	cout << "\nYear Descending: " << endl;
	head = list.yearDescendSort(head);
	list.display(head);
	
	//prints the list sorted model ascending
	cout << "\nModel Ascending: " << endl;
	list.modelAscendSort(&head);
	list.display(head);
	
	//prints the list sorted model desceding
	cout << "\nModel Descending: " << endl;
	head = list.modelDescendSort(head);
	list.display(head);
	
	//prints the repeats in the list
	cout << "\nRepeats: " << endl;
	list.repeated(head);

	//closes the carFile
	carFile.close();
	
    return 0;
}

