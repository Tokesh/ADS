//LEETCODE
/* #include <stack> */
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
/* stack<int>zxc;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL){
            zxc.push(temp->val);
            temp = temp->next;
        }
        while(head != NULL){
            if(head->val != zxc.top()) return false;
            head = head->next;
            zxc.pop();
        }
        return true;
    }
}; */