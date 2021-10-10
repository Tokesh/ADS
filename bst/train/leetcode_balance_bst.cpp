#include <algorithm>
#include <vector>
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

vector<int>zxc;
void check_ev(TreeNode* root){
    if(root == NULL) return;
    check_ev(root->left);
    if(root != NULL) zxc.push_back(root->val);
    check_ev(root->right);
}

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        zxc.clear();
        check_ev(root1);
        check_ev(root2);
        sort(zxc.begin(),zxc.end());
        return zxc;
    }
};