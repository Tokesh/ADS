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
    void insert(int val){
        root = insert(root, val);
    }
    void inOrder(node* root){
        if(root == NULL) return;
        inOrder(root->left);
        cout << root->val << endl;
        inOrder(root->right);
    }
    void postOrder(node* root){
        if(root == NULL) return;
        postOrder(root->right);
        cout << root->val << ' ';
        postOrder(root->left);
    }
    void inOrder(){
        inOrder(root);
        cout << endl;
    }
    void postOrder(){
        postOrder(root);
        cout << endl;
    }
    int cnt_height(node* root, int count){
        if(root == NULL) return count;
        return max(cnt_height(root->left, count+1), cnt_height(root->right, count+1));
    }
};

int main(){
    bst tree;
    int x;
    cin >> x;
    while(x != 0){
        tree.insert(x);
        cin >> x;
    }
    cout << tree.cnt_height(tree.root, 0);
    return 0;
}