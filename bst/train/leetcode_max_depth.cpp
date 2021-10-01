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

int cnt_height(TreeNode* root, int count){
    if(root == NULL) return count;
    return max(cnt_height(root->left, count+1), cnt_height(root->right, count+1));
}


class Solution {
public:
    int maxDepth(TreeNode* root) {
        return cnt_height(root, 0);
        
    }
};