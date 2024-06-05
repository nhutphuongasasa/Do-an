#pragma once
#include "customType.h" 
#include<iostream> 
using namespace std; 

// tim kiem trong danh sach don
void idSearchInSingleLinkedlist(singleLinkedList *head, string idSearch);
void hoSearchInSingleLinkedlist(singleLinkedList *head, string hoSearch);    
void nameSearchInSingleLinkedlist(singleLinkedList *head, string nameSearch);
void GPASearchInSingleLinkedlist(singleLinkedList *head, float GPASearch);
void classNameSearchInSingleLinkedlist(singleLinkedList *head, string classNameSearch);
void searchInSingleLinkedList(singleLinkedList *head);


// tim kiem trong danh sach kep
void idSearchInDoubleLinkedlist(doubleLinkedList *head, string idSearch);
void hoSearchInDoubleLinkedlist(doubleLinkedList *head, string hoSearch);    
void nameSearchInDoubleLinkedlist(doubleLinkedList *head, string nameSearch);
void GPASearchInDoubleLinkedlist(doubleLinkedList *head, float GPASearch);
void classNameSearchInDoubleLinkedlist(doubleLinkedList *head, string classNameSearch);
void searchInDoubleLinkedList(doubleLinkedList *head);


// tim kiem trong danh sach vong
void idSearchInCircleLinkedlist(circleLinkedList *head, string idSearch);
void hoSearchInCircleLinkedlist(circleLinkedList *head, string hoSearch);    
void nameSearchInCircleLinkedlist(circleLinkedList *head, string nameSearch);
void GPASearchInCircleLinkedlist(circleLinkedList *head, float GPASearch);
void classNameSearchInCircleLinkedlist(circleLinkedList *head, string classNameSearch);
void searchInCircleLinkedList(circleLinkedList *head);
string toLowerCase(string str);
