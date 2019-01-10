//============================================================================
// Name        : AS4.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 10;

struct node {
	int v;
	node *next;
};

class Graph {
	node adj[MAX];
	int adjMat[MAX][MAX];
	int visited[MAX];
	int V, E;
	queue<int> Q;
public:
	Graph() {

		V = E = 0;
	}

	void initAdjlist() {
		for (int i = 0; i < V; i++) {
			adj[i].next = NULL;
		}
	}

	void initMat() {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++)
				adjMat[i][j] = 0;
		}
	}

	void initVisited() {
		for (int i = 0; i < V; i++) {
			visited[i] = 0;
		}
	}

	void getData();
	void createAdjMat();
	void displayAdjMat();
	void createAdjList();
	void addEdgeList(int s, int e);
	void displayAdjList();

	void DFSMat(int x);
	void BFSMat(int x);
	void DFSList(int x);
	void BFSList(int x);
};

void Graph::getData() {
	cout << "Enter the number of Vertices: ";
	cin >> V;
	cout << "Enter the number of Edges: ";
	cin >> E;
}

void Graph::createAdjMat() {

	initMat();

	int s, e;

	for (int i = 0; i < E; i++) {

		cout << "\nEnter Start Vertex And End Vertex of " << i << "th edge: ";
		cin >> s >> e;

		adjMat[s][e] = 1;
		adjMat[e][s] = 1;

		cout << endl;
	}
}

void Graph::addEdgeList(int s, int e) {

	node *cn, *nn;

	if (adj[s].next == NULL) {

		adj[s].v = s;

		nn = new node;
		nn->v = e;
		nn->next = NULL;

		adj[s].next = nn;

	} else {

		cn = adj[s].next;

		while (cn->next) {
			cn = cn->next;
		}

		nn = new node;
		nn->v = e;
		nn->next = NULL;

		cn->next = nn;
	}
}

void Graph::createAdjList() {

	initAdjlist();

	int s, e;

	cout << "\nEnter the edges in ascending order : \n";

	for (int i = 0; i < E; i++) {

		cout << "\nEnter start vertex and end vertex of " << i << "th edge: ";
		cin >> s >> e;

		addEdgeList(s, e);
		addEdgeList(e, s);

		cout << endl;
	}

}

void Graph::displayAdjMat() {
	cout << "\nAdjacency Matrix is: " << endl;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}

	initVisited();
	cout << "\nIt's DFS traversal is : ";
	DFSMat(0);
	cout << "\nIt's BFS traversal is : ";
	BFSMat(0);

}

void Graph::displayAdjList() {

	node *cn;

	cout << "\nAdjacency list is: " << endl;
	for (int i = 0; i < V; i++) {
		cout << adj[i].v << " ";
		cn = adj[i].next;
		while (cn) {
			cout << cn->v << " ";
			cn = cn->next;
		}
		cout << endl;
	}

	initVisited();
	cout << "\nIt's DFS traversal is : ";
	DFSList(0);
	cout << "\nIt's BFS traversal is : ";
	BFSList(0);

}

void Graph::DFSMat(int x) {

	visited[x] = 1;
	cout << x << " ";
	for (int i = 1; i < V; i++) {
		if (adjMat[x][i] == 1 && visited[i] != 1)
			DFSMat(i);
	}
}

void Graph::BFSMat(int v) {

	initVisited();

	visited[v] = 1;
	cout << v << " ";
	Q.push(v);

	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 1; i < V; i++) {
			if (adjMat[v][i] == 1 && visited[i] != 1) {
				visited[i] = 1;
				cout << i << " ";
				Q.push(i);
			}
		}
	}

}

void Graph::DFSList(int x) {

	node *cn;

	visited[x] = 1;

	cout << adj[x].v << " ";

	for (cn = adj[x].next; cn != NULL; cn = cn->next) {
		if (visited[cn->v] != 1)
			DFSList(cn->v);
	}
}

void Graph::BFSList(int x) {

	node *cn;

	initVisited();

	visited[x] = 1;

	cout << x << " ";
	Q.push(x);

	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		for (cn = adj[x].next; cn != NULL; cn = cn->next) {
			if (visited[cn->v] != 1) {
				visited[cn->v] = 1;
				cout << cn->v << " ";
				Q.push(cn->v);
			}
		}
	}

}

int main() {

	int choice;

	Graph G;

	G.getData();

	cout
			<< "\nEnter 1 to create and display Adjacency Matrix\nEnter 2 to create and display Adjacency list\nChoice : ";
	cin >> choice;

	switch (choice) {
	case 1:
		G.createAdjMat();
		G.displayAdjMat();
		break;
	case 2:
		G.createAdjList();
		G.displayAdjList();
		break;
	default:
		break;
	}

	return 0;
}
