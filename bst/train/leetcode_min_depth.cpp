/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { 
public:
 int calc(TreeNode *root)
 {
     if(root->left==NULL&&root->right==NULL)
        return 1;
     else if(root->left==NULL)
     {
         return 1+calc(root->right);
     }
    else if(root->right==NULL)
     {
         return 1+calc(root->left);
     }
     else{
     return 1+min(calc(root->left),calc(root->right));
     }
 }
int minDepth(TreeNode* root) {
if(root==NULL)
    return 0;
    
    return calc(root); 
}};