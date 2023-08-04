#include <iostream>
using namespace std;

class insertion
{
public:
    int data;
    insertion *next;
    void ins(int);
    void show();
};

insertion *head = NULL;
insertion *header = new insertion;

void insertion::ins(int x)
{
    insertion *temp = head;
    insertion *nn = new insertion;
    nn->data = x;
    nn->next = NULL;
    if (temp == NULL)
        head = nn;
    else
    {
        for (; temp->next != NULL; temp = temp->next)
            ;
        temp->next = nn;
    }
}

void insertion::show()
{
    insertion *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void swap(insertion *a, insertion *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void sort()
{
    insertion *nxt = head->next;
    while (nxt != NULL)
    {
        insertion *curr = head;
        while (curr != nxt)
        {
            if (nxt->data < curr->data)
                swap(curr, nxt);

            curr = curr->next;
        }
        nxt = nxt->next;
    }
}

int main()
{
    insertion obj;
    int ch, n;
    header->data = 0;
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
            sort();
            cout << header->data << " : ";
            obj.show();
            break;

        case 3:
            cout << header->data << " : ";
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