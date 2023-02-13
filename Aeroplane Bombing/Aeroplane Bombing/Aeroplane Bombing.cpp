#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

void dfs(int row, int col, int coins, int rowSafe, bool isBombed, int &maxCount, vector<vector<int>> &graph) {
	if (col < 0 || col >= 5 || row < 0) {
		maxCount = max(coins, maxCount);
		return;
	}

	//maxCount = max(coins, maxCount);
	if (graph[row][col] == 1) {
		int newCoins = coins + 1;
		if (isBombed) rowSafe--;
		dfs(row - 1, col, newCoins, rowSafe, isBombed, maxCount, graph);
		dfs(row - 1, col + 1, newCoins, rowSafe, isBombed, maxCount, graph);
		dfs(row - 1, col - 1, newCoins, rowSafe, isBombed, maxCount, graph);
	}
	else if (graph[row][col] == 0) {
		if (isBombed) rowSafe--;
		dfs(row - 1, col, coins, rowSafe, isBombed, maxCount, graph);
		dfs(row - 1, col + 1, coins, rowSafe, isBombed, maxCount, graph);
		dfs(row - 1, col - 1, coins, rowSafe, isBombed, maxCount, graph);
	}
	else if (graph[row][col] == 2) {
		if (!isBombed) {
			isBombed = true;
			rowSafe = 4;
			dfs(row - 1, col + 1, coins, rowSafe, isBombed, maxCount, graph);
			dfs(row - 1, col, coins, rowSafe, isBombed, maxCount, graph);
			dfs(row - 1, col - 1, coins, rowSafe, isBombed, maxCount, graph);
		}
		else if (rowSafe > 0) {
			rowSafe--;
			dfs(row - 1, col + 1, coins, rowSafe, isBombed, maxCount, graph);
			dfs(row - 1, col, coins, rowSafe, isBombed, maxCount, graph);
			dfs(row - 1, col - 1, coins, rowSafe, isBombed, maxCount, graph);
		}
		else {
			maxCount = max(coins, maxCount);
			return;
		}
	}


}

int main()
{
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		int RowCount;
		int maxCoins = -1;
		cin >> RowCount;
		vector<vector<int>> graph(RowCount + 1, vector<int>(5));
		for (int i = 0; i < RowCount; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> graph[i][j];
			}
		}
		dfs(RowCount - 1, 1, 0, 0, false, maxCoins, graph);
		dfs(RowCount - 1, 2, 0, 0, false, maxCoins, graph);
		dfs(RowCount - 1, 3, 0, 0, false, maxCoins, graph);

		cout << "#" << z << " " << maxCoins << endl;
	}
}