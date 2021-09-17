
class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
        
        Node* zxc = new Node(x);
        if(head==NULL) return zxc;
        zxc->next = head;
        head = zxc;
        return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
        Node* zxc = new Node(x);
        if(head==NULL) return zxc;
        Node* temp = head;
        while(temp->next != NULL) temp=temp->next;
        temp->next = zxc;
        return head;
    }
};