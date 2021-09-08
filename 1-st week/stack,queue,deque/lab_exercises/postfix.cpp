#include <iostream>
#include <sstream>
#include<string>

using namespace std;

struct Nodes{
    int data;
    Nodes* next;
    Nodes(int d){
        this->data=d;
        this->next=NULL;
    }
};

struct stack{
    int cnt;
    Nodes* top;
    stack(){
        cnt = 0;
        top = NULL;
    }
    void push(int n){
        Nodes* temp = new Nodes(n);
        temp->next = top;
        top = temp;
        cnt++;
    }
    void pop(){
        top = top->next;
        cnt--;
    }
    int top_d(){
        return top->data;
    }
};


int main(){
    stack st;
    string s;
    getline(cin,s);
    int a,b;
    stringstream ss(s);
    string word;
    while(ss >> word){
        if(word == "+"){
            a = st.top_d();
            st.pop();
            b = st.top_d();
            st.pop();
            st.push(a+b);
        }
        else if(word == "-"){
            a = st.top_d();
            st.pop();
            b = st.top_d();
            st.pop();
            st.push(b-a);
        }
        else if(word == "*"){
            a = st.top_d();
            st.pop();
            b = st.top_d();
            st.pop();
            st.push(a*b);
        }
        else if(word == "/"){
            a = st.top_d();
            st.pop();
            b = st.top_d();
            st.pop();
            st.push(b/a);
        }
        else{
            st.push(stoi(word));
        }
    }
    cout << st.top_d();
    return 0;
}