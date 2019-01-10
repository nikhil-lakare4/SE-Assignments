/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 5
You have a business with several offices; you want to lease phone lines to connect them up
with each other; and the phone company charges different amounts of money to connect
different pairs of cities. You want a set of lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate data structures.
*/

#include<iostream>
using namespace std;
#define SIZE 10
#define INF 999

class graph
{
	int vertex,edge;
	int G[SIZE][SIZE],cost[SIZE][SIZE];
public:
	void read();
	void display_adj();
	void display_cmat();
	void prims();
};

void graph::read()
{
	int m,n,wt;
	
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
		for(int i=1;i<=edge;i++)
		{
			cout<<"\nEnter edge (m,n,weight) : ";
			cin>>m>>n>>wt;
			G[m][n]=wt;
			G[n][m]=wt;
		}
}

void graph::display_adj()
{
	cout<<"\n\n******* ADJACENCY MATRIX ********\n\n";

	for(int i=1;i<=vertex;i++)
	{
		for(int j=1;j<=vertex;j++)
		{
			cout<<G[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void graph::display_cmat()
{
	cout<<"\n\n******** COST MATRIX *********\n\n";
	
	for(int i=1;i<=vertex;i++)
	{
		for(int j=1;j<=vertex;j++)
		{
			if(G[i][j]==0)
			{
				cost[i][j]=INF;
			}
			else
			{
				cost[i][j]=G[i][j];
			}
		}
	}
	for(int i=1;i<=vertex;i++)
	{
		for(int j=1;j<=vertex;j++)
		{
			cout<<cost[i][j]<<"\t";
		}
		cout<<endl;
	}
	
}

void graph::prims()
{
	int e,v,u;
	int min_wt=0;
	int dist[SIZE],visit[SIZE],source[SIZE];
	int mst[SIZE][SIZE];
	
	for(int i=1;i<=vertex;i++)				//Initializations
	{
		dist[i]=cost[1][i];
		source[i]=1;
		visit[i]=0;
	}
	for(int i=1;i<=vertex;i++)
		for(int j=1;j<=vertex;j++)
			mst[i][j]=0;
			
	visit[1]=1;
	e=vertex-1;
	while(e>0)
	{
		int min;
		min=INF;
		for(int i=2;i<=vertex;i++)			//To find minimum distance
		{
			if(visit[i]==0 && dist[i]<min)
			{
				min=dist[i];
				v=i;
			}
		}
		u=source[v];
		
		
		
		//To add edge in minimum spanning tree
		mst[u][v]=dist[v];
		mst[v][u]=dist[v];
		visit[v]=1;
		
		//To adjust distance and source
		for(int i=2;i<=vertex;i++)
		{
			if(visit[i]==0 && cost[i][v]<dist[i])
			{
				dist[i]=cost[i][v];
				source[i]=v;
			}
		}
		min_wt=min_wt+cost[u][v];
		e--;
	}
	
	
	//To Display
	
	cout<<"\n\n******* MINIMUM SPANNING TREE ********\n\n";

	for(int i=1;i<vertex;i++)
	{
		for(int j=i+1;j<=vertex;j++)
		{
			if(mst[i][j]!=0)
			{
				cout<<"\n(m,n,weight) = ( "<<i<<" , "<<j<<" , "<<mst[i][j]<<" )";
			}
		}
		
	}
	cout<<"\n\nMinimum cost of spanning tree = "<<min_wt;
	cout<<endl;
}

int main()
{
	graph g;
	g.read();
	g.display_adj();
	g.display_cmat();
	g.prims();
	return 0;
}

