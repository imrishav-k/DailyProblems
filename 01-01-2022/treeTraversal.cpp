#include<iostream>
#include<climits>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

void Inorder(Node *root){
    if(root != NULL){
        Inorder(root->left);
        cout<<root->key<<" ";
        Inorder(root->right);
    }
}

void Preorder(Node *root){
    if(root != NULL){
        cout<<root->key<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(Node *root){
    if(root != NULL){
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->key<<" ";
    }
}

int TreeSize(Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + TreeSize(root->left)+TreeSize(root->right);
}

int getMax(Node *root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}

int main(){
    Node *root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(90);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    root->right->left = new Node(60);
    root->right->left->left = new Node(80);
    Inorder(root);
    cout<<"\n";
    Preorder(root);
    cout<<"\n";
    Postorder(root);
    cout<<"\n";
    cout<<getMax(root);
    return 0;
}