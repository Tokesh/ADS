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
    bool rev;
    int cnt;
    Nodes* first;
    Nodes* second;
    deque(){
        cnt = 0;
        first = NULL;
        second = NULL;
        rev = false;
    }
    void push_front(int d){
        Nodes* temp = new Nodes(d);
        if(first == NULL){
            first = temp;
            second = temp;
            cnt++;
        }else{
            temp->next = first;
            first->prev = temp;
            first = temp;
            cnt++;
        }
    }
    void push_back(int d){
        Nodes* temp = new Nodes(d);
        if(second == NULL){
            first = temp;
            second = temp;
            cnt++;
        }else{
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
        }else{
            first=first->next;
            if(first == NULL){
                second = NULL;
            }else{
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
        }else{
            second = second->prev;
            if(second == NULL){
                first = NULL;
                cnt=0;
            }else{
                second->next = NULL;
                cnt--;
            }
        }
    }
};


int main(){
    int x,k;
    deque zxc;
    int n;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> x;
        if(x == 1){
            cin >> k;
            if(zxc.rev == false){
                zxc.push_back(k);
            }else{
                zxc.push_front(k);
            }
        }
        if(x== 2){
            if(zxc.rev == true){
                zxc.rev = false;
            }else{
                zxc.rev = true;
            }
        }
    }
    if(zxc.rev == false){
        while(zxc.first != NULL){
            cout << zxc.first->data << ' ';
            zxc.pop_front();
        }
    }
    if(zxc.rev == true){
        while(zxc.second != NULL){
            cout << zxc.second->data << ' ';
            zxc.pop_back();
        }
    }
    return 0;
}