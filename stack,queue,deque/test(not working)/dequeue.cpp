#include <iostream>
using namespace std;

struct Nodes{
    int data;
    Nodes *next;
    Nodes(int data){
        this->data=data;
        this->next=NULL;
    }
};

struct deque{
    Nodes *first;
    Nodes *second;
    int cnt;
    deque(){
        cnt = 0;
        first =NULL;
        second = NULL;
    }
    int add_elem_front(int data){
        if(cnt == 0){
            Nodes *temp = new Nodes(data);
            temp->data = data;
            temp->next = NULL;
            first = temp;
            second = temp;
            cnt++;
        }
        else{
            Nodes *temp = new Nodes(data);
            temp->data = data;
            temp->next = first;
            first= temp;
            cnt++;
        }
    }
    int add_elem_back(int data){
        if(cnt == 0){
            Nodes *temp = new Nodes(data);
            temp->data = data;
            temp->next = NULL;
            first = second = temp;
            cnt++;
        }
        else{
            Nodes *temp = new Nodes(data);
            temp->data = data;
            temp->next = NULL;
            second->next = temp;
            second = temp;
            cnt++;
        }
    }
    void del_elem_front(){
        if(cnt != 0){
            first = first->next;
            cnt--;
        }
    }
    void del_elem_back(){
        if(cnt != 0){
            second = second->next;
            cnt--;
        }
    }
    bool empty() {
        return (cnt == 0);
    }

    int size() {
        return cnt;
    } 
};

int main(){
    deque *de = new deque();
    de->add_elem_front(1);
    de->add_elem_back(10);
    de->add_elem_back(2);
    de->add_elem_back(3);
    de->add_elem_back(5);
    de->add_elem_back(4);
    while(!de->empty()){
        cout << de->second->data << endl;
        de->del_elem_back();
    }
    return 0;
}