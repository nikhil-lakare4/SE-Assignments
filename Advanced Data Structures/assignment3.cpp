/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 3
construct inorder threaded binary tree. Design an algorithm for inorder, preorder 
and postorder traversal without using stack. Analyse time and space complexity 
of the algorithm.
*/
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *L,*R;
	int lThread,rThread;
}tbt;

class tree
{
public:
	void create(tbt*,int);
	tbt* leftmost(tbt*);
	void inorder(tbt*);
	tbt* premost(tbt*);
	void preorder(tbt*);
};

void tree::create(tbt *parent,int lr)
{
	tbt *nn;
	int d;
	
	cout<<"\nEnter data: ";
	cin>>d;
	
	if(d==-1)
		return;
	else
	{
		nn=new tbt;
		nn->data=d;
		if(lr)
		{
			nn->L=parent->L;
			nn->lThread=parent->lThread;
			nn->R=parent;
			nn->rThread=1;
			parent->L=nn;
			parent->lThread=0;
		}
		else
		{
			nn->R=parent->R;
			nn->rThread=parent->rThread;
			nn->L=parent;
			nn->lThread=1;
			parent->R=nn;
			parent->rThread=0;
		}
	}
	cout<<"\nEnter the left child of "<<nn->data;
	create(nn,1);
	cout<<"\nEnter the right child of "<<nn->data;
	create(nn,0);
	
}

tbt* tree::leftmost(tbt *cn)			//leftmost node
{
	while(cn->lThread==0)
		cn=cn->L;
	return cn;
}

void tree::inorder(tbt *root)			//Inorder traversal
{
	tbt *cn;
	cn=cn->L;
	cn=leftmost(cn);
		while(cn!=root)
		{
			cout<<cn->data<<"  ";
				if(cn->rThread)
					cn=cn->R;
				else
					cn=leftmost(cn->R);
		}
}

tbt* tree::premost(tbt *cn)				//Premost node
{
	if(cn->lThread==0)
		return (cn->L);
	if(cn->rThread==0)
		return (cn->R);
		while(cn->rThread)
			cn=cn->R;
	return (cn->R);
}

void tree::preorder(tbt *root)			//Preorder
{
	tbt *cn;
	cn=cn->L;
		while(cn!=root)
		{
			cout<<cn->data<<"  ";
			cn=premost(cn);
		}
}

int main()
{

	char ch;
	int choice;
	tbt *dummy;
	dummy=new tbt;
	tree obj;
	dummy->L=dummy->R=dummy;
	dummy->lThread=dummy->rThread=1;
	cout<<"\n**Enter -1 if child don't exist\n";
	/*
	do
	{
		cout<<"\n\t******** MENU **********\n";
		cout<<"\t1. Create TBT\n";
		cout<<"\t2. Inorder Traversal\n";
		cout<<"\t3. Preorder Traversal\n";
		cout<<"\t4. Exit\n\n";
		cout<<"\tEnter choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				obj.create(dummy,1);
				break;
			case 2:
				cout<<"\nInorder Traversal : \n";
				obj.inorder(dummy);
				cout<<endl;	
				break;
			case 3:
				cout<<"\nPreorder Traversal : \n";
				obj.preorder(dummy);
				cout<<endl;
				break;	
			case 4:
				cout<<"\nBye...\n";
				return 0;
				break;
			default: 
				cout<<"\nInvalid choice...\n";	
		}
		cout<<"\nDo u want to continue(y/n) : ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	*/
	obj.create(dummy,1);
	
	cout<<"\n***** Inorder Traversal ******\n";
	obj.inorder(dummy);
	cout<<endl;	
	
	cout<<"\n***** Preorder Traversal ******\n";
	obj.preorder(dummy);
	cout<<endl;	
	return 0;
	
	return 0;
}
