#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

class Swap{
	Node *head,*tail;
	public:
		Swap()
		{
			head=NULL;
			tail=NULL;
		}
		void addNode_end(int m)
		{
		   Node *newnode=new Node;
			newnode->data=m;
			newnode->next=NULL;
			Node *ptr=head;
			if (head==NULL && tail==NULL)
			{
				head=newnode;
				tail=newnode;
			}
			else{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
		void swap(Node *n1,Node *n2){
			Node* temp=n1->next;
			Node*ptr=head;
			while(ptr->next!=n2)
			{
				ptr=ptr->next;
			}
			
			if (n1==head && n2==tail)		//2,3,1,7
			{	
				n2->next = temp;
				ptr->next = n1;
				n1->next=NULL;
				tail = n1;
				head = n2;
				return;
			}
			else if(n1==head)			//2,3,1,7
			{
				Node* tmp=n2->next;
				n2->next=temp;
				temp->next=n1;
				n1->next=tmp;
				head=n2;
				return;		
			}
			else if (n2==tail)		
			{
				Node *prev=head;
				while(prev->next!=n1)
				{
					prev=prev->next;
				}
				prev->next=n2;
				n2->next=ptr;
				ptr->next=n1;
				n1->next=NULL;
				tail=n1;
				
				return;
			}
			else{								//	2	,3	,1	,7	,8
				Node *prev=head;				// prev n1  ptr n2
				while(prev->next!=n1)
				{
					prev=prev->next;
				}
				Node *t=n2->next;
				prev->next=n2;
				n2->next=ptr;
				ptr->next=n1;
				n1->next=t;
				return;
							
			}
		}
	
		void display()
		{
			Node *ptr=head;
			while(ptr!=NULL)
			{
				cout<<ptr->data<<" ";
				ptr=ptr->next;
			}
		}
		
		Node* gethead()
		{
			return head;
		}
		Node* gettail()
		{
			return tail;
		}

};



int main()
{
	Swap S;
	S.addNode_end(2);
	S.addNode_end(3);
	S.addNode_end(1);
	S.addNode_end(7);
	S.addNode_end(8);
	S.swap(S.gethead(),S.gettail();//swapping head & tail
	S.swap(S.gethead(),S.gethead()->next->next);//swapping head with any value
	S.swap(S.gethead()->next,S.gettail());//swapping tail with any value
	S.swap(S.gethead()->next,S.gethead()->next->next);//checking two middle values
	
	S.display();
}
