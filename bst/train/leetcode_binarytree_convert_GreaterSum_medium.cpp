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
    class Solution {
        public:
            int sum=0;
            void dfs(TreeNode* root){
                if(!root)
                    return ;
                dfs(root->right);
                root->val+=sum;
                sum=root->val;
                dfs(root->left);
            }

            TreeNode* bstToGst(TreeNode* root) {
                dfs(root);
                return root;
            }
};
 
 
 
 */

map<int,int>zxc;
int total_sum = 0;

void check_ev(TreeNode* root){
    if(root==NULL) return;
    check_ev(root->left);
    if(zxc[root->val]==0){
        zxc[root->val] = 1;
        total_sum += root->val;
    }
    check_ev(root->right);
}

void res_c(TreeNode* root){
    if(root == NULL) return;
    res_c(root->left);
    int cnt=total_sum;
    map<int,int>::iterator it;
    for(it=zxc.begin();it!= zxc.end();it++){
        if(it->first < root->val) cnt -= it->first;
        else break;
    }
    root->val = cnt;
    res_c(root->right);
}


class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        zxc.clear();
        total_sum = 0;
        check_ev(root);
        res_c(root);
        return root;
    }
};





