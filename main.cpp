#include <iostream>
#include <cstdlib>
using namespace std;
int selection, vnum, t, valuet,removenum;
class Node{
public:
    Node* next;
    int data;
    void print();
};
class LinkedList{
public:
    int length;
    Node* head;
    void insert(int data);
    void remove(int data);
    void print();
    void isEmpty();
    void isFull();
    Node* removeDuplicates();
};

void LinkedList::insert(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}
void LinkedList::remove(int data){
    if(this->length == 0){
        cout << "The list is empty" << endl;
    }else if(this->head->data == data){
        Node* current = head;
        this->head = this->head->next;
        delete current;
        this->length--;
    }else{
        Node* previous = this->head;
        Node* current = head->next;
        while(current != NULL) {
            if(current->data == data) {
                break;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
        if(current == NULL) {
            cout << "Can't remove value: no match found.\n";
        } else {
            previous->next = current->next;
            delete current;
            this->length--;
        }
    }
}
void LinkedList::print(){
    if(this->length == 0){
        cout << "The list is empty" << endl;
    }else{
        Node* head = this->head;
        int i = 1;
        cout << "===============================" << endl;
        while(head){
            cout << i << ": " << head->data << endl;
            head = head->next;
            i++;
        }
        cout << "===============================" << endl;
    }
}
void LinkedList::isEmpty(){
	if(this->length == 0){
        cout << "The list is empty" << endl;
}
else 
LinkedList::isFull();
}
void LinkedList::isFull(){
	if(this->length != 0){
        cout << "The list is full" << endl;
    }
    else
    LinkedList::isEmpty();
}
Node* LinkedList::removeDuplicates(){
	Node* temp = head;
	Node* dup;
	while (temp && (dup = temp->next)){
    if (temp->data == dup->data) {
        temp->next = dup->next;
        delete dup;
    } else {
        temp = temp->next;
    }
}
return head;
}
int main(){
    LinkedList* list = new LinkedList();
    while(1){
	cout<<"*******************************************************"<<endl;
    cout<< "1. Insert "<<endl;
    cout<< "2. Print List"<<endl;
    cout<< "3. Remove"<<endl;
    cout<< "4. Remove Duplicates"<<endl;
    cout<< "5. Is list empty or full ?"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"Which transaction do you want to perform?"<<endl;
    cin>>selection;
    cout<<"*******************************************************"<<endl;
   if(selection==1){
   		cout<<"How many value do you want to insert?"<<endl;;
   		cin>>vnum;
   			for(t=0;t<vnum;t++){
   				cout<<t+1<<":";
   					cin>>valuet;
   				list->insert(valuet);
   				}
   		list->print();
}
	else if (selection==2){
		cout<<"List:"<<endl;
		list->print();
	}
	else if (selection==3){
		list->print();
		cout<<"Which value do you want to remove?"<<endl;
		cin>>removenum;
		list->remove(removenum);
		cout<<"New List:"<<endl;
		list->print();
	}
	else if (selection==4){
		list->removeDuplicates();
		cout<<"New List"<<endl;
		list->print();
	}
	else if (selection==5){
		list->isEmpty();
	}
}
    return 0;
}
