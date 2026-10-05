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
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
Input:
n1 = 4 n2 = 2
1→2→3→4
    |
  5→6
Output:
3
*/
int getLength(Node* head){
    int n = 0;
    Node* temp = head;
    while(temp){
        n++;
        temp = temp->next;
    }
    return n;
}

Node* moveKSteps(Node* head, int k){
    Node* ptr = head;
    while(k--){
        ptr = ptr->next;
    }
    return ptr;
}

Node* getIntersectionNode(Node* head1, Node* head2){
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    if(l1>l2){
        int k = l1 - l2;
        ptr1 = moveKSteps(head1, k);
    }
    else{
        int k = l2 - l1;
        ptr2 = moveKSteps(head2, k);
    }
    while(ptr1 && ptr2){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}


/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
Input:
n = 5
k = 2
List = 1→2→3→4→5
Output:
2→1→4→3→5
*/
Node* reverseKLL(Node* &head, int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* aft = head->next;
    int count = 0;
    while(curr&&count<k){
        aft = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aft;
        count++;
    }
    if(curr){
        Node* newHead = reverseKLL(curr, k);
        head->next = newHead;
    }
    return prev;

}

/*
Given the head of a linked list, detect if the linked list has cycle in it. If it does, break the cycle.
Input:
1→2→3→4→5
    |___|
Output:
Yes
1→2→3→4→5
*/
bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    // Nếu fast chạy đến cuối -> Danh sách KHÔNG có vòng lặp -> Dừng
    if (fast == NULL || fast->next == NULL) return;
    cout<<fast->value<<endl;
    fast = head;
    // Trường hợp đặc biệt: Vòng lặp bắt đầu ngay tại Node head
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }
    while(slow->next!=fast->next) {
        slow=slow->next; 
        fast=fast->next;
    }
    slow->next = NULL;
}

int main(){
    Node* head = NULL;
    insertAtEnd (head, 1); 
    insertAtEnd (head, 2); 
    insertAtEnd (head, 3); 
    insertAtEnd (head, 4);
    insertAtEnd (head, 5); 
    head->next->next->next->next->next = head->next->next;
    cout<< detectCycle(head)<<endl;
    if(detectCycle(head)){
        removeCycle(head);
        traverse(head);
    }
    else{
        cout<<"No cycle"<<endl;
    }


    return 0;
}