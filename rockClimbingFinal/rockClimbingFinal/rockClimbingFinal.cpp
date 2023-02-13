#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int x, int y, vector<vector<int>>&graph, vector<vector<int>>&visited, int &flag, int maxJump, int N, int M) {
	if (graph[x][y] == 3) {
		flag = 1;
		return;
	}
	visited[x][y] = 1;
	if (y - 1 >= 0 && !visited[x][y - 1] && (graph[x][y-1] == 1 || graph[x][y-1] == 3)) {
		dfs(x, y-1, graph, visited, flag, maxJump, N , M);
	}
	if (y + 1 <M && !visited[x][y + 1] && (graph[x][y+1] == 1 || graph[x][y+1] == 3)) {
		dfs(x, y + 1, graph, visited, flag, maxJump, N, M);
	}
	
	for (int i = 1; i <= maxJump; i++) {
		if (x - i >= 0 && !visited[x-i][y] && (graph[x-i][y] == 1 || graph[x-i][y] == 3)) {
			dfs(x-i, y, graph, visited, flag, maxJump, N, M);
		}
	}

	for (int i = 1; i <= maxJump; i++) {
		if (x + i < N && !visited[x + i][y] && (graph[x + i][y] == 1 || graph[x + i][y] == 3)) {
			dfs(x + i, y, graph, visited, flag, maxJump, N, M);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>>graph(N + 1, vector<int>(M + 1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		int flag = 0;
		vector<vector<int>>visited(N + 1, vector<int>(M + 1,0));
		dfs(N - 1, 0, graph, visited, flag, i,  N,  M);
		if (flag) {
			cout << i << endl;
			break;
		}
	}

}
