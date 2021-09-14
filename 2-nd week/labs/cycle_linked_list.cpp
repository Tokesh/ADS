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

struct linked{
    int cnt;
    Nodes* first;
    Nodes* second;
    linked(){
        cnt=0;
        first=second=NULL;
    }
    void add(int x){
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
    void print(){
        Nodes* temp123 = first;
        while(temp123 != NULL){
            cout << temp123->data;
            if(temp123->next != NULL) cout << ' ';
            temp123 = temp123->next;
        }
    }
    void delete_dup(){
        Nodes* temp = first;
        for(Nodes* i = temp; i!= NULL;i=i->next){
            for(Nodes* j = i->next; j!= NULL;j=j->next){

                if(i->data == j->data){
                    if(j->next != NULL && j->prev != NULL){
                        j->prev->next = j->next;
                        j->next->prev = j->prev;
                    }
                    else if(j->next == NULL){
                        second = j->prev;
                        j->prev->next = NULL;
                    }
                }

            }   
        }
    }
};

int main(){
    linked ll1;
    ll1.add(1);
    ll1.add(2);
    ll1.add(4);
    ll1.add(1);
    ll1.add(3);
    ll1.add(4);
    ll1.print();
    ll1.delete_dup();
    cout << endl;
    ll1.print();
}

//LEETCODE
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && slow!= NULL && fast!=slow){
            if(fast->next != NULL && fast->next->next != NULL) fast= fast->next->next;
            else return false;
            slow = slow->next;
        }
        if(slow == fast) return true;
        return false;
    }
}; */