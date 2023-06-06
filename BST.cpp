/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
v. Search a value
*/
#include<iostream>
using namespace std;

class Node{

public : 
 Node *right,*left;
 int data;
 
 Node(int data){
 	this->data=data;
 	left=NULL;
 	right=NULL;
 }
};

class tree{
	Node *root=NULL;
	public :

	Node* insert(Node *r,int data)
	{
		if(r==NULL)
		{
			r=new Node(data);
			cout <<"Insertion successful"<<endl;
			return r;
		}
		if(data<r->data)
		{
			r->left=insert(r->left,data);
		}
		else if(data>r->data)  
		{
			r->right=insert(r->right,data);
		}
	    else
	    {
	     	cout <<"No duplicate values allowed!"<< endl;
	     	return r; 
		}
		return r;
	}
	
	int calculateHeight(Node* node) 
	{
	    if (node == NULL)
	        return 0;
	
	    int left_height = calculateHeight(node->left);
	    int right_height = calculateHeight(node->right);
	
	    return 1 + max(left_height, right_height);
	}

	int calculateLongestPath(Node* node) 
	{
	    int height = calculateHeight(node);
	    return height - 1;
	}
	
	int minval(Node *temp){
		//Node *temp=root;	
		while(temp->left!=NULL){
			temp=temp->left;
		}
		return temp->data;
	}
	
	void search(Node* temp,int data){
		 if(temp->data==data){
		 	cout<<"\nValue You Entered is found !";
		 }
		 else if((temp->data > data)&&(temp!=NULL)){
		 	search(temp->left,data);
		 }
		 else if((temp->data<data)&&(temp!=NULL)){
		 	search(temp->right,data);
		 }
		 else{
		 	cout<<"\nValue Not found";
		 }
	}
	void swaptree(Node* temproot)
	{	
		if (temproot == NULL)
		{
			return;
		}
		else
		{
			swaptree(temproot->left);
			swaptree(temproot->right);
			
			Node *temp=temproot->left;
			temproot->left=temproot->right;
			temproot->right=temp;
		}
	}
	void printPatternHelper(Node* x, int level) {
    if (x == NULL)
        return;

    const int spacing = 4;

    printPatternHelper(x->right, level + 1);

    for (int i = 0; i < level * spacing; ++i)
        cout << " ";

    cout << x->data <<endl;

    printPatternHelper(x->left, level + 1);
}

void printPattern(Node* x) {
    printPatternHelper(x, 0);
}
	
};
int main(){
	Node *root=NULL;
	tree t;
	int height=0;
	int mini=0;
	root=t.insert(root,10);
	//t.printPattern(root);
	root=t.insert(root,12);
	root=t.insert(root,8);
	root=t.insert(root,11);
	root=t.insert(root,13);
	root=t.insert(root,7);
	root=t.insert(root,9);
	t.printPattern(root);
	t.search(root,11);
	//t.search(root,15);
	height = t.calculateHeight(root);
	cout<<"\n Height : "<<height-1;
	mini=t.minval(root);
	cout<<"\n Minimum Value in Tree : "<<mini;
	cout<<"\nSwapped Tree : ";
	cout<<"\n\n\n";
	t.swaptree(root);
	t.printPattern(root);
	 
}


