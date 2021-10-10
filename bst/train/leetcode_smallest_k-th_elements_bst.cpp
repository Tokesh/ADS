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
    int res;
    void smallestMin(TreeNode* root, int &k){
        if(root == NULL) return;
        smallestMin(root->left, k);
        k--;
        if(k == 0){
            k--;
            res = root->val;
        }
        smallestMin(root->right,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        res = 0;
        smallestMin(root, k);
        return res;
    }
};