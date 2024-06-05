#pragma once
#include "customType.h"
#include "init.h" 
#include<iostream> 
#include <chrono>
using namespace std; 

// danh sach lien ket vong

// thuat toan merge sort
bool soSanh2(const SV &a, const SV &b, int tieuChi);
circleLinkedList* split(circleLinkedList* head);// Chia danh sách liên k?t vòng thành hai n?a
circleLinkedList* merge(circleLinkedList* a, circleLinkedList* b, int tieuChi);// Hàm g?p hai danh sách liên k?t vòng dã s?p x?p
circleLinkedList* mergeSort(circleLinkedList* head, int tieuChi);// Hàm s?p x?p Merge Sort cho danh sách liên k?t vòng
void mergeSortInCircleLinkedList(circleLinkedList* danhsach);   


// thuat toan heap sort
void heapifyID2(vector<SV> &danhsach, int n, int i);
void heapifyName2(vector<SV> &danhsach, int n, int i);
void heapifyGPA2(vector<SV> &danhsach, int i);
//
void heapSortArrID2(vector<SV> &danhsach, int n);//sort bang ma sinh vien
void heapSortArrName2(vector<SV> &danhsach );//sort bang ten sinh vien
void heapSortArrGPA2(vector<SV> &danhsach);//sort theo GPA
vector<SV> convertArrVong(circleLinkedList *head);//chuyen doi dslk doi sang mang
circleLinkedList *convertCL(vector<SV> a);//chuyen doi mang sang dslk doi
void heapSortInCircleLinkedList(circleLinkedList *&head);//menu


// thuat toan selection sort
void IDSelectionSortInCircleLinkedList(circleLinkedList*& head) ;
void nameSelectionSortInCircleLinkedList(circleLinkedList*& head);
void GPASelectionSortInCircleLinkedList(circleLinkedList*& head);
void selectionSortInCircleLinkedList(circleLinkedList*& head) ;


// thuat toan insertion sort
void IDInsertionSortInCircleLinkedList(circleLinkedList*& head);
void nameInsertionSortInCircleLinkedList(circleLinkedList*& head);
void GPAInsertionSortInCircleLinkedList(circleLinkedList*& head);
void insertionSortInCircleLinkedList(circleLinkedList*& head);


// thuat toan bubble sort
void idBubbleSortInCircleLinkedList(circleLinkedList*& head);
void nameBubbleSortInCircleLinkedList(circleLinkedList*& head) ;
void GPABubbleSortInCircleLinkedList(circleLinkedList*& head) ;
void bubbleSortInCircleLinkedList(circleLinkedList*& head) ;

// thuat toan quick sort
void nameQuickSortInCircleLinkedList(circleLinkedList *&head, bool is_cirular, int idx); 
void GPAQuickSortInCircleLinkedList(circleLinkedList *&head, bool is_cirular, int idx);
void IDQuickSortInCircleLinkedList(circleLinkedList *&head,bool is_cirular,int idx);
void quickSortInCircleLinkedList(circleLinkedList *&head);



