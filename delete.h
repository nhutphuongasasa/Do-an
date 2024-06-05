#pragma once
#include "customType.h"
#include<iostream> 
using namespace std; 
 
bool deleteStudentInArray(vector<SV> &danhsach, string idDelete);
bool deleteStudentInSingleLinkedList(singleLinkedList *&head, string idDelete);
bool deleteStudentInDoubleLinkedList(doubleLinkedList *&head, string idDelete);
bool deleteStudentInCircleLinkedList(circleLinkedList *&head, string idDelete);

