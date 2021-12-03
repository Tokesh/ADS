#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
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

struct linked{
    Nodes* first;
    Nodes* second;
    int cnt;
    linked(){
        first = second = NULL;
        cnt = 0;
    }
    void push_back(int x){
        cnt++;
        Nodes* temp = new Nodes(x);
        if(first == NULL){
            first=second=temp;
        }else{
            second->next = temp;
            temp->prev = second;
            second = temp;

        }
    }
    void push_front(int x){
        cnt++;
        Nodes* temp = new Nodes(x);
        if(first == NULL){
            first=second=temp;
        }else{
            temp->next = first;
            first->prev = temp;
            first = temp;
        }
    }
    bool find_1(int x){
        Nodes* temp = first;
        while(temp != NULL){
            if(temp->data == x){
                return true;
            }
            temp = temp->next;
        }
        return false;
        
    }
    Nodes* find_2(int x){
        Nodes* temp = first;
        while(temp != NULL){
            if(temp->data == x){
                return temp;
            }
            temp = temp->next;
        }
        cout << temp;
        return NULL;
        
    }
    void dl(Nodes* n){
        cnt--;
        if(n == NULL) return;


        if(n->prev == NULL && n->next == NULL){
            first=second=NULL;
        } else if(n->prev != NULL && n->next != NULL){
            n->prev->next = n->next;
            n->next->prev = n->prev;
        } else if(n->prev == NULL){
            first = first->next;
            n->next->prev = NULL;
        } else if(n->next == NULL){
            second = second->prev;
            n->prev->next = NULL;
        }
    }
    void print(){
        Nodes* temp = first;
        while(temp != NULL){
            cout << temp->data;
            temp = temp->next;
            if(temp != NULL) cout << ' ';
        }
    }
    void sort_byd(){
        Nodes* a;
        Nodes* b;
        int temp;
        for(Nodes* i=first;i!=NULL;i=i->next){
            for(Nodes* j=i->next;j!=NULL;j=j->next){
                if(i->data > j->data){
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
    Nodes* joinll(Nodes* h1 ,Nodes* h2){
        if(h1==NULL){
            return h2;
        }
    
        if(h2 == NULL){
            return h1;
        }
        Nodes* head;
        Nodes* tail;
        
        if(h1->data <= h2->data){
            head = h1;
            tail = h1;
            h1=h1->next;
        }else{
            head = h2;
            tail = h2;
            h2=h2->next;
        }
        while(h1!=NULL && h2!=NULL){
            if(h1->data <= h2->data){
                tail->next = h1;
                h1->prev = tail;
                tail = h1;
                h1=h1->next;             
            }else{
                tail->next = h2;
                h2->prev = tail;
                tail = h2;
                h2=h2->next;
            }
        }
        if(h1==NULL){
            tail->next = h2 ;
            h2->prev = tail;
        }
        else{
            tail->next = h1 ; 
            h1->prev = tail;
        }
        return head;
    }
    Nodes* mergeSort(Nodes *head) {
    
        if(head==NULL || head->next==NULL)
        {
            return head ;
        }
        
        Nodes* slow = head ;
        Nodes* fast = head->next ;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next ;
            fast =fast->next->next ;
        }
        Nodes*h2 = slow->next ;
        slow->next =NULL ;
        
        head = mergeSort(head) ;
        h2 = mergeSort(h2) ; 
        
        return joinll(head , h2) ;
    }
};


int main(){
    /* freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout); */
    linked ll;
    ll.push_back(4);
    ll.push_back(1);
    ll.push_back(8);
    ll.first = ll.mergeSort(ll.first);
    ll.print();
}