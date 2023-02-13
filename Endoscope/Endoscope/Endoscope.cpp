#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct grid {
	int X, Y, CurrLength;
};

int checkUp(int X, int Y, int(&graph)[50][50]) {
	if (graph[X][Y] == 1 || graph[X][Y] == 2 || graph[X][Y] == 4 || graph[X][Y] == 7) return true;
	return false;
}

int checkDown(int X, int Y, int(&graph)[50][50]) {
	if (graph[X][Y] == 1 || graph[X][Y] == 2 || graph[X][Y] == 5 || graph[X][Y] == 6) return true;
	return false;
}

int checkLeft(int X, int Y, int(&graph)[50][50]) {
	if (graph[X][Y] == 1 || graph[X][Y] == 3 || graph[X][Y] == 6 || graph[X][Y] == 7) return true;
	return false;
}

int checkRight(int X, int Y, int(&graph)[50][50]) {
	if (graph[X][Y] == 1 || graph[X][Y] == 3 || graph[X][Y] == 4 || graph[X][Y] == 5) return true;
	return false;
}

void BFS(int N, int M, int Rx, int Ry, int L, int(&graph)[50][50], int(&visited)[50][50], int &ans) {
	queue<grid> qGrid;
	grid start;
	start.X = Rx;
	start.Y = Ry;
	start.CurrLength = L - 1;
	qGrid.push(start);
	visited[Rx][Ry] = 1;
	while (!qGrid.empty()) {
		grid top = qGrid.front();
		qGrid.pop();
		ans++;
		if (top.CurrLength <= 0) {
			continue;
		}
		if (top.X - 1 >= 0 && checkDown(top.X - 1, top.Y, graph) && checkUp(top.X, top.Y, graph) && !visited[top.X - 1][top.Y]) {
			visited[top.X - 1][top.Y] = 1;
			grid temp;
			temp.X = top.X - 1;
			temp.Y = top.Y;
			temp.CurrLength = top.CurrLength - 1;
			qGrid.push(temp);
		}
		if (top.X + 1 < N && checkDown(top.X, top.Y, graph) && checkUp(top.X + 1, top.Y, graph) && !visited[top.X + 1][top.Y]) {
			visited[top.X + 1][top.Y] = 1;
			grid temp;
			temp.X = top.X + 1;
			temp.Y = top.Y;
			temp.CurrLength = top.CurrLength - 1;
			qGrid.push(temp);
		}
		if (top.Y - 1 >= 0 && checkRight(top.X, top.Y - 1, graph) && checkLeft(top.X, top.Y, graph) && !visited[top.X][top.Y - 1]) {
			visited[top.X][top.Y - 1] = 1;
			grid temp;
			temp.X = top.X;
			temp.Y = top.Y - 1;
			temp.CurrLength = top.CurrLength - 1;
			qGrid.push(temp);
		}
		if (top.Y + 1 < M && checkLeft(top.X, top.Y + 1, graph) && checkRight(top.X, top.Y, graph) && !visited[top.X][top.Y + 1]) {
			visited[top.X][top.Y + 1] = 1;
			grid temp;
			temp.X = top.X;
			temp.Y = top.Y + 1;
			temp.CurrLength = top.CurrLength - 1;
			qGrid.push(temp);
		}

	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, M, Rx, Ry, L;
		cin >> N >> M >> Rx >> Ry >> L;
		int graph[50][50];
		int visited[50][50];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> graph[i][j];
				visited[i][j] = 0;
			}
		}
		int ans = 0;
		BFS(N, M, Rx, Ry, L, graph, visited, ans);
		cout << ans << endl;
	}
	return 0;
}