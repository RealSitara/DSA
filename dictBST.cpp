/*
A Dictionary stores keywords and its meanings. 
Provide facility for adding new keywords
deleting keywords
updating values of any entry
Provide facility to display whole data sorted in ascending/ Descending order. 
Also find how many maximum comparisons may require for finding any keyword. 
Use Binary Search Tree for implementation.
*/

#include<iostream>
using namespace std;

class Node{
	public :
		string keyword;
		string meaning;
		Node *left;
		Node *right;
		
		Node(string key,string mean){
			keyword=key;
			meaning=mean;
			left=NULL;
			right=NULL;
		}
};
class tree{
	public :
		Node* insert(Node* root,string key,string mean){
			if(root==NULL){
				cout<<"\n"<<key<<" Inserted!";
				return new Node(key,mean);
			}
			if(key>root->keyword){
				root->right=insert(root->right,key,mean);
			}
			else if(key<root->keyword){
				root->left=insert(root->left,key,mean);
			}
			else{
				root->meaning=mean;
				cout<<"\nMeaning for "<<root->keyword<<" updated to "<<root->meaning;
			}
			return root;
		}
		void search(Node*root,string key,int compare){
			if(!root){
				cout<<"\n"<<key<<" not found !";
				return;
			}
			if(key > root->keyword){
				compare++;
				search(root->right,key,compare);
			}
			else if(key < root->keyword){
				compare++;
				search(root->left,key,compare);
			}
			else{
				cout<<"\n"<<key<<" Found after "<<compare<<" comparisons ";
			}
		}
		Node* findMin(Node* root){
			Node * n=root;
			while(n->left!=NULL){
				n=n->left;
			}
			return n;
		}
		Node* deleteNode(Node *root,string key){
			if(root==NULL){
				return root;
			}
			if(key < root->keyword){
				root->left=deleteNode(root->left,key);
			}
			else if(key > root->keyword){
				root->right=deleteNode(root->right,key);
			}
			else{
				if(root->left==NULL){
					Node* temp=root->right;
					delete root;
					return temp;
				}
				else if(root->right==NULL){
					Node* temp=root->left;
					delete root;
					return temp;	
				}
				else{
					Node *temp=findMin(root->right);
					root->keyword=temp->keyword;
					root->meaning=temp->keyword;
					root->right=deleteNode(root->right,temp->keyword);
				}
			}
			return root;
		}
		void Ascending(Node*root){
			if(!root){
				return;
			}
			Ascending(root->left);
			cout<<"\n KEYWORD : "<<root->keyword<<",MEANING : "<<root->meaning;
			Ascending(root->right);
		}
};
int main(){
	tree t;
	int ch;
	string key,mean;
	Node *root=NULL;
	do{
		cout<<"\n--MENU--\n";
		cout<<"1.insert\n2.update\n3.print ascending\n4.search\n0.Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 1 :
					cout<<"\nEnter keyword : ";
					cin>>key;
					cout<<"\nEnter meaning : ";
					cin>>mean;
					root=t.insert(root,key,mean);
					break;
			case 2 :
					cout<<"\nEnter keyword to be updated : ";
					cin>>key;
					cout<<"\nEnter meaning : ";
					cin>>mean;
					root=t.insert(root,key,mean);
					break;
			case 3 :
					cout<<"\nPrinting Ascending order : \n";
					t.Ascending(root);
					break;
			case 4:
					cout<<"\nEnter the key : ";
					cin>>key;
					t.search(root,key,0);
					break;
			case 5:
					cout<<"\nEnter the key : ";
					cin>>key;
					root=t.deleteNode(root,key);
					break;
		}
		
	}while(ch!=0);
}
