#include <iostream>
using namespace std;

int mini = INT_MAX;
const int SIZE = 26;
struct Node{
    Node * children[SIZE];
    int cnt;
    Node(){
        for(int i=0;i<SIZE;i++){
            children[i] = NULL;
        }
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
            /* cout << char(index+97) << ' ' << cur->cnt << endl; */
        }
    }
    void search(string word) {
        Node * cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            cur = cur->children[index];
            mini = min(cur->cnt, mini);
        }
    }
    void startsWith(string prefix) {
        Node * cur = root;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i] - 'a';
            if(cur->children[index] == NULL){
                break;
            }
            
            cur = cur->children[index];
        }
    }
};

int main(){
    Trie trie;
    string k;
    cin >> k;
    trie.insert(k);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string zz;
        cin >> zz;
        trie.insert(zz);
    }
    trie.search(k);
    cout << mini;
    if(mini == 1) cout << "YES";
    else cout <<"NO";
    return 0;
}