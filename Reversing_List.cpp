#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Reversing
{
    Node *head, *tail;

public:
    Reversing()
    {
        head = NULL;
        tail = NULL;
    }

    void add_end(int m)
    {
        Node *newnode = new Node;
        newnode->data = m;
        newnode->next = NULL;
        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
    }
    
    void Reverse_List() 
    { 
     
        Node* ptr = head; 
        Node *prev = NULL, *next = NULL; 
  
        while (ptr != NULL) { 
            next = ptr->next; 
            ptr->next = prev; 
            prev = ptr; 
            ptr = next; 
        } 
        head = prev; 
    } 
    
    
    
    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }


};

int main()
{
    system("cls");
    Reversing R;
    R.add_end(2);
    R.add_end(8);
    R.add_end(3);
    R.add_end(9);
    R.Reverse_List();
    R.display();


}