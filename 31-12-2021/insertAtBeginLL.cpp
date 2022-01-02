#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node *head){
    while (head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }    
}

Node* insertAtBegin(Node *head, int key){
    Node *temp = new Node(key);
    temp->next = head;
    return temp;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
    cout<<"\n";
    head = insertAtBegin(head, 0);
    printList(head);
    return 0;
}