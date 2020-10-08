#include<iostream>
using namespace std;



class  Node{
	public:
		int val;
		Node *next;
	
};

class LinkedList{
	
	Node *head , *tail;
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		
		
	
		
		
		void add_end(int n){
			//create a node
			Node *newnode = new Node;
			newnode->val = n ;
			newnode->next = NULL;
			
			if(head == NULL && tail == NULL){
				head = newnode;
				tail = newnode;
			}else{
				
				tail->next = newnode;
				tail = newnode;
			}
			
		}
		
		
		int delete_element(int n){
			
			Node *ptr = head;
			Node *prev = head;
			if(head == NULL){
				cout << "no elemetn to delddet";
				return 0;
			}
			
			if(ptr->val == n){
				head = ptr->next;
				return 1;
					 
			}
			
			
			while(ptr->next->next != NULL){
				
				if(ptr->next->val == n){
					ptr->next = ptr->next->next;
					
					return 1;
				}	
				
				
					
				ptr = ptr->next;	
				
			}
			if(ptr->next->val == n){
				tail = ptr;
				tail->next = NULL;
				return 1;
			}
			
			return 0;
			
		}
		
			void display(){
				for(Node *ptr = head ; ptr != NULL ; ptr= ptr->next){
					cout << ptr->val << " ";
	}
				cout << endl;
			}

};



int main(){
	
	LinkedList l1;
	for(int i =1 ; i <= 10 ; i++){
		l1.add_end(i);
		
	}
	for(int i = 0 ; i < 20 ; i++){
		cout << "at i = " << i+1 << "the result is "  << (l1.delete_element(i+1) == 1 ? "true" : "false") ;
		cout << endl;
	}
	l1.display();
	
	
	return 0;
}
