#include "choice.h"

float lowestScore= 10.0;
float highestScore= 0.0;

void highestScoreInArray(vector<SV> danhsach){
    if(danhsach.size()==0){
        cout<<"Danh sach trong!!!!"<<endl;
        return;
    }
    for(int i=0;i<danhsach.size();i++){
    	if(danhsach[i].GPA > highestScore){
    		highestScore= danhsach[i].GPA ;
    	}
	}
    		
    cout<<"Danh sach sinh vien co diem cao nhat : "<<endl;
    cout << left << setw(12) << " ID" 
         << left << setw(20) << " Ho" 
         << left << setw(10) << "Name" 
         << left << setw(20) << "ClassName" 
         << left << setw(5) << "GPA" << endl;
    for(int i=0;i<danhsach.size();i++){
        if(danhsach[i].GPA==highestScore){
           	cout << left << setw(12) << danhsach[i].id 
	         	 << left << setw(20) << danhsach[i].ho 
	          	 << left << setw(10) << danhsach[i].name 
	         	 << left << setw(20) << danhsach[i].className 
	         	 << left << setw(5) << danhsach[i].GPA << endl;
        }
    }
}
void lowestScoreInArray(vector<SV> danhsach){
    if(danhsach.size()==0){
        cout<<"Danh sách trong!!!!"<<endl;
        return;
    }
    for(int i=0;i<danhsach.size();i++){
    	if(danhsach[i].GPA < lowestScore){
    		lowestScore= danhsach[i].GPA ;
    	}
	}
    	
    cout<<"Danh sach sinh vien co diem thap nhat : "<<endl;
     cout << left << setw(12) << " ID" 
         << left << setw(20) << " Ho" 
         << left << setw(10) << "Name" 
         << left << setw(20) << "ClassName" 
         << left << setw(5) << "GPA" << endl;
    for(int i=0;i<danhsach.size();i++){
        if(danhsach[i].GPA==lowestScore){
   		 	cout << left << setw(12) << danhsach[i].id 
         	<< left << setw(20) << danhsach[i].ho 
         	<< left << setw(10) << danhsach[i].name 
         	<< left << setw(20) << danhsach[i].className 
         	<< left << setw(5) << danhsach[i].GPA << endl;
		}
    }

}
void averageScoreInArray(vector<SV> danhsach){
    if(danhsach.size()==0){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }
    float sum=0.0;
    for(int i=0;i<danhsach.size();i++){
        sum+=danhsach[i].GPA;
    }
    float average= sum/danhsach.size();
    cout<<"Diem trung binh cua lop la: "<<fixed<<setprecision(2)<<average<<endl;
}
void choiceInArray(vector<SV> danhsach){
	choice:
		cout<<"CHUC NANG TUY CHON "<<endl<<endl;
		cout<<"1. Liet ke cac sinh vien co diem thap nhat."<<endl;
		cout<<"2. Liet ke cac sinh vien co diem cao nhat."<<endl;
		cout<<"3. Tinh diem trung binh cua lop."<<endl;
		cout<<"0. Thoat."<<endl;
		cout<<"Vui long nhap lua chon: ";
		char choice; cin>>choice;
		if( choice > '3' || choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto choice;
		}
		switch(choice){
			case '1':{
				lowestScoreInArray( danhsach);
				break;
			}
			case '2':{
				highestScoreInArray(danhsach);
				break;
			}
			case '3':{
				 averageScoreInArray(danhsach);
				break;
			}
			case '0':
				break;
		}
}


