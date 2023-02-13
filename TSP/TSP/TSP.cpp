#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void backtrack(int currNode, int cost, int nodeLeft, int (&dist)[20][20], int (&vis)[20], int &N, int &minAns) {
	if (nodeLeft == 0) {
		minAns = min(minAns, (cost + dist[currNode][0]));
		return;
	}
	for (int i = 1; i < N; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			backtrack(i,cost + dist[currNode][i], nodeLeft-1, dist, vis, N, minAns);
			vis[i] = 0;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int dist[20][20];
		int vis[20];
		int N;
		int minAns = 999999;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> dist[i][j];
			}
			vis[i] = 0;
		}
		backtrack(0, 0, N-1, dist, vis, N, minAns);
		cout << minAns << endl;
	}
	return 0;
}

