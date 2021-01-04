#include <iostream>

using namespace std;

struct BSTNode {
    int data;
    struct BSTNode* leftChild;
    struct BSTNode* rightChild;


};

BSTNode* GetNewNode(int x){
    struct BSTNode* newNode = new BSTNode;
    newNode->data = x;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;

}


BSTNode* Insert(BSTNode* currNode, int x){

//----------Check if current node is pointing to other node i.e. it exists or its NULL
if (currNode == NULL){
    currNode = GetNewNode(x);  //--------Generate a node for current node if its absent
}

//--------RECURSION------------------------------------
else if (x <= currNode->data){

    currNode->leftChild = Insert(currNode, x);  // if current x value is less than current node value - navigate left and set the current node -> right child address to func Insert new node that returns address
}


// if current x value is less than current node value - navigate Right and set the current node -> right child address to func Insert new node that returns address
else{

    currNode->rightChild = Insert(currNode, x);

}

return currNode;

}

bool Search(BSTNode* currNode, int x){

//================================Condition for serach=========================
if (currNode == NULL){
return false;
}


else if (x == currNode->data){
return true;
}
//=============================================================================

//=====================RECURSION===============================================
else if(x <= currNode->data){
return Search(currNode->leftChild, x);
}

else{
return Search(currNode->rightChild, x);

}
}


int main(){

int number;
struct BSTNode* root = NULL;
Insert(root, 15);
Insert(root, 25);
Insert(root, 5);
Insert(root, 35);

cout<< "Enter the number to be searched"<<endl;
cin>> number;

if (Search(root,number)){
cout<< "Found the Number";
}
else{
cout<< "Number Not Found";
}
    cout << "Hello world!" << endl;
    return 0;
}
