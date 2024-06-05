 #pragma once
 #include "customType.h"
#include<iomanip>
#include<iostream> 
using namespace std; 

void highestScoreInArray(vector<SV> danhsach);
void lowestScoreInArray(vector<SV> danhsach);
void averageScoreInArray(vector<SV> danhsach);
void choiceInArray(vector<SV> danhsach);


// danh sach lien ket don
void highestScoreInSingleLinkedList(singleLinkedList *head);
void lowestScoreInSingleLinkedList(singleLinkedList *head);
void averageScoreInSingleLinkedList(singleLinkedList *head);
void choiceInSingleLinkedList(singleLinkedList *head);


// danh sach lien ket kep
void highestScoreInDoubleLinkedList(doubleLinkedList *head);
void lowestScoreInDoubleLinkedList(doubleLinkedList *head);
void averageScoreInDoubleLinkedList(doubleLinkedList *head);
void choiceInDoubleLinkedList(doubleLinkedList *head);


// danh sach lien ket vong
void highestScoreInCircleLinkedList(circleLinkedList *head);
void lowestScoreInCircleLinkedList(circleLinkedList *head);
void averageScoreInCircleLinkedList(circleLinkedList *head);
void choiceInCircleLinkedList(circleLinkedList *head);

