#include <iostream>

using namespace std;
const int SIZE = 26;
struct Node{
    Node * children[SIZE];
    bool isEnd;
    Node(){
        for(int i=0;i<SIZE;i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};
struct Trie {
    Node * root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(cur->children[index]==NULL){
                cur->children[index] = new Node();
            }
            cur = cur->children[index];
        }
        cur->isEnd = true; 
    }
    
    bool search(string word) {
        Node * cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(cur->children[index] == NULL){
                return false;
            }
            cur = cur->children[index];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node * cur = root;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i] - 'a';
            if(cur->children[index] == NULL){
                return false;
            }
            cur = cur->children[index];
        }
        return true;
    }
};

int main(){

    return 0;
}