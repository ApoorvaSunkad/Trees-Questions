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

//Code word for POSTORDER TRAVERSAL
//LRN - LEFT,RIGHT,NODE
void postOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout << "printing the nodes" << endl;
    postOrder(root);
}