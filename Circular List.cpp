	#include<iostream>
	using namespace std;
	
	//Muhammad Ibad Saleem 19K0220 E1 Q3 Circular List
	//Loop will run infinite due to the reason that the tail will be pointing to the head everytime 
	//implemented Add+Delete (Beginning,Middle,End)
	
	
	
	
	
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
			void display(){
				Node *ptr = head;
				while(ptr != NULL){
					cout << ptr->val << " ";
					ptr = ptr->next;
				}
				cout << endl;
			}
			
			void add_middle(int n ,Node *target ){
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
							tail->next=head;
					}
						break;
					}
					ptr=  ptr->next;
				}
			}
			
			
			void add_end(int n){
				Node *newnode = new Node;
				newnode->val = n ;
				newnode->next = head;
				
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
					tail->next=head;
				}		
			}
				
				
				int delete_element(int n){
				
				Node *ptr = head;
				Node *prev = head;
				if(head == NULL){
					cout << "EMPTY";
					return 0;
				}
				
				if(ptr->val == n){
					head = ptr->next;
					return 1;			 
			}
			
				while(ptr->next->next != head){
					
					if(ptr->next->val == n){
						ptr->next = ptr->next->next;
						
						return 1;
					}	
					
					
						
					ptr = ptr->next;	
					
				}
				if(ptr->next->val == n){
					tail = ptr;
					tail->next = head;
					return 1;
				}
				
				return 0;
				
			}
			
			Node * gethead(){
				return head;
			}	
	};
	
	
	
	int main(){
		
		LinkedList l1;
		LinkedList l2;
	
		for(int i = 0 ; i< 10 ; i++){
			l1.add_beginning(i);
		}
		l1.add_end(98);
		l1.add_middle(100 , l1.gethead()->next->next );	
		l1.delete_element(98);
		l1.display();
		
		
		return 0;
	}
