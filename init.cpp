
#include "init.h"
bool checkID(unordered_set<string> IdList, string id) {
	if (IdList.find(id) != IdList.end()) {
		return true;// bi trung id
	}
	else {
		return false; // khong trung
	}
}
void addStudentInArray(vector<SV>& danhsach, SV sinhVienMoi) {
    danhsach.push_back(sinhVienMoi);

}
void getInfoStudentInArray(vector<SV> &danhsach, unordered_set<string> &daMaSV) {
    SV sinhVienMoi;
    cout << "NHAP THONG TIN SINH VIEN" << endl << endl;

    while (true) {
        cout << "Vui Long nhap ID: ";
        cin >> sinhVienMoi.id;
        cin.ignore();
        sinhVienMoi.id+=" ";
        sinhVienMoi.id = customType::toUpperCase(sinhVienMoi.id);
        if (checkID(daMaSV, sinhVienMoi.id)) {//kiem tra ma sinh vien co bi trung hay ko  
            cout << "Loi: Ma sinh vien '" << sinhVienMoi.id << "' bi trung! Vui long nhap ma sinh vien moi!!" << endl;
       		cout<<"Ban co muon tiep tuc them moi sinh vien khong? "<<endl;
			cout<<"1. Tiep tuc"<<endl;
			cout<<"0. Khong"<<endl;
			string choice;
			cin>>choice;
			if( choice =="1"){
				continue;
			} else{
				break;
			}
	    }
        else {
            
            daMaSV.insert(sinhVienMoi.id);
            break;
        }
    }

    daMaSV.insert(sinhVienMoi.id);
    cout << "Ho: ";
    getline(cin, sinhVienMoi.ho);
    cout << "Ten sinh vien: ";
    getline(cin, sinhVienMoi.name);
    cout << "Lop: ";
    getline(cin, sinhVienMoi.className);
    nhapGPA:
    cout << "Diem GPA: ";
    cin >> sinhVienMoi.GPA;
    if(cin.fail()){
    	cout<<"Ban vua nhap ki tu!!"<<endl;
    	cout<<"Vui long nhap kieu du lieu so!!"<<endl;
    	cin.clear(); 
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// xoa toan bo ki tu trong bo nho dem
    	goto nhapGPA;
	}
    cin.ignore();

    addStudentInArray(danhsach, sinhVienMoi);
    cout << "Da them thanh cong sinh vien: " << sinhVienMoi.name << endl;

}
void printStudentListInArray(vector<SV> danhsach){
    if(danhsach.size()==0){
        cout<<"Danh sach rong!!!"<<endl;
        return;
    }
 
    cout << left << setw(12) << " ID" 
         << left << setw(20) << " Ho" 
         << left << setw(10) << "Name" 
         << left << setw(20) << "ClassName" 
         << left << setw(5) << "GPA" << endl;
     for (int i=0;i<danhsach.size();i++) {

	    cout << left << setw(12) << danhsach[i].id 
	         << left << setw(20) << danhsach[i].ho 
	         << left << setw(10) << danhsach[i].name 
	         << left << setw(20) << danhsach[i].className 
	         << left << setw(5) << danhsach[i].GPA << endl;
	}

}


