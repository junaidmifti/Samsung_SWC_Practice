// EndoscopeFinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

struct node {
	int x, y, length;
};

bool isUp(int x, int y, vector<vector<int>> &graph) {
	if (graph[x][y] == 1 || graph[x][y] == 2 || graph[x][y] == 4 || graph[x][y] == 7) {
		return true;
	}
	return false;
}

bool isDown(int x, int y, vector<vector<int>> &graph) {
	if (graph[x][y] == 1 || graph[x][y] == 2 || graph[x][y] == 5 || graph[x][y] == 6) {
		return true;
	}
	return false;
}

bool isLeft(int x, int y, vector<vector<int>> &graph) {
	if (graph[x][y] == 1 || graph[x][y] == 3 || graph[x][y] == 6 || graph[x][y] == 7) {
		return true;
	}
	return false;
}

bool isRight(int x, int y, vector<vector<int>> &graph) {
	if (graph[x][y] == 1 || graph[x][y] == 3 || graph[x][y] == 4 || graph[x][y] == 5) {
		return true;
	}
	return false;
}

void bfs(int startX, int startY, int length, int &ans, vector<vector<int>> &graph, vector<vector<int>> &visited, int N, int M) {
	queue<node> pipes;
	node startPipe;
	startPipe.x = startX;
	startPipe.y = startY;
	startPipe.length = length;
	visited[startX][startY] = 1;
	pipes.push(startPipe);
	while (!pipes.empty()) {
		node top = pipes.front();
		pipes.pop();
		ans++;
		if (top.length > 0) {
			if (top.x - 1 >= 0 && !visited[top.x - 1][top.y] && isUp(top.x, top.y, graph) && isDown(top.x - 1, top.y, graph)) {
				visited[top.x - 1][top.y] = 1;
				node temp;
				temp.x = top.x - 1;
				temp.y = top.y;
				temp.length = top.length - 1;
				pipes.push(temp);
			}

			if (top.x + 1 <= N && !visited[top.x + 1][top.y] && isUp(top.x + 1, top.y, graph) && isDown(top.x, top.y, graph)) {
				visited[top.x + 1][top.y] = 1;
				node temp;
				temp.x = top.x + 1;
				temp.y = top.y;
				temp.length = top.length - 1;
				pipes.push(temp);
			}

			if (top.y - 1 >= 0 && !visited[top.x][top.y - 1] && isRight(top.x, top.y - 1, graph) && isLeft(top.x, top.y, graph)) {
				visited[top.x][top.y - 1] = 1;
				node temp;
				temp.x = top.x;
				temp.y = top.y - 1;
				temp.length = top.length - 1;
				pipes.push(temp);
			}

			if (top.y + 1 < M && !visited[top.x][top.y + 1] && isRight(top.x, top.y, graph) && isLeft(top.x, top.y + 1, graph)) {
				visited[top.x][top.y + 1] = 1;
				node temp;
				temp.x = top.x;
				temp.y = top.y + 1;
				temp.length = top.length - 1;
				pipes.push(temp);
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, M, Rx, Ry, pipeLength;
		cin >> N >> M >> Rx >> Ry >> pipeLength;
		vector<vector<int>> graph(N+1, vector<int>(M+1));
		vector<vector<int>> visited(N+1, vector<int>(M+1));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> graph[i][j];
				visited[i][j] = 0;
			}
		}
		int ans = 0;
		if (graph[Rx][Ry]) {
			bfs(Rx, Ry, pipeLength - 1, ans, graph, visited, N, M);
		}
		cout << ans << endl;
	}
}
