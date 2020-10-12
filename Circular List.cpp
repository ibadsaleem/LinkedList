#include <iostream>
using namespace std;
//Circular List implementation Muhammad Ibad Saleem
class Node
{
public:
    int data;
    Node *next;
};

class CLL
{

    Node *head, *tail;

public:
    CLL()
    {
        head = NULL;
        tail = NULL;
    }

    void addnode_end(int m)
    {
        Node *newnode = new Node;
        newnode->data = m;
        newnode->next = head;

        if (head == NULL && tail == NULL)
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

        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = head;
        }

        else
        {
            newnode->next = head;
            head = newnode;
            tail->next=newnode;
        }
    }

    void add_middle(int m, Node* target)
    {
        Node *newnode = new Node;
        newnode->data = m;
        newnode->next = NULL;
        Node *ptr = head;
        
        do
        {
            Node *nextnode = ptr->next;
            if(ptr==target){
            if (nextnode==head)
            {
                addnode_end(m);
            }
            else         //2,4,3,4,5,6
            {
                ptr->next = newnode;
                newnode->next = nextnode;
            }
            
        }
            ptr = ptr->next;
    	}while (ptr!=head);
    }
    void add_middle_index(int m,int index)
    {
        Node *ptr = head;
        int i = 0;
        do
        {
           if (index==0)
           {
               addnode_beginning(m);
               break;
           }
            if (i==index-1)
                add_middle(m,ptr);
            i++;
            ptr = ptr->next;
        }while(ptr!=head);
    }

    void deleteendnode(){
        Node *ptr = head;
        do
        {
            if (ptr->next->next==head)  //4,5
            {
                tail = ptr;
                tail->next = head;
                
            }
            ptr = ptr->next;
        }while(ptr!=head);
    }
    
     void deletebeginningnode(){
        Node *ptr = head;
        head = head->next;
        tail->next=head;
    }

    void deletemiddle(Node* index)
    {
        Node *ptr = head;
        do
        {
            if (ptr->next==index)
            {
                ptr->next = index->next;
            }
            ptr = ptr->next;
        }while(ptr!=head);
    }
    
    void deletemiddle_index(int index)
    {
        int i = 0;
        Node *ptr = head;
        if(index==0){
            deletebeginningnode();
        }
        
        do
        {
            
            if(i==index)
            {
                deletemiddle(ptr);
            }
            i++;
            ptr = ptr->next;
        }while(ptr!=head);
        if (index==i)
        {
            deleteendnode();
        }
    }
    void display()
    {
        Node *ptr = head;
        do {
      cout<<ptr->data <<" ";
      ptr = ptr->next;
   } while(ptr != head);
        
    }
    Node* gethead()
    {
        return head;
    }
};

int main()
{
    system("cls");
    CLL C;
//	    C.addnode_end(2);
//	    C.addnode_end(3);
//	    C.addnode_end(4);
//	    C.addnode_end(5);
//	    C.addnode_beginning(2);
//	    C.add_middle(5, C.gethead());
//	    C.add_middle_index(55, 2);
//	    C.addnode_beginning(3);
//	    C.addnode_beginning(4);
//	    C.addnode_beginning(5);
//	    C.deleteendnode();
//	    C.deletebeginningnode();				//array starts from 0 so is link list
//	    C.deletemiddle_index(2);
//	    C.display();
}
