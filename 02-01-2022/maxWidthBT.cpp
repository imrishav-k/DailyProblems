#include<iostream>
#include<queue>

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

int maxWidth(Node *root){
    if(root==NULL) return 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int res = 0;

    while(q.size()>1){
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){
            int s = q.size();
            res = max(res, s);
            q.push(NULL);
            continue;
        }
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    return res;
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
    cout<<maxWidth(root);
    return 0;
}