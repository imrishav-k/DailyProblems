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
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void printListRecursive(Node *head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printListRecursive(head);
    return 0;
}