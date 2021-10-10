#include <iostream>
using namespace std;

struct Nodes{
    int val;
    Nodes* left;
    Nodes* right;
    Nodes(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    Nodes* root;
    bst(){
        root = NULL;
    }
    Nodes* insert(Nodes* node, int val){
        if(node == NULL){
            return new Nodes(val);
        }
        if(node->val <= val) node->right = insert(node->right, val);
        if(node->val > val) node->left = insert(node->left, val);
        return node;
    }
    Nodes* search(Nodes* node, int xc){
        if(node == NULL || node->val == xc) return node;
        cout << node->val << ' ' ;
        if(node->val < xc) search(node->right, xc);
        else search(node->left, xc);
    }
    Nodes* findMin(Nodes* node){
        while(node->left != NULL) node = node->left;
        return node;
    }
    Nodes* findMax(Nodes* node){
        while(node->right != NULL) node = node->right;
        return node;
    }
    void inOrder(Nodes* node){
        if(node == NULL) return;
        inOrder(node->left);
        cout << node->val << ' ';
        inOrder(node->right);
    }
    Nodes* deleteNode(Nodes* node, int val){
        if(node == NULL) return node;
        if(node->val > val) node->left = deleteNode(node->left, val);
        else if(node->val < val) node->right = deleteNode(node->right, val);
        else{
            if(node->left == NULL && node->right == NULL) return NULL;
            else if(node->left == NULL) node = node->right;
            else if(node->right == NULL) node = node->left;
            else{
                Nodes* temp = findMax(node->left);
                node->val = temp->val;
                node->left = deleteNode(node->left, temp->val);
            }

        }
        return node;
    }

    int sumi(Nodes* node){
        if(node == NULL) return 0;
        int left_sum = sumi(node->left);
        int right_sum = sumi(node->right);
        return node->val + left_sum + right_sum;
    }
    int sumi(Nodes* node, int left_sum, int right_sum){
        if(node == NULL) return 0;
        left_sum = sumi(node->left);
        right_sum = sumi(node->right);
        return node->val + left_sum + right_sum;
    }
};



int main(){
    bst zz;
    zz.root = zz.insert(zz.root, 5);
    zz.root = zz.insert(zz.root, 4);
    zz.root = zz.insert(zz.root, 2);
    zz.root = zz.insert(zz.root, 15);
    zz.root = zz.insert(zz.root, 10);
    zz.root = zz.insert(zz.root, 4);
    zz.deleteNode(zz.root, 5);
    zz.inOrder(zz.root);
    return 0;
}