// danh sach lien ket don
void addStudentInSingleLinkedList(singleLinkedList *&head, singleLinkedList *newStudent){

    if(head==NULL){
        head=newStudent;
    }else{
        singleLinkedList* tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=newStudent;
	}
}
void getInfoStudentInSingleLinkedList(singleLinkedList *&head,  unordered_set<string>& daMaSV){// ham nhap thong tin sinh vien 
    SV newStudent;
    cout<<"NHAP THONG TIN SINH VIEN"<<endl<<endl;
    while (true) { 
        cout << "Vui Long nhap ID : ";
         cin>>newStudent.id;
      	newStudent.id+=" ";
        cin.ignore();
        newStudent.id= customType::toUpperCase(newStudent.id);
        if (checkID(daMaSV, newStudent.id)) {//kiem tra ma sinh vien co bi trung hay ko  
            cout << "Loi: Ma sinh vien '" << newStudent.id << "' bi trung! Vui long nhap ma sinh vien moi!!" << endl;
        	cout<<"Ban co muon tiep tuc them moi sinh vien khong? "<<endl;
			cout<<"1. Tiep tuc"<<endl;
			cout<<"0. Khong"<<endl;
			string choice;
			cin>>choice;
			if( choice =="1"){
				continue;
			} else{
				break;
			}
		}
        else {
            daMaSV.insert(newStudent.id);
            break;
        }
    }
    
    cout<<"Ho sinh vien: ";
    getline(cin,newStudent.ho);
    cout<<"Ten sinh vien: ";
    getline(cin,newStudent.name);
    cout<<"Lop: ";
    getline(cin,newStudent.className);
    nhapGPA:
    cout<<"Diem GPA: ";
    cin>>newStudent.GPA;
    if(cin.fail()){
    	cout<<"Ban vua nhap ki tu!!"<<endl;
    	cout<<"Vui long nhap kieu du lieu so!!"<<endl;
    	cin.clear(); 
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// xoa toan bo ki tu trong bo nho dem
    	
    	goto nhapGPA;
	}
    cin.ignore();
    singleLinkedList * newNode= makeNodeDon(newStudent);
    addStudentInSingleLinkedList(head,newNode);
   
   
    cout<<"Da them thanh cong sinh vien: "<<newStudent.name<<endl;

}
void printStudentListInSingleLinkedList(singleLinkedList *head){

    if(head==NULL){
        cout<<"Danh sach trong";
        return;
    }
        cout << left << setw(12) << " ID" 
         << left << setw(20) << " Ho" 
         << left << setw(10) << "Name" 
         << left << setw(20) << "ClassName" 
         << left << setw(5) << "GPA" << endl;
    

    while(head!=NULL){
	    cout << left << setw(12) << head->sinhVien.id 
	         << left << setw(20) << head->sinhVien.ho 
	         << left << setw(10) << head->sinhVien.name 
	         << left << setw(20) << head->sinhVien.className 
	         << left << setw(5) << head->sinhVien.GPA << endl;
	    head=head->next;
	}
    
}


