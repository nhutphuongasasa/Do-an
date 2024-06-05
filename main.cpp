#include "runWithArray.h"
#include "runWithCircleLinkedList.h"
#include "runWithDoubleLinkedList.h"
#include "runWithSingleLinkedList.h"


int main(){
	char storage_choice;
	do {
		while(true){
		cout<<"CHUONG TRINH QUAN LI SINH VIEN"<<endl;
		cout<<endl<<endl<<endl;
		cout<<"Ban muon luu danh sach sinh vien duoi dang nao?"<<endl;
		cout<<"1. Mang."<<endl;
		cout<<"2. Danh sach lien ket don."<<endl;
		cout<<"3. Danh sach lien ket kep."<<endl;
		cout<<"4. Danh sach lien ket vong."<<endl;
		cout<<"0. Thoat."<<endl;
		cout<<"Nhap lua chon cua ban: ";
		cin>>storage_choice;

			if( storage_choice > '4' ||  storage_choice < '0'){
					cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
					cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
					system("pause");
			}else{
				break;
			}
		}
		switch(storage_choice){
			case '1':{
				runWithArray();
				break;
			}
			case '2':{
				runWithSingleLinkedList();
				break;
			}
			case '3':{
				runWithDoubleLinkedList();
				break;
			}
			case '4':{
				runWithCircleLinkedList();
				break;
			}
			case '0':{
				cout<<"Cam on ban da su dung chuong trinh!!!"<<endl;
				cout<<"Chuc ban luon vui ve va thanh cong."<<endl;
				return 0;
			}
		}
	}while(storage_choice!=0);
}
