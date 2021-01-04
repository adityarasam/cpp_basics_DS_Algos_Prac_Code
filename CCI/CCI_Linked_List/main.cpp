#include <iostream>

using namespace std;


struct Node{
int data;
Node *next;
};

struct Node* head;

void Insert_At_HEAD(int x){

Node* new_node = new Node;

new_node->data = x;
new_node->next = head;

head = new_node;

}

//-----------equivalent to create a list sequencially--------------------------
void Insert_At_END(int x){
Node* new_node = new Node;

new_node->data = x;
new_node->next = NULL;

if (head==NULL){
head = new_node;
}
else{
Node* temp = head;



while(temp->next != NULL){

temp = temp->next;
}

temp->next = new_node;

}

}



void Print_List(){
    Node* new_node = new Node;
    new_node = head;
    cout<<"List is:";
    while(new_node!=NULL){
    cout<< new_node->data<<" ";
    new_node = new_node->next;
    }
    cout<<endl;
}

void LinkList_head_entry(){
int n,x;

    cout<<"Number of Integers in a LIST?"<<endl;
    cin>>n;
    cout<<"Enter the numbers:"<<endl;

    for (int i = 0; i<n;i++){
    cin>>x;

    Insert_At_HEAD(x);

    }
    cout<<endl;
    Print_List();
}

void LinkedList_tail_entry(){

int n,x;

    cout<<"Number of Integers in a LIST?"<<endl;
    cin>>n;
    cout<<"Enter the numbers:"<<endl;

    for (int i = 0; i<n;i++){
    cin>>x;

    Insert_At_END(x);

    }
    cout<<endl;
    Print_List();
}







int main()
{   head = NULL;
    //LinkList_head_entry();


    LinkedList_tail_entry();
    //cout << "Hello world!" << endl;
    return 0;
}
