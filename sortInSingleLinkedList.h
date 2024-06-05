#pragma once
#include "customType.h"
#include "init.h"
#include<iostream> 
#include <chrono>
using namespace std; 

// Danh sach lien ket don 


// thuat toan insertion Sort
void  idInsertionSortInSingleLinkedList(singleLinkedList *&head);
void  nameInsertionSortInSingleLinkedList(singleLinkedList *&head);
void  GPAInsertionSortInSingleLinkedList(singleLinkedList *&head);
void InsertionSortInSingleLinkedList(singleLinkedList *&head);


// thuat toan bubble sort
void idBubbleSortInSingleLinkedList(singleLinkedList*& head);
void nameBubbleSortInSingleLinkedList(singleLinkedList*& head);
void GPABubbleSortInSingleLinkedList(singleLinkedList*& head);
void BubbleSortInSingleLinkedList(singleLinkedList*& head);

 
// thuat toan selection sort
void idSelectionSortInSingleLinkedList(singleLinkedList*& head);
void nameSelectionSortInSingleLinkedList(singleLinkedList*& head);
void GPASelectionSortInSingleLinkedList(singleLinkedList*& head);
void SelectionSortInSingleLinkedList(singleLinkedList*& head);


// thuat toan Heap Sort
void heapifyIDInSingleLinkedList(vector<SV> &a, int n, int i);
void heapifyNameInSingleLinkedList(vector<SV> &a, int n, int i);
void heapifyGPAInSingleLinkedList(vector<SV> &a, int n, int i);

void heapSortArrID(vector<SV> &a, int n);
void heapSortArrName(vector<SV> &a, int n);
void heapSortArrGPA(vector<SV> &a, int n);
int sizeDon(singleLinkedList *head);
vector<SV> convertArrDon(singleLinkedList *head);// chuyen doi danh sach lien ket thanh danh sach lien ket don
singleLinkedList *convertSL(vector<SV> a);// chuyen doi vector thanh danh sach lien ket don
void HeapSortInSingleLinkedList(singleLinkedList  *&head);


// thuat toan Quick Sort
void push_node(singleLinkedList* newnode,singleLinkedList *&head);
void GPAQuickSortInSingleLinkedList(singleLinkedList *&head);
void IDQuickSortInSingleLinkedList(singleLinkedList *&head);
void nameQuickSortInSingleLinkedList(singleLinkedList *&head);
void QuickSortInSingleLinkedList(singleLinkedList *&head);


// thuat toan Merge Sort
bool soSanh(const SV &a, const SV &b, int tieuChi);// ham so sanh du tren tieu chi sap xep
singleLinkedList* merge(singleLinkedList* a, singleLinkedList* b, int tieuChi);// H�m gop hai danh s�ch li�n k?t d� s?p x?p
singleLinkedList* mergeSort(singleLinkedList* head, int tieuChi);// H�m sap xep Merge Sort cho danh s�ch li�n ket don
void MergeSortInSingleLinkedList(singleLinkedList* danhsach);



