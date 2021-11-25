#include <iostream>
using namespace std;

const int SIZE = 10;
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
class Trie {
    Node * root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - '0';
            if(cur->children[index]==NULL){
                cur->children[index] = new Node();
            }
            cur = cur->children[index];
        }
        cur->isEnd = true; 
    }
    bool search(string word){
        Node * cur = root;
        bool local_ok = false;
        for(int i=0;i<word.size();i++){
            int index = word[i] - '0';
            if(cur->children[index]==NULL){
                /* cout << local_ok; */
                if(cur->isEnd == true || local_ok == true) return true;
                return false;
            }
            /* cout << index << endl; */
            if(local_ok == true) return true;
            if(cur->isEnd == true) local_ok = true;
            cur = cur->children[index];
            
        }
        return false;
    }
};

int main(){
    Trie trie;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string k;
        cin >> k;
        trie.insert(k);
    }
    for(int i=0;i<m;i++){
        string k;
        cin >> k;
        if(trie.search(k) == true) cout << "YES" << endl;
        else cout <<"NO"<<endl;
    }
    return 0;
}