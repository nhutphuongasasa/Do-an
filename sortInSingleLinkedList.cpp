#include "sortInSingleLinkedList.h"

//  sap xep danh sach sinh vien bang insertionSort trong danh sach lien ket
void  idInsertionSortInSingleLinkedList(singleLinkedList *&head){
    if(head==NULL|| head->next==NULL){
        return ;
    }

    singleLinkedList* sortedList=NULL;
    singleLinkedList *current=head;
    while(current!=NULL){
        singleLinkedList *nextNode=current->next;

        if(sortedList==NULL || sortedList->sinhVien.id>= current->sinhVien.id){// kiểm tra linkedList đang xét có id nhỏ hơn linkedList đầu tiên danh sách đã sắp xếp không
            current->next=sortedList; // nếu nhỏ hơn thì chèn linkedList đó vào đầu danh sách đã sắp xếp
            sortedList= current; // trả lại con trỏ chỉ linkedList đầu trong danh sách đã sắp xếp
        }else{
            singleLinkedList *tmp= sortedList;// tạo một biến tạm để duyệt danh sách dsx;
            while(tmp->next!= NULL&& tmp->next->sinhVien.id< current->sinhVien.id){
                tmp=tmp->next;
            }
                current->next=tmp->next;
                tmp->next=current;  // nối hai đầu của linkedList 
         }

         current=nextNode;
    }

   head= sortedList;
}
void  nameInsertionSortInSingleLinkedList(singleLinkedList *&head){
    if(head==NULL|| head->next==NULL){
        return ;
    }

    singleLinkedList* sortedList=NULL;
    singleLinkedList *current=head;
    while(current!=NULL){
        singleLinkedList *nextNode=current->next;

        if(sortedList==NULL || sortedList->sinhVien.name>= current->sinhVien.name){// kiểm tra linkedList đang xét có id nhỏ hơn linkedList đầu tiên danh sách đã sắp xếp không
            current->next=sortedList; // nếu nhỏ hơn thì chèn linkedList đó vào đầu danh sách đã sắp xếp
            sortedList= current; // trả lại con trỏ chỉ linkedList đầu trong danh sách đã sắp xếp
        }else{
            singleLinkedList *tmp= sortedList;// tạo một biến tạm để duyệt danh sách dsx;
            while(tmp->next!= NULL&& tmp->next->sinhVien.name< current->sinhVien.name){
                tmp=tmp->next;
            }
                current->next=tmp->next;
                tmp->next=current;  // nối hai đầu của linkedList 
         }

         current=nextNode;
    }

   head= sortedList;
}
void  GPAInsertionSortInSingleLinkedList(singleLinkedList *&head){
    if(head==NULL|| head->next==NULL){
        return ;
    }

    singleLinkedList* sortedList=NULL;
    singleLinkedList *current=head;
    while(current!=NULL){
        singleLinkedList *nextNode=current->next;

        if(sortedList==NULL || sortedList->sinhVien.GPA>= current->sinhVien.GPA){// kiểm tra linkedList đang xét có id nhỏ hơn linkedList đầu tiên danh sách đã sắp xếp không
            current->next=sortedList; // nếu nhỏ hơn thì chèn linkedList đó vào đầu danh sách đã sắp xếp
            sortedList= current; // trả lại con trỏ chỉ linkedList đầu trong danh sách đã sắp xếp
        }else{
            singleLinkedList *tmp= sortedList;// tạo một biến tạm để duyệt danh sách dsx;
            while(tmp->next!= NULL&& tmp->next->sinhVien.GPA< current->sinhVien.GPA){
                tmp=tmp->next;
            }
                current->next=tmp->next;
                tmp->next=current;  // nối hai đầu của linkedList 
         }

         current=nextNode;
    }

   head= sortedList;
}
void InsertionSortInSingleLinkedList(singleLinkedList *&head){
		
choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG INSERTIONSORT"<<endl<<endl;
	cout<< "Ban muon sap xep theo tieu chi nao?"<<endl;
	cout<< "1. Ma sinh vien."<<endl;
	cout<< "2. Ten sinh vien."<<endl;
	cout<< "3. Diem GPA."<<endl;
	cout<< "0. Thoat."<<endl;
	cout<< "Nhap lua chon cua ban: ";
	char choice;
	cin>>choice;
	if( choice > '3' ||  choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
		goto choice;
	}
	switch(choice){
		case '1':{
			idInsertionSortInSingleLinkedList(head);
			break;
		}
		case '2':{
			nameInsertionSortInSingleLinkedList(head);
			break;
		}
		case '3':{
			GPAInsertionSortInSingleLinkedList(head);
			break;
		}
		case '0':
			break;
	}
}


