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
TreeNode* Insert(TreeNode *root,int x){
    if(root==NULL){
    return new TreeNode(x);
    }

    if(x > root->val){
        root->right = Insert(root->right,x);
    }
    if(x < root->val){
        root->left = Insert(root->left,x);
    }
    return root;
    }
TreeNode* bstFromPreorder(vector<int>& preorder) {

    TreeNode* root=NULL;
    
    root=Insert(root,preorder[0]);
    for(int i=1;i<preorder.size();i++)
        Insert(root,preorder[i]);

    return root;
    }
};