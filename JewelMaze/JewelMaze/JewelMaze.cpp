#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
unordered_map<int, vector<vector<int>>> ansMap;

void dfs(int x, int y, int value, int cost, int &maxCost, vector<vector<int>> graph, int N) {

	if (graph[x][y] == 2) {
		cost = cost + 1;
	}

	if (x == (N - 1) && y == (N - 1)) {
		if (cost > maxCost) {
			maxCost = cost;
			ansMap[cost] = graph;
		}
		return;
	}
	graph[x][y] = 3;
	if (x - 1 >= 0 && (graph[x - 1][y] == 2 || graph[x - 1][y] == 0)) {
		dfs(x - 1, y, graph[x - 1][y], cost, maxCost, graph, N);

	}
	if (y - 1 >= 0 && (graph[x][y - 1] == 2 || graph[x][y - 1] == 0)) {
		dfs(x, y - 1, graph[x][y - 1], cost, maxCost, graph, N);

	}
	if (x + 1 < N && (graph[x + 1][y] == 2 || graph[x + 1][y] == 0)) {
		dfs(x + 1, y, graph[x + 1][y], cost, maxCost, graph, N);

	}
	if (y + 1 < N && (graph[x][y + 1] == 2 || graph[x][y + 1] == 0)) {
		dfs(x, y + 1, graph[x][y + 1], cost, maxCost, graph, N);

	}

}

int main() {
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		int N;
		cin >> N;
		int maxCost = 0;
		vector<vector<int>> graph(N + 1, vector<int>(N + 1));
		//vector<vector<int>> visited(N + 1, vector<int>(N + 1, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
			}
		}
		dfs(0, 0, graph[0][0], 0, maxCost, graph, N);
		vector<vector<int>> temp;
		temp = ansMap[maxCost];
		temp[N - 1][N - 1] = 3;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << temp[i][j] << " ";
			}
			cout << endl;
		}
		cout << maxCost << endl;
	}
}