#include <iostream>
using namespace std;

struct Nodes{
    string data;
    Nodes* next;
    Nodes* prev;
    Nodes(string d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct deq{
    int cnt;
    Nodes* first;
    Nodes* second;
    deq(){
        cnt = 0;
        first = NULL;
        second = NULL;
    }
    void push_front(string s){
        Nodes* temp = new Nodes(s);
        if(first == NULL){
            first = temp;
            second = temp;
            cnt++;
        }else{
            temp->next = first;
            first->prev = temp;
            first=temp;
            cnt++;
        }
    }
    void push_back(string s){
        Nodes* temp = new Nodes(s);
        if(first == NULL){
            first = temp;
            second = temp;
            cnt++;
        }else{
            temp->prev = second;
            second->next = temp;
            second = temp;
            cnt++;
        }
    }
    void pop_front(){
        if(cnt == 1){
            first = NULL;
            second = NULL;
            cnt = 0;
        }else{
            first = first->next;
            if(first == NULL){
                first=NULL;
                cnt = 0;
            }else{
                first->prev = NULL;
                cnt--;
            }
        }
    }
    void pop_back(){
        if(cnt == 1){
            first = NULL;
            second = NULL;
            cnt = 0;
        }else{
            second = second->prev;
            if(second == NULL){
                first=NULL;
                cnt = 0;
            }else{
                second->next = NULL;
                cnt--;
            }
        }
    }
    
};


int main(){
    deq zxc;
    string s,j;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){
            j += s[i];
        }
        else{
            zxc.push_back(j);
            j="";
        }
        if(i == s.size()-1 && j!=""){
            zxc.push_back(j);
        }
    }
    string last;
    while(zxc.second != NULL){
        last += zxc.second->data;
        zxc.pop_back();
        if(zxc.cnt != 0) last += ' ';
    }
    cout << last;
}