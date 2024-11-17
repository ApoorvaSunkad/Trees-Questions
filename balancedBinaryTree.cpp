/*
Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4


*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<iostream>
using namespace std;

//T.C = O(N)
//S.C = O(N)

bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;

        int leftH = dfsHeight(root->left);
        if(leftH == -1) return -1;

        int rightH = dfsHeight(root->right);
        if(rightH == -1) return -1;

        if(abs(leftH-rightH)>1) return -1;
        return max(leftH,rightH)+1;
    }
