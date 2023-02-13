#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(int x, int y, int coins, bool isBombed, int rowSafe, vector<vector<int>>&graph, int &N, int &maxCoin) {
	if (x < 0 || y < 0 || y >= 5) {
		maxCoin = max(maxCoin, coins);
		return;
	}
	
	if (graph[x][y] == 1 || graph[x][y] == 0) {
		if (isBombed) rowSafe--;
		if (graph[x][y] == 1) coins+=1;
		solve(x-1, y, coins, isBombed, rowSafe, graph, N, maxCoin);
		solve(x - 1, y-1, coins, isBombed, rowSafe, graph, N, maxCoin);
		solve(x - 1, y+1, coins, isBombed, rowSafe, graph, N, maxCoin);
	}
	else if (graph[x][y] == 2) {
		if (!isBombed) {
			isBombed = true;
			rowSafe = 4;
			solve(x - 1, y, coins, isBombed, rowSafe, graph, N, maxCoin);
			solve(x - 1, y - 1, coins, isBombed, rowSafe, graph, N, maxCoin);
			solve(x - 1, y + 1, coins, isBombed, rowSafe, graph, N, maxCoin);
		}
		else if (rowSafe > 0) {
			rowSafe--;
			solve(x - 1, y, coins, isBombed, rowSafe, graph, N, maxCoin);
			solve(x - 1, y - 1, coins, isBombed, rowSafe, graph, N, maxCoin);
			solve(x - 1, y + 1, coins, isBombed, rowSafe, graph, N, maxCoin);
		}
		else {
			maxCoin = max(maxCoin, coins);
			return;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		int N;
		cin >> N;
		vector<vector<int>>graph(N + 1, vector<int>(N + 1));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> graph[i][j];
			}
		}
		int maxCoin = -1;
		solve(N - 1, 1, 0, 0, 0, graph, N, maxCoin);
		solve(N - 1, 2, 0, 0, 0, graph, N, maxCoin);
		solve(N - 1, 3, 0, 0, 0, graph, N, maxCoin);
		cout << "#" << z << " " << maxCoin << endl;
	}
}

