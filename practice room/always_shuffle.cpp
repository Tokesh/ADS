#include <iostream>
using namespace std;

struct Nodes{
    string data;
    Nodes* next;
    Nodes* prev;
    Nodes(string d){
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
    void push_front(string data){
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
    void push_back(string data){
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
    deque zz;
    for(int i=0;i<52;i++){
        string x;
        cin >> x;
        zz.push_back(x);
    }
    int n;
    cin >> n;
    int cnt=0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt += x;
    }
    cnt %= 52;
    for(int i=0;i<cnt;i++){
        string temp = zz.first->data;
        zz.pop_front();
        zz.push_back(temp);
    }
    cout << zz.first->data << endl;
    cout << zz.first->next->data << endl;

    return 0;
}