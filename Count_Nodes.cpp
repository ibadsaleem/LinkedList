#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CountNodes
{
    Node *head, *tail;

public:
    CountNodes()
    {
        head = NULL;
        tail = NULL;
    }
    void addnode_end(int m)
    {
        Node *newnode = new Node;
        newnode->data = m;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    int count()
    {
        int i = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            i++;
            ptr = ptr->next;
        }

        return i;
    }
    int specificcount(int m)
    {
        int i = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data==m){ i++;}
            ptr = ptr->next;
        }

        return i;
    }
};

int main()
{
    system("cls");
    CountNodes C;
    for (int i = 0; i < 10; i++)
    {
        C.addnode_end(i);
    }
    cout<< "Number of Nodes = " << C.count()<<endl;
    cout<< "Number of Specific Nodes = " << C.specificcount(2)<<endl<<endl;
    system("pause");
}