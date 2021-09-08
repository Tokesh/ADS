#include <iostream>
using namespace std;

struct Nodes{
    int data;
    Nodes* next;
    Nodes* prev;
    Nodes(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
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
    void push_front(int n){
        Nodes* temp = new Nodes(n);
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
    void push_back(int n){
        Nodes* temp = new Nodes(n);
        if(second == NULL){
            first = temp;
            second = temp;
            cnt++;
        }else{
            second->next = temp;
            temp->prev = second;
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
            if (first == NULL)
                second = NULL;
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
};


int main(){
    deq dq1;
    deq dq;
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        char c;
        int n;
        cin >> c;
        if(c == '+'){
            cin >> n;
            dq1.push_back(n);
        }
        if(c == '-'){
            cout << dq.first->data << "\n";
            dq.pop_front();
        }
        if(c == '*'){
            cin >> n;
            dq1.push_front(n);
        }
        if(dq1.cnt>dq.cnt){
            dq.push_back(dq1.first->data);
            dq1.pop_front();
        }
    }
    return 0;
}