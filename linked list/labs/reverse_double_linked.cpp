
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* p = NULL;
    DoublyLinkedListNode* c = llist;
    DoublyLinkedListNode* n;
    while(c!=NULL){
        n = c->next;
        c->next = p;
        p = c;
        c->prev = p;
        c=n;
    }
    return p;
}
