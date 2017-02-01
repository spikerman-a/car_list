//
//  carLists.cpp
//  car_lists
//
//  Created by Alyxandra Spikerman on 12/4/16.
//  Copyright © 2016 Embedded Design. All rights reserved.
//

#include "carLists.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
 Displays the inputted linked list to the console
 */
void records::display(struct carData* head){
    struct carData* current = head;
    
    while (current != NULL) {
        cout << current->make << ", " << current->model << ", " << current->year << ", " << current->color << endl;
        current = current->next;
    }
}

/*
 adds a node to the beginning of the inputted list
 */
struct carData* records::addData(struct carData* head, string ma, string mo, string y, string c){
    newNode = new struct carData;
    newNode->make = ma;
    newNode->model = mo;
    newNode->year = y;
    newNode->color = c;
    
    if (head == NULL) {
        head = newNode;
        newNode->next = NULL;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

/*
 displays the repeated nodes in the linked list by creating a new linked
    list @param repeats
 */
void records::repeated(struct carData* head){
    cars = head;
    repeats = new struct carData;
    repeats = NULL;
    
    while (cars != NULL){
        head = cars->next;
        while (head != NULL) {
            if (cars->make == head->make){
                if (cars->model == head->model){
                    if (cars->year == head->year){
                        if (cars->color == head->color){
                            repeats = addData(repeats, cars->make, cars->model, cars->year, cars->color);
                            break;
                        }
                    }
                }
            }
            head = head->next;
        }
        cars = cars->next;
    }
    display(repeats);
}

/*
 Functions for merge sort of the linked list (for ascending and desceding 
    order of the model or year of the list
 */
/*
 sorts the inputted list by ascending year
 */
void records::yearAscendSort(struct carData** headRef){
    struct carData* head = *headRef;
    struct carData* a;
    struct carData* b;
    
    //trivial case
    if (head == NULL || head->next == NULL){
        return;
    }
    
    frontBackSplit(head, &a, &b); //splits the list in half
    yearAscendSort(&a); //recursively calls yearAscendSort on &a
    yearAscendSort(&b); //recursively calls yearAscendSort on &b
    *headRef = sortedMerge(a, b); //merges the sorted list
}

/*
 sorts and merges the list based on year
 */
struct carData* records::sortedMerge(struct carData* a, struct carData* b){
    struct carData* result = NULL;
    
    //trivial cases
    if (a == NULL){
        return b;
    } else if (b == NULL){
        return a;
    }
    
    if (a->year <= b->year){
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

/*
 breaks the list in half and accounts for odd length
 */
void records::frontBackSplit(struct carData* source, struct carData** frontRef, struct carData** backRef){
    struct carData* front;
    struct carData* back;
    
    //trivial case
    if (source == NULL || source->next == NULL){
        *frontRef = source;
        *backRef = NULL;
    } else {
        front = source;
        back = source->next;
        while (back != NULL){
            back = back->next;
            if (back != NULL){
                front =  front->next;
                back = back->next;
            }
        }
        *frontRef = source;
        *backRef = front->next;
        front->next = NULL;
    }
}

/*
 sorts the inputted list by descending year
 */
struct carData* records::yearDescendSort(struct carData* head){
    yearAscendSort(&head);
    struct carData* new_node;
    new_node = new struct carData;
    new_node = head;
    head = NULL;
    
    //flips the ascended sorted list to make it descending order
    while(new_node != NULL){
        head = addData(head, new_node->make, new_node->model,new_node->year, new_node->color);
        new_node = new_node->next;
    }
    
    return head;
}

/*
 sorts the inputted list by ascending model
 */
void records::modelAscendSort(struct carData** headRef){
    struct carData* head = *headRef;
    struct carData* a;
    struct carData* b;
    
    //trivial case
    if (head == NULL || head->next == NULL){
        return;
    }
    
    frontBackSplit(head, &a, &b); //splits the list in half
    modelAscendSort(&a); //recursively calls modelAscendSort on &a
    modelAscendSort(&b); //recursively calls modelAscendSort on &b
    *headRef = modelSortedMerge(a, b); //merges the sorted list
}

/*
 sorts and merges the list based on model
 */
struct carData* records::modelSortedMerge(struct carData* a, struct carData* b){
    struct carData* result = NULL;
    
    //trivial cases
    if (a == NULL){
        return b;
    } else if (b == NULL){
        return a;
    }
    
    if (a->model <= b->model){
        result = a;
        result->next = modelSortedMerge(a->next, b);
    } else {
        result = b;
        result->next = modelSortedMerge(a, b->next);
    }
    return result;
}

/*
 sorts the inputted list by descending model
 */
struct carData* records::modelDescendSort(struct carData* head){
    modelAscendSort(&head);
    struct carData* new_node;
    new_node = new struct carData;
    new_node = head;
    head = NULL;
    
    //flips the ascended sorted list to make it descending order
    while(new_node != NULL){
        head = addData(head, new_node->make, new_node->model,new_node->year, new_node->color);
        new_node = new_node->next;
    }
    
    return head;
}
