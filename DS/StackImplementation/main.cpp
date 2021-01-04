#include <iostream>

using namespace std;

struct Node{
int data;
struct Node* next;

};



struct Node* top;
void Push(int x){
    //----ALLOCATION OF HEAP MEMORY FOR NEW NODE AND POINTING ITS ADDRESS USING TEMP
    struct Node* new_node = new Node;


    //---------ADD data to heap memory using pointer that points to heap  memory
    temp-> data = x;

    //----------Make the connection from new node to address pointed by top or head
    temp-> next = top;

    //----------break the connection of top/head with last node and connect it to new node of stack list
    top = temp;
}

void Pop(){
    //----New node pointer to point to the address of the node on heap thats needs to be deleted.
    struct Node* del_node = new Node;
    if (top == NULL){
    return;     // NO NODE TO DELETE;
    }
    del_node =   top;
    top = del_node-> next;
    free(del_node);


}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
