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
		//insertion
		void display(){
			Node *ptr = head;
			while(ptr != NULL){
				cout << ptr->val << " ";
				ptr = ptr->next;
			}
			cout << endl;
		}
		
		void add_beech(int n ,Node *target ){
			Node *newnode = new Node;
			newnode->val = n ;
			newnode->next = NULL;
			
			Node *ptr = head;
			if(head==NULL && tail == NULL){
				head= newnode;
				tail = newnode;
			}
			
			while(ptr != NULL){
				if(ptr == target){
					Node *nextone = ptr->next;
					if(nextone == NULL){
						add_end(n);
					}else{
						ptr->next = newnode;
						newnode->next =  nextone;
						
					}
					
					
					
					
					break;
				}
				ptr=  ptr->next;
			}
			
		
			
			
				
			
			
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
		
		void add_beginning(int value){
			Node *newnode = new Node;
			newnode->val = value;
			newnode->next = NULL;
			
			if(head == NULL && tail ==NULL){
				
				head = newnode;
				tail = newnode;
			}else{
				newnode->next = head;
				head = newnode;
			}
			
			
			
			
			
			
		}
		
		
		
		
	
		Node * gethead(){
			return head;
		}
	
		
			void add_beech_index(int n ,int m ){
			Node *newnode = new Node;
			newnode->val = n ;
			newnode->next = NULL;
			
			Node *ptr = head;
			
			
			int i = 0;
			if(head==NULL && tail == NULL){
				head = newnode;
				tail = newnode;
			}
			
			
			while(ptr != NULL ){
				
				if(i == m-1){
					add_beech(n , ptr);
					
				}	
					
				
				i++;
				ptr=  ptr->next;
			}
			
		
			
			
				
			
			
		}
	
	
	
};


int main(){
	LinkedList l1;
	LinkedList l2;
	for(int i = 0 ; i< 10 ; i++){
		l1.add_beginning(i);
	}
	for(int i = 0 ; i< 10 ; i++){
		l2.add_end(i);
	}
	l2.add_beech(100 , l2.gethead()->next->next );	
	l2.add_beech_index( 500, 3);
	l2.display();
	
//	
//	
//	cout << "ulti list"<<endl;
//	l1.display();
//	cout << "ssedhi list" << endl;
//	l2.display();
//	
//	
	
	return 0;
}
