#include "runWithSingleLinkedList.h"

using namespace std;
using namespace customType;

void runWithSingleLinkedList(){
	system("cls");
	cout<<"CHUONG TRINH QUAN LI SINH VIEN"<<endl;
	cout<<" QUAN LI SINH VIEN BANG LIEN KET VONG"<<endl;
	
	singleLinkedList *head=NULL;
	unordered_set<string> daMaSV;
	char main_menu_choice;
	
	main_choice: 
	do{
		cout<< "--------------MENU---------------"<<endl;
		cout<< "1. Them sinh vien bang file"<<endl;
		cout<< "2. Them moi sinh vien."<<endl;
		cout<< "3. Sua thong tin sinh vien."<<endl;
		cout<< "4. Tim kiem thong tin sinh vien."<<endl;
		cout<< "5. Xoa thong tin sinh vien."<<endl;
		cout<< "6. Tuy chon."<<endl;
		cout<< "7. Sap xep danh sach sinh vien. "<<endl;
		cout<< "8. Xuat danh sach sinh vien."<<endl;
		cout<< "0. Thoat."<<endl;
		cout<< "Nhap lua chon cua ban: ";
		cin>>main_menu_choice;// nhap 1 ki so 
		
		if( main_menu_choice > '8' ||  main_menu_choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto main_choice;
		}
		cin.ignore();
		switch(main_menu_choice) {
			case '1':{
				string filePath;
			    cout << "Nhap duong dan toi file CSV: ";
			    getline(cin, filePath);
				docDuLieuTuCSVsangDon(head,filePath,daMaSV);
				printStudentListInSingleLinkedList(head);
				cout<<endl; 
				system("pause");
				break;
			}
			case '2':{
				getInfoStudentInSingleLinkedList(head,daMaSV);
				system("pause");
				break;
			}
			case '3':{
				string ID;
				cout<<"Nhap ma so sinh vien can sua: ";
				getline(cin, ID);
				editStudentInSingleLinkedList(head, ID);
				system("pause");
				break;
			}
			case '4':{
				searchInSingleLinkedList(head);
				system("pause");
				break;
			}
			case '5':{
				system("cls");
				cout<<" XOA THONG TIN SINH VIEN "<<endl;
				
				string idDelete;
				cout<<" Vui long nhap ma so sinh vien can xoa: "; 
				cin>>idDelete;
				idDelete=customType::toUpperCase(idDelete);
				
				bool check =  deleteStudentInSingleLinkedList(head, idDelete);
				if(check){
					daMaSV.erase(idDelete);
				}
				system("pause");
				break;
			}
			case '6':{
				system("cls");
				choiceInSingleLinkedList(head);
				break;
			}
			case '7':{
			menuSortChoice:
				system("cls");
				cout<<"SAP XEP DANH SACH SINH VIEN"<<endl<<endl;
				cout<<"Ban muon sap xep danh sach sinh vien theo: "<<endl;
				cout<< "1.Bubble Sort. "<<endl;
				cout<< "2.Selection Sort. "<<endl;
				cout<< "3.Insertion Sort. "<<endl;
				cout<< "4.Merge Sort. "<<endl;
				cout<< "5.Quick Sort. "<<endl;
				cout<< "6.Heap Sort. "<<endl;
				cout<< "0.Thoat. "<<endl;
				cout<< "Nhap lua chon cua ban: ";
				char sortChoice;
				cin>>sortChoice;
				if( sortChoice > '7' ||  sortChoice < '0'){
					cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
					cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
					system("pause");
					goto menuSortChoice;
				}
				switch(sortChoice){
					case '1':{
						BubbleSortInSingleLinkedList(head);
						system("pause");
						break;
					}
					case '2':{
						SelectionSortInSingleLinkedList(head);
						system("pause");
						break;
					}
					case '3':{
						idInsertionSortInSingleLinkedList(head);
						system("pause");
						break;
					}
					case '4':{
						MergeSortInSingleLinkedList(head);
						break;
					}
					case '5':{
						QuickSortInSingleLinkedList(head);
						system("pause");
						break;
					}
					case '6':{
						HeapSortInSingleLinkedList(head);
						system("pause");
						break;
					}
					case '0':{
						
						break;
					}	
				}
				break;
			}
			case '8':{
				system("cls");
				cout<<"Danh sach sinh vien: "<<endl;
				printStudentListInSingleLinkedList(head);
				
				system("pause");
				break;
			}
			case '0':{
				main_menu_choice=0;
				singleLinkedList *tmp=head; //giai phong bo nho 
				while(head!= NULL){
					tmp=head->next;
					delete head;
					head=tmp; 
				}
				break;
			}
		}
	system("cls");
	}while(main_menu_choice!=0);	
}
