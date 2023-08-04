// insert an element at the beginning of a linked list

#include <iostream>
using namespace std;

class linklist
{
private:
    struct node
    {
        int data;
        node *next;
    } * head;

public:
    linklist();
    void ins(int data);
    void show();
};

linklist::linklist()
{
    head = NULL;
}

void linklist::ins(int data)
{
    node *temp, *nn;
    temp = new node;
    temp->data = data;
    temp->next = head;
    head = temp;
}

void linklist::show()
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
    linklist l;
    int option, n;
    cout << "MENU\n-----------" << endl;
    do
    {
        cout << "\n\n1.Contiune insertion\n2.Display list\n3.Exit\n";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter element: ";
            cin >> n;
            l.ins(n);
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