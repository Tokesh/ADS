#include <map>
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
map<int, int>zxc;
void findMode1(TreeNode* node){
    if(node == NULL) return;
    findMode1(node->left);
    zxc[node->val] += 1;
    findMode1(node->right);
    
}

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        zxc.clear();
        vector<int>res;
        findMode1(root);
        int maxi=-100000;
        map<int,int>::iterator it;
        for(it = zxc.begin();it != zxc.end();it++){
            cout << it->first << ' ' << it->second << endl;
            if(it->second > maxi) maxi = it->second;
        }
        for(it = zxc.begin();it != zxc.end();it++){
            if(it->second == maxi) res.push_back(it->first);
        }
        return res;
        
    }
};