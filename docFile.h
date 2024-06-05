#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <string>
#include "customType.h"
using namespace std;


// Hàm đọc dữ liệu từ tệp CSV
void docDuLieuTuCSVsangDon( singleLinkedList *&head, string filePath,unordered_set<string> &daMaSV);
void docDuLieuTuCSVsangKep( doubleLinkedList *&head, string filePath,unordered_set<string> &daMaSV);
void docDuLieuTuCSVsangVong(circleLinkedList *&head, string filePath,unordered_set<string> &daMaSV);
void docDuLieuTuCSVsangMang( vector<SV> &danhsach, string filePath,unordered_set<string> &daMaSV);