// danh sach lien ket kep
void addStudentInDoubleLinkedList(doubleLinkedList *&head, doubleLinkedList *newStudent){
 doubleLinkedList* newNode = new doubleLinkedList;
    newNode = newStudent;
    newNode->next = nullptr;

    if (head == nullptr) {
        // Danh sách r?ng, thêm nút d?u tiên
        newNode->prev = nullptr;
        head = newNode;
    } else {
        // Tìm nút cu?i cùng
        doubleLinkedList* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Thêm nút m?i vào cu?i
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void getInfoStudentInDoubleLinkedList(doubleLinkedList *&head,  unordered_set<string>& daMaSV){// ham nhap thong tin sinh vien 
       SV newStudent;
    cout<<"NHAP THONG TIN SINH VIEN"<<endl<<endl;
    while (true) { 
        cout << "Vui Long nhap ID : ";
         cin>>newStudent.id;
      	newStudent.id+=" ";
        cin.ignore();
        newStudent.id= customType::toUpperCase(newStudent.id);
        if (checkID(daMaSV, newStudent.id)) {//kiem tra ma sinh vien co bi trung hay ko  
            cout << "Loi: Ma sinh vien '" << newStudent.id << "' bi trung! Vui long nhap ma sinh vien moi!!" << endl;
        	cout<<"Ban co muon tiep tuc them moi sinh vien khong? "<<endl;
			cout<<"1. Tiep tuc"<<endl;
			cout<<"0. Khong"<<endl;
			string choice;
			cin>>choice;
			if( choice =="1"){
				continue;
			} else{
				break;
			}
		}
        else {
            daMaSV.insert(newStudent.id);
            break;
        }
    }
    
    cout<<"Ho sinh vien: ";
    getline(cin,newStudent.ho);
    cout<<"Ten sinh vien: ";
    getline(cin,newStudent.name);
    cout<<"Lop: ";
    getline(cin,newStudent.className);
    nhapGPA:
    cout<<"Diem GPA: ";
    cin>>newStudent.GPA;
	if(cin.fail()){
    	cout<<"Ban vua nhap ki tu!!"<<endl;
    	cout<<"Vui long nhap kieu du lieu so!!"<<endl;
    	cin.clear(); 
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// xoa toan bo ki tu trong bo nho dem
    	
    	goto nhapGPA;
	}
    cin.ignore();
    doubleLinkedList * newNode= makeNodeDoi(newStudent);
    addStudentInDoubleLinkedList(head,newNode);
   
    cout<<"Da them thanh cong sinh vien: "<<newNode->sinhVien.name<<endl;

}
void printStudentListInDoubleLinkedList(doubleLinkedList *head){

    if(head==NULL){
        cout<<"Danh sach trong";
        return;
    }
        cout << left << setw(12) << " ID" 
         << left << setw(20) << " Ho" 
         << left << setw(10) << "Name" 
         << left << setw(20) << "ClassName" 
         << left << setw(5) << "GPA" << endl;
    

    while(head!=NULL){
	    cout << left << setw(12) << head->sinhVien.id 
	         << left << setw(20) << head->sinhVien.ho 
	         << left << setw(10) << head->sinhVien.name 
	         << left << setw(20) << head->sinhVien.className 
	         << left << setw(5) << head->sinhVien.GPA << endl;
	    head=head->next;
	}
    
}


// danh sach lien ket vong
void addStudentInCircleLinkedList(circleLinkedList *&head, circleLinkedList *newStudent){
	if (head == NULL) {
        head = newStudent;
        newStudent->next=head;
        return;
	}else {
        circleLinkedList* current = head;
       	do{
            current = current->next;
        } while (current->next != head);
        current->next = newStudent;
        newStudent->next=head;
    }
}
void getInfoStudentInCircleLinkedList(circleLinkedList *&head,  unordered_set<string>& daMaSV){// ham nhap thong tin sinh vien 
   SV newStudent;
    cout<<"NHAP THONG TIN SINH VIEN"<<endl<<endl;
    while (true) { 
        cout << "Vui Long nhap ID : ";
         cin>>newStudent.id;
      	newStudent.id+=" ";
        cin.ignore();
        newStudent.id= customType::toUpperCase(newStudent.id);
        if (checkID(daMaSV, newStudent.id)) {//kiem tra ma sinh vien co bi trung hay ko  
            cout << "Loi: Ma sinh vien '" << newStudent.id << "' bi trung! Vui long nhap ma sinh vien moi!!" << endl;
        	cout<<"Ban co muon tiep tuc them moi sinh vien khong? "<<endl;
			cout<<"1. Tiep tuc"<<endl;
			cout<<"0. Khong"<<endl;
			string choice;
			cin>>choice;
			if( choice =="1"){
				continue;
			} else{
				break;
			}
		}
        else {
            daMaSV.insert(newStudent.id);
            break;
        }
    }
    cout<<"Ho sinh vien: ";
    getline(cin,newStudent.ho);
    cout<<"Ten sinh vien: ";
    getline(cin,newStudent.name);
    cout<<"Lop: ";
    getline(cin,newStudent.className);
    nhapGPA:
    cout<<"Diem GPA: ";
    cin>>newStudent.GPA;
    if(cin.fail()){
    	cout<<"Ban vua nhap ki tu!!"<<endl;
    	cout<<"Vui long nhap kieu du lieu so!!"<<endl;
    	cin.clear(); 
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// xoa toan bo ki tu trong bo nho dem
    	
    	goto nhapGPA;
	}
    cin.ignore();
    circleLinkedList * newNode= makeNodeVong(newStudent);
    addStudentInCircleLinkedList(head,newNode);
   
    cout<<"Da them thanh cong sinh vien: "<<newNode->sinhVien.name<<endl;

}
void printStudentListInCircleLinkedList(circleLinkedList *head){

    if(head==NULL){
        cout<<"Danh sach trong";
        return;
    }
        cout << left << setw(12) << " ID" 
         << left << setw(20) << " Ho" 
         << left << setw(10) << "Name" 
         << left << setw(20) << "ClassName" 
         << left << setw(5) << "GPA" << endl;
    
	circleLinkedList* tmp=head;
    do{
	    cout << left << setw(12) << tmp->sinhVien.id 
	         << left << setw(20) << tmp->sinhVien.ho 
	         << left << setw(10) << tmp->sinhVien.name 
	         << left << setw(20) << tmp->sinhVien.className 
	         << left << setw(5) << tmp->sinhVien.GPA << endl;
	    tmp=tmp->next;
	}while(tmp!=head);
    
}




