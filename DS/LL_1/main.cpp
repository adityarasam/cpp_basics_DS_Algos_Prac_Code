#include <iostream>
#include <stdlib.h>

using namespace std;


struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

 
/*
temp is pointer of type Node defined above
head is pointer of type Node pointing to head of the list
tmep = head takes content of head thats address  of first

 */


void Print_List(){

    struct Node* temp = head;

    cout<<"List is:";

    while (temp != NULL){

        cout<<temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl;
}



void Print_List_recur(Node* p){

    if (p==NULL){           //----EXIT condition
        return;
    }
    //cout<<p->data<<" ";          //-----Prints the node
    //Print_List_recur(p->next);    //-----Enters the recursion


    //Reverse the order to print the list in reverse order

    Print_List_recur(p->next);    //-----Enters the recursion
    cout<<p->data<<" ";          //-----Prints the node

}

Node* Reverse(Node *head)
{
  // Complete this method
    Node* temp1 = head;         //CURRENT
    Node* temp2;                //NEXT
    Node* temp3 = NULL;         //PREVIOUS

    while(temp1!=NULL){

        temp2 = temp1->next;    //Saving link to next node
        temp1->next = temp3;    //Reversing link of current node
        temp3 = temp1;          //Saving the previous node for step 2 of next iteration
        temp1 = temp2;          //Advancing to next node saved in 1

    }
    head = temp3;
    return head;

}


Node* Reverse(Node *head)
{
  // Complete this method
    Node* CURRENT = head;         //CURRENT
    Node* NEXT;                //NEXT
    Node* PREVIOUS = NULL;         //PREVIOUS

    while(CURRENT!=NULL){

        NEXT = CURRENT->next;    //Saving link to next node
        CURRENT->next = PREVIOUS;    //Reversing link of current node
        PREVIOUS = CURRENT;          //Saving the previous node for step 2 of next iteration
        CURRENT = NEXT;          //Advancing to next node saved in 1

    }
    head = PREVIOUS;
    return head;

}


void Insert_front (int x){

    Node* temp = new Node;

    temp->data = x;         //Updating the data
    temp->next = head;      //Updating the current node next pointer
    head = temp;            //Updating the head node pointer

}

void Insert_end(int x){
    Node* temp = new Node;
    Node* temp2 = new Node;

    //----------------------CHECK for EMPTY LIST--------------------
    if (head == NULL){
        temp->next = NULL;
        head = temp;
    }

    //----------------------NOT AN EMPTY LIST - Insertion of new NODE at THE END-----------
    else{
        temp2 = head;

    while (temp2->next != NULL){        //-----Traversing the list to its end
        temp2 = temp2->next;
    }


    temp2->next = temp;                 //-----Updating the pointer of existing last node
    temp-> next = NULL;                 //-----Updating new node pointer to NULL
    }

    temp->data = x;                     //-----Updating the data

}

//Wrong
void Insert_InBetween(int x, int p){    //x is the data, p is the position to be inserted at
struct Node* temp = new Node;
struct Node* traverser = head;

for (int i =1; i< p-1; i++){        //start at 1 and i < p-1 or i <= p-2    should stop updating once traverser reaches previous node
    traverser = traverser->next;
}

temp->next = traverser->next;
traverser->next = temp;

temp->data = x;
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

void Delete_node(int p){    // p is the position to be deleted

    Node* traverser = head;
    if (p==1){                      // For 1st position

        head = traverser->next;
        free(traverser);
        return;
    }

    for (int i =1; i < p-1; i++){       //----Traversing to p-2 position
    traverser = traverser->next;
    }

    Node* temp = traverser->next;       //updating the next address to temp which is node to be deleted

    traverser->next = temp->next;       //Linking previous node next to node  after the node to be deleted

    free(temp);
}

Node* Delete(Node *head, int position)
{
  // Complete this method

    Node* traverser = head;

    if (head == NULL){
        return NULL;
    }
    if (position==0){
        head = traverser->next;
        free(traverser);
        return head;
    }
    else if (position == 1){
        Node* currentNode = traverser->next;
        traverser->next = currentNode->next;
        return head;
    }
    else{
    for (int i=0; i< position-1;i++){
        traverser = traverser->next;
    }
    Node* currentNode = traverser->next;
    traverser->next = currentNode->next;

    free(currentNode);

    return head;

    }
}

Node* InsertNth(Node *head, int data, int position)  //Returning head value
{
  // Complete this method only
  // Do not write main function.

    Node* temp = new Node;
    temp-> data = data;

    Node* temp1 = head;

    if (head == NULL) {


        temp-> next = head;
        head = temp;
        return temp;
    }
    if (position ==0){

        temp->next = head;
        head = temp;
        return head;
    }


    else if (position == 1){
        temp-> next = temp1->next;
        temp1->next = temp;
        return head;
    }
    else{
        for (int i =0; i<= position-2; i++){
        temp1 = temp1->next;

    }

    temp-> next = temp1->next;
    temp1->next = temp;

    return head;

    }




}


//Floyd's cycle finding algorithm - C++


bool has_cycle(Node * head)
{
// Complete this function
// Do not write the main method

Node * slow_ptr = head;
Node * fast_ptr = head;

while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;
    if (slow_ptr == fast_ptr){
    return true;
    }
    }
    return false;
}



//-------------------------------------------------------

//Finding if its a binary tree or not
bool checkBST(Node* root, int minVal, int maxVal){
       if (root == NULL){
           return true;
       }
       if ((root->data < minVal)|| (root->data >maxVal )){
           return false;
       }
       return (checkBST(root->left, minVal, root->data -1) && checkBST(root->right, root->data+1, maxVal));
   }



   bool checkBST(Node* root) {
       return checkBST(root, 0, 10000);

   }

//---------------------------------------------------------
int main()
{
    int x,n,p;

    head=NULL;                              //-----INITIALIZATION OF HEAD TO NULL --CREATION OF EMPTY LIST

    cout<< "How many numbers:"<<endl;       //----- CREATING A LIST OF n NUMBERS
    cin>>n;

    for(int i=0;i<n; i++){
        cout<<"Enter the number"<< endl;
        cin>>x;
        //Insert_front(x);
        Insert_end(x);
        Print_List();
    }


    cout<<"Insert  the node in between"<<endl;       //---- INSERTING A NODE AT pth POSITION
    cout<<" Specify the node position";
    cin>>p;
    cout<<"Enter the number"<< endl;
    cin>>x;

    Insert_InBetween(x,p);
    Print_List();
    Print_List_recur(head);

    cout<<"Node Deletion"<<endl;       //---- INSERTING A NODE AT pth POSITION
    cout<<" Specify the Node position";
    cin>>p;
    //Delete_node(p);
    Delete(head, p);
    Print_List();

    cout << "Hello world!" << endl;
    return 0;
}
