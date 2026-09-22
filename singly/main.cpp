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

int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next = node2;
    Node* head = node1;
    traverse(head);
    insertAtHead(head, 3);
    traverse(head);
}