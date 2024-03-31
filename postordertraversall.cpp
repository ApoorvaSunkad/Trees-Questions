/*
Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:
5 10 39 1

        1
     /     \
   10     39
  /
5


Example 1:

Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19
Example 2:

Input:
          11
         /
       15
      /
     7
Output: 7 15 11

Your Task:
You don't need to read input or print anything. Your task is to complete the function postOrder() that takes root node as input and returns an array containing the postorder traversal of the given Binary Tree.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= Number of nodes <= 10^5
0 <= Data of a node <= 10^6
*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(N)
//GFG Question
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; 

//Function to return a list containing the postorder traversal of the tree.
void fun(vector<int>&ans, Node* root){
    if(root == NULL){
        return;
    }
    fun(ans,root->left);
    fun(ans,root->right);
    ans.push_back(root->data);
    
}
vector <int> postOrder(Node* root)
{
  
  //LRN
  vector<int> v;
  
  if(root == NULL){
      return v;
  }
  fun(v,root);
  return v;
}