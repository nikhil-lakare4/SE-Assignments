/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 4
Write a function to get the number of vertices in an undirected graph and its edges. You may
assume that no edge is input twice.
i. Use adjacency list representation of the graph and find runtime of the function
ii. Use adjacency matrix representation of the graph and find runtime of the function
*/
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}node;

class graph
{
	int vertex,edge;
	int G[10][10];
	node *hn[10];
public:
	void read();
	void display_mat();
	
	void create_list();
	void add_edge(int m,int n,node *hn[10]);
	void display_list();
};

void graph::read()
{
	int m,n;
	
	cout<<"\nEnter the number of vertices : ";
	cin>>vertex;
	cout<<"\nEnter the number of edges : ";
	cin>>edge;
	
		for(int i=1;i<=vertex;i++)
		{
			for(int j=1;j<=vertex;j++)
			{
				G[i][j]=0;
			}
		}
		for(int i=0;i<edge;i++)
		{
			cout<<"\nEnter edge "<<i+1<<" : ";
			cin>>m>>n;
			G[m][n]=1;
			G[n][m]=1;
		}
}

void graph::display_mat()
{
	cout<<"\n\n******* ADJACENCY MATRIX ********\n\n";

	for(int i=1;i<=vertex;i++)
	{
		for(int j=1;j<=vertex;j++)
		{
			cout<<G[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void graph::create_list()
{
	node *nn;
	int m,n;
	
	cout<<"\nEnter the number of vertices : ";
	cin>>vertex;
	cout<<"\nEnter the number of edges : ";
	cin>>edge;
	
		for(int i=1;i<=vertex;i++)
		{
			hn[i]=NULL;
		}
		for(int i=0;i<edge;i++)
		{
			cout<<"\nEnter edge "<<i+1<<" : ";
			cin>>m>>n;
			add_edge(m,n,hn);
			add_edge(n,m,hn);
		}
}

void graph::add_edge(int m,int n,node *hn[10])
{
	node *cn,*nn;
	nn=new node;
	nn->data=n;
	nn->next=NULL;
		if(hn[m]==NULL)
		{
			hn[m]=nn;
		}
		else
		{
			cn=hn[m];
				while(cn->next!=NULL)
				{
					cn=cn->next;
				}
				cn->next=nn;
		}
}

void graph::display_list()
{
	cout<<"\n\n******* ADJACENCY LIST ********\n\n";
	node *cn;
	for(int i=1;i<=vertex;i++)
	{
		cout<<"\n["<<i<<"] -> ";
		cn=hn[i];
			while(cn!=NULL)
			{
				cout<<cn->data<<" -> ";
				cn=cn->next;
			}
			cout<<"NULL";
			
	}
}

int main()
{
	graph g;
	int choice;
	char ch;
	do
	{
		cout<<"\n\t******** MENU **********\n\n";
		cout<<"\t1. Adjacency Matrix\n";
		cout<<"\t2. Adjacency List\n";
		cout<<"\t3. Exit\n\n";
		cout<<"\tEnter ur choice: ";
		cin>>choice;
			switch(choice)
			{
				case 1:
					g.read();
					g.display_mat();
					break;
				case 2:
					g.create_list();
					g.display_list();
					cout<<endl;
					break;
				case 3:
					cout<<"\nBye...\n";
					return 0;
				default:
					cout<<"\nInvalid choice..\n";
			}
			cout<<"\nDo u want to continue(y/n): ";
			cin>>ch;
	}while(ch=='y'||ch=='Y');

	return 0;
}
