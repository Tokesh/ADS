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

    void print_list(node* root){
        if(root == NULL) return;
        print_list(root->left);
        if(root->left == NULL && root->right == NULL) cout << root->val << endl;
        print_list(root->right);
    }
    void print_list(){
        print_list(root);
        cout << endl;
    }

    void print_razvilok(node* root){
        if(root == NULL) return;
        print_razvilok(root->left);
        if(root->left != NULL && root->right != NULL) cout << root->val << endl;
        print_razvilok(root->right);
    }
    void print_razvilok(){
        print_razvilok(root);
        cout << endl;
    }

    void print_vetok(node* root){
        if(root == NULL) return;
        print_vetok(root->left);
        if(root->left != NULL && root->right == NULL) cout << root->val << endl;
        else if(root->left == NULL && root->right != NULL) cout << root->val << endl;
        print_vetok(root->right);
    }
    void print_vetok(){
        print_vetok(root);
        cout << endl;
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
    tree.print_vetok();
    return 0;
}