#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;

    Node(int v){
        value = v;
        next = NULL;
    /*Cách viết 2: 
    Node(int value){
        this->value = value;
        this->next = NULL;
    }*/
    /*Cách viết 3:
    Node (int value) : value(value), next(NULL) {}*/
    }
};

void traverse(Node* head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->value<< " ";
        temp = temp->next;
    } cout <<"NULL"<<endl;
}

void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int val){
    if(head == NULL){
        insertAtHead(head, val);
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMiddle(Node* &head, int val, int position){

    if(position == 1){
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* prev = head;
    int count = 1;
    while(count < (position - 1)){
        prev = prev->next;
        count++;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void deleteAtStart(Node* &head){
    if(head == NULL){
        return;
    }
    Node*temp = head;
    head = head->next;
    free(temp);
}

void deleteAtLast(Node* &head){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtStart(head);
        return;
    }
    Node* secondLastNode = head;
    while(secondLastNode->next->next!=NULL){
        secondLastNode = secondLastNode->next;
    }

    Node* lastNode = secondLastNode->next;
    secondLastNode->next =NULL;
    free(lastNode);
}

void deleteAtMiddle(Node* &head, int position){
    if(head == NULL){
        return;
    }
    if(position ==1){
        deleteAtStart(head);
        return;
    } 
    Node *prev = head;
    int count = 1;
    while(count<(position-1)){
        prev=prev->next;
        count++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    free(curr);
}

int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next = node2;
    Node* head = node1;
    traverse(head);
    insertAtHead(head, 3);
    traverse(head);
    insertAtEnd(head, 4);
    traverse(head);
    insertAtMiddle(head, 5, 3);
    traverse(head);
    deleteAtStart(head);
    traverse(head);
    deleteAtLast(head);
    traverse(head);
    deleteAtMiddle(head, 2);
    traverse(head);
    return 0;
}