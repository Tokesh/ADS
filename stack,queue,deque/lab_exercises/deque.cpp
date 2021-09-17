#include <iostream>
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

struct deque{
    int cnt;
    Nodes* first;
    Nodes* second;
    deque(){
        first = NULL;
        second = NULL;
        cnt = 0;
    }
    void push_front(int data){
        Nodes* temp = new Nodes(data);
        if(first == NULL){
            first = temp;
            second = temp;
            cnt++;
        }
        else{
            temp->next = first;
            first->prev = temp;
            first=temp;
            cnt++;
        }
    }
    void push_back(int data){
        Nodes* temp = new Nodes(data);
        if(second == NULL){
            first = temp;
            second = temp;
            cnt++;
        }
        else{
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
        }
        else{
            first = first->next;
            if (first == NULL){
                second = NULL;
                cnt = 0;
            }
            else{
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
        }
        else{
            second = second->prev;
            if (second == NULL){
                first = NULL;
                cnt = 0;
            }
            else{
                second->next = NULL;
                cnt--;
            }
        }
    }
    void clear(){
        second = NULL;
        while(first!=NULL){
            first = first->next;
        }
        cnt = 0;
    }
};



int main(){
    string s;
    deque de;
    while(cin >> s){
        if(s == "push_front"){
            int x;
            cin >> x;
            de.push_front(x);
            cout << "ok" << endl;
        }
        else if(s == "push_back"){
            int x;
            cin >> x;
            de.push_back(x);
            cout << "ok" << endl;
        }
        else if(s == "pop_front"){
            if(de.cnt != 0){
                cout << de.first->data << endl;
                de.pop_front();
            }
            else cout << "error" << endl;
        }
        else if(s == "pop_back"){
            if(de.cnt != 0){
                cout << de.second->data << endl;
                de.pop_back();
            }
            else cout << "error" << endl;
        }
        else if(s == "front"){
            if(de.cnt != 0){
                cout << de.first->data << endl;
            }
            else cout << "error" << endl;
        }
        else if(s == "back"){
            if(de.cnt != 0){
                cout << de.second->data << endl;
            }
            else cout << "error" << endl;
        }
        else if(s == "size"){
            cout << de.cnt << endl;
        }
        else if(s == "clear"){
            de.clear();
            cout << "ok" << endl;
        }
        else if(s =="exit"){
            cout << "bye" << endl;
            return 0;
        }
    }
}