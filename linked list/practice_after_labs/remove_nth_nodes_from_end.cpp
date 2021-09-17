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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt=0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        if(cnt == 1) return NULL;
        if(cnt-n-1 < 0) return head->next;
        ListNode* temp1=head;
        while(cnt-n-1 != 0){
            cnt--;
            temp1=temp1->next;
        }
        if(temp1->next != NULL && temp1->next->next != NULL) temp1->next = temp1->next->next;
        else if(temp1->next != NULL && temp1->next->next == NULL) temp1->next = NULL;
        return head;
        
    }
};