//  sap xep danh sach sinh vien bang bubbleSort trong danh sach lien ket
void idBubbleSortInSingleLinkedList(singleLinkedList*& head) {
    if (head==NULL) return;

    bool swapped;
    singleLinkedList* ptr1;
    singleLinkedList* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->sinhVien.id > ptr1->sinhVien.id) {
                swap(ptr1->sinhVien.id, ptr1->next->sinhVien.id);
                swap(ptr1->sinhVien.name, ptr1->next->sinhVien.name);
                swap(ptr1->sinhVien.className, ptr1->next->sinhVien.className);
                swap(ptr1->sinhVien.GPA, ptr1->next->sinhVien.GPA);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void nameBubbleSortInSingleLinkedList(singleLinkedList*& head) {
    if (head==NULL) return;

    bool swapped;
    singleLinkedList* ptr1;
    singleLinkedList* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->sinhVien.name > ptr1->sinhVien.name) {
                swap(ptr1->sinhVien.id, ptr1->next->sinhVien.id);
                swap(ptr1->sinhVien.name, ptr1->next->sinhVien.name);
                swap(ptr1->sinhVien.className, ptr1->next->sinhVien.className);
                swap(ptr1->sinhVien.GPA, ptr1->next->sinhVien.GPA);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void GPABubbleSortInSingleLinkedList(singleLinkedList*& head) {
    if (head==NULL) return;

    bool swapped;
    singleLinkedList* ptr1;
    singleLinkedList* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->sinhVien.GPA > ptr1->sinhVien.GPA) {
                swap(ptr1->sinhVien.id, ptr1->next->sinhVien.id);
                swap(ptr1->sinhVien.name, ptr1->next->sinhVien.name);
                swap(ptr1->sinhVien.className, ptr1->next->sinhVien.className);
                swap(ptr1->sinhVien.GPA, ptr1->next->sinhVien.GPA);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void BubbleSortInSingleLinkedList(singleLinkedList *&head){
		
choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG INSERTIONSORT"<<endl<<endl;
	cout<< "Ban muon sap xep theo tieu chi nao?"<<endl;
	cout<< "1. Ma sinh vien."<<endl;
	cout<< "2. Ten sinh vien."<<endl;
	cout<< "3. Diem GPA."<<endl;
	cout<< "0. Thoat."<<endl;
	cout<< "Nhap lua chon cua ban: ";
	char choice;
	cin>>choice;
	if( choice > '3' ||  choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
		goto choice;
	}
	switch(choice){
		case '1':{
			idBubbleSortInSingleLinkedList(head);
			break;
		}
		case '2':{
			nameBubbleSortInSingleLinkedList(head);
			break;
		}
		case '3':{
			GPABubbleSortInSingleLinkedList(head);
			break;
		}
		case '0':
			break;
	}
}


//  sap xep danh sach sinh vien bang selectionSort trong danh sach lien ket
void idSelectionSortInSingleLinkedList(singleLinkedList*& head) {
  if (!head) return;

    singleLinkedList* sorted = nullptr;  // Danh s�ch d� s?p x?p

    while (head) {
        singleLinkedList* min_prev = nullptr;
        singleLinkedList* min = head;
        singleLinkedList* current = head;

        // T�m sinh vi�n c� t�n nho nhat
        while (current->next) {
            if (current->next->sinhVien.id < min->sinhVien.id) {
                min_prev = current;
                min = current->next;
            }
            current = current->next;
        }

        // Loai bo sinh vi�n c� t�n nho nhat khoi danh s�ch ban dau
        if (min_prev) {
            min_prev->next = min->next;
        } else {
            head = head->next;
        }

        // Th�m sinh vi�n do v�o dau danh s�ch d� sap xep
        min->next = sorted;
        sorted = min;
    }

    // �ao nguoc danh s�ch d� sap xep da c� thu tu tang dan
    singleLinkedList* prev = nullptr;
    singleLinkedList* current = sorted;
    while (current) {
        singleLinkedList* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
void nameSelectionSortInSingleLinkedList(singleLinkedList*& head) {
  if (!head) return;

    singleLinkedList* sorted = nullptr;  // Danh s�ch d� s?p x?p

    while (head) {
        singleLinkedList* min_prev = nullptr;
        singleLinkedList* min = head;
        singleLinkedList* current = head;

        // T�m sinh vi�n c� t�n nho nhat
        while (current->next) {
            if (current->next->sinhVien.name == min->sinhVien.name) {
            	if(current->next->sinhVien.ho < min->sinhVien.ho)
                min_prev = current;
                min = current->next;
            }else if (current->next->sinhVien.name < min->sinhVien.name){
                min_prev = current;
                min = current->next;
			}
            current = current->next;
        }

        // Loai bo sinh vi�n c� t�n nho nhat khoi danh s�ch ban dau
        if (min_prev) {
            min_prev->next = min->next;
        } else {
            head = head->next;
        }

        // Th�m sinh vi�n d� v�o dau danh s�ch d� sap xep
        min->next = sorted;
        sorted = min;
    }

    // �ao nguoc danh s�ch d� sap xep da c� thu tu tang dan
    singleLinkedList* prev = nullptr;
    singleLinkedList* current = sorted;
    while (current) {
        singleLinkedList* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
void GPASelectionSortInSingleLinkedList(singleLinkedList*& head) {
  if (!head) return;

    singleLinkedList* sorted = nullptr;  // Danh s�ch d� s?p x?p

    while (head) {
        singleLinkedList* min_prev = nullptr;
        singleLinkedList* min = head;
        singleLinkedList* current = head;

        // T�m sinh vi�n c� t�n nho nhat
        while (current->next) {
            if (current->next->sinhVien.GPA < min->sinhVien.GPA) {
                min_prev = current;
                min = current->next;
            }
            current = current->next;
        }

        // Loai bo sinh vi�n c� t�n nho nhat khoi danh s�ch ban dau
        if (min_prev) {
            min_prev->next = min->next;
        } else {
            head = head->next;
        }

        // Th�m sinh vi�n do v�o dau danh s�ch d� sap xep
        min->next = sorted;
        sorted = min;
    }

    // �ao nguoc danh s�ch d� sap xep da c� thu tu tang dan
    singleLinkedList* prev = nullptr;
    singleLinkedList* current = sorted;
    while (current) {
        singleLinkedList* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
void SelectionSortInSingleLinkedList(singleLinkedList*& head){

choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG INSERTIONSORT"<<endl<<endl;
	cout<< "Ban muon sap xep theo tieu chi nao?"<<endl;
	cout<< "1. Ma sinh vien."<<endl;
	cout<< "2. Ten sinh vien."<<endl;
	cout<< "3. Diem GPA."<<endl;
	cout<< "0. Thoat."<<endl;
	cout<< "Nhap lua chon cua ban: ";
	char choice;
	cin>>choice;
	if( choice > '3' ||  choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
		goto choice;
	}
	switch(choice){
		case '1':{
			idSelectionSortInSingleLinkedList(head);
			break;
		}
		case '2':{
			nameSelectionSortInSingleLinkedList(head);
			break;
		}
		case '3':{
			GPASelectionSortInSingleLinkedList(head);
			break;
		}
		case '0':
			break;
	}
}



//  sap xep danh sach sinh vien bang Heap Sort trong danh sach lien ket
void heapifyIDInSingleLinkedList(vector<SV> &a, int n, int i){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    if(left < n && a[left].id > a[largest].id){
        largest = left;
    }
    if(right < n && a[right].id > a[largest].id){
        largest = right;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        heapifyIDInSingleLinkedList(a, n, largest);
    }
} 
void heapifyNameInSingleLinkedList(vector<SV> &a, int n, int i){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    if(left < n && a[left].name > a[largest].name){
        largest = left;
    }
    if(right < n && a[right].name > a[largest].name){
        largest = right;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        heapifyNameInSingleLinkedList(a, n, largest);
    }
} 
void heapifyGPAInSingleLinkedList(vector<SV> &a, int n, int i){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    if(left < n && a[left].GPA > a[largest].GPA){
        largest = left;
    }
    if(right < n && a[right].GPA > a[largest].GPA){
        largest = right;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        heapifyGPAInSingleLinkedList(a, n, largest);
    }
} 

void heapSortArrID(vector<SV> &a, int n){
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyIDInSingleLinkedList(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyIDInSingleLinkedList(a, i, 0);
    }
}
void heapSortArrName(vector<SV> &a, int n){
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyNameInSingleLinkedList(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyNameInSingleLinkedList(a, i, 0);
    }
}
void heapSortArrGPA(vector<SV> &a, int n){
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyGPAInSingleLinkedList(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyGPAInSingleLinkedList(a, i, 0);
    }
}
int sizeDon(singleLinkedList *head){
    singleLinkedList *tmp = head;
    int dem = 0;
    while(tmp != NULL){
        ++dem;
        tmp = tmp->next;
    }
    return dem;
}
vector<SV> convertArrDon(singleLinkedList *head){//chuyen doi dslk sang mang
    vector<SV> a;
    singleLinkedList *tmp = head;
    int s = sizeDon(head);
    for(int i = 0; i < s; i++){
        a.push_back(tmp->sinhVien);
        tmp = tmp->next; 
    }
    return a;
}
singleLinkedList *convertSL(vector<SV> a){//chuyen doi mang sang dslk
    singleLinkedList *current = NULL;
    for(int i = 0; i < a.size(); i++){
        pushBackDon(current, a[i]);
    }
    return current;
}
void HeapSortInSingleLinkedList(singleLinkedList  *&head){
	menuHeapSort:
    cout << "SAP XEP DANH SACH SINH VIEN BANG HEAPSORT\n";
    cout << "1. Ma sinh vien\n";
    cout << "2. Ten sinh vien\n";
    cout << "3. Diem GPA\n";
    cout << "4. Thoat\n";
    char choice; 
    cin >> choice;
    if( choice > '4' ||  choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
        goto menuHeapSort;
	}

    switch (choice){
        case '1': {
            vector<SV> a = convertArrDon(head);
            heapSortArrID(a, a.size());
            head = NULL;
            head = convertSL(a);
            a.clear();
            
            break;
        }
        case '2':{
            vector<SV> a = convertArrDon(head);
            heapSortArrName(a, a.size());
            head = NULL;
            head = convertSL(a);
            a.clear();
            //In cac phan tu sau khi duoc sort
         
            break;
        }
        case '3':{
            vector<SV> a = convertArrDon(head);
            heapSortArrGPA(a, a.size());
            head = NULL;
            head = convertSL(a);
            a.clear();
            //In cac phan tu sau khi duoc sort
            //printStudentListInSingleLinkedList(head);
            break;
        }
        case '4':{
            break;
        }
        default:{
            cout << "Lua chon cua ban khong hop le!\n";
          
            break;
        }    
	}
}


// sap xep danh sach sinh vien bang Quick Sort trong danh sach lien ket
void push_node(singleLinkedList* newnode,singleLinkedList *&head){
if (head == NULL) {
        head = newnode;
    }
    else {
        singleLinkedList* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}
void GPAQuickSortInSingleLinkedList(singleLinkedList *&head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    singleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    singleLinkedList* l1 = NULL;
    singleLinkedList* l2 = NULL;
    while (head != NULL) {
        singleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        if (temp->sinhVien.GPA <= pivot->sinhVien.GPA) {
            push_node(temp,l1);    
        }
        else {
            push_node(temp,l2);
        }
    }
    GPAQuickSortInSingleLinkedList(l1);
    GPAQuickSortInSingleLinkedList(l2);
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        singleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
    }
    pivot->next = l2;
}
void IDQuickSortInSingleLinkedList(singleLinkedList *&head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    singleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    singleLinkedList* l1 = NULL;
    singleLinkedList* l2 = NULL;
    while (head != NULL) {
        singleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        if (temp->sinhVien.GPA <= pivot->sinhVien.GPA) {
            push_node(temp,l1);    
        }
        else {
            push_node(temp,l2);
        }
    }
    IDQuickSortInSingleLinkedList(l1);
    IDQuickSortInSingleLinkedList(l2);
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        singleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
    }
    pivot->next = l2;
}
void nameQuickSortInSingleLinkedList(singleLinkedList *&head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    singleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    singleLinkedList* l1 = NULL;
    singleLinkedList* l2 = NULL;
    while (head != NULL) {
        singleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        if (temp->sinhVien.name <= pivot->sinhVien.name) {
            push_node(temp,l1);    
        }
        else {
            push_node(temp,l2);
        }
    }
    nameQuickSortInSingleLinkedList(l1);
    nameQuickSortInSingleLinkedList(l2);
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        singleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
    }
    pivot->next = l2;
}
void QuickSortInSingleLinkedList(singleLinkedList *&head){
		
choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG QUICKSORT"<<endl<<endl;
	cout<< "Ban muon sap xep theo tieu chi nao?"<<endl;
	cout<< "1. Ma sinh vien."<<endl;
	cout<< "2. Ten sinh vien."<<endl;
	cout<< "3. Diem GPA."<<endl;
	cout<< "0. Thoat."<<endl;
	cout<< "Nhap lua chon cua ban: ";
	char choice;
	cin>>choice;
	if( choice > '3' ||  choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
		goto choice;
	}
	switch(choice){
		case '1':{
			 auto start = chrono::steady_clock::now();
			IDQuickSortInSingleLinkedList(head);
    		 auto end = chrono::steady_clock::now();
    		 cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    		 printStudentListInSingleLinkedList(head);
   			  // hien thi thoi gian thuc hien
    		 cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '2':{
			auto start = chrono::steady_clock::now();
			nameQuickSortInSingleLinkedList(head);
    		auto end = chrono::steady_clock::now();
		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInSingleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '3':{
			auto start = chrono::steady_clock::now();
			GPAQuickSortInSingleLinkedList(head);
     		auto end = chrono::steady_clock::now();
    		 // hien thi ket qua danh sach sinh vien sau khi sap xep
    		 cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    		 printStudentListInSingleLinkedList(head);
    		 // hien thi thoi gian thuc hien
     		cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '0':
			break;
	}
}


// sap xep danh sach sinh vien bang Merge Sort trong danh sach lien ket
bool soSanh(const SV &a, const SV &b, int tieuChi){// ham so sanh du tren tieu chi sap xep
    switch (tieuChi){
    case 1: // sap xep theo ma sinh vien
        return a.id < b.id;
    case 2: // Sắp xếp theo tên
        if (a.name == b.name)
            return a.ho < b.ho;
        else
            return a.name < b.name;
    case 3: // Sắp xếp theo điểm
        return a.GPA < b.GPA;
    default:
        return false;
    }
}
singleLinkedList* merge(singleLinkedList* a, singleLinkedList* b, int tieuChi) {// H�m gop hai danh s�ch li�n k?t d� s?p x?p
    singleLinkedList *dummy;
    singleLinkedList* tail = dummy;

    while (a && b) {
        if (soSanh(a->sinhVien, b->sinhVien, tieuChi)) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a) {
        tail->next = a;
    } else {
        tail->next = b;
    }

    return dummy->next;
}
singleLinkedList* mergeSort(singleLinkedList* head, int tieuChi) {// H�m sap xep Merge Sort cho danh s�ch li�n ket don
    if (!head || !head->next) {
        return head;
    }

    singleLinkedList* slow = head;
    singleLinkedList* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    singleLinkedList* mid = slow->next;
    slow->next = nullptr;

    singleLinkedList* left = mergeSort(head, tieuChi);
    singleLinkedList* right = mergeSort(mid, tieuChi);

    return merge(left, right, tieuChi);
}
void MergeSortInSingleLinkedList(singleLinkedList* danhsach){
     int tieuChi;
     cout << "Chon tieu chi sap xep:" << endl;
     cout << "1. Ma sinh vien" << endl;
     cout << "2. Ten" << endl;
     cout << "3. Diem" << endl;
     cin >> tieuChi;

     // sap xep danh sach sinh vien theo tieu chi da chon
     auto start = chrono::steady_clock::now();
     mergeSort(danhsach, tieuChi);
     auto end = chrono::steady_clock::now();

     // hien thi ket qua danh sach sinh vien sau khi sap xep
     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
     printStudentListInSingleLinkedList(danhsach);
     // hien thi thoi gian thuc hien
     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}




