// danh sach lien ket don
void highestScoreInSingleLinkedList(singleLinkedList *head){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }
    cout<<"Danh sach sinh vien co diem cao nhat: "<<endl;
    singleLinkedList *tmp1=head;
    while(tmp1!= NULL){
    	if(tmp1->sinhVien.GPA>highestScore){
    		highestScore=tmp1->sinhVien.GPA;
		}
		tmp1=tmp1->next;
	}
	singleLinkedList *tmp=head;
    while (tmp!=NULL){
    
        if(tmp->sinhVien.GPA==highestScore){
            cout<<"ID: "<<tmp->sinhVien.id<<"   ";
            cout<<"Ho: "<<tmp->sinhVien.ho<<"   ";
            cout<<"Ten: "<<tmp->sinhVien.name<<"   ";
            cout<<"Lop: "<<tmp->sinhVien.className<<"  ";
            cout<<"Diem GPA: "<<tmp->sinhVien.GPA<<endl;
        }

        tmp=tmp->next;
    }
    
}
void lowestScoreInSingleLinkedList(singleLinkedList *head){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }
	singleLinkedList *tmp1=head;
	while(tmp1!= NULL){
    	if(tmp1->sinhVien.GPA>highestScore){
    		highestScore=tmp1->sinhVien.GPA;
		}
		tmp1=tmp1->next;
	}
    cout<<"Danh sach sinh vien co diem cao nhat: "<<endl;
    singleLinkedList *tmp=head;

    while (tmp!=NULL){

        if(tmp->sinhVien.GPA==lowestScore){
            cout<<"ID: "<<tmp->sinhVien.id<<"   ";
            cout<<"Ho: "<<tmp->sinhVien.ho<<"   ";
            cout<<"Ten: "<<tmp->sinhVien.name<<"   ";
            cout<<"Lop: "<<tmp->sinhVien.className<<"  ";
            cout<<"Diem GPA: "<<tmp->sinhVien.GPA<<endl;
        }
        tmp=tmp->next;
    }
    
}
void averageScoreInSingleLinkedList(singleLinkedList *head){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }

    singleLinkedList *tmp=head;
    float sum=0.0;
    int soLuong=0;
    while(tmp!=NULL){
        sum+=tmp->sinhVien.GPA;
        soLuong++;
        tmp=tmp->next;
    }
    float average= sum/soLuong;
    cout<<"Diem trung binh cua lop la: "<<fixed<<setprecision(2)<<average<<endl;
} 
void choiceInSingleLinkedList(singleLinkedList *head){
	choice:
		cout<<"CHUC NANG TUY CHON "<<endl<<endl;
		cout<<"1. Liet ke cac sinh vien co diem thap nhat."<<endl;
		cout<<"1. Liet ke cac sinh vien co diem cao nhat."<<endl;
		cout<<"3. Tinh diem trung binh cua lop."<<endl;
		cout<<"0. Thoat."<<endl;
		cout<<"Vui long nhap lua chon: ";
		char choice; cin>>choice;
		if( choice > '3' || choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto choice;
		}
		switch(choice){
			case '1':{
				highestScoreInSingleLinkedList(head);
				break;
			}
			case '2':{
				lowestScoreInSingleLinkedList( head);
				break;
			}
			case '3':{
				 averageScoreInSingleLinkedList(head);
				break;
			}
			case '0':
				break;
		}
}


// danh sach lien ket kep
void highestScoreInDoubleleLinkedList(doubleLinkedList *head){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }
    cout<<"Danh sach sinh vien co diem cao nhat: "<<endl;
    doubleLinkedList *tmp1=head;
    while(tmp1!= NULL){
    	if(tmp1->sinhVien.GPA>highestScore){
    		highestScore=tmp1->sinhVien.GPA;
		}
		tmp1=tmp1->next;
	}
	doubleLinkedList *tmp=head;
    while (tmp!=NULL){
    
        if(tmp->sinhVien.GPA==highestScore){
            cout<<"ID: "<<tmp->sinhVien.id<<"   ";
            cout<<"Ho: "<<tmp->sinhVien.ho<<"   ";
            cout<<"Ten: "<<tmp->sinhVien.name<<"   ";
            cout<<"Lop: "<<tmp->sinhVien.className<<"  ";
            cout<<"Diem GPA: "<<tmp->sinhVien.GPA<<endl;
        }

        tmp=tmp->next;
    }
    
}
void lowestScoreDoubleSingleLinkedList(doubleLinkedList *head){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }
	doubleLinkedList *tmp1=head;
	while(tmp1!= NULL){
    	if(tmp1->sinhVien.GPA>highestScore){
    		highestScore=tmp1->sinhVien.GPA;
		}
		tmp1=tmp1->next;
	}
    cout<<"Danh sach sinh vien co diem cao nhat: "<<endl;
    doubleLinkedList *tmp=head;

    while (tmp!=NULL){

        if(tmp->sinhVien.GPA==lowestScore){
            cout<<"ID: "<<tmp->sinhVien.id<<"   ";
            cout<<"Ho: "<<tmp->sinhVien.ho<<"   ";
            cout<<"Ten: "<<tmp->sinhVien.name<<"   ";
            cout<<"Lop: "<<tmp->sinhVien.className<<"  ";
            cout<<"Diem GPA: "<<tmp->sinhVien.GPA<<endl;
        }
        tmp=tmp->next;
    }
    
}
void averageScoreInDoubleSingleLinkedList(doubleLinkedList *head){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }

    doubleLinkedList *tmp=head;
    float sum=0.0;
    int soLuong=0;
    while(tmp!=NULL){
        sum+=tmp->sinhVien.GPA;
        soLuong++;
        tmp=tmp->next;
    }
    float average= sum/soLuong;
    cout<<"Diem trung binh cua lop la: "<<fixed<<setprecision(2)<<average<<endl;
} 
void choiceInDoubleLinkedList(doubleLinkedList *head){
	choice:
		cout<<"CHUC NANG TUY CHON "<<endl<<endl;
		cout<<"1. Liet ke cac sinh vien co diem thap nhat."<<endl;
		cout<<"1. Liet ke cac sinh vien co diem cao nhat."<<endl;
		cout<<"3. Tinh diem trung binh cua lop."<<endl;
		cout<<"0. Thoat."<<endl;
		cout<<"Vui long nhap lua chon: ";
		char choice; cin>>choice;
		if( choice > '3' || choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto choice;
		}
		switch(choice){
			case '1':{
				lowestScoreDoubleSingleLinkedList(head);
				break;
			}
			case '2':{
				highestScoreInDoubleleLinkedList( head);
				break;
			}
			case '3':{
				 averageScoreInDoubleSingleLinkedList(head);
				break;
			}
			case '0':
				break;
		}
}


