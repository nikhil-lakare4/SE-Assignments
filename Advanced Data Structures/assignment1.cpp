/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 1
A dictionary stores keywords and its meanings. provide facility for adding new keywords, deleting keywords,
updating keywords of any entry. provide facility to display whole data in ascending / descending order. 
Also find how many maximum comparisons may require for finding any keyword. 
Use Binary search tree for implementation.
*/

#include<iostream>
#include<cstring>
using namespace std;
struct node
{
string key;
string meaning;
struct node *L,*R;
};
class tree
{
public:
	node* create();
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
	void search(node*,string);
	void update(node*,string,string);
	void delete_word(node*,string);
	void add_node(node*);
};

node* tree::create()		//Create tree
{
node *root,*cn,*nn,*parent;
char ch;
root=NULL;
do
{
nn=new node;
cout<<"\nPlease enter the word: ";
cin>>nn->key;
cout<<"\nPlease enter the meaning: ";
cin>>nn->meaning;
nn->L=nn->R=NULL;

	if(root==NULL)
	{
	root=nn;
	}
	else
	{
	cn=root;
		while(cn)
		{
		parent=cn;
			if(cn->key<nn->key)
				cn=cn->R;
			else
				cn=cn->L;
		}
		if(parent->key<nn->key)
			parent->R=nn;
		else
			parent->L=nn;
			
		
	}
cout<<"\nDo u want to continue(y/n): ";
cin>>ch;
	
}while(ch=='Y'||ch=='y');
return root;
}

void tree::inorder(node *cn)		//Inorder traversal
{
if(cn)
{
inorder(cn->L);
cout<<cn->key<<" : "<<cn->meaning;
cout<<endl;
inorder(cn->R);

}
}

void tree::preorder(node *cn)		//Preorder traversal
{
if(cn)
{
cout<<cn->key<<" : "<<cn->meaning<<endl;
preorder(cn->L);
preorder(cn->R);
}
}

void tree::postorder(node *cn)		//Postorder traversal
{
if(cn)
{
postorder(cn->L);
postorder(cn->R);
cout<<cn->key<<" : "<<cn->meaning<<endl;
}
}

void tree::search(node *root,string word)		//Searching a word
{
	int count;
	count=0;
	node *cn,*parent;
	cn=root;
	while(cn)
	{
		parent=cn;
		if(cn&&cn->key==word)
		{
			count++;
			break;
		}
		else if(cn->key>word)
		{
			cn=cn->L;
			count++;
		}
		else
		{
			cn=cn->R;
			count++;
		}
	}
	if(cn==NULL)
	{
		cout<<"\nWord : "<<word<<" not found in dictionary\n";
	}
	else
	{
		cout<<"\nWord : "<<word<<" found in dictionary\n";
		cout<<parent->key<<" : "<<parent->meaning<<endl;
		cout<<"\nTotal number of comparisons : "<<count<<endl;
	}
}

void tree::update(node *root,string new_word,string new_mean)	//Update opearation
{
	node *cn,*parent;
	cn=root;
	while(cn)
	{
		parent=cn;
		if(cn&&cn->key==new_word)
		{
			break;
		}
		else if(cn->key>new_word)
		{
			cn=cn->L;
		}
		else
		{
			cn=cn->R;
		}
	}
	if(cn==NULL)
	{
		cout<<"\nWord : "<<new_word<<" not found in dictionary\n";
	}
	else
	{
		parent->meaning=new_mean;
	}
	
}

