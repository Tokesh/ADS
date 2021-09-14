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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/* class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->next != NULL && temp->val == temp->next->val){
                if(temp->next->next != NULL){
                    temp->next = temp->next->next;
                }else{
                    temp->next = NULL;
                }
            }
            if(temp->next != NULL && temp->val != temp->next->val) temp = temp->next;
            else if(temp->next == NULL) temp=temp->next;
            else if(temp->next != NULL && temp->val == temp->next->val && temp->next->next == NULL) temp->next = NULL;
        }
        return head;
    }
}; */