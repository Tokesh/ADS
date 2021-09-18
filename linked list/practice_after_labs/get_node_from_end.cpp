
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* temp = llist;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    temp = llist;
    while(cnt-positionFromTail-1 > 0){
        positionFromTail++;
        temp=temp->next;
    }
    return temp->data;
}
