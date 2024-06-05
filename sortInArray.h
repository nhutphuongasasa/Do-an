#pragma once
#include "customType.h"
#include "init.h" 
#include <iostream> 
#include <chrono>

using namespace std; 
// thuat toan insertion Sort
void idInsertionSortInArray(vector<SV> &danhsach);
void nameInsertionSortInArray(vector<SV> &danhsach);
void GPAInsertionSortInArray(vector<SV> &danhsach);
void insertionSortInArray(vector<SV> &danhsach); 


// thuat toan bubble Sort
void idBubbleSortInArray(vector<SV> &danhsach);
void nameBubbleSortInArray(vector<SV> &danhsach);
void GPABubbleSortInArray(vector<SV> &danhsach);
void BubbleSortInArray(vector<SV> &danhsach);


// thuat toan selection sort
void idSelectionSortInArray(vector<SV> &danhsach);
void nameSelectionSortInArray(vector<SV> &danhsach);
void GPASelectionSortInArray(vector<SV> &danhsach);
void selectionSortInArray(vector<SV> &danhsach);


// thuat toan heap sort
void heapifyIDInArray(vector<SV> &a, int i);
void IdHeapSortInArray(vector<SV> &a);//sort theo ma sinh vien
void heapifyNameInArray(vector<SV> &a, int i);
void nameHeapSortInArray(vector<SV> &a);//sort theo ten sinh vien
void heapifyGPAInArray(vector<SV> &a, int i);
void GPAHeapSortInArray(vector<SV> &a);//sort theo GPA
void heapSortInArray(vector<SV> &danhsach);//menu tieu chi sap xep 


// thuat toan mergeSort
bool soSanhArr(const SV &a, const SV &b, int tieuChi);
void gop(vector<SV> &arr, int l, int m, int r, int tieuChi);
void mergeSort(vector<SV> &arr, int l, int r, int tieuChi);
void mergeSortInArray(vector<SV> &danhsach);


// thuat toan Quick Sort
void swap(SV &a,SV &b);
int partition_gpa(vector<SV> &danhsach, int l, int r);
int partition_msv(vector<SV> &danhsach, int l, int r);
int partition_name(vector<SV> &danhsach, int l, int r);
void IDQuickSortInArray(vector<SV> &danhsach, int l, int r);
void nameQuickSortInArray(vector<SV> &danhsach, int l, int r);
void GPAQuickSortInArray(vector<SV> &danhsach, int l, int r);
void QuickSortInArray(vector<SV> &danhsach);




