#include "sortInDoubleLinkedList.h"


// sap xep danh sach sinh vien bang Merge Sort trong danh sach lien ket
bool soSanh1(const SV &a, const SV &b, int tieuChi){// ham so sanh du tren tieu chi sap xep
    switch (tieuChi){
    case 1: // sap xep theo ma sinh vien
        return a.id < b.id;
    case 2: // Sáº¯p xáº¿p theo tÃªn
        if (a.name == b.name)
            return a.ho < b.ho;
        else
            return a.name < b.name;
    case 3: // Sáº¯p xáº¿p theo Ä‘iá»ƒm
        return a.GPA < b.GPA;
    default:
        return false;
    }
}
doubleLinkedList* merge(doubleLinkedList* a, doubleLinkedList* b, int tieuChi) {// Hàm g?p hai danh sách liên k?t kép dã s?p x?p
    doubleLinkedList* dummy;
    doubleLinkedList* tail = dummy;

    while (a && b) {
        if (soSanh1(a->sinhVien, b->sinhVien, tieuChi)) {
            tail->next = a;
            a->prev = tail;
            a = a->next;
        } else {
            tail->next = b;
            b->prev = tail;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a) {
        tail->next = a;
        a->prev = tail;
    } else {
        tail->next = b;
        b->prev = tail;
    }

    return dummy->next;
}
doubleLinkedList* mergeSort(doubleLinkedList* head, int tieuChi) {// Hàm s?p x?p Merge Sort cho danh sách liên k?t kép
    if (!head || !head->next) {
        return head;
    }

    doubleLinkedList* slow = head;
    doubleLinkedList* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    doubleLinkedList* mid = slow->next;
    slow->next = nullptr;
    if (mid) mid->prev = nullptr;

    doubleLinkedList* left = mergeSort(head, tieuChi);
    doubleLinkedList* right = mergeSort(mid, tieuChi);

    return merge(left, right, tieuChi);
}
void mergeSortInDoubleLinkedList(doubleLinkedList* danhsach){
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
     printStudentListInDoubleLinkedList(danhsach);
     // hien thi thoi gian thuc hien
     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}


// sap xep danh sach sinh vien bang heap Sort trong danh sach lien ket
void heapifyID1(vector<SV> &a, int n, int i){//sort bang ma sinh vien
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
        heapifyID1(a, n, largest);
    }
} 
void heapSortArrID1(vector<SV> &a, int n){
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyID1(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyID1(a, i, 0);
    }
}
void heapifyName1(vector<SV> &a, int n, int i){//sort bang ten sinh vien
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
        heapifyName1(a, n, largest);
    }
} 
void heapSortArrName1(vector<SV> &a, int n){//sort theo GPA
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyName1(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyName1(a, i, 0);
    }
}
void heapifyGPA1(vector<SV> &a, int n, int i){
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
        heapifyGPA1(a, n, largest);
    }
} 
void heapSortArrGPA1(vector<SV> &a, int n){
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyGPA1(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyGPA1(a, i, 0);
    }
}
int sizeDoi(doubleLinkedList *head){//ham tinh kich thuoc cua danh sach lien ket
    doubleLinkedList *tmp = head;
    int dem = 0;
    while(tmp != NULL){
        ++dem;
        tmp = tmp->next;
    }
    return dem;
}
vector<SV> convertArrDoi(doubleLinkedList *head){//chuyen doi dslk doi sang mang
    vector<SV> a;
    doubleLinkedList *tmp = head;
    int s = sizeDoi(head);
    for(int i = 0; i < s; i++){
        a.push_back(tmp->sinhVien);
        tmp = tmp->next; 
    }
    return a;
}
doubleLinkedList *convertToDoubleLinkedList(vector<SV> a){//chuyen doi mang sang dslk doi
    doubleLinkedList *current = NULL;
    for(int i = 0; i < a.size(); i++){
        pushBackDoi(current, a[i]);
    }
    return current;
}
void heapSortInDoubleLinkedList(doubleLinkedList *&head){//menu
heapsort_choice:
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
        goto heapsort_choice;
	}

    switch (choice){
        case '1': {
			auto start = chrono::steady_clock::now();
            vector<SV> a = convertArrDoi(head);
            heapSortArrID1(a, a.size());
            head = NULL;
            head = convertToDoubleLinkedList(a);
            a.clear();
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInDoubleLinkedList(head);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

            break;
        }
        case '2':{
            auto start = chrono::steady_clock::now();
            vector<SV> a = convertArrDoi(head);
            heapSortArrName1(a, a.size());
            head = NULL;
            head = convertToDoubleLinkedList(a);
            a.clear();
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInDoubleLinkedList(head);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

            break;
        }
        case '3':{
            auto start = chrono::steady_clock::now();
            vector<SV> a = convertArrDoi(head);
            heapSortArrGPA1(a, a.size());
            head = NULL;
            head = convertToDoubleLinkedList(a);
            a.clear();
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInDoubleLinkedList(head);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

            break;
        }
        case '4':{
            break;
        }
        default:{
            cout << "Lua chon cua ban khong hop le!\n";
            system("pause");
            goto heapsort_choice;
            break;
        }    
	}
}


