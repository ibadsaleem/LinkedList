#include <iostream>
using namespace std;

class Node
{
public:
    Node(){};
    int data;
    Node *next;
    Node *prev;
};

class DLL
{
    Node *head, *tail;

public:
    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void addnode_beginning(int m)
    {
        Node *newnode = new Node;
        newnode->data = m;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = newnode;
        }

        else
        {
            newnode->next = head;
            newnode->prev = NULL;
            head = newnode;
        }
    }

    void addmiddle(int m, Node *target)
    {
        Node *newnode = new Node;
        newnode->data = m;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else //2,,3,4,5
        {
            Node *ptr = head;
            while (ptr != NULL)
            {
                Node *nextnode = ptr->next;
                if (target->prev == NULL)
                {
                    addnode_beginning(m);
                    break;
                }
                else if (target->next == NULL)
                {
                    addnode_end(m);
                    break;
                }
                else if (ptr == target)
                {
                    ptr->next = newnode;
                    newnode->next = nextnode;
                    newnode->prev = ptr;
                    break;
                }
                ptr = ptr->next;
            }
        }
    }
    void addmiddle_index(int m, int index)
    {
        int i = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (i == 0)
            {
                addnode_beginning(m);
                break;
            }
            else if (i == index)
            {
                addmiddle(m, ptr);
            }
            ptr = ptr->next;
            i++;
        }
    }

    void addnode_end(int m)
    {
        Node *newnode = new Node;
        newnode->data = m;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->prev = tail;           //2,3,4,5,
            tail->next = newnode;
            tail = newnode;
        }
    }

    void deletenode_end() //2,4,5,6,7
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->next->next == NULL)
            {
                tail = ptr;
                tail->next = NULL;
            }

            ptr = ptr->next;
        }
    }
    void deletenode_begin() //2,4,5,6,7
    {
        head = head->next;
    }

    void deletenode_middle(Node *target)
    {
        Node *ptr = head;
        while (ptr!=NULL)
        {
            if (ptr==target)                //2,3,4,5,6,7
            {
                if (target->next==NULL){
                    deletenode_end();
                }
                else if(target->prev==NULL){
                    deletenode_begin();
                }else
                ptr->prev->next = ptr->next;
            }
            ptr = ptr->next;
        }
    }

    void deletenode_index(int index)
    {
        int i = 0;
        Node *ptr = head;
         if (index==0)
            {
                deletenode_begin();
            }
        while(ptr!=NULL)
        {
           
            if (i==index)
            {
                deletenode_middle(ptr);
            }
            
            i++;
            ptr = ptr->next;
        }
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

    Node *gethead()
    {
        return head;
    }
};

int main()
{
    system("cls");
    DLL D;
    // D.addnode_end(2);
    // D.addnode_end(5);
    // D.addnode_end(8);
    // D.addnode_beginning(8);
    // D.addnode_beginning(4);
    // D.deletenode_begin();
    // D.deletenode_end();
    // D.deletenode_middle(D.gethead());
    // D.deletenode_index(1);
    // D.addnode_beginning(5);
    // D.addmiddle(65, D.gethead());
    // D.addmiddle_index(65, 0);
    // D.display();
}