struct Node* reverseList(struct Node *head)
{
    Node* next;
    Node* prev=NULL;
    Node* cur=head;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}