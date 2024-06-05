#include "searchInLinkedList.h"
using namespace customType; 
// danh sach lien ket don
void idSearchInSingleLinkedlist(singleLinkedList *head, string idSearch){
    int found=0;
    idSearch=toUpperCase(idSearch);
    while(head!=NULL){
        if(head->sinhVien.id.find(idSearch)!= string::npos){
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        head=head->next;
    }
    if(found==0){
        cout<<"Khong tim thay sinh vien co id: "<<idSearch<<endl;
    }
}
void hoSearchInSingleLinkedlist(singleLinkedList *head, string hoSearch){
     hoSearch=toUpperCase(hoSearch);
    int found=0;
    while(head!=NULL){
        string hoCurrent= customType::toUpperCase(head->sinhVien.ho);
        if (hoCurrent.find(hoSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                 cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        head=head->next;
    }
          
    if(found==0){
        cout<<"Khong tim thay sinh co ho: "<<hoSearch<<endl;
    }  
}    
void nameSearchInSingleLinkedlist(singleLinkedList *head, string nameSearch){
     nameSearch=toUpperCase(nameSearch);
    int found=0;
    while(head!=NULL){
        string nameCurrent= customType::toUpperCase(head->sinhVien.name);
        if (nameCurrent.find(nameSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        head=head->next;
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co ten: "<<nameSearch<<endl;
    }  
}       
void GPASearchInSingleLinkedlist(singleLinkedList *head, float GPASearch){
    int found=0;
    while(head!=NULL){
        if(head->sinhVien.GPA== GPASearch) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
            }
        }
        head=head->next;
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co GPA: "<<GPASearch<<endl;
    }  
}
void classNameSearchInSingleLinkedlist(singleLinkedList *head, string classNameSearch){
     classNameSearch=toUpperCase(classNameSearch);
    int found=0;
    while(head!=NULL){
        string classNameCurrent= customType::toUpperCase(head->sinhVien.id);
        if (classNameCurrent.find(classNameSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Có."<<endl;
            cout<<"2. Không."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        head=head->next;
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co lop: "<<classNameSearch<<endl;
    }  
}
void searchInSingleLinkedList(singleLinkedList *head){
	gotoSearchChoice:
		system("cls");
		cout<<"TIM KIEM THONG TIN SINH VIEN"<<endl;
		cout<<"Ban muon tim kiem theo tieu chi nao ?"<<endl;
		cout<<"1. Ma sinh vien."<<endl;
		cout<<"2. Ho."<<endl;
		cout<<"3. Ten."<<endl;
		cout<<"4. Lop."<<endl;
		cout<<"5. Diem GPA."<<endl;
		cout<<"0. Thoat."<<endl;
		char search_choice;
		cout<<"Vui long nhap lua chon: ";
		cin>>search_choice;
		if( search_choice > '7' ||  search_choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto gotoSearchChoice;
		}
		cin.ignore();
		switch(search_choice){
			case '1':{
				string idSearch;
				cout<<"Nhap ma sinh vien can tim: ";
				getline(cin,idSearch);
				idSearchInSingleLinkedlist(head,idSearch);
				system("pause");
				break;
			}
			case '2':{
				string hoSearch;
				cout<<"Nhap ho sinh vien can tim: ";
				getline(cin,hoSearch);
				hoSearchInSingleLinkedlist(head,hoSearch);
				system("pause");
				break;
			}
			case '3':{
				string tenSearch;
				cout<<"Nhap ten sinh vien can tim: ";
				getline(cin,tenSearch);
				nameSearchInSingleLinkedlist(head,tenSearch);
				system("pause");
				break;
			}
			case '4':{
				string classSearch;
				cout<<"Nhap lop can tim: ";
				getline(cin,classSearch);
				classNameSearchInSingleLinkedlist(head,classSearch);
				system("pause");
				break;
			}
			case '5':{
				float GPASearch;
				cout<<"Nhap diem GPA can tim: ";
				cin>>GPASearch;
				GPASearchInSingleLinkedlist(head,GPASearch);
				system("pause");
				break;
			}
			case '0':{
				
				break;
			}
			default:
				cout<<"Lua chon khong hop le. Vui long chon lai..."<<endl;
				break;
		}
}


// danh sach lien ket kep
void idSearchInDoubleLinkedlist(doubleLinkedList *head, string idSearch){
    int found=0;
    idSearch=toUpperCase(idSearch);
    while(head!=NULL){
        if(head->sinhVien.id==idSearch){
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        head=head->next;
    }
    if(found==0){
        cout<<"Khong tim thay sinh vien co id: "<<idSearch<<endl;
    }
}
void hoSearchInDoubleLinkedlist(doubleLinkedList *head, string hoSearch){
     hoSearch=toUpperCase(hoSearch);
    int found=0;
    while(head!=NULL){
        string hoCurrent= customType::toUpperCase(head->sinhVien.ho);
        if (hoCurrent.find(hoSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                 cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        head=head->next;
    }
          
    if(found==0){
        cout<<"Khong tim thay sinh co ho: "<<hoSearch<<endl;
    }  
}    
void nameSearchInDoubleLinkedlist(doubleLinkedList *head, string nameSearch){
     nameSearch=toUpperCase(nameSearch);
    int found=0;
    while(head!=NULL){
        string nameCurrent= customType::toUpperCase(head->sinhVien.name);
        if (nameCurrent.find(nameSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        head=head->next;
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co ten: "<<nameSearch<<endl;
    }  
}       
void GPASearchInDoubleLinkedlist(doubleLinkedList *head, float GPASearch){
    int found=0;
    while(head!=NULL){
        if (head->sinhVien.GPA==GPASearch) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
            }
        }
        head=head->next;
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co GPA: "<<GPASearch<<endl;
    }  
}
void classNameSearchInDoubleLinkedlist(doubleLinkedList *head, string classNameSearch){
     classNameSearch=toUpperCase(classNameSearch);
    int found=0;
    while(head!=NULL){
        string classNameCurrent= customType::toUpperCase(head->sinhVien.id);
        if (classNameCurrent.find(classNameSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Có."<<endl;
            cout<<"2. Không."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        head=head->next;
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co lop: "<<classNameSearch<<endl;
    }  
}
void searchInDoubleLinkedList(doubleLinkedList *head){
	gotoSearchChoice:
		system("cls");
		cout<<"TIM KIEM THONG TIN SINH VIEN"<<endl;
		cout<<"Ban muon tim kiem theo tieu chi nao ?"<<endl;
		cout<<"1. Ma sinh vien."<<endl;
		cout<<"2. Ho."<<endl;
		cout<<"3. Ten."<<endl;
		cout<<"4. Lop."<<endl;
		cout<<"5. Diem GPA."<<endl;
		cout<<"0. Thoat."<<endl;
		char search_choice;
		cout<<"Vui long nhap lua chon: ";
		cin>>search_choice;
		if( search_choice > '7' ||  search_choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto gotoSearchChoice;
		}
		cin.ignore();
		switch(search_choice){
			case '1':{
				string idSearch;
				cout<<"Nhap ma sinh vien can tim: ";
				getline(cin,idSearch);
				idSearchInDoubleLinkedlist(head,idSearch);
				system("pause");
				break;
			}
			case '2':{
				string hoSearch;
				cout<<"Nhap ho sinh vien can tim: ";
				getline(cin,hoSearch);
				hoSearchInDoubleLinkedlist(head,hoSearch);
				system("pause");
				break;
			}
			case '3':{
				string tenSearch;
				cout<<"Nhap ten sinh vien can tim: ";
				getline(cin,tenSearch);
				nameSearchInDoubleLinkedlist(head,tenSearch);
				system("pause");
				break;
			}
			case '4':{
				string classSearch;
				cout<<"Nhap lop can tim: ";
				getline(cin,classSearch);
				classNameSearchInDoubleLinkedlist(head,classSearch);
				system("pause");
				break;
			}
			case '5':{
				float GPASearch;
				cout<<"Nhap diem GPA can tim: ";
				cin>>GPASearch;
				GPASearchInDoubleLinkedlist(head,GPASearch);
				system("pause");
				break;
			}
			case '0':{
				
				break;
			}
			default:
				cout<<"Lua chon khong hop le. Vui long chon lai..."<<endl;
				break;
		}
}


// danh sach lien ket vong
void idSearchInCircleLinkedlist(circleLinkedList *head, string idSearch){
    int found=0;
    idSearch=toUpperCase(idSearch);
    circleLinkedList* tmp;
    do{
        if(tmp->sinhVien.id==idSearch){
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        tmp=tmp->next;
    }while(tmp!= head);
    if(found==0){
        cout<<"Khong tim thay sinh vien co id: "<<idSearch<<endl;
    }
}
void hoSearchInCircleLinkedlist(circleLinkedList *head, string hoSearch){
     hoSearch=toUpperCase(hoSearch);
    int found=0;
    circleLinkedList* tmp;
    do{
    	string hoCurrent= customType::toUpperCase(tmp->sinhVien.ho);
        if (hoCurrent.find(hoSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ten: " << head->sinhVien.name << endl;
                string namereverse(head->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << head->sinhVien.id << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                 cout << "Ho: "<< head->sinhVien.ho << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ten: " << head->sinhVien.name << endl;
                cout << "Lop: " << head->sinhVien.className << endl;
                cout << "Diem GPA: " << head->sinhVien.GPA << endl;
            }
        }
        tmp=tmp->next;
	}while(tmp!=head);
          
    if(found==0){
        cout<<"Khong tim thay sinh co ho: "<<hoSearch<<endl;
    }  
}    
void nameSearchInCircleLinkedlist(circleLinkedList *head, string nameSearch){
     nameSearch=toUpperCase(nameSearch);
    int found=0;
    circleLinkedList *tmp;
    do{
    	 string nameCurrent= customType::toUpperCase(tmp->sinhVien.name);
        if (nameCurrent.find(nameSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << tmp->sinhVien.id << endl;
                cout << "Ho: "<< tmp->sinhVien.ho << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ten: " << tmp->sinhVien.name << endl;
                string namereverse(tmp->sinhVien.name.rbegin(), head->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Lop: " << tmp->sinhVien.className << endl;
                cout << "Diem GPA: " << tmp->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << tmp->sinhVien.id << endl;
                cout << "Ho: "<< tmp->sinhVien.ho << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ten: " << tmp->sinhVien.name << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Lop: " << tmp->sinhVien.className << endl;
                cout << "Diem GPA: " << tmp->sinhVien.GPA << endl;
            }
        }
        tmp=tmp->next;
	} while(tmp!=head);      
     if(found==0){
        cout<<"Khong tim thay sinh co ten: "<<nameSearch<<endl;
    }  
}       
void GPASearchInCircleLinkedlist(circleLinkedList *head, float GPASearch){
    int found=0;
    circleLinkedList* tmp;
    do{
    	 if (tmp->sinhVien.GPA==GPASearch) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << tmp->sinhVien.id << endl;
                cout << "Ho: "<< tmp->sinhVien.ho << endl;
                cout << "Ten: " << tmp->sinhVien.name << endl;
                string namereverse(tmp->sinhVien.name.rbegin(), tmp->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << tmp->sinhVien.className << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Diem GPA: " << tmp->sinhVien.GPA << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
            }else{
                cout << "ID: " << tmp->sinhVien.id << endl;
                cout << "Ho: "<< tmp->sinhVien.ho << endl;
                cout << "Ten: " << tmp->sinhVien.name << endl;
                cout << "Lop: " << tmp->sinhVien.className << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Diem GPA: " << tmp->sinhVien.GPA << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
            }
        }
        tmp=tmp->next;
	} while(tmp!=head);
     if(found==0){
        cout<<"Khong tim thay sinh co GPA: "<<GPASearch<<endl;
    }  
}
void classNameSearchInCircleLinkedlist(circleLinkedList *head, string classNameSearch){
     classNameSearch=toUpperCase(classNameSearch);
    int found=0;
    circleLinkedList* tmp;
    do{
    	string classNameCurrent= customType::toUpperCase(tmp->sinhVien.id);
        if (classNameCurrent.find(classNameSearch) != string::npos) {
            // In thông tin sinh viên, bôi đỏ tên nếu tìm thấy
            found=1;
            cout<<"Da tim thay thong tin sinh vien!!!"<<endl;
            cout<<"Ban co muon in nguoc ten cua sinh vien khong?"<<endl;
            cout<<"1. Co."<<endl;
            cout<<"2. Khong."<<endl;
            cout<<"Vui long nhap lua chon: ";
            char luaChon;
            cin>>luaChon;
            if(luaChon=='1'){
                cout << "ID: " << tmp->sinhVien.id << endl;
                cout << "Ho: "<< tmp->sinhVien.ho << endl;
                cout << "Ten: " << tmp->sinhVien.name << endl;
                string namereverse(tmp->sinhVien.name.rbegin(), tmp->sinhVien.name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Lop: " << tmp->sinhVien.className << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Diem GPA: " << tmp->sinhVien.GPA << endl;
            }else{
                cout << "ID: " << tmp->sinhVien.id << endl;
                cout << "Ho: "<< tmp->sinhVien.ho << endl;
                cout << "Ten: " << tmp->sinhVien.name << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Lop: " << tmp->sinhVien.className << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Diem GPA: " << tmp->sinhVien.GPA << endl;
            }
        }
        tmp=tmp->next;
	}while(tmp!=head);
     if(found==0){
        cout<<"Khong tim thay sinh co lop: "<<classNameSearch<<endl;
    }  
}
void searchInCircleLinkedList(circleLinkedList *head){
	gotoSearchChoice:
		system("cls");
		cout<<"TIM KIEM THONG TIN SINH VIEN"<<endl;
		cout<<"Ban muon tim kiem theo tieu chi nao ?"<<endl;
		cout<<"1. Ma sinh vien."<<endl;
		cout<<"2. Ho."<<endl;
		cout<<"3. Ten."<<endl;
		cout<<"4. Lop."<<endl;
		cout<<"5. Diem GPA."<<endl;
		cout<<"0. Thoat."<<endl;
		char search_choice;
		cout<<"Vui long nhap lua chon: ";
		cin>>search_choice;
		if( search_choice > '7' ||  search_choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto gotoSearchChoice;
		}
		cin.ignore();
		switch(search_choice){
			case '1':{
				string idSearch;
				cout<<"Nhap ma sinh vien can tim: ";
				getline(cin,idSearch);
				idSearchInCircleLinkedlist(head,idSearch);
				system("pause");
				break;
			}
			case '2':{
				string hoSearch;
				cout<<"Nhap ho sinh vien can tim: ";
				getline(cin,hoSearch);
				hoSearchInCircleLinkedlist(head,hoSearch);
				system("pause");
				break;
			}
			case '3':{
				string tenSearch;
				cout<<"Nhap ten sinh vien can tim: ";
				getline(cin,tenSearch);
				nameSearchInCircleLinkedlist(head,tenSearch);
				system("pause");
				break;
			}
			case '4':{
				string classSearch;
				cout<<"Nhap lop can tim: ";
				getline(cin,classSearch);
				classNameSearchInCircleLinkedlist(head,classSearch);
				system("pause");
				break;
			}
			case '5':{
				float GPASearch;
				cout<<"Nhap diem GPA can tim: ";
				cin>>GPASearch;
				GPASearchInCircleLinkedlist(head,GPASearch);
				system("pause");
				break;
			}
			case '0':{
				
				break;
			}
			default:
				cout<<"Lua chon khong hop le. Vui long chon lai..."<<endl;
				break;
		}
}