void tree::delete_word(node *root,string del_word)
{
node *cn,*parent;
cn=root;
	while(cn)
	{
	
		if(cn&&cn->key==del_word)
		{
			break;
		}
		else
		{
		parent=cn;
		 	if(cn->key>del_word)
			{
				cn=cn->L;
			}
			else
			{
			cn=cn->R;
			}
		}
	}
	if(cn==NULL)
	{
	cout<<"\nWord : "<<del_word<<" not found in dictionary\n";
	}
	else
	{
		if(cn->L==NULL&&cn->R==NULL)		//Leaf node
		{
			if(parent->L==cn)
			{
			parent->L=NULL;
			}
			else
			{
			parent->R=NULL;
			}
			delete(cn);
			return;
		}
		
		else if(cn->L==NULL&&cn->R!=NULL || cn->L!=NULL&&cn->R==NULL)		//Non-leaf with one child
		{
			if(parent->L==cn)
			{
				if(cn->L==NULL)
					parent->L=cn->R;
				else
					parent->L=cn->L;
			}
			else
			{
				if(cn->L==NULL)
					parent->R=cn->R;
				else
					parent->R=cn->L;
			}
			delete(cn);
			return;
		}
		
		else if(cn->L!=NULL&&cn->R!=NULL)		//Non-leaf with 2 child
		{
		node *check;
		check=cn->R;
			if(cn->L==NULL && cn->R==NULL)
			{
				cn=check;
				delete(check);
				cn->R=NULL;
			}
			else
			{
				if((cn->R)->L!=NULL)
				{
					node *lcn,*lcnpre;
					lcnpre=cn->R;
					lcn=(cn->R)->L;
					while(lcn->L!=NULL)
					{
						lcnpre=lcn;
						lcn=lcn->L;
					}
					cn->key=lcn->key;
					delete(lcn);
					lcnpre->L=NULL;
				}
				else
				{
					node *temp;
					temp=cn->R;
					cn->key=temp->key;
					cn->R=temp->R;
					delete(temp);
				}
			}
			return;
		}
	}
}

void tree::add_node(node *root)				//Add new node
{
	node *cn,*nn,*parent;
	nn=new node;
	cout<<"\nEnter the word u want to add: ";
	cin>>nn->key;
	cout<<"\nEnter meaning of word: ";
	cin>>nn->meaning;
	nn->R=nn->L=NULL;
	
	cn=root;
		while(cn)
		{
		parent=cn;
			if(cn->key<nn->key)
				cn=cn->R;
			else
				cn=cn->L;
		}
		if(parent->key<nn->key)
			parent->R=nn;
		else
			parent->L=nn;
}


int main()
{
int choice;
char ch;
string search_word,update_word,update_mean,del;
tree t;
node *p;



do
{
	cout<<"\n\t********** MENU ************\n\n";
	cout<<"\t1. Create\n";
	cout<<"\t2. Display\n";
	cout<<"\t3. Search word\n";
	cout<<"\t4. Update meaning\n";
	cout<<"\t5. Add new word\n";
	cout<<"\t6. Delete word\n";
	cout<<"\t7. Exit\n";
	cout<<"\n\tEnter your choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			p=t.create();
			break;
		case 2:
			cout<<"\n****** INORDER ********\n";
			t.inorder(p);
			cout<<"\n****** PREORDER ********\n";
			t.preorder(p);	
			cout<<"\n****** POSTORDER ********\n";
			t.postorder(p);
			break;
		case 3:
			cout<<"\n\n********** SEARCH OPERATION **************\n\n";
			do
			{
			
			cout<<"\nEnter the word u want to search : ";
			cin>>search_word;
			t.search(p,search_word);
			
			cout<<"\nDo u want to continue searching(y/n): ";
			cin>>ch;
			}while(ch=='y'||ch=='Y');
			break;
		case 4:
			cout<<"\n******** UPDATE OPERATION **********\n\n";
			do
			{
			
			cout<<"\nEnter the word whose meaning is to be updated: ";
			cin>>update_word;
			cout<<"\nEnter the new meaning: ";
			cin>>update_mean;
			t.update(p,update_word,update_mean);
			
			cout<<"\nDo u want to continue updation(y/n): ";
			cin>>ch;
			
			}while(ch=='y'||ch=='Y');
			cout<<"\nAfter updation: \n\n";
			t.inorder(p);			
			break;
		case 5:
			cout<<"\n********* ADDITION OF NEW NODE **********\n\n";
			do
			{	
			t.add_node(p);
			
			cout<<"\nDo u want to add more nodes(y/n): ";
			cin>>ch;
			}while(ch=='y'||ch=='Y');
			cout<<"\nAfter addition: \n\n";
			t.inorder(p);
			break;
		case 6:
			cout<<"\n********* DELETION OPERATION **********\n\n";
			do
			{
			cout<<"\nEnter the word u want to delete: ";
			cin>>del;
			t.delete_word(p,del);
			
			cout<<"\nDo u want to continue deletion(y/n): ";
			cin>>ch;
			}while(ch=='y'||ch=='Y');
			cout<<"\nAfter deletion: \n\n";
			t.inorder(p);
			break;
		case 7:
			return 0;
			break;
		default:
			cout<<"\nInvalid choice...\n";	
	}
	cout<<"\nContinue(y/n): ";
	cin>>ch;
}while(ch=='y'||ch=='Y');

return 0;
}


