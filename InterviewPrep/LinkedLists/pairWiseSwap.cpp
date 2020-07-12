Node* pairWiseSwap(struct Node* head) {
    // struct Node* temp=head;
    Node* cur=head;
    Node* prev=NULL;
    Node* next = NULL;
    int count=0;
    while(cur and count<2)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        count++;
    }
    if(next)
    {
        head->next=pairWiseSwap(next);
    }
    return prev;
}
