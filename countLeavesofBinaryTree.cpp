/*
Given a Binary Tree of size N, You have to count leaves in it. 
For example, there are two leaves in following tree

        1
     /      \
   10      39
  /
5

 

Example 1:


Input:
Given Tree is 
               4
             /   \
            8     10
           /     /   \
          7     5     1
         /
        3 
Output:
3
Explanation: 
Three leaves are 3 , 5 and 1.
 

Your Task:
You don't have to take input. Complete the function countLeaves() that 
takes root node of the given tree as parameter and returns the count of 
leaves in tree. The printing is done by the driver code.
 

Constraints:
1<= N <= 104

*/
#include<bits/stdc++.h>
using namespace std;
void countleaves(Node* root , int &count){
       if(root==NULL){
           return ;
       }
       if(root->left==NULL && root->right==NULL){
           count++;
           return;
           
       }
       countleaves(root->left , count);
       countleaves(root->right , count);
       
   }
int countLeaves(Node* root)
{
  // Your code here
  
        int count = 0;
        
        countleaves(root,count);
        return count;
       
}