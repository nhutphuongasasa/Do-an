#pragma once
#include "customType.h"
#include "init.h" 
#include<iostream> 
#include <chrono>
using namespace std; 

// thuat toan insertion Sort 
void  idInsertionSortInDoubleLinkedList(doubleLinkedList *&head);
void  nameInsertionSortInDoubleLinkedList(doubleLinkedList *&head);
void  GPAInsertionSortInDoubleLinkedList(doubleLinkedList *&head);
void insertionSortInDoubleLinkedList(doubleLinkedList *&head);


// thuat toan bubble Sort
void IDBubbleSortInDoubleLinkedList(doubleLinkedList*& head);
void nameBubbleSortInDoubleLinkedList(doubleLinkedList*& head);
void GPABubbleSortInDoubleLinkedList(doubleLinkedList*& head);
void bubbleSortInDoubleLinkedList(doubleLinkedList*& head);


// thuat toan selection Sort
void swap_data(doubleLinkedList* a, doubleLinkedList* b);
void IDSelectionSortInDoubleLinkedList(doubleLinkedList*& head);
void nameSelectionSortInDoubleLinkedList(doubleLinkedList*& head);
void GPASelectionSortInDoubleLinkedList(doubleLinkedList*& head);
void selectionSortInDoubleLinkedList(doubleLinkedList*& head);


// thuat toan merge sort
bool soSanh1(const SV &a, const SV &b, int tieuChi);
doubleLinkedList* merge(doubleLinkedList* a, doubleLinkedList* b, int tieuChi);// Hàm g?p hai danh sách liên k?t kép dã s?p x?p
doubleLinkedList* mergeSort(doubleLinkedList* head, int tieuChi);// Hàm s?p x?p Merge Sort cho danh sách liên k?t kép
void mergeSortInDoubleLinkedList(doubleLinkedList* danhsach);   


// thuat toan heap sort
void heapifyID1(vector<SV> &a, int n, int i);
void heapifyName1(vector<SV> &a, int n, int i);
void heapifyGPA1(vector<SV> &a, int n, int i);//sort theo GPA

void heapSortArrID1(vector<SV> &a, int n);//sort bang ma sinh vien
void heapSortArrName1(vector<SV> &a, int n);//sort bang ten sinh vien
void heapSortArrGPA1(vector<SV> &a, int n);//ham tinh kich thuoc cua danh sach lien ket
int sizeDoi(doubleLinkedList *head);
vector<SV> convertArrDoi(doubleLinkedList *head);//chuyen doi dslk doi sang mang
doubleLinkedList *convertDL(vector<SV> a);//chuyen doi mang sang dslk doi
void heapSortInDoubleLinkedList(doubleLinkedList *&head);//menu


// thuat toan quick sort
void nameQuickSortInDoubleLinkedList(doubleLinkedList *&head);
void GPAQuickSortInDoubleLinkedList(doubleLinkedList *&head) ;
void IDQuickSortInDoubleLinkedList(doubleLinkedList *&head);
void quickSortInDoubleLinkedList(doubleLinkedList *&head);







