#include <iostream>
using namespace std;

struct Nodes{
    int data;
    Nodes *next;
    Nodes(int data){
        this->data = data;
        this->next = next;
    }
};

struct st{
    public:
        Nodes *top;
        int cnt;
    st(){
        top = NULL;
        cnt=0;
    }
    int push(int data){
        Nodes *temp = new Nodes(data);
        temp->next = top;
        top = temp;
        cnt++;
    }
    void pop(){
        if(top!= NULL){
            top = top->next;
            cnt--;
        }
    }
    bool empty() {
        return (top == NULL);
    }

    int size() {
        return cnt;
    } 
};


int main(){
    st *s = new st();
    s->push(1);
    s->push(10);
    s->push(2);
    s->push(3);
    s->push(5);
    s->push(4);
    while(!s->empty()){
        cout << s->top->data << endl;
        s->pop();
    }
    return 0;
}