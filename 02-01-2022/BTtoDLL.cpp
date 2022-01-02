#include<iostream>
using namespace std;
struct Node *p = NULL;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

Node* BTtoDll(Node* root){
    if(root == NULL) return root;
    //left subtree
    Node *head = BTtoDll(root->left);
    ////
    if(p == NULL){
        head = root;
    }
    else{
        root->left = p;
        p->right = root;
    }
    p = root;
    ////
    //right subtree
    BTtoDll(root->right);
    return head;
}

void PrintDLL(Node* head){
    while (head!=NULL){
        cout<<head->key<<" ";
        head = head->right;
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(50);
    root->left->right = new Node(60);
    root->right->left = new Node(100);
    root->right->right = new Node(70);
    root->right->right->left = new Node(80);
    root->right->right->left->right = new Node(90);
    Node* head = BTtoDll(root);
    PrintDLL(head);
    return 0;
}