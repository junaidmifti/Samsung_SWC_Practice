#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void backTrack(int currNode, int cost, int nodeLeft, int &minCost, vector<vector<int>> &graph, vector<int> &visited, int N) {
	if (nodeLeft == 0) {
		minCost = min(minCost, cost + graph[currNode][0]);
		return;
	}
	for (int i = 1; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			backTrack(i, cost + graph[currNode][i], nodeLeft - 1, minCost, graph, visited, N);
			visited[i] = 0;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int minCost = 999999;
		vector<vector<int>> graph(N+1, vector<int>(N+1));
		vector<int> visited(N + 1, 0);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
			}
		}
		backTrack(0, 0, N - 1, minCost, graph, visited, N);
		cout << minCost << endl;
	}

	
	
}
