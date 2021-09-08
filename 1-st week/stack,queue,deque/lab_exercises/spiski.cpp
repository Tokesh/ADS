#include <iostream>
using namespace std;

struct Nodes{
    string data;
    Nodes* next;
    Nodes(string s){
        this->data = s;
        this->next = NULL;
    }
};

struct queue{
    int cnt;
    Nodes* first;
    Nodes* second;
    queue(){
        first= NULL;
        second=NULL;
        cnt = 0;
    }
    void push(string s){
        Nodes* temp = new Nodes(s);
        if(first == NULL){
            first = temp;
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
        first=first->next;
        cnt--;
    }
};

int main(){
    queue q1;
    queue q2;
    int x;
    string s;
    while(cin >> x){
        cin >> s;
        if(x == 9){
            cout << x << " "<< s << endl;
        }
        if(x == 10){
            q1.push(s);
        }
        if(x == 11){
            q2.push(s);
        }
    }
    while(q1.cnt != 0){
        cout <<"10 " << q1.first->data << endl;
        q1.pop();
    }
    while(q2.cnt != 0){
        cout <<"11 " << q2.first->data << endl;
        q2.pop();
    }

    return 0;
}