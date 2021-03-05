#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

int count_BST_nodes(Node* root)
{
	Node* temp=root;
	int lh=0,rh=0;
	while(temp!=NULL)
	{
		lh++;
		temp=temp->left;
	}
	temp=root;
	while(temp!=NULL)
	{
		rh++;
		temp=temp->right;
	}

	if(lh==rh)
	return (pow(2,lh)-1);

	else
	return (1+count_BST_nodes(root->left)+count_BST_nodes(root->right));
}

int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

	cout<<count_BST_nodes(root);
}