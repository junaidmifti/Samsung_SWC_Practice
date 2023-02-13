#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct node {
	int x, y, cost;
};

void bfs(int startx, int starty, vector<vector<int>>&graph, vector<vector<int>>&visited, int &N, int E, int &maxCost) {
	queue<node> grids;
	node start;
	start.x = startx;
	start.y = starty;
	start.cost = 0;
	visited[startx][starty] = 1;
	grids.push(start);
	while (!grids.empty()) {
		node top = grids.front();
		grids.pop();
		if (E <= 0) break;
		if (graph[top.x][top.y] == 2) {
			maxCost = max(maxCost, top.cost);
			E--;
		}
		if (top.x - 1 >= 0 && !visited[top.x - 1][top.y] && (graph[top.x - 1][top.y] == 1 || graph[top.x - 1][top.y] == 2)) {
			visited[top.x - 1][top.y] = 1;
			node temp;
			temp.x = top.x - 1;
			temp.y = top.y;
			temp.cost = top.cost + 1;
			grids.push(temp);
		}

		if (top.x + 1 <N && !visited[top.x + 1][top.y] && (graph[top.x + 1][top.y] == 1 || graph[top.x + 1][top.y] == 2)) {
			visited[top.x + 1][top.y] = 1;
			node temp;
			temp.x = top.x + 1;
			temp.y = top.y;
			temp.cost = top.cost + 1;
			grids.push(temp);
		}

		if (top.y - 1 >= 0 && !visited[top.x][top.y-1] && (graph[top.x][top.y-1] == 1 || graph[top.x][top.y-1] == 2)) {
			visited[top.x][top.y-1] = 1;
			node temp;
			temp.x = top.x;
			temp.y = top.y-1;
			temp.cost = top.cost + 1;
			grids.push(temp);
		}

		if (top.y + 1 <N && !visited[top.x][top.y + 1] && (graph[top.x][top.y + 1] == 1 || graph[top.x][top.y+1] == 2)) {
			visited[top.x][top.y + 1] = 1;
			node temp;
			temp.x = top.x;
			temp.y = top.y + 1;
			temp.cost = top.cost + 1;
			grids.push(temp);
		}
	}
}

int main(){
	int T;
	cin >> T;
	while (T--) {
		int minCost = 9999999;
		int N, E;
		cin >> N >> E;
		vector<vector<int>>graph(N + 1, vector<int>(N + 1));
		for (int i = 0; i < E; i++) {
			int j, k;
			cin >> j >> k;
			graph[j - 1][k - 1] = 2;
		}

		for (int i = 0; i < N;i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
			}
		}

		for (int i = 0; i < N;i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == 1) {
					vector<vector<int>>visited(N + 1, vector<int>(N + 1, 0));
					int maxCost = -1;
					bfs(i,j,graph,visited,N,E,maxCost);
					minCost = min(minCost, maxCost);
				}
			}
		}

		cout << minCost << endl;
	}
}

