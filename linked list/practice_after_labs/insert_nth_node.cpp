SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    int pos = position;
    SinglyLinkedListNode* temp = llist;
    int size_ll=0;
    while(temp != NULL){
        size_ll++;
        temp=temp->next;
    }
    temp = llist;
    while(pos-1 != 0){
        temp=temp->next;
        pos--;
    }
    SinglyLinkedListNode* zxc = new SinglyLinkedListNode(data);
    if(temp->next != NULL && temp != llist){
        zxc->next=temp->next;
        temp->next = zxc;
    }else if(temp == llist){
        zxc->next = temp;
        llist = zxc;
    }else if(temp->next == NULL){
        temp->next = zxc;
    }
    return llist;
}