/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 10

*/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//T.C = O(N^2)
    int maxi = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        maxi = max(maxi,lh+rh);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi;

}

//optimized solution

 int maxDiameter = 0;

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    // Update maxDiameter at each node
    maxDiameter = max(maxDiameter, lh + rh);

    // Return the height of the current node
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    maxDepth(root);  // This will update maxDiameter as a side effect
    return maxDiameter;

}