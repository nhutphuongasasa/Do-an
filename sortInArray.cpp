#include "sortInArray.h"

// sap xep danh sach sinh vien bang  insertionSort trong mang
void idInsertionSortInArray(vector<SV> &danhsach){
	auto start = chrono::steady_clock::now();
    for(int i=1;i<danhsach.size();i++){
        if(danhsach[i].id<danhsach[i-1].id){
        SV tam=danhsach[i];
        int j = i;
            while (j > 0 && danhsach[j - 1].id > tam.id) {
                danhsach[j] = danhsach[j - 1];
                j--;
            }
            danhsach[j] = tam; 
        }
    }
   
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void nameInsertionSortInArray(vector<SV> &danhsach){
    auto start = chrono::steady_clock::now();
    for(int i=1;i<danhsach.size();i++){
        if(danhsach[i].name<danhsach[i-1].name){
        SV tam=danhsach[i];
        int j = i;
            while (j > 0 && danhsach[j - 1].name > tam.name) {
                danhsach[j] = danhsach[j - 1];
                j--;
            }
            danhsach[j] = tam;
            
        }
    }
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void GPAInsertionSortInArray(vector<SV> &danhsach){
    auto start = chrono::steady_clock::now();
    for(int i=1;i<danhsach.size();i++){
        if(danhsach[i].GPA<danhsach[i-1].GPA){
        SV tam=danhsach[i];
        int j = i;
            while (j > 0 && danhsach[j - 1].GPA > tam.GPA) {
                danhsach[j] = danhsach[j - 1];
                j--;
            }
            danhsach[j] = tam;
            
        }
    }
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void insertionSortInArray(vector<SV> &danhsach){
	
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
			idInsertionSortInArray(danhsach);
			break;
		}
		case '2':{
			nameInsertionSortInArray(danhsach);
			break;
		}
		case '3':{
			GPAInsertionSortInArray(danhsach);
			break;
		}
		case '0':
			break;
	}
}

 
// sap xep danh sach sinh vien bang bubble sort trong mảng
void idBubbleSortInArray(vector<SV> &danhsach){
    auto start = chrono::steady_clock::now();
    for(int i=0;i<danhsach.size()-1;i++){
        for(int j=i+1;j<danhsach.size();j++){
            if(danhsach[j].id<danhsach[i].id){
                SV tam= danhsach[i];
                danhsach[i]=danhsach[j];
                danhsach[j]=tam;
            }
        }
    }
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void nameBubbleSortInArray(vector<SV> &danhsach){
    auto start = chrono::steady_clock::now();
    for(int i=0;i<danhsach.size()-1;i++){
        for(int j=i+1;j<danhsach.size();j++){
            if(danhsach[j].name<danhsach[i].name){
                SV tam= danhsach[i];
                danhsach[i]=danhsach[j];
                danhsach[j]=tam;
            }
        }
    }
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void GPABubbleSortInArray(vector<SV> &danhsach){
    auto start = chrono::steady_clock::now();
    for(int i=0;i<danhsach.size()-1;i++){
        for(int j=i+1;j<danhsach.size();j++){
            if(danhsach[j].GPA<danhsach[i].GPA){
                SV tam= danhsach[i];
                danhsach[i]=danhsach[j];
                danhsach[j]=tam;
            }
        }
    }
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void BubbleSortInArray(vector<SV> &danhsach){
		
choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG BUBBLESORT "<<endl<<endl;
	cout<< "Ban muon sap xep theo tieu chi nao?"<<endl;
	cout<< "1. Ma sinh vien."<<endl;
	cout<< "2. Ten sinh vien."<<endl;
	cout<< "3. Diem GPA."<<endl;
	cout<< "0. Thoat."<<endl;
	cout<< "Nhap lua chon cua ban: ";
	char choice;
	cin>>choice;
	if( choice > '3' || choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
		goto choice;
	}
	switch(choice){
		case '1':{
			idBubbleSortInArray(danhsach);
			break;
		}
		case '2':{
			nameBubbleSortInArray(danhsach);
			break;
		}
		case '3':{
			GPABubbleSortInArray(danhsach);
			break;
		}
		case '0':
			break;
	}
}



// sap xep danh sach sinh vien bang selection sort trong mang
void idSelectionSortInArray(vector<SV> &danhsach){
    auto start = chrono::steady_clock::now();
    for(int i=0;i<danhsach.size()-1;i++){
        int pos=i;
        for(int j=i+1;j<danhsach.size();j++){
            if(danhsach[j].id<danhsach[pos].id){
                pos=j;
            }
        }
        SV tam= danhsach[i];
        danhsach[i]=danhsach[pos];
        danhsach[pos]=tam;

    }
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void nameSelectionSortInArray(vector<SV> &danhsach){
    auto start = chrono::steady_clock::now();
    for(int i=0;i<danhsach.size()-1;i++){
        int pos=i;
        for(int j=i+1;j<danhsach.size();j++){
            if(danhsach[j].name<danhsach[pos].name){
                pos=j;
            }
        }
        SV tam= danhsach[i];
        danhsach[i]=danhsach[pos];
        danhsach[pos]=tam;

    }
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void GPASelectionSortInArray(vector<SV> &danhsach){
    auto start = chrono::steady_clock::now();
    for(int i=0;i<danhsach.size()-1;i++){
        int pos=i;
        for(int j=i+1;j<danhsach.size();j++){
            if(danhsach[j].GPA<danhsach[pos].GPA){
                pos=j;
            }
        }
        SV tam= danhsach[i];
        danhsach[i]=danhsach[pos];
        danhsach[pos]=tam;

    }
    auto end = chrono::steady_clock::now();
    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
    printStudentListInArray(danhsach);
    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

}
void selectionSortInArray(vector<SV> &danhsach){
			
choice:	
	system("cls");
	cout<< "SAP XEP DANH SACH SINH VIEN BANG SELECTION SORT "<<endl<<endl;
	cout<< "Ban muon sap xep theo tieu chi nao?"<<endl;
	cout<< "1. Ma sinh vien."<<endl;
	cout<< "2. Ten sinh vien."<<endl;
	cout<< "3. Diem GPA."<<endl;
	cout<< "0. Thoat."<<endl;
	cout<< "Nhap lua chon cua ban: ";
	char choice;
	cin>>choice;
		if( choice > '3' || choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
		goto choice;
	}
	switch(choice){
		case '1':{
			idSelectionSortInArray(danhsach);
			break;
		}
		case '2':{
			nameSelectionSortInArray(danhsach);
			break;
		}
		case '3':{
			GPASelectionSortInArray(danhsach);
			break;
		}
		case '0':
			break;
	}
}


// sap xep danh sach sinh vien bang merge sort trong mang
// ham so sanh du tren tieu chi sap xep
bool soSanhArr(const SV &a, const SV &b, int tieuChi){
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
 // ham gop hai mang con da sap xep
void gop(vector<SV> &danhsach, int l, int m, int r, int tieuChi){
     int n1 = m - l + 1;
     int n2 = r - m;
     vector<SV> L(n1), R(n2);

     for (int i = 0; i < n1; i++)
         L[i] = danhsach[l + i];
     for (int j = 0; j < n2; j++)
         R[j] = danhsach[m + 1 + j];

     int i = 0, j = 0, k = l;
     while (i < n1 && j < n2)
     {
         if (soSanhArr(L[i], R[j], tieuChi))
             danhsach[k++] = L[i++];
         else
             danhsach[k++] = R[j++];
     }

     while (i < n1)
         danhsach[k++] = L[i++];
     while (j < n2)
         danhsach[k++] = R[j++];
 }
 // ham sap xep mergesort
void mergeSort(vector<SV> &danhsach, int l, int r, int tieuChi){
     if (l < r) {
         int m = l + (r - l) / 2;
         mergeSort(danhsach, l, m, tieuChi);
         mergeSort(danhsach, m + 1, r, tieuChi);
         gop(danhsach, l, m, r, tieuChi);
     }
 }
void mergeSortInArray(vector<SV> &danhsach){
     int tieuChi;
     cout << "Chon tieu chi sap xep:" << endl;
     cout << "1. Ma sinh vien" << endl;
     cout << "2. Ten" << endl;
     cout << "3. Diem" << endl;
     cin >> tieuChi;

     // sap xep danh sach sinh vien theo tieu chi da chon
     auto start = chrono::steady_clock::now();
     mergeSort(danhsach, 0, danhsach.size() - 1, tieuChi);
     auto end = chrono::steady_clock::now();

     // hien thi ket qua danh sach sinh vien sau khi sap xep
     cout << "Danh sach sinh vien sau khi sap xep:" << endl;
     printStudentListInArray(danhsach);
     // hien thi thoi gian thuc hien
     cout << "Thoi gian thuc hien: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}




// sap xep danh sach sinh vien bang heap sort trong mang

void heapifyIDInArray(vector<SV> &danhsach, int n,int i){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    if(left < n && danhsach[left].id > danhsach[largest].id){
        largest = left;
    }
    if(right < n && danhsach[right].id > danhsach[largest].id){
        largest = right;
    }
    if(largest != i){
        swap(danhsach[i], danhsach[largest]);
        heapifyIDInArray(danhsach, n, largest);
    }
} 
void heapifyNameInArray(vector<SV> &danhsach, int n, int i){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    if(left < n && danhsach[left].name > danhsach[largest].name){
        largest = left;
    }
    if(right < n && danhsach[right].name > danhsach[largest].name){
        largest = right;
    }
    if(largest != i){
        swap(danhsach[i], danhsach[largest]);
        heapifyNameInArray(danhsach, n, largest);
    }
} 
void heapifyGPAInArray(vector<SV> &danhsach, int n, int i){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    if(left < n && danhsach[left].GPA > danhsach[largest].GPA){
        largest = left;
    }
    if(right < n && danhsach[right].GPA > danhsach[largest].GPA){
        largest = right;
    }
    if(largest != i){
        swap(danhsach[i], danhsach[largest]);
        heapifyGPAInArray(danhsach, n, largest);
    }
} 

void IdHeapSortInArray(vector<SV> &danhsach){
	int n=danhsach.size();
    for(int i = n/2 - 1; i >= 0; i--){
         heapifyIDInArray(danhsach, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(danhsach[i], danhsach[0]);
        heapifyIDInArray(danhsach, i, 0);
    }
   
}
void nameHeapSortInArray(vector<SV> &danhsach){
    for(int i = danhsach.size()/2 - 1; i >= 0; i--){
         heapifyNameInArray(danhsach, danhsach.size(), i);
    }

    for(int i = danhsach.size() - 1; i >= 0; i--){
        swap(danhsach[i], danhsach[0]);
        heapifyNameInArray(danhsach, i, 0);
    }
    
}
void GPAHeapSortInArray(vector<SV> &danhsach){
    int n=danhsach.size();
	for(int i = n/2 - 1; i >= 0; i--){
         heapifyGPAInArray(danhsach, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(danhsach[i], danhsach[0]);
        heapifyGPAInArray(danhsach, i, 0);
    }
   
}
void heapSortInArray(vector<SV> &danhsach){
heapSort_choice: 
    cout << "SAP XEP DANH SACH SINH VIEN BANG HEAPSORT\n";
    cout << "1. Ma sinh vien\n";
    cout << "2. Ten sinh vien\n";
    cout << "3. Diem GPA\n";
    cout << "0. Thoat\n";
    char choice; 
    cin >> choice;
    if( choice > '4' ||  choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
        goto heapSort_choice;
	}

    switch (choice){
        case '1': {
			auto start = chrono::steady_clock::now();
            IdHeapSortInArray(danhsach); 
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInArray(danhsach);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

            break;
        }
        case '2':{
			auto start = chrono::steady_clock::now();
            nameHeapSortInArray(danhsach);  
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInArray(danhsach);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
       
            break;
        }
        case '3':{
            auto start = chrono::steady_clock::now();
            GPAHeapSortInArray(danhsach);
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInArray(danhsach);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
       
            cout << endl;
            break;
        }
        case '0':{
            break;
        }
        default:{
            cout << "Lua chon cua ban khong hop le!\n";
            system("pause");
            goto heapSort_choice;
            break;
        }    
	}
}


// sap xep danh sach sinh vien bang quick sort trong mang
void swap(SV &a,SV &b){
	SV temp=a;
	a=b;
	b=temp;
}
int partition_gpa(vector<SV> &danhsach, int l, int r){
	double pivot=danhsach[r].GPA;
	int i=l-1;
	for(int j=l;j<r;j++){
		if(danhsach[j].GPA<=pivot){
			++i;
			swap(danhsach[j],danhsach[i]);
		}
	}
	i++;
	swap(danhsach[i],danhsach[r]);
	return i;
}
int partition_msv(vector<SV> &danhsach, int l,int r){
	string pivot=danhsach[r].id;
	int i=l-1;
	for(int j=l;j<r;j++){
		if(danhsach[j].id<=pivot){
			++i;
			swap(danhsach[j],danhsach[i]);
		}
	}
	i++;
	swap(danhsach[i],danhsach[r]);
	return i;
}
int partition_name(vector<SV> &danhsach,int l,int r){
	string pivot=danhsach[r].name;
	int i=l-1;
	for(int j=l;j<=r;j++){
		if(danhsach[j].name<pivot){
			++i;
			swap(danhsach[j],danhsach[i]);
		}
	}
	i++;
	swap(danhsach[i],danhsach[r]);
	return i;
}

void GPAQuickSortInArray(vector<SV> &danhsach, int l, int r){
	if(l>=r) return;
	int temp=partition_gpa(danhsach,l,r);
	GPAQuickSortInArray(danhsach,l,temp-1);
	GPAQuickSortInArray(danhsach,temp+1,r);
	
}
void IDQuickSortInArray(vector<SV> &danhsach,int l,int r){
	if(l>=r) return;
	int temp=partition_msv(danhsach,l,r);
	IDQuickSortInArray(danhsach,l,temp-1);
	IDQuickSortInArray(danhsach,temp+1,r);

}
void nameQuickSortInArray(vector<SV> &danhsach,int l,int r){
	if(l>=r) return;
	int temp=partition_name(danhsach,l,r);
	nameQuickSortInArray(danhsach,l,temp-1);
	nameQuickSortInArray(danhsach,temp+1,r);

}
void QuickSortInArray(vector<SV> &danhsach){
		
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
	if( choice > '3' || choice < '0'){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
		cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
		system("pause");
		goto choice;
	}
	switch(choice){
		case '1':{
			auto start = chrono::steady_clock::now();
			IDQuickSortInArray(danhsach,0,danhsach.size()-1);
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInArray(danhsach);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '2':{
			auto start = chrono::steady_clock::now();
			nameQuickSortInArray(danhsach,0,danhsach.size()-1);
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInArray(danhsach);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

		}
		case '3':{
			auto start = chrono::steady_clock::now();
			GPAQuickSortInArray(danhsach,0,danhsach.size()-1);
		    auto end = chrono::steady_clock::now();
		    cout<<"danh sach sinh vien sau khi sap xep :"<<endl;
		    printStudentListInArray(danhsach);
		    cout<<"Thoi gian thuc hien cua thuat toan la:"<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

			break;
		}
		case '0':
			break;
	}
}

















