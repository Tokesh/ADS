#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Nodes{
    int data;
    Nodes* next;
    Nodes* prev;
    Nodes(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct linked{
    Nodes* first;
    Nodes* second;
    int cnt;
    linked(){
        first = second = NULL;
        cnt = 0;
    }
    void add(int x){
        cnt++;
        Nodes* temp = new Nodes(x);
        if(first == NULL){
            first=second=temp;
        }else{
            second->next = temp;
            temp->prev = second;
            second = temp;

        }
    }
    bool find_1(int x){
        Nodes* temp = first;
        while(temp != NULL){
            if(temp->data == x){
                return true;
            }
            temp = temp->next;
        }
        return false;
        
    }
    Nodes* find_2(int x){
        Nodes* temp = first;
        while(temp != NULL){
            if(temp->data == x){
                return temp;
            }
            temp = temp->next;
        }
        cout << temp;
        return NULL;
        
    }
    void dl(Nodes* n){
        cnt--;
        if(n == NULL) return;


        if(n->prev == NULL && n->next == NULL){
            first=second=NULL;
        } else if(n->prev != NULL && n->next != NULL){
            n->prev->next = n->next;
            n->next->prev = n->prev;
        } else if(n->prev == NULL){
            first = first->next;
            n->next->prev = NULL;
        } else if(n->next == NULL){
            second = second->prev;
            n->prev->next = NULL;
        }
    }
    void print(){
        Nodes* temp = first;
        while(temp != NULL){
            cout << temp->data;
            temp = temp->next;
            if(temp != NULL) cout << ' ';
        }
    }
    void sort_byd(){
        Nodes* a;
        Nodes* b;
        int temp;
        for(Nodes* i=first;i!=NULL;i=i->next){
            for(Nodes* j=i->next;j!=NULL;j=j->next){
                if(i->data > j->data){
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
};


int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    linked ll;
    bool ok = true;
    string s;
    
    while(cin >> s){
        string j="";
        if(s[0] == '+'){
            for(int i=1;i<s.size();i++){
                j += s[i];
            }
            ll.add(stoi(j));
        }
        if(s[0] == '-'){
            for(int i=1;i<s.size();i++){
                j += s[i];
            }
            int x=stoi(j);
            if(ll.find_1(x) == false){
                ok = false;
            }
            if(ll.find_1(x)){
                ll.dl(ll.find_2(x));
            }else{
                ok = false;
            }
            
            
        }
    }
    if(ok == false) cout << "ERROR";
    else if(ll.cnt == 0) cout << "EMPTY";
    else{
        ll.sort_byd();
        ll.print();
    }
}