#include <iostream>
using namespace std;

struct Nodes{
    int data;
    Nodes* next;
    Nodes(int d){
        this->data=d;
        this->next=NULL;
    }
};

struct queue{
    int cnt;
    Nodes* first;
    Nodes* second;
    queue(){
        cnt = 0;
        first=NULL;
        second=NULL;
    }
    void push(int data){
        Nodes* temp = new Nodes(data);
        if(first == NULL){
            first=temp;
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
        first = first->next;
        cnt--;
    }
};

int main(){
    queue player1;
    queue player2;
    long long int xod=0;
    for(int i=0;i<5;i++){
        int x;
        cin >> x;
        player1.push(x);
    }
    for(int i=0;i<5;i++){
        int x;
        cin >> x;
        player2.push(x);
    }
    while(player1.cnt != 0 && player2.cnt !=0 && xod != 1000000){
        xod++;
        int a=player1.first->data;
        int b=player2.first->data;
        player1.pop();
        player2.pop();
        if((a>b && a != 9 && b != 0) || (a==0 && b == 9)){
            player1.push(a);
            player1.push(b);
        }
        else{
            player2.push(a);
            player2.push(b);
        }
    }
    if(player1.cnt == 0){
        cout << "second " << xod;
    }
    if(player2.cnt == 0){
        cout << "first " << xod;
    }
    if(xod == 1000000){
        cout <<"botva";
        return 0;
    }
    
    return 0;
}