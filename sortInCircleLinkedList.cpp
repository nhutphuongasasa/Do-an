#include "sortInCircleLinkedList.h" 

// sap xep danh sach sinh vien bang Merge Sort trong danh sach lien ket
bool soSanh2(const SV &a, const SV &b, int tieuChi){// ham so sanh du tren tieu chi sap xep
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
circleLinkedList* split(circleLinkedList* head) {// Chia danh sách liên k?t vòng thành hai n?a
    if (!head || !head->next) {
        return nullptr;
    }

    circleLinkedList* slow = head;
    circleLinkedList* fast = head->next;

    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    circleLinkedList* mid = slow->next;
    slow->next = head;  // T?o vòng cho n?a d?u

    return mid;
}
circleLinkedList* merge(circleLinkedList* a, circleLinkedList* b, int tieuChi) {// Hàm g?p hai danh sách liên k?t vòng dã s?p x?p
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }

    circleLinkedList dummy;
    circleLinkedList* tail = &dummy;
    circleLinkedList* head = nullptr;

    while (a && b) {
        if (soSanh2(a->sinhVien, b->sinhVien, tieuChi)) {
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

    head = dummy.next;
    tail->next = head;  // T?o vòng cho danh sách k?t qu?

    return head;
}
circleLinkedList* mergeSort(circleLinkedList* head, int tieuChi) {// Hàm s?p x?p Merge Sort cho danh sách liên k?t vòng
    if (!head || !head->next) {
        return head;
    }

    circleLinkedList* mid = split(head);
    circleLinkedList* left = mergeSort(head, tieuChi);
    circleLinkedList* right = mergeSort(mid, tieuChi);

    return merge(left, right, tieuChi);
}
void mergeSortInCircleLinkedList(circleLinkedList* danhsach){
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
     printStudentListInCircleLinkedList(danhsach);
     // hien thi thoi gian thuc hien
     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}


//sort bang ma sinh vien
void heapifyID2(vector<SV> &a, int n, int i){
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
        heapifyID2(a, n, largest);
    }
} 
void heapSortArrID2(vector<SV> &a, int n){
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyID2(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyID2(a, i, 0);
    }
}
void heapifyName2(vector<SV> &a, int n, int i){//sort bang ten sinh vien
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
        heapifyName2(a, n, largest);
    }
} 
void heapSortArrName2(vector<SV> &a, int n){//sort theo GPA
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyName2(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyName2(a, i, 0);
    }
}
void heapifyGPA2(vector<SV> &a, int n, int i){
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
        heapifyGPA2(a, n, largest);
    }
} 
void heapSortArrGPA2(vector<SV> &a, int n){
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyGPA2(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapifyGPA2(a, i, 0);
    }
}
int sizeVong(circleLinkedList *head){//ham tinh kich thuoc cua danh sach lien ket
    if(head==NULL){
    	return 0;
	}
	circleLinkedList *tmp = head;
    int dem = 0;
   do{
        ++dem;
        tmp = tmp->next;
    } while(tmp != head);
    return dem;
}
vector<SV> convertArrVong(circleLinkedList *head){//chuyen doi dslk vong sang mang
    vector<SV> a;
    circleLinkedList *tmp = head;
    int s = sizeVong(head);
    for(int i = 0; i < s; i++){
        a.push_back(tmp->sinhVien);
        tmp = tmp->next; 
    }
    return a;
}
circleLinkedList *convertCL(vector<SV> a){//chuyen doi mang sang dslk vong
    circleLinkedList *current = NULL;
    for(int i = 0; i < a.size(); i++){
        pushBackVong(current, a[i]);
    }
    return current;
}
void heapSortInCircleLinkedList(circleLinkedList *&head){//menu
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
            vector<SV> a = convertArrVong(head);
            heapSortArrID2(a, a.size());
            head = NULL;
            head = convertCL(a);
            //In cac phan tu sau khi duoc sort
            a.clear();
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInCircleLinkedList(head);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

            break;
        }
        case '2':{
            auto start = chrono::steady_clock::now();
            vector<SV> a = convertArrVong(head);
            heapSortArrName2(a, a.size());
            head = NULL;
            head = convertCL(a);
            a.clear();
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInCircleLinkedList(head);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

            break;
        }
        case '3':{
            auto start = chrono::steady_clock::now();
            vector<SV> a = convertArrVong(head);
            heapSortArrGPA2(a, a.size());
            head = NULL;
            head = convertCL(a);
            a.clear();
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInCircleLinkedList(head);
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


// sap xep danh sach sinh vien bang selection Sort trong danh sach lien ket
void IDSelectionSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    circleLinkedList* start = head;
    do {
        circleLinkedList* min = start;
        circleLinkedList* current = start->next;

        do {
        	if (current->sinhVien.id < min->sinhVien.id) {
                min = current;
              }
            current = current->next;
        } while (current != head);

        if (min != start) {
            swap(start->sinhVien.id, min->sinhVien.id);
            swap(start->sinhVien.name, min->sinhVien.name);
            swap(start->sinhVien.className, min->sinhVien.className);
            swap(start->sinhVien.GPA, min->sinhVien.GPA);
        }

        start = start->next;
    } while (start->next != head);
}
void nameSelectionSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    circleLinkedList* start = head;
    do {
        circleLinkedList* min = start;
        circleLinkedList* current = start->next;

        do {
        	if (current->sinhVien.name == min->sinhVien.name) {
        		if (current->sinhVien.ho < min->sinhVien.ho) {
                	min = current;
            	}
            } else if(current->sinhVien.name < min->sinhVien.name){
                min = current;
              }
            current = current->next;
        } while (current != head);

        if (min != start) {
            swap(start->sinhVien.id, min->sinhVien.id);
            swap(start->sinhVien.name, min->sinhVien.name);
            swap(start->sinhVien.className, min->sinhVien.className);
            swap(start->sinhVien.GPA, min->sinhVien.GPA);
        }

        start = start->next;
    } while (start->next != head);
}
void GPASelectionSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    circleLinkedList* start = head;
    do {
        circleLinkedList* min = start;
        circleLinkedList* current = start->next;

        do {
        	if (current->sinhVien.GPA < min->sinhVien.GPA) {
                min = current;
              }
            current = current->next;
        } while (current != head);

        if (min != start) {
            swap(start->sinhVien.id, min->sinhVien.id);
            swap(start->sinhVien.name, min->sinhVien.name);
            swap(start->sinhVien.className, min->sinhVien.className);
            swap(start->sinhVien.GPA, min->sinhVien.GPA);
        }

        start = start->next;
    } while (start->next != head);
}
void selectionSortInCircleLinkedList(circleLinkedList *&head){
		
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
			auto start = chrono::steady_clock::now();
			IDSelectionSortInCircleLinkedList(head);
    		auto end = chrono::steady_clock::now();

		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '2':{
				auto start = chrono::steady_clock::now();
			nameSelectionSortInCircleLinkedList(head);
    		auto end = chrono::steady_clock::now();

		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '3':{
				auto start = chrono::steady_clock::now();
			GPASelectionSortInCircleLinkedList(head);
			
    		auto end = chrono::steady_clock::now();

		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '0':
			break;
	}
}


//sap xep danh sach sinh vien bang insertion Sort trong danh sach lien ket
void IDInsertionSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    circleLinkedList* sorted = nullptr;
    circleLinkedList* current = head;
    circleLinkedList* next = nullptr;

    do {
        next = current->next;
        if (!sorted || sorted->sinhVien.id >= current->sinhVien.id) {
            // Insert at the beginning
            current->next = sorted ? sorted : current;
            circleLinkedList* last = sorted ? sorted : head;
            while (last && last->next != sorted && last->next != head) {
                last = last->next;
            }
            if (last) last->next = current;
            sorted = current;
        } else {
            // them vao danh sach da sap xep 
            circleLinkedList* sorted_current = sorted;
            while (sorted_current->next != sorted && sorted_current->next->sinhVien.id < current->sinhVien.id) {
                sorted_current = sorted_current->next;
            }
            current->next = sorted_current->next;
            sorted_current->next = current;
        }
        current = next;
    } while (current != head);

   // tim node moi (phan tu nho nhat) 
    head = sorted;
    while (head->next != sorted) {
        head = head->next;
    }
    head->next = sorted;
    head = sorted;
} 
void nameInsertionSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    circleLinkedList* sorted = nullptr;
    circleLinkedList* current = head;
    circleLinkedList* next = nullptr;

    do {
        next = current->next;
        if (!sorted || sorted->sinhVien.name >= current->sinhVien.name) {
            // Insert at the beginning
            current->next = sorted ? sorted : current;
            circleLinkedList* last = sorted ? sorted : head;
            while (last && last->next != sorted && last->next != head) {
                last = last->next;
            }
            if (last) last->next = current;
            sorted = current;
        } else {
            // Insert in the middle or end
            circleLinkedList* sorted_current = sorted;
            while (sorted_current->next != sorted && sorted_current->next->sinhVien.name < current->sinhVien.name) {
                sorted_current = sorted_current->next;
            }
            current->next = sorted_current->next;
            sorted_current->next = current;
        }
        current = next;
    } while (current != head);

    // Find new head (smallest element)
    head = sorted;
    while (head->next != sorted) {
        head = head->next;
    }
    head->next = sorted;
    head = sorted;
} 
void GPAInsertionSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    circleLinkedList* sorted = nullptr;
    circleLinkedList* current = head;
    circleLinkedList* next = nullptr;

    do {
        next = current->next;
        if (!sorted || sorted->sinhVien.GPA >= current->sinhVien.GPA) {
            current->next = sorted ? sorted : current;
            circleLinkedList* last = sorted ? sorted : head;
            while (last && last->next != sorted && last->next != head) {
                last = last->next;
            }
            if (last) last->next = current;
            sorted = current;
        } else {
           //them phan tu vao danh sach da sap xep 
            circleLinkedList* sorted_current = sorted;
            while (sorted_current->next != sorted && sorted_current->next->sinhVien.GPA < current->sinhVien.GPA) {
                sorted_current = sorted_current->next;
            }
            current->next = sorted_current->next;
            sorted_current->next = current;
        }
        current = next;
    } while (current != head);

    // tim node dau va phan tu nho nhat 
    head = sorted;
    while (head->next != sorted) {
        head = head->next;
    }
    head->next = sorted;
    head = sorted;
} 
void insertionSortInCircleLinkedList(circleLinkedList*& head){
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
			auto start = chrono::steady_clock::now();
			IDInsertionSortInCircleLinkedList(head);
		
    		auto end = chrono::steady_clock::now();

		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '2':{
				auto start = chrono::steady_clock::now();
			nameInsertionSortInCircleLinkedList(head);
    		auto end = chrono::steady_clock::now();

		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '3':{
				auto start = chrono::steady_clock::now();
			GPAInsertionSortInCircleLinkedList(head);
			
    		auto end = chrono::steady_clock::now();

		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '0':
			break;
	}
}


//sap xep danh sach sinh vien bang bubble Sort trong danh sach lien ket
void idBubbleSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    bool swapped;
    circleLinkedList* current;
    circleLinkedList* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != head && current->next != last) {
			if (current->sinhVien.id > current->next->sinhVien.id) {
                swap(current->sinhVien.id, current->next->sinhVien.id);
                swap(current->sinhVien.ho, current->next->sinhVien.ho);
                swap(current->sinhVien.name, current->next->sinhVien.name);
                swap(current->sinhVien.className, current->next->sinhVien.className);
                swap(current->sinhVien.GPA, current->next->sinhVien.GPA);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
} 
void nameBubbleSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    bool swapped;
    circleLinkedList* current;
    circleLinkedList* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != head && current->next != last) {
			if (current->sinhVien.name == current->next->sinhVien.name) {
				if (current->sinhVien.ho < current->next->sinhVien.ho) {
	                swap(current->sinhVien.id, current->next->sinhVien.id);
	                swap(current->sinhVien.ho, current->next->sinhVien.ho);
	                swap(current->sinhVien.name, current->next->sinhVien.name);
	                swap(current->sinhVien.className, current->next->sinhVien.className);
	                swap(current->sinhVien.GPA, current->next->sinhVien.GPA);
	                swapped = true;
	        	}
            }else if (current->sinhVien.name < current->next->sinhVien.name) {
                swap(current->sinhVien.id, current->next->sinhVien.id);
                swap(current->sinhVien.ho, current->next->sinhVien.ho);
                swap(current->sinhVien.name, current->next->sinhVien.name);
                swap(current->sinhVien.className, current->next->sinhVien.className);
                swap(current->sinhVien.GPA, current->next->sinhVien.GPA);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
} 
void GPABubbleSortInCircleLinkedList(circleLinkedList*& head) {
    if (!head || head->next == head) return;

    bool swapped;
    circleLinkedList* current;
    circleLinkedList* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != head && current->next != last) {
			if (current->sinhVien.GPA < current->next->sinhVien.GPA) {
                swap(current->sinhVien.id, current->next->sinhVien.id);
                swap(current->sinhVien.ho, current->next->sinhVien.ho);
                swap(current->sinhVien.name, current->next->sinhVien.name);
                swap(current->sinhVien.className, current->next->sinhVien.className);
                swap(current->sinhVien.GPA, current->next->sinhVien.GPA);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
} 
void bubbleSortInCircleLinkedList(circleLinkedList *&head){
		
choice:	
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
		goto choice;
	}
	switch(choice){
		case '1':{
			auto start = chrono::steady_clock::now();
			idBubbleSortInCircleLinkedList(head);
    		auto end = chrono::steady_clock::now();

		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '2':{
			auto start = chrono::steady_clock::now();
			nameBubbleSortInCircleLinkedList(head);
		    auto end = chrono::steady_clock::now();
		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '3':{
			
			auto start = chrono::steady_clock::now();
			GPABubbleSortInCircleLinkedList(head);
		    auto end = chrono::steady_clock::now();
		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
			break;
		}
		case '0':
			break;
	}
}

//sap xep danh sach sinh vien bang quick Sort trong danh sach lien ket
void nameQuickSortInCircleLinkedList(circleLinkedList *&head, bool is_cirular, int idx) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    idx++;
    
    if(is_cirular==true){
    	circleLinkedList* current=head;
    	while(current->next!=head){
    		current=current->next;
		}
		current->next=NULL;
		is_cirular=false;
	}
    circleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    circleLinkedList* l1 = NULL;
    circleLinkedList* l2 = NULL;
    while (head != NULL) {
        circleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        if (temp->sinhVien.name <= pivot->sinhVien.name) {
            addStudentInCircleLinkedList(l1, temp);    
        }
        else {
            addStudentInCircleLinkedList(l2, temp);
        }
    }
    nameQuickSortInCircleLinkedList(l1,is_cirular,idx);
    nameQuickSortInCircleLinkedList(l2,is_cirular,idx);
    idx--;
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        circleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
    }
    pivot->next = l2;
    if(idx==0){
    	
    	circleLinkedList* current_1=head;
		while(current_1->next!=NULL){
			current_1=current_1->next;
		}
		current_1->next=head;
	}
}
void GPAQuickSortInCircleLinkedList(circleLinkedList *&head, bool is_cirular, int idx) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    idx++;
    
    if(is_cirular==true){
    	circleLinkedList* current=head;
    	while(current->next!=head){
    		current=current->next;
		}
		current->next=NULL;
		is_cirular=false;
	}
    circleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    circleLinkedList* l1 = NULL;
    circleLinkedList* l2 = NULL;
    while (head != NULL) {
        circleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        if (temp->sinhVien.GPA <= pivot->sinhVien.GPA) {
            addStudentInCircleLinkedList(l1, temp);    
        }
        else {
            addStudentInCircleLinkedList(l2, temp);
        }
    }
    GPAQuickSortInCircleLinkedList(l1,is_cirular,idx);
    GPAQuickSortInCircleLinkedList(l2,is_cirular,idx);
    idx--;
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        circleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
    }
    pivot->next = l2;
    if(idx==0){
    	
    	circleLinkedList* current_1=head;
		while(current_1->next!=NULL){
			current_1=current_1->next;
		}
		current_1->next=head;
	}
}
void IDQuickSortInCircleLinkedList(circleLinkedList *&head,bool is_cirular,int idx) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    idx++;
    
    if(is_cirular==true){
    	circleLinkedList* current=head;
    	while(current->next!=head){
    		current=current->next;
		}
		current->next=NULL;
		is_cirular=false;
	}
    circleLinkedList* pivot = head;
    head = head->next;
    pivot->next = NULL;
    circleLinkedList* l1 = NULL;
    circleLinkedList* l2 = NULL;
    while (head != NULL) {
        circleLinkedList* temp = head;
        head = head->next;
        temp->next = NULL;
        if (temp->sinhVien.id <= pivot->sinhVien.id) {
            addStudentInCircleLinkedList(l1, temp);    
        }
        else {
            addStudentInCircleLinkedList(l2, temp);
        }
    }
    IDQuickSortInCircleLinkedList(l1,is_cirular,idx);
    IDQuickSortInCircleLinkedList(l2,is_cirular,idx);
    idx--;
    if (l1 == NULL) {
        head = pivot;
    }
    else {
        head = l1;
        circleLinkedList* tail = l1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = pivot;
    }
    pivot->next = l2;
    if(idx==0){
    	
    	circleLinkedList* current_1=head;
		while(current_1->next!=NULL){
			current_1=current_1->next;
		}
		current_1->next=head;
	}
}
void quickSortInCircleLinkedList(circleLinkedList *&head){		
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
			IDQuickSortInCircleLinkedList(head,true,0);
		    auto end = chrono::steady_clock::now();
		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '2':{
			auto start = chrono::steady_clock::now();
			nameQuickSortInCircleLinkedList(head,true,0);
		    auto end = chrono::steady_clock::now();
		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '3':{
			auto start = chrono::steady_clock::now();
			GPAQuickSortInCircleLinkedList(head,true,0);
		    auto end = chrono::steady_clock::now();
		     // hien thi ket qua danh sach sinh vien sau khi sap xep
		     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
		     printStudentListInCircleLinkedList(head);
		     // hien thi thoi gian thuc hien
		     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '0':
			break;
	}
}







