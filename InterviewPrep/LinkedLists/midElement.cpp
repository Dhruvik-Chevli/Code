int getMiddle(Node *head)
{
    if(!head)
        return -1;
    Node* slow = head;
    Node* fast = head;
    while(fast->next and fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast->next)
    {
        return slow->next->data;
    }
    return slow->data;
   
}