// danh sach lien ket vong
void highestScoreInCircleLinkedList(circleLinkedList *head){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }
    cout<<"Danh sach sinh vien co diem cao nhat: "<<endl;
    circleLinkedList *tmp1=head;
    do{
    	if(tmp1->sinhVien.GPA>highestScore){
    		highestScore=tmp1->sinhVien.GPA;
		}
		tmp1=tmp1->next;
	}while(tmp1!= head);
	circleLinkedList *tmp=head;
    do{
    	if(tmp->sinhVien.GPA==highestScore){
            cout<<"ID: "<<tmp->sinhVien.id<<"   ";
            cout<<"Ho: "<<tmp->sinhVien.ho<<"   ";
            cout<<"Ten: "<<tmp->sinhVien.name<<"   ";
            cout<<"Lop: "<<tmp->sinhVien.className<<"  ";
            cout<<"Diem GPA: "<<tmp->sinhVien.GPA<<endl;
        }

        tmp=tmp->next;
	}while (tmp!=head);
    
}
void lowestScoreInCircleLinkedList(circleLinkedList *head){
     if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }
    cout<<"Danh sach sinh vien co diem cao nhat: "<<endl;
    circleLinkedList *tmp1=head;
    do{
    	if(tmp1->sinhVien.GPA<lowestScore){
    		highestScore=tmp1->sinhVien.GPA;
		}
		tmp1=tmp1->next;
	}while(tmp1!= head);
	circleLinkedList *tmp=head;
    do{
    	if(tmp->sinhVien.GPA==lowestScore){
            cout<<"ID: "<<tmp->sinhVien.id<<"   ";
            cout<<"Ho: "<<tmp->sinhVien.ho<<"   ";
            cout<<"Ten: "<<tmp->sinhVien.name<<"   ";
            cout<<"Lop: "<<tmp->sinhVien.className<<"  ";
            cout<<"Diem GPA: "<<tmp->sinhVien.GPA<<endl;
        }

        tmp=tmp->next;
	}while (tmp!=head);
    
}
void averageScoreInCircleLinkedList(circleLinkedList *head){
    if(head==NULL){
        cout<<"Danh sach rong!!!!!"<<endl;
        return;
    }

    circleLinkedList *tmp=head;
    float sum=0.0;
    int soLuong=0;
    do{
    	sum+=tmp->sinhVien.GPA;
        soLuong++;
        tmp=tmp->next;
	}while(tmp!=head);
    float average= sum/soLuong;
    cout<<"Diem trung binh cua lop la: "<<fixed<<setprecision(2)<<average<<endl;
} 
void choiceInCircleLinkedList(circleLinkedList *head){
	choice:
		cout<<"CHUC NANG TUY CHON "<<endl<<endl;
		cout<<"1. Liet ke cac sinh vien co diem thap nhat."<<endl;
		cout<<"1. Liet ke cac sinh vien co diem cao nhat."<<endl;
		cout<<"3. Tinh diem trung binh cua lop."<<endl;
		cout<<"0. Thoat."<<endl;
		cout<<"Vui long nhap lua chon: ";
		char choice; cin>>choice;
		if( choice > '3' || choice < '0'){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// loai bo cac ki tu neu nguoi dung nhap du 
			cout<<"Lua chon khong phu hop. Vui long chon lai......"<<endl;
			system("pause");
			goto choice;
		}
		switch(choice){
			case '1':{
				lowestScoreInCircleLinkedList(head);
				break;
			}
			case '2':{
				highestScoreInCircleLinkedList( head);
				break;
			}
			case '3':{
				 averageScoreInCircleLinkedList(head);
				break;
			}
			case '0':
				break;
		}
}



