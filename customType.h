#ifndef CUSTOM_TYPE_H
#define CUSTOM_TYPE_H

#include<iostream>
#include<string>
#include <iomanip>  
#include<algorithm>
using namespace std;


struct SV{
 	 string id, name, ho, className;
	 float GPA;
};

struct singleLinkedList{
    SV sinhVien;
    singleLinkedList* next=NULL;
};
struct doubleLinkedList{
    SV sinhVien;
    doubleLinkedList *next=NULL;
    doubleLinkedList *prev=NULL;
    
};
struct circleLinkedList{
    SV sinhVien;
    circleLinkedList *next=NULL;
 
};


singleLinkedList *makeNodeDon(SV a);
doubleLinkedList *makeNodeDoi(SV a);
circleLinkedList *makeNodeVong(SV a);
//them node vao cuoi
void pushBackDon(singleLinkedList  *&head, SV x);
void pushBackDoi(doubleLinkedList *&head, SV x);
void pushBackVong(circleLinkedList *&head, SV newnode);
namespace customType {
    string toUpperCase(string str); 
} 
#endif


