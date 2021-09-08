#include <iostream>
using namespace std;

struct Nodes{
    char data;
    Nodes* next;
    Nodes(char d){
        this->data = d;
        this->next = NULL;
    }
};  

struct stack{
    int cnt;
    Nodes* tail;
    stack(){
        cnt = 0;
        tail = NULL;
    }
    void push(char n){
        Nodes* temp = new Nodes(n);
        temp->next = tail;
        tail = temp;
        cnt++;
    }
    void pop(){
        tail = tail->next;
        cnt--;
    }
    bool empty(){
        return (tail==NULL);
    }
};



int main(){
    bool ok = true;
    stack syeta;
    string s;
    cin >> s;
    int num = s.size();
    for(int i =0;i<num;i++){
        if(ok == false) break;
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            syeta.push(s[i]);
        }
        else{
            if(syeta.empty()){
                ok = false;
                break;
            }
            char symbol1 = syeta.tail->data;
            if(s[i] == ')' && symbol1 != '('){
                ok = false;
            }
            if(s[i] == ']' && symbol1 != '['){
                ok = false;
            }
            if(s[i] == '}' && symbol1 != '{'){
                ok = false;
            }
            syeta.pop();
        }
    }
    if(ok == true && syeta.empty()){
        cout << "yes";
    }
    else{
        cout <<"no";
    }



    return 0;
}