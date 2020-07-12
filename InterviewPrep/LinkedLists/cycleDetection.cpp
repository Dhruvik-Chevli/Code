bool detectLoop(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast and fast->next and slow)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}