int getLength(Node* cur)
{
    int n=0;
    Node* head=cur;
    
    while(head)
    {
        n++;
        head=head->next;
    }
    return n;
}
int intersectPoint(Node* head1, Node* head2)
{
    int n1=getLength(head1);
    int n2=getLength(head2);
    // cout<<n1<<" "<<n2<<" "<<head1->data<<" "<<head2->data<<"\n";
    if(n1>n2)
    {
        int k=n1-n2;
        for(int i=0;i<k;i++)
        {
            head1=head1->next;
        }
    }
    else {
        int k=n2-n1;
        for(int i=0;i<k;i++)
        {
            head2=head2->next;
        }
    }
    // cout<<head1->data<<" "<<head2->data<<"\n";
    while(head1 and head2)
    {
        if(head1==head2)
        {
            return head1->data;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return -1;
}