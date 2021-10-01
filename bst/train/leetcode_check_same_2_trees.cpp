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

bool ok = false;
void check_same(TreeNode* p, TreeNode* q){
    if(p != NULL && q == NULL) ok = true;
    if(p == NULL && q != NULL) ok = true;
    if(p == NULL || q == NULL) return;
    check_same(p->left, q->left);
    if(p != NULL && q != NULL && p->val != q->val) ok = true;
    if(ok == true) return;
    check_same(p->right, q->right);
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        ok = false;
        check_same(p,q);
        if(ok==true) return false;
        return true;
    }
};