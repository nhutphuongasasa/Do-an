#pragma once
#include "customType.h"
#include<iostream> 
#include <string>
#include <unordered_set>
#include <iomanip>
using namespace std; 
bool checkID(unordered_set<string>IdList, string id);
// mang  
void addStudentInArray(vector<SV> &danhsach, SV sinhVienMoi);
void getInfoStudentInArray(vector<SV> &danhsach,unordered_set<string> &daMaSV);
void printStudentListInArray(vector<SV> danhsach);


// danh sach lien ket don
void addStudentInSingleLinkedList(singleLinkedList *&head, singleLinkedList *newNode);
void getInfoStudentInSingleLinkedList(singleLinkedList *&head, unordered_set<string>& daMaSV);
void printStudentListInSingleLinkedList(singleLinkedList *head);


// danh sach lien ket kep
void addStudentInDoubleLinkedList(doubleLinkedList *&head, doubleLinkedList *newNode);
void getInfoStudentInDoubleLinkedList(doubleLinkedList *&head, unordered_set<string>& daMaSV);
void printStudentListInDoubleLinkedList(doubleLinkedList *head);


// danh sach lien ket vong
void addStudentInCircleLinkedList(circleLinkedList *&head, circleLinkedList *newNode);
void getInfoStudentInCircleLinkedList(circleLinkedList *&head, unordered_set<string>& daMaSV);
void printStudentListInCircleLinkedList(circleLinkedList *head);







