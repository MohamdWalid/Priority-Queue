#include <iostream>
using namespace std;
template<class t>
struct node
{
    t data;
    int priority;
    node *next;

};
template<class t>
class PriorityQueue
{
private:
    node<t> *head=NULL,*tail=NULL;
    int length=0;
public:
    void enqueue(t d,int p)
    {
     node<t> *newnode=new node<t>;
     newnode->data=d;
     newnode->priority=p;
     if(isempty())
     {
       head=tail=newnode;
     }
     else
     {
        node<t> *curr=head;
        tail->next=newnode;
        tail=newnode;
        t y;
        int z;
       for(int i=0;i<length;i++)
       {
          if(tail->priority>curr->priority)
          {
              y=tail->data;
              z=tail->priority;
              tail->priority=curr->priority;
              curr->priority=z;
              tail->data=curr->data;
              curr->data=y;
          }
          curr=curr->next;
       }
     }
     length++;
    }
    void dequeue()
    {
        if(isempty())
        {
         cout<<"Empty"<<endl;
        }
        else
        {
            node<t> *curr=head;
            head=head->next;
            delete curr;
            length--;
        }
    }
    bool isempty()
    {
        if(length==0)
        {
         return true;
        }
        else
        {
            return false;
        }
    }
    void first()
    {
        if(isempty())
        {
             cout<<"Empty"<<endl;
        }
        else
        {
            cout<<"First Element: "<<head->data<<endl;
        }
    }
    void clear1()
    {
        if(isempty())
        {
             cout<<"Empty"<<endl;
        }
        else
        {
            node<t> *curr;
            for(int i=0;i<length;i++)
            {
                curr=head;
                head=head->next;
                delete curr;
            }
            tail=NULL;
            length=0;
        }
    }
    void last()
    {
        if(isempty())
        {
             cout<<"Empty"<<endl;
        }
        else
        {
            cout<<"Last Element: "<<tail->data<<endl;
        }
    }
    void display()
    {
        if(isempty())
        {
            cout<<"Empty"<<endl;
        }
        else
        {
            node<t> *curr=head;
            for(int i=0; i<length; i++)
            {
                cout<<curr->data<<endl;
                curr=curr->next;
            }
        }

    }
    bool search1(t item)
    {
        if(isempty())
        {
            cout<<"Empty"<<endl;
        }
        else
        {
            node<t> *curr=head;
            for(int i=0;i<length;i++)
            {
                if(curr->data==item)
                {
                    return true;
                    break;
                }
                else if(curr==tail)
                {
                    return false;
                }
                curr=curr->next;
            }
        }
    }

};
int main()
{
    PriorityQueue<int> p;
    int choice;
    int choice2;
    int data;
    int priority;
    while(true)
    {
        do
        {
            cout<<"[1] Enqueue"<<endl<<"[2] Dequeue"<<endl<<"[3] print first element"<<endl<<"[4] print last element"<<endl<<"[5] Search"<<endl<<"[6] print queue"<<endl<<"[7] clear"<<endl;
            cout<<"Enter choice: ";
            cin>>choice;
        }
        while(choice<1 || choice>7);
        switch(choice)
        {
        case 1:
            cout<<"Enter data: ";
            cin>>data;
            cout<<"Enter priority: ";
            cin>>priority;
            p.enqueue(data,priority);
            break;

        case 2:
            p.dequeue();
            break;

        case 3:
            p.first();
            break;

        case 4:
            p.last();
            break;

        case 5:
            cout<<"Enter data: ";
            cin>>data;
            if(p.search1(data))
            {
                cout<<"Element is found"<<endl;
            }
            else
            {
                cout<<"Element not found"<<endl;
            }
            break;

        case 6:
            p.display();
            break;

        case 7:
            p.clear1();
            break;
        }
        do
        {
          cout<<"[1] continue"<<"[2] stop"<<endl;
          cin>>choice2;
        }while(choice2!=1 && choice2!=2);
        if(choice2==2)
        {
            break;
        }

    }


    return 0;
}
