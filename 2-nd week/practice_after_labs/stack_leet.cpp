#include <iostream>
using namespace std;

struct Nodes{
    char data;
    Nodes* next;
    Nodes(char d){
        this->data=d;
        this->next = NULL;
    }
};

struct stack{
    int cnt;
    Nodes* top;
    stack(){
        cnt = 0;
        top = NULL;
    }
    void push(char d){
        Nodes* temp = new Nodes(d);
        temp->next = top;
        top = temp;
        cnt++;
    }
    void pop(){
        top = top->next;
        cnt--;
    }
    char top_s(){
        return top->data;
    }
};



int main(){
    stack zxc;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=65 && s[i] <=90){
            zxc.push(s[i]);
        }else if(s[i] >=97 && s[i]<=122){
            zxc.push(s[i]);
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>=65 && s[i] <=90){
            cout << zxc.top_s();
            zxc.pop();
        }else if(s[i] >=97 && s[i]<=122){
            cout << zxc.top_s();
            zxc.pop();
        }else{
            cout << s[i];
        }
    }
}