#include <iostream>

using namespace std;

struct BSTNode
{
    int data;
    BSTNode* leftChild;
    BSTNode* rightChild;
};

BSTNode* GetNewNode(int value)
{
    BSTNode* newNode = new BSTNode();
    
    newNode->data = value;
    newNode->rightChild = NULL;
    newNode->leftChild = NULL;

    return newNode;

}

BSTNode* InsertNode(BSTNode* currNode, int value)
{
    if (currNode == NULL)
    {
        currNode = GetNewNode(value);
        return currNode;
    }
    else if(value <= currNode->data )
    {
        currNode->leftChild = InsertNode(currNode->leftChild, value);
    } 
    else
    {
        currNode->rightChild = InsertNode(currNode->rightChild, value);
    }

    
}

bool SearchNode(BSTNode* rootNode, int value)
{
    if(rootNode==NULL)
    {
        cout<<" Node Not found "<<endl;
        return false;
    }

    else if(rootNode->data == value)
    {   cout<< "Node Found: " <<rootNode->data<<endl;
        return true;
    }

    else
    {
        if (value < rootNode-> data)
        {   cout<<"Left of: "<< rootNode->data<<endl;
            return  SearchNode(rootNode->leftChild, value);            
        }
        else
        {   
            cout<<"Right of: "<< rootNode->data<<endl;
            return  SearchNode(rootNode->rightChild, value);
        }
    }


}

void inOrderTrav(BSTNode* root)
{
    
    
    if (root!= NULL)
    {
        inOrderTrav(root->leftChild);
        cout<<root->data<< endl;
        inOrderTrav(root->rightChild);
    }
}

void preOrderTrav(BSTNode* root)
{
    if (root!= NULL)
    {
        cout<< root->  data<< endl;
        preOrderTrav(root->leftChild);
        preOrderTrav(root->rightChild);
    }
}

void postOrderTrav(BSTNode* root)
{
    if (root!= NULL)
    {   
        postOrderTrav(root->leftChild);
        postOrderTrav(root->rightChild);
        cout<< root->data<< endl;
    }    
}

//Finding if its a binary tree or not
bool checkBST(BSTNode* root, int minVal, int maxVal){
       if (root == NULL){
           return true;
       }
       if ((root->data < minVal)|| (root->data >maxVal )){
           return false;
       }
       return (checkBST(root->leftChild, minVal, root->data -1) && checkBST(root->rightChild, root->data+1, maxVal));
   }



   bool checkBST(BSTNode* root) {
       return checkBST(root, 0, 10000);

   }


int main()
{
    BSTNode* root = NULL;
    bool Found;

    root = InsertNode (root, 50);
    root = InsertNode (root, 40);
    root = InsertNode (root, 60);
    root = InsertNode (root, 35);
    root = InsertNode (root, 45);
    root = InsertNode (root, 55);
    root = InsertNode (root, 65);
    root = InsertNode (root, 70);

    //Found = SearchNode(root, 35);
    cout<<"inOrderTrav"<<endl;
    inOrderTrav(root);

    cout<<"preOrderTrav"<<endl;
    preOrderTrav(root);

    cout<<"postOrderTrav"<<endl;
    postOrderTrav(root);

    return 0;
}