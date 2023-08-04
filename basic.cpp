// make a linked list of 3 nodes

#include <iostream>
#include <conio.h>
using namespace std;

class linklist
{
private:
    // structure contains data and link
    struct node
    {
        int data;
        node *link;
    } * p;

public:
    linklist();
    void ins_at_end(int data);
    void ins_at_beg(int data);
    void ins_at_mid(int data, int loc);
    void ins();
    void dlt_ele(int data);
    void show();
    ~linklist();
};

int option, n, pos, action;

// initialise data member
// structure poinnter is assigned null
linklist::linklist()
{
    p = NULL;
}

// add node at end
void linklist::ins_at_end(int data)
{
    node *temp, *nn;

    // check if the list is empty or not
    if (p == NULL)
    {
        temp = new node;
        temp->data = data;
        temp->link = NULL;
        p = temp;
    }

    else
    {
        // goto last node
        temp = p;
        while (temp->link != NULL)
            temp = temp->link;
        // pointer is at the last node
        // now add a node at the end
        nn = new node;
        nn->data = data;
        nn->link = NULL;
        temp->link = nn;
    }
}

// add node at start
void linklist::ins_at_beg(int data)
{
    node *temp;

    // add new node
    temp = new node;
    temp->data = data;
    temp->link = p;
    p = temp;
}

// add node at a user given location
void linklist::ins_at_mid(int data, int loc)
{
    node *temp, *nn;
    temp = p;

    for (int i = 1; i < loc - 1; i++)
    {
        temp = temp->link;
        // check if the location is out of bound or not
        if (temp == NULL)
        {
            cout << "Out of  bound input!!" << endl;
            return;
        }
    }

    // insert new node
    nn = new node;
    nn->data = data;
    nn->link = temp->link;
    temp->link = nn;
}

// display the linked list
void linklist::show()
{
    node *temp = p;
    cout << endl;
    int i = 0; // here 'i' is the counter variable

    // traverse the entire linked list and print it
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->link;
        i++;
    }

    cout << "\nNumber of elemets in the linked list: " << i;
}

// insertion
void linklist::ins()
{
    linklist i;
}

// delete an element
void linklist::dlt_ele(int data)
{
    node *temp, *old;
    temp = p;
    while (temp != NULL)
    {
        // if data found
        if (temp->data == data)
        {
            // if the first  node is to be deleted
            if (temp == p)
                p = temp->link;
            else
                old->link = temp->link;
            delete temp;
            return;
        }

        // if data not found
        else
        {
            old = temp;
            temp = temp->link;
        }
    }
    cout << "\n\nElement " << data << " not found!!" << endl;
}

// free memory
// destructor
linklist::~linklist()
{
    node *temp;
    while (p != NULL)
    {
        temp = p->link;
        delete p;
        p = temp;
    }
}

int main()
{
    linklist l;

    cout << "MENU\n-----------" << endl;
    do
    {
        cout << "\n\n1.Insert\n2.Delete\n3.Display list\n4.Exit\n";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            cout << "ACTIONS\n-----------\n";
            cout << "\t1.insert at the beginning\n";
            cout << "\t2.insert at any given position\n";
            cout << "\t3.insert at the end\n";
            cin >> option;
            cout << "Enter element: ";
            cin >> n;
            switch (option)
            {
            case 1:
                l.ins_at_beg(n);
                break;
            case 2:
                cout << "Enter position of insertion: ";
                cin >> pos;
                if (pos == 0)
                    l.ins_at_beg(n);
                else
                    l.ins_at_mid(n, pos);
                break;
            case 3:
                l.ins_at_end(n);
                break;
            default:
                return 0;
                break;
            }
            break;
        }
        case 2:
            cout << "Enter the element to be deleted: ";
            cin >> n;
            l.dlt_ele(n);
            break;
        case 3:
            l.show();
            break;
        case 4:
            return 0;
        default:
            l.show();
            return 0;
            break;
        }
    } while (true);
    return 0;
}
