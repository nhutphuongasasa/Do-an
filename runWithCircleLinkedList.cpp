#include "runWithCircleLinkedList.h"

using namespace std;
using namespace customType;

void runWithCircleLinkedList(){
	system("cls");
	cout<<"CHUONG TRINH QUAN LI SINH VIEN"<<endl;
	cout<<" QUAN LI SINH VIEN BANG LIEN KET VONG"<<endl;
	
	circleLinkedList *head=NULL;
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
				docDuLieuTuCSVsangVong(head,filePath,daMaSV);
				printStudentListInCircleLinkedList(head);
				cout<<endl; 
		         system("pause");
				break;
			}
			case '2':{
				getInfoStudentInCircleLinkedList(head,daMaSV);
				system("pause");
				break;
			}
			case '3':{
				string ID;
				cout<<"Nhap ma so sinh vien can sua: ";
				getline(cin, ID);
				editStudentInCircleLinkedList(head, ID);
				system("pause");
				break;
			}
			case '4':{
				searchInCircleLinkedList(head);
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
				
				bool check =  deleteStudentInCircleLinkedList(head, idDelete);
				if(check){
					daMaSV.erase(idDelete);
				}
				system("pause");
				break;
			}
			case '6':{
				system("cls");
				choiceInCircleLinkedList(head);
				system("pause");
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
						bubbleSortInCircleLinkedList(head);
						system("pause");
						break;
					}
					case '2':{
						selectionSortInCircleLinkedList(head);
						system("pause");
						break;
					}
					case '3':{
						insertionSortInCircleLinkedList(head);
						system("pause");
						break;
					}
					case '4':{
						mergeSortInCircleLinkedList(head);
						break;
					}
					case '5':{
						quickSortInCircleLinkedList(head);
						system("pause");
						break;
					}
					case '6':{
						heapSortInCircleLinkedList(head);
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
				printStudentListInCircleLinkedList(head);
				
				system("pause");
				break;
			}
			case '0':{
				main_menu_choice=0;
				circleLinkedList *tmp=head;// giai phong bo nho
				circleLinkedList *next;
				do{
					next=tmp->next;
					delete tmp;
					tmp=next; 
				}while(tmp!= head);
				break;
			}
		}
	system("cls");
	}while(main_menu_choice!=0);	
}
