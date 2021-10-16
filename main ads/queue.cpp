#include <iostream>
using namespace std;

struct Nodes{
    int data;
    Nodes* next;
    Nodes(int d){
        this->data=d;
        this->next=NULL;
    }
};

struct que{
    int cnt;
    Nodes* first;
    Nodes* second;
    que(){
        cnt = 0;
        first=NULL;
        second=NULL;
    }
    void push(int data){
        Nodes* temp = new Nodes(data);
        if(first == NULL){
            first=temp;
            second = temp;
            cnt++;
        }
        else{
            second->next = temp;
            second = temp;
            cnt++;
        }
    }
    void pop(){
        first = first->next;
        cnt--;
    }
    int front(){
        return first->data;
    }
    bool empty(){
        return (first == NULL);
    }
};



int main(){
    que qu;
    string s;
    while(cin >> s){
        if(s == "push"){
            int x;
            cin >> x;
            qu.push(x);
            cout << "ok" << endl;
        }
        if(s == "pop"){
            if(qu.cnt != 0){
                cout << qu.first->data << endl;
                qu.pop();
            }
            else cout << "error" << endl;
        }
        if(s == "front"){
            if(qu.cnt != 0) cout << qu.first->data << endl;
            else cout << "error" << endl;
        }
        if(s == "size"){
            cout << qu.cnt << endl;
        }
        if(s == "clear"){
            while(qu.cnt != 0){
                qu.pop();
            }
            cout << "ok" << endl;
        }
        if(s == "exit"){
            cout << "bye";
            return 0;
        }
    }
}