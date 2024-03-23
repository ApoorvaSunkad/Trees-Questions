#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildTree(Node* root){
    cout << "Enter the data:" << endl;
    int data;
    cin>>data;
    root = new Node(data);

    //Representing the NULL node
    if(data == -1){
        return NULL;
    }

    //Adding data in a tree in recursive way
    cout << "Enter the data for inserting at left of "<< data << endl;
    root->left = buildTree(root->left); //recursive call
    cout << "Enter the data for inserting at right of "<< data << endl;
    root->right = buildTree(root->right);
    return root;
}

//Code word for INORDER TRAVERSAL
//LNR - LEFT, NODE, RIGHT
void inOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout << "printing the nodes" << endl;
    inOrder(root);
}