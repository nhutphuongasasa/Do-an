#include "searchInArray.h"
using namespace customType; 


// tim kiem sinh vien trong danhsach theo tieu chi
void idSearchInArray(vector<SV> danhsach, string idSearch){
    int found=0;
     idSearch= toUpperCase(idSearch);
    for(int i=0;i<danhsach.size();i++){
        string idCurrent= toUpperCase(danhsach[i].id);
        if (idCurrent.find(idSearch) != string::npos) {
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
                cout << "ID: " << danhsach[i].id << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "Ten: " << danhsach[i].name << endl;
                string namereverse(danhsach[i].name.rbegin(), danhsach[i].name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
            }else{
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "ID: " << danhsach[i].id << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "Ten: " << danhsach[i].name << endl;
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
            }
        }
    } 
    if(found==0){
        cout<<"Khong tim thay sinh co id: "<<idSearch<<endl;
    }       
}
void hoSearchInArray(vector<SV> danhsach, string hoSearch){
     hoSearch=toUpperCase(hoSearch);
    int found=0;
    for(int i=0;i<danhsach.size();i++){
        string hoCurrent= toUpperCase(danhsach[i].ho);
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
                cout << "ID: " << danhsach[i].id << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ten: " << danhsach[i].name << endl;
                string namereverse(danhsach[i].name.rbegin(), danhsach[i].name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
            }else{
                cout << "ID: " << danhsach[i].id << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                 cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Ten: " << danhsach[i].name << endl;
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
            }
        }
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co ho: "<<hoSearch<<endl;
    }  
}    
void nameSearchInArray(vector<SV> danhsach, string nameSearch){
     nameSearch=toUpperCase(nameSearch);
    int found=0;
    for(int i=0;i<danhsach.size();i++){
        string nameCurrent= toUpperCase(danhsach[i].name);
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
                cout << "ID: " << danhsach[i].id << endl;
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ten: " << danhsach[i].name << endl;
                string namereverse(danhsach[i].name.rbegin(), danhsach[i].name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
            }else{
                cout << "ID: " << danhsach[i].id << endl;
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Ten: " << danhsach[i].name << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
            }
        }
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co ten: "<<nameSearch<<endl;
    }  
}       
void GPASearchInArray(vector<SV> danhsach, float GPASearch){
    int found=0;
    for(int i=0;i<danhsach.size();i++){
        if (danhsach[i].GPA==GPASearch) {
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
                cout << "ID: " << danhsach[i].id << endl;
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "Ten: " << danhsach[i].name << endl;
                string namereverse(danhsach[i].name.rbegin(), danhsach[i].name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
            }else{
                cout << "ID: " << danhsach[i].id << endl;
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "Ten: " << danhsach[i].name << endl;
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
            }
        }
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co GPA: "<<GPASearch<<endl;
    }  
}
void classNameSearchInArray(vector<SV> danhsach, string classNameSearch){
     classNameSearch=toUpperCase(classNameSearch);
    int found=0;
    for(int i=0;i<danhsach.size();i++){
        string classNameCurrent= toUpperCase(danhsach[i].id);
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
                cout << "ID: " << danhsach[i].id << endl;
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "Ten: " << danhsach[i].name << endl;
                string namereverse(danhsach[i].name.rbegin(), danhsach[i].name.rend());
                cout << "Ten dao nguoc: " << namereverse << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
            }else{
                cout << "ID: " << danhsach[i].id << endl;
                cout << "Ho: "<< danhsach[i].ho << endl;
                cout << "Ten: " << danhsach[i].name << endl;
                cout << "\033[1;31m"; // Mã màu đỏ
                cout << "Lop: " << danhsach[i].className << endl;
                cout << "\033[0m"; // Trả lại màu mặc định
                cout << "Diem GPA: " << danhsach[i].GPA << endl;
            }
        }
    }        
     if(found==0){
        cout<<"Khong tim thay sinh co lop: "<<classNameSearch<<endl;
    }  
}
void searchInArray(vector<SV> danhsach){
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
				idSearchInArray(danhsach,idSearch);
				system("pause");
				break;
			}
			case '2':{
				string hoSearch;
				cout<<"Nhap ho sinh vien can tim: ";
				getline(cin,hoSearch);
				hoSearchInArray(danhsach,hoSearch);
				system("pause");
				break;
			}
			case '3':{
				string tenSearch;
				cout<<"Nhap ten sinh vien can tim: ";
				getline(cin,tenSearch);
				nameSearchInArray(danhsach,tenSearch);
				system("pause");
				break;
			}
			case '4':{
				string classSearch;
				cout<<"Nhap lop can tim: ";
				getline(cin,classSearch);
				classNameSearchInArray(danhsach,classSearch);
				system("pause");
				break;
			}
			case '5':{
				float GPASearch;
				cout<<"Nhap diem GPA can tim: ";
				cin>>GPASearch;
				GPASearchInArray(danhsach,GPASearch);
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



