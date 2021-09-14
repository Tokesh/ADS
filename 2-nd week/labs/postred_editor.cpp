#include <iostream>
using namespace std;

struct Nodes{
    string data[100000];
    Nodes* next;
    Nodes* prev;
    Nodes(string d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

int main(){
    string s;
    return 0;
}