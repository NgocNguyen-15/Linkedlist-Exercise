#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;
    Node(int value){
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};

void forwardTraversal(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->value<<"<-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void backwardTraversal(Node* head){
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        cout<<temp->value<<"<-->";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

void insertAtStart(Node* &head, int v){
    Node* newNode = new Node(v);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtEnd(Node* &head, int v){
    Node* newNode = new Node(v);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next){
        temp= temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next = NULL;
}
void insertAtMiddle(Node* &head, int v, int k){
    if(k<=1|| head==NULL){
        insertAtStart(head, v);
        return;
    }
    Node* newNode = new Node(v);
    Node* back = head;
    int count = 1;
    while(count < k-1 && back->next != NULL){
        back = back->next;
        count++;
    }
    newNode->next = back->next;
    newNode->prev = back;
    if (back->next != NULL) {
        back->next->prev = newNode;
    }
    back->next = newNode;
}


void deleteAtHead(Node* &head){
    if(head->next == NULL){
        delete head;
        return;
    }
    Node* temp = head;
    head= head->next;
    head->prev = NULL;
    delete temp;
}
void deleteAtEnd(Node* &head){
    Node* temp = head;
    while(temp->next){
        temp=temp->next;
    }
    Node* newLastNode = temp->prev;
    newLastNode->next = NULL;
    delete temp;
}
void deleteAtMiddle(Node* &head, int k){
    if (k==1){
        deleteAtHead(head);
    }
    Node* temp = head;
    for (int i=1;i<k-1;i++){
        temp=temp->next;
    }
    Node* delNode = temp->next; 
    temp->next = delNode->next;
    if (delNode->next) {
        delNode->next->prev = temp;
    }
    delete delNode;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->next = n2;
    n2->prev = n1;
    Node* head = n1;
    forwardTraversal(head);
    backwardTraversal(head);
    insertAtStart(head, 9);
    forwardTraversal(head);
    return 0;
}