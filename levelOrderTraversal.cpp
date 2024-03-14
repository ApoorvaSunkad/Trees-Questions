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

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);

    q.push(NULL); /*
    if(temp == NULL){//previous level is completed
            cout << endl;
    adding a seperator in order to print the nodes in a tree manner
    while traversing in a queue if NULL is encountered then a endl is marked
    meaning next nodes should be printed on the next line.*/

    /*
    if(!q.empty()){ //queue still has some child nodes
                q.push(NULL);
            }
    This implies that if queue is not empty then push NULL in queue so that
    while traversing the queue if NULL is encountered again then that means
    next nodes should be printed on the next line.
    */

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){//previous level is completed
            cout << endl;
            if(!q.empty()){ //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout << "printing the nodes" << endl;
    levelOrderTraversal(root);
}
