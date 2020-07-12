void remove(Node* loopNode, Node* head)
{
    Node* p1=head;
    Node* p2;
    while(1)
    {
        p2=loopNode;
        while(p2!=loopNode and p2!=p1)
        {
            p2=p2->next;
        }
        if(p2==p1)
            break;
        p1=p1->next;
    }
    p2->next=NULL;
}
void removeLoop(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(slow and fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            remove(slow,head);
        }
    }
}