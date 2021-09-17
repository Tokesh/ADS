#include <iostream>
using namespace std;

struct Nodes{
    int data;
    Nodes *next;
    Nodes(int data){
        this->data=data;
        this->next=next;
    }
};

struct Stack{
    int cnt;
    Nodes *top;
    Stack(){
        cnt = 0;
        top = NULL;
    }
    void push(int data){
        Nodes *temp = new Nodes(data);
        temp->next = top;
        top = temp;
        cnt++;
    }
    void pop(){
        top = top->next;
        cnt--;
    }
};



int main(){
    Stack st;
    string s;
    while(cin >> s){
        if(s == "size"){
            cout << st.cnt << endl;
        }
        if(s == "push"){
            int x;
            cin >> x;
            st.push(x);
            cout << "ok" << endl;
        }
        if(s == "pop"){
            if(st.cnt != 0){
                cout << st.top->data << endl;
                st.pop();
            }
            else cout << "error"<< endl;
        }
        if(s == "clear"){
            while(st.cnt!=0){
                st.pop();
            }
            cout << "ok" << endl;
        }
        if(s== "back"){
            if(st.cnt == 0) cout<<"error" <<endl;
            else cout << st.top->data << endl;
        }
        if(s == "exit"){
            cout << "bye" << endl;
            return 0;
        }
    
    }
}