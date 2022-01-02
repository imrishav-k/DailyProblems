#include<iostream>

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

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

//Naive solution O(n^2)
bool isBalanced(Node *root){
    if(root == NULL){
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return (abs(lh - rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

//Efficient solution O(n)

int isBalancedOptimized(Node *root){
    if(root == NULL){
        return 0;
    }
    int lh = isBalancedOptimized(root->left);
    if(lh == -1) return -1;
    int rh = isBalancedOptimized(root->right);
    if(rh == -1) return -1;
    return (abs(lh-rh)>1) ? -1 : max(lh, rh) +1;
}


int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    // root->left->left = new Node(40);
    // root->left->left->left = new Node(50);
    // root->left->right = new Node(60);
    // root->right->right = new Node(70);
    // root->right->right->left = new Node(80);
    // root->right->right->left->right = new Node(90);

    cout<<isBalancedOptimized(root);
    return 0;
}