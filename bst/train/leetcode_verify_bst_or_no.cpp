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
    
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
    bool isBST(TreeNode* root, long long int min = LLONG_MIN, long long int max = LLONG_MAX) {
       if(root == NULL){
           return true;
       }
       if(root -> val <= min || root -> val >= max){
           return false;
       }
       bool isLeftOkay = isBST(root -> left, min, root -> val);
       bool isRightOkay = isBST(root -> right, root -> val, max);
       
       return isLeftOkay && isRightOkay;
   }
};
// with int min
class Solution
{
    public:
    bool isBST(Node* root, int min = INT_MIN, int max = INT_MAX) 
   {
       // Your code here
       if(root == NULL){
           return true;
       }
       if(root -> data < min || root -> data > max){
           return false;
       }
       bool isLeftOkay = isBST(root -> left, min, root -> data - 1);
       bool isRightOkay = isBST(root -> right, root -> data, max);
       
       return isLeftOkay && isRightOkay;
   }
};
