#include <iostream>
using namespace std;

class stack
{
public:
    int data;
    stack *next;
    void peek();
    void push(int);
};

stack *head = NULL;

void stack::peek()
{
    stack *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void stack::push(int x)
{
    stack *nn = new stack;
    nn->data = x;
    nn->next = NULL;
    if (head == NULL)
        head = nn;
    else
    {
        nn->next = head;
        head = nn;
    }
}

void pop()
{
    stack *temp = head;
    if (head == NULL)
    {
        cout << "Underflow!\n";
        return;
    }
    head = head->next;
    cout << "Poped element is: " << temp->data << endl;
    delete (temp);
}

int main()
{
    stack obj;
    int ch, n;
    do
    {
        cout << "\n\nMENU\n------------\n";
        cout << "1.push\n2.pop\n3.peek\n4.exit\nENTER YOUR CHOICE: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element to be pushed: ";
            cin >> n;
            obj.push(n);
            break;

        case 2:
            pop();
            break;

        case 3:
            obj.peek();
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