#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

class Sorting{
    Node *head, *tail;

    public:
    Sorting()
    {
        head = NULL;
        tail = NULL;
    }
    
    void addnode_end(int m)
    {
        Node *newnode = new Node;
        newnode->data = m;
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
    void addnode_beginning(int m)
    {
        Node *newnode = new Node;
        newnode->data = m;
        newnode->next = NULL;
        if (head==NULL && tail==NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            head->next = head;
            head = newnode;
        }
        
    }

    void Sort_List_Ascending()
    {
        Node *ptr = head;
        while (ptr!=NULL)
        {
            Node *min = ptr;
            Node *r = ptr->next;

            while (r!=NULL)
            {
                if (min->data > r->data)
                    min = r;

                r = r->next;
            }

            // Swap Data
            int x = ptr->data;
            ptr->data = min->data;
            min->data = x;
            ptr = ptr->next; 
    } 
    }
    void Sort_List_Descending()
    {
        Node *ptr = head;
        while (ptr!=NULL)
        {
            Node *max = ptr;
            Node *r = ptr->next;

            while (r!=NULL)
            {
                if (max->data < r->data)
                    max = r;

                r = r->next;
            }
            
            //Swapping takes place
            
            int x = ptr->data;
            ptr->data = max->data;
            max->data = x;



            ptr = ptr->next; 
        } 
}

    void display()
    {
        Node *ptr= head;
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
    Sorting Sort;
    Sort.addnode_end(2);
    Sort.addnode_end(4);
    Sort.addnode_end(1);
    Sort.addnode_end(9);
    Sort.addnode_end(5);
    cout << endl;
    Sort.Sort_List_Descending();
    Sort.Sort_List_Ascending();
    Sort.display();
}