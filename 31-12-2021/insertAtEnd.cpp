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

Node* insertAtEnd(Node *head, int key){
    if(head == NULL){
        return new Node(key);
    }
    else{
        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new Node(key);
    }
    return head;
}

Node *deleteBegin(Node *head){
    if(head == NULL){
        return NULL;
    }
    Node *temp = head->next;
    delete head;
    return temp;
}

Node *deleteLast(Node *head){
    if(head == NULL){
        return NULL;
    }
    else if(head->next == NULL){
        delete head;
        return NULL;
    }
    else{
        Node *curr = head;
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        Node *p = curr->next;
        curr->next = NULL;
        delete p;
        return head;
    }
}

void printList(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
    cout<<"\n";
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    // head = deleteLast(head);
    printList(head);
    return 0;
}