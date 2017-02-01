//
//  carLists.h
//  car_lists
//
//  Created by Alyxandra Spikerman on 12/4/16.
//  Copyright © 2016 Embedded Design. All rights reserved.
//

#ifndef carLists_h
#define carLists_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
 Declares struct carData and it's four data points
 @param make: string value of the make of the car
 @param model: string value of the model of the car
 @param year: string value of the year of the car
 @param color: string value of the color of the car
 @param next: pointer value to next node
 */
struct carData {
    string make;
    string model;
    string year;
    string color;
    struct carData* next;
};

/*
 Declares class records with public and private functions and parameters
 @param cars/repeats/new_node: used within private functions
 
 function display: displays inputted list
 function addData: adds a node to the inputted list
 function repeated: prints the repeated nodes
 function yearAscendSort: sorts the cars by ascending year
 function sortedMerge: sorts and merges the cars by year
 function frontBackSplit: splits the list into front and back parts
 function yearDescendSort: sorts the cars by descending year
 function modelAscendSort: sorts the cars by ascending model
 function modelSortedMerge: sorts and merges the cars by model
 function modelDescendSort: sorts the cars by desceding model
 */
class records{
private:
    struct carData* cars;
    struct carData* repeats;
    struct carData* newNode;
public:
    void display(struct carData*);
    struct carData* addData(struct carData*, string, string, string, string);
    void repeated(struct carData*);
    void yearAscendSort(struct carData**);
    struct carData* sortedMerge(struct carData* a, struct carData*);
    void frontBackSplit(struct carData*, struct carData**, struct carData**);
    struct carData* yearDescendSort(struct carData*);
    void modelAscendSort(struct carData**);
    struct carData* modelSortedMerge(struct carData* a, struct carData*);
    struct carData* modelDescendSort(struct carData*);
};

#endif
