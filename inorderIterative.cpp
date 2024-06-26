/*
Given the root of a binary tree, return the inorder traversal of its 
nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;

    TreeNode* node = root;

    vector<int> v;

    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()==true){
                break;
            }
            node = st.top();
            st.pop();
            v.push_back(node->val);
            node = node->right;
        }

    }
    return v;
}