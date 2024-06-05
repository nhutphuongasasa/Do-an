#include "customType.h"
#include <algorithm>

namespace customType {
    string toUpperCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    }
} 
singleLinkedList *makeNodeDon(SV a){
    singleLinkedList *tmp = new singleLinkedList();
    tmp->sinhVien = a;
    tmp->next = NULL;
    return tmp;
}
doubleLinkedList *makeNodeDoi(SV a){
    doubleLinkedList *tmp = new doubleLinkedList();
    tmp->sinhVien = a;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}
circleLinkedList *makeNodeVong(SV a){
    circleLinkedList *tmp = new circleLinkedList();
    tmp->sinhVien = a;
    tmp->next = NULL;
    return tmp;
}
//them node vao cuoi
void pushBackDon(singleLinkedList  *&head, SV x){
    singleLinkedList *newNode = makeNodeDon(x);        
    if(head == NULL){
        head = newNode;
        return;
    }
    singleLinkedList *tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void pushBackDoi(doubleLinkedList *&head, SV x){
    doubleLinkedList *newNode = makeNodeDoi(x);        
    if(head == NULL){
        head = newNode;
        return;
    }
    doubleLinkedList *tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}
void pushBackVong(circleLinkedList *&head, SV newnode){
	if (head == NULL) {
		circleLinkedList* tmp=  makeNodeVong(newnode);
        head = tmp;
        tmp->next=head;
        return;
	}else {
        circleLinkedList* current = head;
        circleLinkedList* tmp=  makeNodeVong(newnode);
        while (current->next != head) {
            current = current->next;
        }
        current->next = tmp;
        tmp->next=head;
    }
}






