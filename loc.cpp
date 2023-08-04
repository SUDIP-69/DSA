// insert element at any  location in linked list

#include <iostream>
using namespace std;

class linkedlist
{
private:
    struct node
    {
        int data;
        struct node *next;
    } * head;

public:
    linkedlist();
    void create(int data);
    void ins(int data, int pos);
    void show();
};

linkedlist::linkedlist()
{
    head = NULL;
}

void linkedlist::create(int data)
{
    node *temp;
    temp=new node;
    temp=head;
    temp->data=data;
    temp->next=
}
void linkedlist::ins(int data, int pos)
{
    node *temp, *nn;
    temp = new node;
    temp = head;

    for (int i = 1; i < pos-1; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "Out of Bound";
            return;
        }
    }
    nn = new node;
    nn->data = data;
    nn->next = temp->next;
    temp->next = nn;
}

void linkedlist::show()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

int main()
{
    linkedlist l;
    int option, n, pos;
    cout << "MENU\n-----------" << endl;
    do
    {
        cout << "\n\n1.Contiune insertion\n2.Display list\n3.Exit\n";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter element: ";
            cin >> n;
            l.ins(n,pos);
            break;
        case 2:
            l.show();
            return 0;
        case 3:
            return 0;
        default:
            l.show();
            return 0;
            break;
        }
    } while (true);
    return 0;
}