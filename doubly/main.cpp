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

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->next = n2;
    n2->prev = n1;
    Node* head = n1;
    forwardTraversal(head);
    backwardTraversal(head);
    return 0;
}