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

/* 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct Nodes{
    string data;
    Nodes *next;
    int cnt;
    Nodes(string d){
        this->cnt = 1;
        this->data = d;
        this->next = NULL;
    }
};

struct LinkedList{
    int size_cnt;
    Nodes* first;
    Nodes* second;
    LinkedList(){
        size_cnt = 0;
        first=second=NULL;
    }
    void push_back(string d){
        Nodes* temp = new Nodes(d);
        Nodes* last = first;
        size_cnt++;
        if(first == NULL){
            first=second=temp;
            return;
        }
        while(last->next != NULL && last->data != d){
            last = last->next;
        }
        if(last->data == d){
            last->cnt++;
            return;
        }
        last->next = temp;
        second = temp;
    }
    void push_front(string d){
        Nodes* temp = new Nodes(d);
        size_cnt++;
        if(first == NULL){
            first = second=temp;
        }else{
            temp->next = first;
            first = temp;
        }
    }
    void pop_back(){
        if(first == NULL) return;
        if(first == second){
            first=second=NULL;
            size_cnt=0;
        }else{
            size_cnt--;
            Nodes* temp = first;
            while(temp->next != second){
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
    void sort_sel(){
        Nodes* current = first;
        while(current != NULL){
            Nodes* end = current->next;
            while(end != NULL){
                if(current->data > end->data){
                    string temp = current->data;
                    int temp_cnt = current->cnt;
                    current->data = end->data;
                    current->cnt = end->cnt;
                    end->data = temp;
                    end->cnt = temp_cnt;
                }
                end = end->next;
            }
            current = current->next;
        }
    }
    void print_m(){
        Nodes* temp = first;
        while(temp != NULL){
            cout << temp->data << ' ' << temp->cnt;
            if(temp->next != NULL) cout << endl;
            temp = temp->next;
        }
    }
};


int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    LinkedList qq;
    string s;
    while(cin >> s){
        qq.push_back(s);
    }
    qq.sort_sel();
    qq.print_m();
    return 0;
} */