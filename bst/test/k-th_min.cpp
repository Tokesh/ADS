#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int val){
        this->val = val;
        right = NULL;
        left = NULL;
    }
};

int res = 0;
struct bst{
    node* root;
    bst(){
        root = NULL;
    }

    node* insert(node* root ,int val){
        if(root == NULL) return new node(val);
        if(root->val > val) root->left = insert(root->left, val);
        if(root->val < val) root->right = insert(root->right, val);
        return root;
    }
    void smallestMin(node* root, int &k){
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
};

int main(){
    bst tree;
    int n,x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        tree.root = tree.insert(tree.root, x);
    }
    int k;
    cin >> k;
    tree.smallestMin(tree.root, k);
    cout << res;
    return 0;
}