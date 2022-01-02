#include<iostream>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int k){
        int key = k;
        left = right = NULL;
    }
};

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(50);
    root->left->right = new Node(60);
    root->right->right = new Node(70);
    root->right->right->left = new Node(80);
    root->right->right->left->right = new Node(90);
    cout<<height(root);
    return 0;
}