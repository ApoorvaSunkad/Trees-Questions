/*
Given the root of a binary tree, return the preorder traversal of its 
nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

*/

#include<bits/stdc++.h>
using namespace std;
//T.C = O(N)
//S.C = O(N) //worst case
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;

    if(root == NULL){
        return v;
    }

    stack<TreeNode*> st;

    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();

        v.push_back(root->val);
        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left != NULL){
            st.push(root->left);
        }
    }

    return v;
}