// sap xep danh sach sinh vien bang bubble Sort trong danh sach lien ket
void IDBubbleSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    bool swapped;
    doubleLinkedList* current;
    doubleLinkedList* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->sinhVien.id < current->next->sinhVien.id) {
                // Swap the data of the nodes
                swap(current->sinhVien.id, current->next->sinhVien.id);
                swap(current->sinhVien.ho, current->next->sinhVien.ho);
                swap(current->sinhVien.name, current->next->sinhVien.name);
                swap(current->sinhVien.GPA, current->next->sinhVien.GPA);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}
void nameBubbleSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    bool swapped;
    doubleLinkedList* current;
    doubleLinkedList* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->sinhVien.name < current->next->sinhVien.name) {
                // Swap the data of the nodes
                swap(current->sinhVien.id, current->next->sinhVien.id);
                swap(current->sinhVien.ho, current->next->sinhVien.ho);
                swap(current->sinhVien.name, current->next->sinhVien.name);
                swap(current->sinhVien.GPA, current->next->sinhVien.GPA);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}
void GPABubbleSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    bool swapped;
    doubleLinkedList* current;
    doubleLinkedList* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->sinhVien.GPA < current->next->sinhVien.GPA) {
                // Swap the data of the nodes
                swap(current->sinhVien.id, current->next->sinhVien.id);
                swap(current->sinhVien.ho, current->next->sinhVien.ho);
                swap(current->sinhVien.name, current->next->sinhVien.name);
                swap(current->sinhVien.GPA, current->next->sinhVien.GPA);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}
void bubbleSortInDoubleLinkedList(doubleLinkedList*& head){
bubbleSort_choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG BUBBLESORT"<<endl<<endl;
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
		goto bubbleSort_choice;
	}
	switch(choice){
		case '1':{
			IDBubbleSortInDoubleLinkedList(head);
			break;
		}
		case '2':{
			nameBubbleSortInDoubleLinkedList(head);
			break;
		}
		case '3':{
			GPABubbleSortInDoubleLinkedList(head);
			break;
		}
		case '0':
			break;
	}
}


void IDInsertionSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    doubleLinkedList* sorted = nullptr; // Danh sách da sap xep
    doubleLinkedList* current = head;   // Danh sách chua sap xep

    while (current != nullptr) {
        doubleLinkedList* next = current->next;

        // Tìm vi tri chen trong danh sách dã sap xep
        if (sorted == nullptr || sorted->sinhVien.id <= current->sinhVien.id) {
            // Chèn vào dau danh sách da sap xep
            current->next = sorted;
            current->prev = nullptr;
            if (sorted != nullptr)
                sorted->prev = current;
            sorted = current;
        } else {
            // Chèn vào giua  danh sach da sap xep
            doubleLinkedList* temp = sorted;
            while (temp->next != nullptr && temp->next->sinhVien.id < current->sinhVien.id) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }

    head = sorted; // cap nhat head de tro den dau danh sach da sap xep
}
void nameInsertionSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    doubleLinkedList* sorted = nullptr; // Danh sách da sap xep
    doubleLinkedList* current = head;   // Danh sách chua sap xep

    while (current != nullptr) {
        doubleLinkedList* next = current->next;

        // Tìm vi tri chen trong danh sách dã sap xep
        if (sorted == nullptr || sorted->sinhVien.name <= current->sinhVien.name) {
            // Chèn vào dau danh sách da sap xep
            current->next = sorted;
            current->prev = nullptr;
            if (sorted != nullptr)
                sorted->prev = current;
            sorted = current;
        } else {
            // Chèn vào giua  danh sach da sap xep
            doubleLinkedList* temp = sorted;
            while (temp->next != nullptr && temp->next->sinhVien.name < current->sinhVien.name) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }

    head = sorted; // cap nhat head de tro den dau danh sach da sap xep
}
void GPAInsertionSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    doubleLinkedList* sorted = nullptr; // Danh sách da sap xep
    doubleLinkedList* current = head;   // Danh sách chua sap xep

    while (current != nullptr) {
        doubleLinkedList* next = current->next;

        // Tìm vi tri chen trong danh sách dã sap xep
        if (sorted == nullptr || sorted->sinhVien.GPA <= current->sinhVien.GPA) {
            // Chèn vào dau danh sách da sap xep
            current->next = sorted;
            current->prev = nullptr;
            if (sorted != nullptr)
                sorted->prev = current;
            sorted = current;
        } else {
            // Chèn vào giua  danh sach da sap xep
            doubleLinkedList* temp = sorted;
            while (temp->next != nullptr && temp->next->sinhVien.GPA < current->sinhVien.GPA) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }

    head = sorted; // cap nhat head de tro den dau danh sach da sap xep
}
void insertionSortInDoubleLinkedList(doubleLinkedList *&head){
		
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
			IDInsertionSortInDoubleLinkedList(head);
			break;
		}
		case '2':{
			nameInsertionSortInDoubleLinkedList(head);
			break;
		}
		case '3':{
			GPAInsertionSortInDoubleLinkedList(head);
			break;
		}
		case '0':
			break;
	}
}
// sap xep danh sach sinh vien bang selection Sort trong danh sach lien ket
void swap_data(doubleLinkedList* a, doubleLinkedList* b) {
    swap(a->sinhVien.id, b->sinhVien.id);
    swap(a->sinhVien.name, b->sinhVien.name);
    swap(a->sinhVien.className, b->sinhVien.className);
    swap(a->sinhVien.GPA, b->sinhVien.GPA);
}
void IDSelectionSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    doubleLinkedList* current = head;

    while (current) {
        doubleLinkedList* min_node = current;
        doubleLinkedList* next_node = current->next;

        while (next_node) {
            if (next_node->sinhVien.id < min_node->sinhVien.id) {
                min_node = next_node;
            }
            next_node = next_node->next;
        }

        if (min_node != current) {
            swap_data(current, min_node);
        }

        current = current->next;
    }
}
void nameSelectionSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    doubleLinkedList* current = head;

    while (current) {
        doubleLinkedList* min_node = current;
        doubleLinkedList* next_node = current->next;

        while (next_node) {
            if (next_node->sinhVien.name < min_node->sinhVien.name) {
                min_node = next_node;
            }
            next_node = next_node->next;
        }

        if (min_node != current) {
            swap_data(current, min_node);
        }

        current = current->next;
    }
}
void GPASelectionSortInDoubleLinkedList(doubleLinkedList*& head) {
    if (!head) return;

    doubleLinkedList* current = head;

    while (current) {
        doubleLinkedList* min_node = current;
        doubleLinkedList* next_node = current->next;

        while (next_node) {
            if (next_node->sinhVien.GPA < min_node->sinhVien.GPA) {
                min_node = next_node;
            }
            next_node = next_node->next;
        }

        if (min_node != current) {
            swap_data(current, min_node);
        }

        current = current->next;
    }
}
void selectionSortInDoubleLinkedList(doubleLinkedList *&head){
		
choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG SELECTIONSORT"<<endl<<endl;
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
			IDSelectionSortInDoubleLinkedList(head);
			break;
		}
		case '2':{
			nameSelectionSortInDoubleLinkedList(head);
			break;
		}
		case '3':{
			GPASelectionSortInDoubleLinkedList(head);
			break;
		}
		case '0':
			break;
	}
}


