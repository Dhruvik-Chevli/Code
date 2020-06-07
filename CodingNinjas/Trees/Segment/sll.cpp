#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
class linkedList
{
private:
    Node *head;
    Node *tail;
public:
    linkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void addNodeb(int data)
    {
        Node* node=new Node;
        node->data=data;
        node->next=NULL;
        if(head==NULL)
        {
            head=node;
            tail=node;
        }
        else
        {
            /*Node *temp=head;
            while(temp->next)
            {
                temp=temp->next;
            }*/
            tail->next=node;
            tail=tail->next;
            //cout<<"tails new data = "<<tail->data<<endl;
        }
        return;
    }
    void addNodef(int data)
    {
        Node* node=new Node;
        node->data=data;
        node->next=head;
        head=node;
        //if(tail=NULL)
            //tail=node;
    }
    void deletef()
    {
        //cout<<"Data at head = "<<head->data<<endl;
        if(head==NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        Node* temp=new Node;
        temp=head;
        head=temp->next;
        delete temp;
        //cout<<"New Data at head = "<<head->data<<endl;
    }
    void deleteb()
    {
        //cout<<"print \n";
        //cout<<"Data at tail = "<<tail->data<<endl;
        if(head==NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        if(head->next==NULL)
        {
            head=NULL;
            delete head;
            return;
        }
        Node* sl=new Node;
        sl=head;
        while ((sl->next)->next != NULL)
        {
            sl = sl->next;
        }
        //delete (sl->next);
        sl->next=NULL;
        tail=sl;
        //cout<<"new Data at tail = "<<tail->data<<endl;
    }
    void print()
    {
        Node* temp=head;
        if(temp==NULL)
        {
            cout<<"empty";
        }
        //cout<<"The linked list is : ";
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    linkedList ll;
    int n,i,m,f;
    //cout<<"Enter "<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>m;
        if(m==1)
        {
            cin>>f;
            ll.addNodeb(f);
        }
        if(m==2)
        {
            cin>>f;
            ll.addNodef(f);
        }
        if(m==3)
        {
            ll.deleteb();
        }
        if(m==4)
        {
            ll.deletef();
        }
        if(m==5)
        {
            ll.print();
        }
    }
}