#include <iostream>
#include<vector>

using namespace std;

void dfs(int startX, int startY, int(&graph)[11][11], int(&visited)[11][11], int maxLevel, int &flag, int N, int M) {
	if (graph[startX][startY] == 3) {
		flag = 1;
		return;
	}
	visited[startX][startY] = 1;
	if (startY - 1 >= 0 && !visited[startX][startY - 1] && (graph[startX][startY - 1] == 1 || graph[startX][startY - 1] == 3)) {
		dfs(startX, startY - 1, graph, visited, maxLevel, flag, N, M);
		if (flag) return;
	}

	if (startY + 1 < M && !visited[startX][startY + 1] && (graph[startX][startY + 1] == 1 || graph[startX][startY + 1] == 3)) {
		dfs(startX, startY + 1, graph, visited, maxLevel, flag, N, M);
		if (flag) return;
	}

	int currentLevel = 1;

	for (int i = currentLevel; i <= maxLevel; i++) {
		if (startX - i >= 0 && !visited[startX - i][startY] && (graph[startX - i][startY] == 1 || graph[startX - i][startY] == 3)) {
			dfs(startX - i, startY, graph, visited, maxLevel, flag, N, M);
			if (flag) return;
		}
	}

	for (int i = currentLevel; i <= maxLevel; i++) {
		if (startX + i < N && !visited[startX + i][startY] && (graph[startX + i][startY] == 1 || graph[startX + i][startY] == 3)) {
			dfs(startX + i, startY, graph, visited, maxLevel, flag, N, M);
			if (flag) return;
		}
	}
}

int main()
{
	int N, M;
	int graph[11][11];
	int visited[11][11];
	int flag = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				visited[j][k] = 0;
			}
		}
		dfs(N - 1, 0, graph, visited, i, flag, N, M);
		if (flag) {
			cout << i << endl;
			break;
		}
	}

}