#pragma once
#include "customType.h"
#include<iostream> 
using namespace std; 


void editStudentInArray(vector<SV> &danhsach,string ID);
void editStudentInSingleLinkedList(singleLinkedList *& head,string ID);
void editStudentInDoubleLinkedList(doubleLinkedList *& head,string ID);
void editStudentInCircleLinkedList(circleLinkedList *& head,string ID);
