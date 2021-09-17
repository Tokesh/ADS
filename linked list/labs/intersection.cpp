#include <iostream>
using namespace std;

struct Nodes{
    int data;
    Nodes* next;
    Nodes* prev;
    Nodes(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};

struct linked{
    int cnt;
    Nodes* first;
    Nodes* second;
    linked(){
        cnt = 0;
        first = second = NULL;
    }
    void add(int x){
        Nodes* temp = new Nodes(x);
        cnt++;
        if(first == NULL){
            first=second=temp;
        }else{
            second->next = temp;
            temp->prev = second;
            second = temp;
        }
    }
    
};

int ll_intersection(Nodes* ll1, Nodes* ll2){
        Nodes* temp1 = ll1;
        Nodes* temp2 = ll2;
        while(temp1 != NULL && temp2 != NULL && temp1->data == temp2->data){
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        if(temp1 != NULL && temp2 != NULL && temp1->data != temp2->data) return temp1->next->data;
        else return 0;
    }


int main(){
    linked ll1;
    linked ll2;
    ll1.add(6);
    ll1.add(2);
    ll1.add(4);
    ll2.add(1);
    ll2.add(2);
    ll2.add(4);
    cout << ll_intersection(ll1.second,ll2.second);
    return 0;
}



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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int cnt1=0,cnt2=0;
        while(temp1 != NULL){
            cnt1++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            cnt2++;
            temp2 = temp2->next;
        }
        while(headA != NULL && headB != NULL){
            if(cnt1 > cnt2){
                headA=headA->next;
                cnt2++;
            }else if(cnt1 < cnt2){
                headB=headB->next;
                cnt1++;
            }else{
                if(headA == headB) return headA;
                if(headA->next != NULL && headB->next != NULL && headA->next == headB->next) return headA->next;
                headA=headA->next;
                headB=headB->next;
            }
        }
        return NULL;
    }
}; */