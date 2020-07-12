int getNthFromLast(Node *head, int n)
{
       n-=1;
       Node* cur=head;
       for(int i=0;i<n;i++)
       {
           if(!cur)
           {
               return -1;
           }
           cur=cur->next;
       }
       if(!cur)
       {
           return -1;
       }
       Node* ans=head;
       while(cur->next)
       {
           cur=cur->next;
           ans=ans->next;
       }
       return ans->data;
       
}