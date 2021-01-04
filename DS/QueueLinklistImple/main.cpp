#include <iostream>

using namespace std;

struct Node{
int data;
struct Node* next;

};

struct Node* head;
struct Node* rear;

//---------ENQUEUE at end------
void EnQueue(int x){
struct Node* new_node;
new_node->data = x;
new_node->next = NULL;
if (head == NULL && rear == NULL){
head = new_node;
rear = new_node;
return;
}
rear->next = new_node;   //-------Assign existing node next (pointed by rear) to temp or new node

rear = new_node;    //------Now point rear node pointer to new_node;

}

//--------------DeQueue at head----------
void DeQueue(){

struct Node* del_node = head;       // -- pointing del_node to headfor deleting at head;

if (head == NULL){          // if empty queue
return;
}
if (head == rear){           // if head and rear pointing to one element i.e only one element in the list
    head = rear = NULL;
}
else {
head = head-> next;         // point head to next location using head-> next

}

free(del_node);



}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
