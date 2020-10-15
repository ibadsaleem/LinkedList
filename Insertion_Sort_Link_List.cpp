#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class InsertionSort{
    Node *head, *tail;
    public:
    
    InsertionSort()
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

    void Insertion_Sort(){

        Node *ptr = head;
        while(ptr->next!=NULL)
        {
        Node *ptr2= ptr->next;
            while(ptr2!=NULL)
            {
                if(ptr->data > ptr2->data){
                    int temp=ptr->data;
                    ptr->data = ptr2->data;
                    ptr2->data = temp;
            }
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;     //3,2,1,0,5,9
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
    InsertionSort I;
    I.addnode_end(2);
    I.addnode_end(5);
    I.addnode_end(3);
    I.Insertion_Sort();
    cout << "Sorted: ";
    I.display();
}