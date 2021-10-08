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
    void kMax(node* root, int &k){
        if(root == NULL) return;
        kMax(root->right, k);
        k--;
        if(k == 0){
            k--;
            res = root->val;
        }
        kMax(root->left,k);
        return;
    }
};

int main(){
    bst tree;
    int x;
    cin >> x;
    while(x != 0){
        tree.root = tree.insert(tree.root, x);
        cin >> x;
    }
    int k=2;
    tree.kMax(tree.root, k);
    cout << res;
    return 0;
}