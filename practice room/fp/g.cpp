#include <iostream>
using namespace std;

const int SIZE = 26;
struct Node{
    Node * children[SIZE];
    bool isEnd;
    int cnt;
    Node(){
        for(int i=0;i<SIZE;i++){
            children[i] = NULL;
        }
        isEnd = false;
        cnt = 0;
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
            cur->cnt += 1;
        }
        cur->isEnd = true; 
    }
    
    int search(string word) {
        int v = 0;
        Node * cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(cur->children[index] == NULL){
                return 0;
            }
            cur = cur->children[index];
        }
        return cur->cnt;
    }
    
    void delz(string word) {
        Node * cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            cur = cur->children[index];
            cur->cnt -= 1;
        }
        cur->isEnd = false;
    }

    int find(string word) {
        Node * cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(cur->children[index] == NULL){
                return 0;
            }
            cur = cur->children[index];
        }
        return cur->isEnd;
    }
};

int main(){
    Trie z;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char x;
        string k;
        cin >> x >> k;
        if(x == '+'){
            z.insert(k);
        }
        else if(x == '-'){
            if(z.find(k)){
                z.delz(k);
            }
        }else if(x == '?'){
            cout << z.search(k) << endl;
        }
    }
    return 0;
}