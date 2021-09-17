
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head){
        if(head == NULL || head->next==NULL) return false;
        Node* slow = head;
        Node* fast = head;
        while(slow != NULL && fast != NULL){
            slow = slow->next;
            if(fast->next !=NULL) fast=fast->next->next;
            else return false;
            if(slow == fast) return true;
        }
        return false;
        
    }
};