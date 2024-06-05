#include "init.h"
#include "choice.h"
#include <conio.h>
#include "customType.h"
#include "delete.h"
#include "edit.h"
#include "init.h"
#include "searchInArray.h"
#include "sortInArray.h"
#include "docFile.h"
using namespace std; 
// khai bao cac bien, mang luu tru can dung
	
vector<SV> studentList;

void pressAnyKey(){
	cout<<endl<<"Nhap phim bat ki ...";
	getch();
}

int main(){
	while(true){
		mainMenuChoice:
		system("cls");
		cout<<"CHUONG TRINH QUAN LI SINH VIEN"<<endl<<endl;
		cout<<"Chuong trinh duoc luu tru bang mang"<<endl;
		cout<<"--------------MENU---------------------"<<endl;
		cout<<"1. Nhap danh sach sinh tu file."<<endl;
		cout<<"2. Them moi sinh vien."<<endl;
		cout<<"3. Tim kiem thong tin sinh vien."<<endl;
		cout<<"4. Xoa thong tin sinh vien."<<endl;
		cout<<"5. Chuc nang tuy chon."<<endl;
		cout<<"6. Sap xep."<<endl;
		cout<<"0. Thoat"<<endl;
		cout<<"Vui long nhap lua chon: ";
		int menu_choice;
		cin>>menu_choice;
		if(menu_choice<0||menu_choice>6){
			cout<<"Vui long chon chuc nang phu hop!!"<<endl;
			cout<<"Nhap so de lua chon chuc nang!!!"<<endl;
			pressAnyKey();
			goto mainMenuChoice;
		}
		switch(menu_choice){
			case 1:{
				system("cls");
				string filePath;
			    cout << "Nhap duong dan toi file CSV: ";
			    getline(cin, filePath);
				studentList= docDuLieuTuCSV(filePath);
    		
    			
				break;
			}
		}
		
		
		
		
		pressAnyKey();
	}
	
}
