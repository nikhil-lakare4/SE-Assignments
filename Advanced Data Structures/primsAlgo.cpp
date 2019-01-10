//============================================================================
// Name        : AS5.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int INF = 9999;

class prims {
	int V, E;
	int visited[10], dist[10], from[10], G[10][10];
public:

	prims() {

		V = E = 0;

		for (int i = 0; i < 10; i++) {
			visited[i] = 0;
			dist[i] = 0;
			from[i] = 0;

			for (int j = 0; j < 10; j++) {
				G[i][j] = 0;
			}
		}
	}

	void getdata();
	void getprims();
	int findMin();
};

void prims::getdata() {

	int temp;

	cout << "\nEnter total number of vertices : ";
	cin >> V;
	cout << "\nEnter total number of edges : ";
	cin >> E;

	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			cout << "\nEnter the  weight of " << i << "--" << j
					<< "  (put 0 otherwise) :";
			cin >> temp;
			if (temp != 0) {
				G[i][j] = temp;
				G[j][i] = temp;
			}

		}
	}

	cout << "\nEntered graph is : ";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}

void prims::getprims() {
	int vertex = 0;
	int sum = 0;

	visited[vertex] = 1;

	for (int i = 0; i < V; i++) {
		if (!visited[i])
			dist[i] = G[0][i];

		from[i] = 0;
	}

	for (int i = 0; i < V - 1; i++) {

		vertex = findMin();

		visited[vertex] = 1;

		for (int j = 0; j < V; j++) {
			if (visited[j] != 1) {
				if (G[vertex][j] < dist[j] && G[vertex][j] != 0) {
					dist[j] = G[vertex][j];
					from[j] = vertex;
				} else if (G[vertex][j] != 0 && dist[j] == 0) {
					dist[j] = G[vertex][j];
					from[j] = vertex;
				}
			}

		}

	}

	cout << "\nConnected vertices are :";
	for (int i = 0; i < V; i++) {

		cout << endl;
		for (int j = 0; j < V; j++) {
			if (j == from[i] || i == from[j])
				cout << G[i][j] << " ";
			else
				cout << "0 ";
		}

		sum = sum + G[from[i]][i];
	}

	cout << "\nMinimum Weight of spanning tree is : " << sum;
}

int prims::findMin() {
	int min = 999;
	int k;
	for (int i = 0; i < V; i++) {
		if (!visited[i] && dist[i] < min && dist[i] != 0) {
			min = dist[i];
			k = i;
		}
	}
	return k;
}

int main() {
	prims P;
	P.getdata();
	P.getprims();
	return 0;
}
