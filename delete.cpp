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

    // Trý?ng h?p nút c?n xóa là nút ð?u tiên
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
            // Liên k?t nút trý?c v?i nút sau
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

    // X? l? trý?ng h?p danh sách ch? có m?t nút
    tmp->sinhVien.id=toUpperCase(tmp->sinhVien.id);
    if ( tmp->sinhVien.id == idDelete && tmp->next == head) {
        delete tmp;
        head = nullptr;
        cout << "Xoa thanh cong sinh vien co id: " << idDelete << endl;
        return true;
    }

    // Duy?t qua danh sách ð? t?m nút có id c?n xóa
    do {
    	tmp->sinhVien.id=toUpperCase(tmp->sinhVien.id);
        if (tmp->sinhVien.id  == idDelete) {
            found = true;
            // X? l? trý?ng h?p nút c?n xóa là nút ð?u tiên
            if (tmp == head) {
                // T?m nút cu?i cùng trong danh sách
                circleLinkedList* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                // C?p nh?t l?i head và nút cu?i cùng
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

