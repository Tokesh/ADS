#include <iostream>

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
    int empty_c(){
        return cnt == 0;
    }
};

using namespace std;
int main(){
    bool ok = false;
    stack zxc;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') zxc.push(s[i]);
        else{
            if(zxc.empty_c()) ok = true;
            else if(s[i] == ')' && zxc.top_s() != '(') ok = true;
            else if(s[i] == ']' && zxc.top_s() != '[') ok = true;
            else if(s[i] == '}' && zxc.top_s() != '{') ok = true;
            zxc.pop();
        }
    }
    if(ok == false && zxc.cnt == 0) cout <<"YES";
    else cout <<"NO";
}