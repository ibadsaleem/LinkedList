#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
};

class BubbleSort
{
    Node *head,*tail;

public:
    BubbleSort()
    {
        head = NULL;
        tail = NULL;
    }

    void addnode_end(int m)
    {
        Node *newnode = new Node;
        newnode->data=m;
        newnode->next = NULL;
        if (head==NULL && tail==NULL)
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

    void Bubble_Sort()
    {
        //Conditions:
        //(ptr->data<ptr2->data)Descending (larger to smaller)
        //(ptr->data>ptr2->data)Ascending (smaller to larger)

        Node *ptr = head;
        while(ptr->next!=NULL)
        {
            Node *ptr2 = ptr->next;
            while(ptr2!=NULL)
            {
                if (ptr->data>ptr2->data)                   
                {
                    int tmp;
                    tmp = ptr->data;
                    ptr->data = ptr2->data;
                    ptr2->data = tmp;
                }
                ptr2 = ptr2->next;
            }
             ptr = ptr->next;
        }
    }
    void display()
    {
        Node *ptr = head;
        while(ptr!=NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};

int main()
{
    system("cls");
    BubbleSort B;
    B.addnode_end(2);
    B.addnode_end(5);
    B.addnode_end(3);
    B.Bubble_Sort();
    cout << "Sorted: ";
    B.display();
}