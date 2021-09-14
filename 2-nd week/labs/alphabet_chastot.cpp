#include <iostream>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Nodes{
    string data;
    Nodes* next;
    Nodes(string d){
        this->data = d;
        this->next = NULL;
    }
};

struct linked{
    Nodes* first;
    Nodes* second;
    linked(){
        first = second = NULL;
    }
    void add(string x){
        Nodes* temp = new Nodes(x);
        if(first == NULL){
            first=second=temp;
        }else{
            second->next = temp;
            second = temp;
        }
    }
};




int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    map<string,int>zxc;
    linked ll;
    string s;
    while(cin >> s){
        zxc[s] += 1;
    }
    map<string,int>::iterator it;
    for(it = zxc.begin();it!=zxc.end();it++){
        cout << it->first << ' ' << it->second << endl;
    }

}