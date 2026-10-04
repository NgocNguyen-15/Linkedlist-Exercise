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
/* 
Given 2 linked lists, Tell if they are equal or not. 
Two linked lists are equal if they have the same data and the arrangement of data is also the same.
Input:
n1=5 n2=5
List 1 = 1→2→3→4→5
List 2 = 1→2→3→5→5
Output:
0
*/
bool checkEqual(Node* &head1, Node* &head2){
    while(head1 && head2){
        if(head1->value!=head2->value){
            return false;
        }
        head1 = head1->next;
        head2= head2->next;
    }
    return(head1 == NULL && head2 == NULL);
}

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Input:
n = 5
List = 1→2→3→4→5
Output:
5→4→3→2→1
*/
void reverseList(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr!= NULL){
        Node* aft = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aft;
    }
    head = prev;
}

/*
Given head, the head of a linked list, determine if the linked list is a palindrome or not.
Input:
n = 4
List = 1→3→3→1
Output:
1
*/
bool checkPalindrome(Node* &head){
    if(head->next==NULL) return true;
    // tìm node giữa
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // đảo phần sau
    Node* curr = slow;
    Node* prev = NULL;
    while(curr){
        Node* aft = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aft;
    }
    // so sánh 2 nửa
    Node* head2 = prev;
    while(head2){
        if(head->value!=head2->value){
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
}

/*
Given the head of a linked list, rotate the list to the right by k places.
Input:
n = 5 k = 2
List = 1→2→3→4→5
Output:
4→5→1→2→3
*/
void moveRightbyk(Node* &head, int k){
    if (head == NULL || head->next == NULL || k == 0) return;
    Node* temp = head;
    int n = 1;
    while(temp->next!=NULL){
        n++;
        temp=temp->next;
    }
    k = k%n;
    if(k == 0) return;
    //make last node point to head
    temp->next = head;
    temp = head;
    //find(n-k)th node
    for (int i{1}; i < (n-k); i++){
        temp = temp->next;
    }
    Node* newHead = temp->next; //(n-k+1)th node
    //point (n-k)th node to NULL
    temp->next = NULL;
    head = newHead;
}
 
/*
Given 2 sorted linked lists, merge them into 1 singly linked list such that the resulting list is also sorted.
Input:
n1=4 n2 = 3
List 1 = 1→3→5→6
List 2 = 2→4→7
Output:
1→2→3→4→5→6→7
*/
Node* mergeLL(Node* &head1, Node* &head2){
    Node* dummyHeadNode = new Node(-1);
    Node* head3 = dummyHeadNode;
    while(head1 && head2){
        if(head1->value < head2->value){
            head3->next = head1;
            head1 = head1->next;
        }
        else{
            head3->next = head2;
            head2 = head2->next;
        }
        head3 = head3->next;
    }
    if(head1){
        head3->next = head1;
    }
    if(head2){
        head3->next = head2;
    }
    return dummyHeadNode->next;
}

int main(){
    Node*head1 = NULL;
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 4);
    insertAtEnd(head1, 5);
    traverse(head1);

    moveRightbyk(head1, 2);
    traverse(head1);

    Node*head2 = NULL;
    insertAtEnd(head2, 1);
    insertAtEnd(head2, 2);
    insertAtEnd(head2, 3);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 8);
    traverse(head2);

    cout<<checkEqual(head1, head2)<<endl; 
    
    Node*head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    reverseList(head);
    traverse(head);

    cout << checkPalindrome(head) <<endl;

     
    return 0;
}