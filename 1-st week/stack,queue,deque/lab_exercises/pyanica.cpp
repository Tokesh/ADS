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

struct que{
    int cnt;
    Nodes* first;
    Nodes* second;
    que(){
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
    int front(){
        return first->data;
    }
    bool empty(){
        return (first == NULL);
    }
};

int main(){
    que q1;
    que q2;
    long long num=0;
    int n;
    for(int i=0;i<5;i++){
        cin >> n;
        q1.push(n);
    }
    for(int i=0;i<5;i++){
        cin >> n;
        q2.push(n);
    }
    while(num<=100000 && !q1.empty() && !q2.empty())
    {   
        num++;
        if(q1.front() == 9 and q2.front() == 0)
        {
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop();
            q2.pop();
            continue;
        }
        if(q1.front() == 0 and q2.front() == 9)
        {
            q1.push(q1.front());
            q1.push(q2.front());
            q1.pop();
            q2.pop();
            continue;
        }
        if(q1.front() > q2.front())
        {
            q1.push(q1.front());
            q1.push(q2.front());
            q1.pop();
            q2.pop();
        }
        else
        {
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop();
            q2.pop();
        }
    }
    if(num>100000)
    {
        cout << "botva";
    }
    else if(q1.empty())
    {
        cout << "second " << num;
    }
    else
    {
        cout << "first " << num;
    }
    return 0;

}