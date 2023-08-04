#include <iostream>
using namespace std;

class bubble
{
    public:
    int data;
    bubble *next;
    void ins(int);
    void show();
    void sort(int);
};

bubble *head=NULL;
bubble *header = new bubble;

void bubble::ins(int x)
{
    bubble *temp=head;
    bubble *nn= new bubble;
    nn->data=x;
    nn->next=NULL;
    if(temp==NULL)
    head=nn;
    else
    {
        for(;temp->next!=NULL;temp=temp->next);
        temp->next=nn;
    }
}

void bubble::show()
{
    bubble *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void bubble::sort(int len)
{
    bubble *temp=head;  
    for(int i=0;i<len-1;i++)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data > temp->next->data)
            {
                int t=temp->data;
                temp->data=temp->next->data;
                temp->next->data=t;
            }
            temp=temp->next;
        }
    }
}

int main()
{  
    bubble obj;
    int ch, n;
    header->data=0;
    do
    {
        cout << "\n\nMENU\n------------\n";
        cout << "1.push\n2.sort\n3.peek\n4.exit\nENTER YOUR CHOICE: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element to be pushed: ";
            cin >> n;
            obj.ins(n);
            header->data++;
            break;

        case 2:
            cout << "Sorted list: ";
            obj.sort(header->data);
            cout<<header->data<<" : ";
            obj.show();
            break;

        case 3:
            cout<<header->data<<" : ";
            obj.show();
            break;

        case 4:
            return 0;
            break;

        default:
            cout << "Invalid Input!! Try again.";
            break;
        }
    } while (true);
}