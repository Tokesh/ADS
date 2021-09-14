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
};

int main(){
    linked ll1,ll2;
    linked ll3;
    ll1.add(1);
    ll1.add(2);
    ll1.add(4);
    ll2.add(1);
    ll2.add(3);
    ll2.add(4);
    Nodes* f1=ll1.first;
    Nodes* f2=ll2.first;
    while(f1 != NULL && f2!=NULL){
        if(f1->data > f2->data){
            ll3.add(f2->data);
            f2 = f2->next;
        }else if(f1->data < f2->data){
            ll3.add(f1->data);
            f1 = f1->next;
        }else{
            ll3.add(f1->data);
            ll3.add(f2->data);
            f1 = f1->next;
            f2 = f2->next;
        }
    }
    if(f1 != NULL){
        while(f1 != NULL){
            ll3.add(f1->data);
            f1 = f1->next;
        }
    }else if(f2 != NULL){
        while(f2 != NULL){
            ll3.add(f2->data);
            f2 = f2->next;
        }
    }
    ll3.print();
}

// LEETCODE SNIZU
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans_final = new ListNode(-1);
        ListNode* ans = ans_final;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                ans->next=l2;
                l2 = l2->next;
            }else if(l1->val < l2->val){
                ans->next = l1;
                l1 = l1->next;
            }else{
                ans->next = l1;
                l1 =l1->next;
            }
            ans = ans->next;
        }
        if(l1 != NULL){
            while(l1 != NULL){
                ans->next = l1;
                ans = ans->next;
                l1 = l1->next;
            }
        }else if(l2 != NULL){
            while(l2 != NULL){
                ans->next = l2;
                ans = ans->next;
                l2 = l2->next;
            }
        }
        return ans_final->next;
    }
}; */