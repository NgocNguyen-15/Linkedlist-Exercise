#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;
    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};
void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int val){
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void traverse(Node* head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->value<< " ";
        temp = temp->next;
    } cout <<"NULL"<<endl;
}
/*Given the head of a linked list, delete every alternate element from the list starting from the second element.
Input:
n = 6
List = 1→2→3→4→5→6
Output:
1→3→5
*/
void deleteAlternateNode(Node* &head){
    Node* temp = head;
    int index = 1;
    while(temp != NULL && temp->next != NULL){
        Node* deleteNode = temp->next;
        temp->next= temp->next->next;
        temp = temp->next;
        delete deleteNode;
    }
}
/*Find the middle element of the given linked list.
Input:
n = 5
List = 1→2→3→4→5
Output:
3
*/
int middleElement(Node* &head){
    /* Cách 1:
    Node*temp = head;
    Node* prev = head;
    int count = 0;
    int i = 1;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(count % 2 == 0){
        return -1;
    }
    else{
        while(i < count / 2 + 1){
            prev=prev->next;
            i++;
        }
        return prev->value;
    }*/
   //Cách 2:
   Node* slow = head;
   Node* fast = head;
   while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
   }
   return slow->value;

}
int main(){
    Node*head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    traverse(head);
    int mid = middleElement(head);
    cout<<mid;
    return 0;
}