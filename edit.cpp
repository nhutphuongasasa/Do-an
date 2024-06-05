#include "edit.h"

void editStudentInArray(vector<SV> &danhsach,string ID){
	if(danhsach.size()==0){
		cout<<"Danh sach rong."<<endl;
		return ;
	} 
	ID=customType::toUpperCase(ID);
	int pos=-1;
	for(int i=0;i<danhsach.size();i++){
		danhsach[i].id = customType::toUpperCase(danhsach[i].id);
		if(danhsach[i].id.find(ID)!= string::npos){
			pos=i;
			break ;
		}
	}
	if(pos==-1){
        cout<<"Khong ton tai sinh vien co ID:"<<ID<<endl;
        return ;
    }else{
    	edit_choice: // danh dau vi tri quay lai neu nhap sai chuc nang trong menu
        string newID,newName,newClassName;
        float newGPA;
        cout<<"Vui long chon thong tin can sua:"<<endl;
        cout<<"1. ID."<<endl;
        cout<<"2. Ten ."<<endl;
        cout<<"3. Lop."<<endl;
        cout<<"4. Diem GPA."<<endl;
        cout<<"5. Toan bo thong tin sinh vien."<<endl;
        cout<<"Vui long nhap lua chon: ";
        char choice;
        cin>>choice;
        if( choice > '7' ||  choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto edit_choice;
		}
		cin.ignore();  
        switch(choice){
            case '1':{
                cout<<"Vui Long nhap ID moi: ";
                cin>>newID;
                danhsach[pos].id=newID;
                cout<<"Da chinh sua thanh cong."<<endl;
                break;
            }
            case '2':{
                cout<<"Vui long nhap ten moi: ";
                getline(cin,newName);
                danhsach[pos].name=newName;
                cout<<"Da chinh sua thanh cong."<<endl;
                break;
            }
            case '3':{
                cout<<"Vui long nhap lop moi: ";
                getline(cin,newClassName);
                danhsach[pos].className=newClassName;
                cout<<"Da chinh sua thanh cong."<<endl;
                break;

            }
            case '4':{
                cout<<"Vui long nhap diem GPA moi: ";
                cin>>newGPA;
                danhsach[pos].GPA=newGPA;
                cout<<"Da chinh sua thanh cong."<<endl;
                break;

            }
            case '5':{
                cout<<"Vui Long nhap ID moi: ";
                cin>>newID;
                danhsach[pos].id=newID;
                cout<<"Vui long nhap ten moi: ";
                getline(cin,newName);
                danhsach[pos].name=newName;
                cout<<"Vui long nhap lop moi: ";
                getline(cin,newClassName);
                danhsach[pos].className=newClassName;
                cout<<"Vui long nhap diem GPA moi: ";
                cin>>newGPA;
                danhsach[pos].GPA=newGPA;
                cout<<"Da chinh sua thanh cong."<<endl;
                break;

            }
            default:
                cout<<"Lua chon khong ton tai !!"<<endl;
                cout<<"Vui long chon lai!!!"<<endl;
                system("pause");
                break;

        }
    }
}

