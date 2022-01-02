#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

void zigzagTraversal(Node *root){
    stack<Node*> ms;
    stack<Node*> cs;

    int level = 1;
    ms.push(root);
    
    while(ms.empty() == false){
        Node *curr = ms.top();
        ms.pop();
        cout<<curr->key<<" ";

        if(level % 2 == 1){
            if(curr->left)
                cs.push(curr->left);
            if(curr->right)
                cs.push(curr->right);
        }
        else{
            if(curr->right)
                cs.push(curr->right);
            if(curr->left)
                cs.push(curr->left);
        }

        if(ms.size() == 0){
            swap(cs, ms);
            level++;
        }
    }   
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    zigzagTraversal(root);
    return 0;
}