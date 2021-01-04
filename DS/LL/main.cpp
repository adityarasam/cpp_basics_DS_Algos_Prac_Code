
#include <iostream>


using namespace std;

struct Node
{
    int data;
    struct Node * next;  
};


struct Node* head;
struct Node* head1;
struct Node* head2;
void PrintList()
{
	struct Node* temp = head;

	cout<<"List is:"<<endl;

	while(temp != NULL)
		{
   		cout<<temp->data<<"->";
		//cout<<temp<<"->";
   		temp = temp->next;

		}
	cout<<"NULL"<<endl;

}


Node* Insert_end (int val)
{
	Node* temp = new Node;
    Node* trav = new Node;

	if(head == NULL)
	{
		temp->next = head;
		head = temp; 	
	} 
	else
	{
		trav = head;
		while(trav->next != NULL )
		{
			trav = trav->next;
		}	

		trav->next = temp;
		temp->next = NULL;
	}

	temp->data = val;

return head;

} 

Node* Insert_nth(int n, int val)
{
	Node* temp = new Node;
    Node* new_node = new Node;
	new_node->data = val;
	temp = head;
	int list_size = 0;
	
	while(temp != 0)
	{
		list_size = list_size + 1;	
		temp = temp->next;
	}
	cout<<list_size<<endl;
	temp = head; 

	if((n <= 0)||(n>list_size+1))
	{
		cout<<"Invalid Position"<<endl;
		return head;	
	}
	else if(n == 1)
	{
		new_node->next = temp;
		head = new_node;
		cout<<temp->data<<endl;
		cout<<new_node->data<<endl;
	}
	else if (n==2)
	{
		new_node->next = temp->next;
		temp->next = new_node;
	}
	else
	{
	for(int i=1; i<n-1; i++)
	{
		temp = temp->next;	
	}
	new_node->next = temp->next;
	temp->next = new_node;
	}
return head;

}

Node* Delete_node(int p){
	Node* traverser = head;
	Node* current_node;
	
	if(p==1)
	{
		head = traverser->next;
		delete(traverser);
		return head;
	}
	
	for (int i =1; i < p-1; i++){       //----Traversing to p-2 position
    	traverser = traverser->next;
    }
	
	current_node = traverser->next;
	traverser->next = traverser->next->next;
	delete(current_node);

	return head;
}

Node* Partition(int val){
	Node* tempLess = new Node;
	Node* tempMore = new Node;
	Node* headMore =new Node;
	Node* headLess =new Node;
	Node* curr = new Node;
	
	headLess = NULL;
	headMore = NULL;
	curr = head;
	
	int i =	1;
	int j = 1;
	while (curr != NULL){
		if(curr->data<val){
			//cout<<"less"<< curr->data<<endl;
			if(i==1)
				{
					tempLess = curr;		
					headLess = tempLess;	
					i++;	
				}
			else{
					tempLess->next=curr;
					tempLess = curr;
					//tempLess = tempLess->next;
				}
			curr=curr->next;
			}
		else{
			//cout<< "more"<<curr->data<<endl;
			if(j==1)
				{
					tempMore = curr;		
					headMore = tempMore;	
					j++;	
				}
			else{
					tempMore->next=curr;
					tempMore=curr;
					//tempMore = tempMore->next;
				}
			curr=curr->next;
			}		
}

if(headLess == NULL){
	//cout<<"Done";
	return headMore;
}

tempLess->next = headMore;
cout<<"headless"<<headLess<<endl;
return headLess;
}


//--------SUM Reverse order digit---------
Node* Sum_rev_list()
{
	Node* temp1 = new Node;
	Node* temp2 = new Node;
	
	temp1 = head1;
	temp2 = head2;
	int carry = 0;
	while(temp1!=0){
		temp1->data = temp1->data + temp2->data + carry;
		if (temp1->data > 10){
			carry = temp1->data/10;
			temp1->data = temp1->data % 10;
			}
		else{
			carry = 0;			
			}
		temp1 = temp1->next;	
		}
	Node* temp_carry = new Node;
	if(carry != 0)
		
		temp_carry->data = carry;
		temp1->next = temp_carry;
return head1;
}




int main()
{
int a =2;
if(a==1){
cout<<"==================Main Started==================="<<endl;
head = NULL;
for (int i=0;i<10;i++)
{
	head = Insert_end(i);
	
}

PrintList();

head = Insert_nth(5, 10);
PrintList();

//head=Delete_node(1);
//PrintList();
cout<<13/10<<endl;
cout<<"Part"<<endl;
head = Partition(0);
PrintList();
}

//----Sum
/* 
head1 = Insert_end(1);
head1 = Insert_end(2);
head1 = Insert_end(3);
head = head1;
PrintList();

head2 = Insert_end(1);
head2 = Insert_end(2);
head2 = Insert_end(3);

head = Sum_rev_list();
PrintList();
*/


return 0;
}