void editStudentInSingleLinkedList(singleLinkedList *& head,string ID){
    if(head==NULL){
        cout<<"Danh sach trong!!!"<<endl;
        return;
    }
    ID=customType::toUpperCase(ID);
    singleLinkedList *tmp= head;// tao mot bien tam de duyet danh sach sinh vien
    singleLinkedList *pos=NULL;// luu lai vi tri sinh vien can sua
    while(tmp!=NULL){
        if(tmp->sinhVien.id.find(ID) != string::npos){
           pos=tmp;// luu lai vi tri sinh vien can sua
            break;
        }
        tmp=tmp->next;
    }
    if(pos==NULL){
        cout<<"Khong ton tai sinh vien co ID:"<<ID<<endl;
        return;
    }else{
        string newID,newName,newClassName;
        float newGPA;
        cout<<"Vui long chon thong tin can sua:"<<endl;
        cout<<"1. ID."<<endl;
        cout<<"2. Ten ."<<endl;
        cout<<"3. Lop."<<endl;
        cout<<"4. Diem GPA."<<endl;
        cout<<"5. Toan bo thong tin sinh vien."<<endl;
        cout<<"Vui long nhap lua chon: ";
        char choice;
        cin>>choice;
        switch(choice){
            case '1':{
                cout<<"Vui Long nhap ID moi: ";
                cin>>newID;
                pos->sinhVien.id=newID;
                break;
            }
            case '2':{
                cout<<"Vui long nhap ten moi: ";
                getline(cin,newName);
                pos->sinhVien.name=newName;
                break;
            }
            case '3':{
                cout<<"Vui long nhap lop moi: ";
                getline(cin,newClassName);
                pos->sinhVien.className=newClassName;
                break;

            }
            case '4':{
                cout<<"Vui long nhap diem GPA moi: ";
                cin>>newGPA;
                pos->sinhVien.GPA=newGPA;
                break;

            }
            case '5':{
                cout<<"Vui Long nhap ID moi: ";
                cin>>newID;
                pos->sinhVien.id=newID;
                cout<<"Vui long nhap ten moi: ";
                getline(cin,newName);
                pos->sinhVien.name=newName;
                cout<<"Vui long nhap lop moi: ";
                getline(cin,newClassName);
                pos->sinhVien.className=newClassName;
                cout<<"Vui long nhap diem GPA moi: ";
                cin>>newGPA;
                pos->sinhVien.GPA=newGPA;

            }
            default:
                cout<<"Lua chon khong ton tai !!"<<endl;
                cout<<"Vui long chon lai!!!"<<endl;
                system("pause");
                break;

        }
    }
}
void editStudentInDoubleLinkedList(doubleLinkedList *& head,string ID){
    if(head==NULL){
        cout<<"Danh sach trong!!!"<<endl;
        return;
    }
    ID=customType::toUpperCase(ID);
    doubleLinkedList *tmp= head;// tao mot bien tam de duyet danh sach sinh vien
    doubleLinkedList *pos=NULL;// luu lai vi tri sinh vien can sua
    while(tmp!=NULL){
        if(tmp->sinhVien.id.find(ID) != string::npos){
           pos=tmp;// luu lai vi tri sinh vien can sua
            break;
        }
        tmp=tmp->next;
    }
    if(pos==NULL){
        cout<<"Khong ton tai sinh vien co ID:"<<ID<<endl;
        return;
    }else{
        string newID,newName,newClassName;
        float newGPA;
        cout<<"Vui long chon thong tin can sua:"<<endl;
        cout<<"1. ID."<<endl;
        cout<<"2. Ten ."<<endl;
        cout<<"3. Lop."<<endl;
        cout<<"4. Diem GPA."<<endl;
        cout<<"5. Toan bo thong tin sinh vien."<<endl;
        cout<<"Vui long nhap lua chon: ";
        char choice;
        cin>>choice;
        switch(choice){
            case '1':{
                cout<<"Vui Long nhap ID moi: ";
                cin>>newID;
                pos->sinhVien.id=newID;
                break;
            }
            case '2':{
                cout<<"Vui long nhap ten moi: ";
                getline(cin,newName);
                pos->sinhVien.name=newName;
                break;
            }
            case '3':{
                cout<<"Vui long nhap lop moi: ";
                getline(cin,newClassName);
                pos->sinhVien.className=newClassName;
                break;

            }
            case '4':{
                cout<<"Vui long nhap diem GPA moi: ";
                cin>>newGPA;
                pos->sinhVien.GPA=newGPA;
                break;

            }
            case '5':{
                cout<<"Vui Long nhap ID moi: ";
                cin>>newID;
                pos->sinhVien.id=newID;
                cout<<"Vui long nhap ten moi: ";
                getline(cin,newName);
                pos->sinhVien.name=newName;
                cout<<"Vui long nhap lop moi: ";
                getline(cin,newClassName);
                pos->sinhVien.className=newClassName;
                cout<<"Vui long nhap diem GPA moi: ";
                cin>>newGPA;
                pos->sinhVien.GPA=newGPA;

            }
            default:
                cout<<"Lua chon khong ton tai !!"<<endl;
                cout<<"Vui long chon lai!!!"<<endl;
                system("pause");
                break;

        }
    }
}
void editStudentInCircleLinkedList(circleLinkedList *& head,string ID){
    if(head==NULL){
        cout<<"Danh sach trong!!!"<<endl;
        return;
    }
    ID=customType::toUpperCase(ID);
    circleLinkedList *tmp= head;// tao mot bien tam de duyet danh sach sinh vien
    circleLinkedList *pos=NULL;// luu lai vi tri sinh vien can sua
    do{
        if(tmp->sinhVien.id.find(ID) != string::npos){
           pos=tmp;// luu lai vi tri sinh vien can sua
            break;
        }
        tmp=tmp->next;
    }while(tmp!=head);
    if(pos==NULL){
        cout<<"Khong ton tai sinh vien co ID:"<<ID<<endl;
        return;
    }else{
        string newID,newName,newClassName;
        float newGPA;
        cout<<"Vui long chon thong tin can sua:"<<endl;
        cout<<"1. ID."<<endl;
        cout<<"2. Ten ."<<endl;
        cout<<"3. Lop."<<endl;
        cout<<"4. Diem GPA."<<endl;
        cout<<"5. Toan bo thong tin sinh vien."<<endl;
        cout<<"Vui long nhap lua chon: ";
        char choice;
        cin>>choice;
        switch(choice){
            case '1':{
                cout<<"Vui Long nhap ID moi: ";
                cin>>newID;
                pos->sinhVien.id=newID;
                break;
            }
            case '2':{
                cout<<"Vui long nhap ten moi: ";
                getline(cin,newName);
                pos->sinhVien.name=newName;
                break;
            }
            case '3':{
                cout<<"Vui long nhap lop moi: ";
                getline(cin,newClassName);
                pos->sinhVien.className=newClassName;
                break;

            }
            case '4':{
                cout<<"Vui long nhap diem GPA moi: ";
                cin>>newGPA;
                pos->sinhVien.GPA=newGPA;
                break;

            }
            case '5':{
                cout<<"Vui Long nhap ID moi: ";
                cin>>newID;
                pos->sinhVien.id=newID;
                cout<<"Vui long nhap ten moi: ";
                getline(cin,newName);
                pos->sinhVien.name=newName;
                cout<<"Vui long nhap lop moi: ";
                getline(cin,newClassName);
                pos->sinhVien.className=newClassName;
                cout<<"Vui long nhap diem GPA moi: ";
                cin>>newGPA;
                pos->sinhVien.GPA=newGPA;

            }
            default:
                cout<<"Lua chon khong ton tai !!"<<endl;
                cout<<"Vui long chon lai!!!"<<endl;
                system("pause");
                break;

        }
    }
}




