// sap xep danh sach sinh vien bang  Sort trong danh sach lien ket
void nameQuickSortInDoubleLinkedList(doubleLinkedList *&head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    doubleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    
    doubleLinkedList* l1 = NULL;
    doubleLinkedList* l2 = NULL;
    while (head != NULL) {
        doubleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        
        if (temp->sinhVien.name <= pivot->sinhVien.name) {
       
            addStudentInDoubleLinkedList(l1,temp);   
        }
        else {
            addStudentInDoubleLinkedList(l2,temp);
        }
    }
    nameQuickSortInDoubleLinkedList(l1);
    nameQuickSortInDoubleLinkedList(l2);
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        doubleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
        pivot->prev=tail;
    }
    if(l2==NULL){
    	pivot->next = l2;
	}
    else{
    	pivot->next = l2;
    	l2->prev=pivot;
	}
}
void GPAQuickSortInDoubleLinkedList(doubleLinkedList *&head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    doubleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    
    doubleLinkedList* l1 = NULL;
    doubleLinkedList* l2 = NULL;
    while (head != NULL) {
        doubleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        
        if (temp->sinhVien.GPA <= pivot->sinhVien.GPA) {
       
            addStudentInDoubleLinkedList(l1,temp);   
        }
        else {
            addStudentInDoubleLinkedList(l2,temp);
        }
    }
    GPAQuickSortInDoubleLinkedList(l1);
    GPAQuickSortInDoubleLinkedList(l2);
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        doubleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
        pivot->prev=tail;
    }
    if(l2==NULL){
    	pivot->next = l2;
	}
    else{
    	pivot->next = l2;
    	l2->prev=pivot;
	}
}
void IDQuickSortInDoubleLinkedList(doubleLinkedList *&head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    doubleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    
    doubleLinkedList* l1 = NULL;
    doubleLinkedList* l2 = NULL;
    while (head != NULL) {
        doubleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        
        if (temp->sinhVien.id<= pivot->sinhVien.id) {
       
            addStudentInDoubleLinkedList(l1,temp);   
        }
        else {
            addStudentInDoubleLinkedList(l2,temp);
        }
    }
    IDQuickSortInDoubleLinkedList(l1);
    IDQuickSortInDoubleLinkedList(l2);
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        doubleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
        pivot->prev=tail;
    }
    if(l2==NULL){
    	pivot->next = l2;
	}
    else{
    	pivot->next = l2;
    	l2->prev=pivot;
	}
}
void quickSortInDoubleLinkedList(doubleLinkedList *&head){
		
choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG QUICKSORT "<<endl<<endl;
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
			IDQuickSortInDoubleLinkedList(head);
     		auto end = chrono::steady_clock::now();
    		 // hien thi ket qua danh sach sinh vien sau khi sap xep
    		 cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    		 printStudentListInDoubleLinkedList(head);
    		 // hien thi thoi gian thuc hien
     		cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '2':{
			auto start = chrono::steady_clock::now();
			nameQuickSortInDoubleLinkedList(head);
     		auto end = chrono::steady_clock::now();
    		 // hien thi ket qua danh sach sinh vien sau khi sap xep
    		 cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    		 printStudentListInDoubleLinkedList(head);
    		 // hien thi thoi gian thuc hien
     		cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '3':{
			auto start = chrono::steady_clock::now();
			GPAQuickSortInDoubleLinkedList(head);
     		auto end = chrono::steady_clock::now();
    		 // hien thi ket qua danh sach sinh vien sau khi sap xep
    		 cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    		 printStudentListInDoubleLinkedList(head);
    		 // hien thi thoi gian thuc hien
     		cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '0':
			break;
	}
}





























