#include <iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;
int N, E;

struct points {
	int x, y, cost;
};

int BFS(int x, int y, int cost, vector<vector<int>> graph, vector<vector<bool>> visited, int N, int E) {
	int maxCost = -1;
	points temp;
	temp.x = x;
	temp.y = y;
	temp.cost = cost;
	queue<points> grid;
	grid.push(temp);
	visited[x][y] = 1;
	while (!grid.empty()) {
		if (E == 0) break;
		points top = grid.front();
		grid.pop();
		if (graph[top.x][top.y] == 2) {
			maxCost = max(maxCost, top.cost);
			E--;
		}
		if (top.x - 1 >= 0 && (graph[top.x - 1][top.y] == 1 || graph[top.x - 1][top.y] == 2) && !visited[top.x - 1][top.y]) {
			visited[top.x - 1][top.y] = 1;
			points temp2;
			temp2.x = top.x - 1;
			temp2.y = top.y;
			temp2.cost = top.cost + 1;
			grid.push(temp2);
		}

		if (top.x + 1 < N && (graph[top.x + 1][top.y] == 1 || graph[top.x + 1][top.y] == 2) && !visited[top.x + 1][top.y]) {
			visited[top.x + 1][top.y] = 1;
			points temp2;
			temp2.x = top.x + 1;
			temp2.y = top.y;
			temp2.cost = top.cost + 1;
			grid.push(temp2);
		}

		if (top.y - 1 >= 0 && (graph[top.x][top.y - 1] == 1 || graph[top.x][top.y - 1] == 2) && !visited[top.x][top.y - 1]) {
			visited[top.x][top.y - 1] = 1;
			points temp2;
			temp2.x = top.x;
			temp2.y = top.y - 1;
			temp2.cost = top.cost + 1;
			grid.push(temp2);
		}

		if (top.y + 1 < N && (graph[top.x][top.y + 1] == 1 || graph[top.x][top.y + 1] == 2) && !visited[top.x][top.y + 1]) {
			visited[top.x][top.y + 1] = 1;
			points temp2;
			temp2.x = top.x;
			temp2.y = top.y + 1;
			temp2.cost = top.cost + 1;
			grid.push(temp2);
		}
	}
	return maxCost;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int minCost = INT_MAX;
		cin >> N >> E;
		vector<vector<int>> elements(E + 1, vector<int>(E + 1));
		vector<vector<int>> graph(N + 1, vector<int>(N + 1));
		vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, 0));
		for (int i = 0; i < E; i++) {
			cin >> elements[i][0] >> elements[i][1];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
			}
		}
		for (int i = 0; i < E; i++) {
			graph[elements[i][0] - 1][elements[i][1] - 1] = 2;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == 1) {
					int cost = BFS(i, j, 0, graph, visited, N, E);
					minCost = min(minCost, cost);
				}
			}
		}
		cout << minCost << endl;
	}
}