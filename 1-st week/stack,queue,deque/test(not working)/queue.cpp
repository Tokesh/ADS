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

struct queue{
    Nodes *first;
    Nodes *second;
    int cnt;
    queue(){
        first=NULL;
        second=NULL;
        cnt = 0;
    }
    int add_elem(int data){
        Nodes *temp = new Nodes(data);
        temp->data = data;
        temp->next = NULL;
        if(cnt == 0){
            first=temp;
            second = temp;
            cnt++;
        }
        else{
            second->next=temp;
            second=temp;
            cnt++;
        }
    }
    void del_elem(){
        if(cnt != 0){
            first = first->next;
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
    queue *qu = new queue();
    qu->add_elem(1);
    qu->add_elem(10);
    qu->add_elem(2);
    qu->add_elem(3);
    qu->add_elem(5);
    qu->add_elem(4);
    while(!qu->empty()){
        cout << qu->first->data << endl;
        qu->del_elem();
    }
    return 0;
}