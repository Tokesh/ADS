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
    int cnt;
    Nodes* first;
    Nodes* second;
    deque(){
        first = NULL;
        second = NULL;
        cnt = 0;
    }
    void push_front(int data){
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
    void push_back(int data){
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
    deque zxc;
    int arr[100000];
    int ind_sv=0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x == 1){
            int k;
            cin >> k;
            zxc.push_front(k);
        }
        else if(x==2){
            int k;
            cin >> k;
            zxc.push_back(k);
        }else if(x==3){
            arr[ind_sv] = zxc.first->data;
            ind_sv++;
            zxc.pop_front();
        }else if(x==4){
            arr[ind_sv] = zxc.second->data;
            ind_sv++;
            zxc.pop_back();
        }
    }
    for(int i=0;i<ind_sv;i++){
        cout << arr[i];
        if(i != ind_sv-1) cout << ' ';
    }
}