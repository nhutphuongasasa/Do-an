#include "delete.h"
using namespace customType;

 
bool deleteStudentInArray(vector<SV> &danhsach, string idDelete){
    if(danhsach.size()==0){
        cout<<"Danh sach rong!!!"<<endl;
        cout<<"Khong the xoa sinh vien vien!!!!!!!!"<<endl;
        return false;
    }
    idDelete=toUpperCase(idDelete);
    bool found=0;
    for(int i=0;i<danhsach.size();i++){
         string idCurrent= toUpperCase(danhsach[i].id);
        if(idCurrent.find(idDelete) != string::npos){
        	found=1;
            danhsach.erase(danhsach.begin()+i);
			break; 
        }
    }
    if(found==1){
        cout<<"Da xoa thanh cong sinh vien co id: "<<idDelete<<endl;
        return true;// tru 1 sinh vien trong danh sach
    }else{
        cout<<" Khong tim thay sinh vien co id: "<<idDelete<<endl;
        cout<<" Xoa that bai!!!!!!!!"<<endl;
        return false;
    }
}
bool deleteStudentInSingleLinkedList(singleLinkedList *&head, string idDelete){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        cout<<"Xoa that bai!!!!!"<<endl;
        return false;
    }
    bool found=0;
    idDelete=toUpperCase(idDelete);
    head->sinhVien.id=toUpperCase(head->sinhVien.id);
    singleLinkedList* tmp=head;
    if(tmp->sinhVien.id==idDelete){// th1: sinh vien can xoa o dau danh sach  -> xoa dau danh sach
        head=head->next;
        delete tmp;
        cout<<"Xoa thanh cong sinh vien co id: "<< idDelete<<endl;
        return true;
    }
    singleLinkedList* pre=tmp;// luu lai node truoc nut dang duyet
    while(tmp!=NULL){
        tmp->sinhVien.id=toUpperCase(tmp->sinhVien.id);
        if(tmp->sinhVien.id==idDelete){
            found=1;
            pre->next=tmp->next;
            delete tmp;
            cout<<"Da xoa thanh cong sinh vien co id: "<<idDelete;
            return true;
        }
        pre=tmp;
        tmp=tmp->next;
    }
    if(!found){
        cout<<"Khong tim thay sinh vien co id: "<<idDelete<<endl;
        cout<<"Xoa that bai!!!!!!!!!"<<endl;
        return false;
    }
}
bool deleteStudentInDoubleLinkedList(doubleLinkedList*& head, string idDelete) {
    if (head == nullptr) {
        cout << "Danh sach rong!!!!!" << endl;
        cout << "Xoa that bai!!!!!" << endl;
        return false;
    }
    bool found = false;
    idDelete = toUpperCase(idDelete);

    doubleLinkedList* tmp = head;

    // Tr�?ng h?p n�t c?n x�a l� n�t �?u ti�n
    if (toUpperCase(tmp->sinhVien.id) == idDelete) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete tmp;
        cout << "Xoa thanh cong sinh vien co id: " << idDelete << endl;
        return true;
    }

    while (tmp != nullptr) {
        if (toUpperCase(tmp->sinhVien.id) == idDelete) {
            found = true;
            // Li�n k?t n�t tr�?c v?i n�t sau
            if (tmp->prev != nullptr) {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next != nullptr) {
                tmp->next->prev = tmp->prev;
            }
            delete tmp;
            cout << "Da xoa thanh cong sinh vien co id: " << idDelete << endl;
            return true;
        }
        tmp = tmp->next;
    }

    if (!found) {
        cout << "Khong tim thay sinh vien co id: " << idDelete << endl;
        cout << "Xoa that bai!!!!!!!!!" << endl;
        return false;
    }
}
bool deleteStudentInCircleLinkedList(circleLinkedList*& head, string idDelete) {
    if (head == nullptr) {
        cout << "Danh sach rong!!!!!" << endl;
        cout << "Xoa that bai!!!!!" << endl;
        return false;
    }

    bool found = false;
    idDelete = toUpperCase(idDelete);

    circleLinkedList* tmp = head;
    circleLinkedList* prev = nullptr;

    // X? l? tr�?ng h?p danh s�ch ch? c� m?t n�t
    tmp->sinhVien.id=toUpperCase(tmp->sinhVien.id);
    if ( tmp->sinhVien.id == idDelete && tmp->next == head) {
        delete tmp;
        head = nullptr;
        cout << "Xoa thanh cong sinh vien co id: " << idDelete << endl;
        return true;
    }

    // Duy?t qua danh s�ch �? t?m n�t c� id c?n x�a
    do {
    	tmp->sinhVien.id=toUpperCase(tmp->sinhVien.id);
        if (tmp->sinhVien.id  == idDelete) {
            found = true;
            // X? l? tr�?ng h?p n�t c?n x�a l� n�t �?u ti�n
            if (tmp == head) {
                // T?m n�t cu?i c�ng trong danh s�ch
                circleLinkedList* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                // C?p nh?t l?i head v� n�t cu?i c�ng
                head = head->next;
                last->next = head;
                delete tmp;
            } else {
                prev->next = tmp->next;
                delete tmp;
            }
            cout << "Xoa thanh cong sinh vien co id: " << idDelete << endl;
            return true;
        }
        prev = tmp;
        tmp = tmp->next;
    } while (tmp != head);

    if (!found) {
        cout << "Khong tim thay sinh vien co id: " << idDelete << endl;
        cout << "Xoa that bai!!!!!!!!!" << endl;
        return false;
    }
    return false;
}

