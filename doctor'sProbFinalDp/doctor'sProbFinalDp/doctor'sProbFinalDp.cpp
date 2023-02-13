#include<iostream>
#include<vector>

using namespace std;
double finalAns = -1.0;
int finalIndex = -1;

void solve(int n, int time, vector<vector<double>> &grid) {
	vector<vector<double>> sol(100, vector<double>(100, 0.0));
	sol[0][1] = 1.0;
	for (int i = 2; i <= n; i++) {
		sol[0][i] = 0;
	}
	for (int i = 0; i < time; i++) {
		for (int k = 1; k <= n;k++) {
			sol[i + 1][k] = 0;
		}
		for (int j = 1; j <= n; j++) {
			if (sol[i][j]) {
				for (int k = 1; k <= n; k++) {
					if (grid[j][k]) {
						sol[i + 1][k] += sol[i][j] * grid[j][k];
					}
				}
			}
		}
	}
	for (int i = 1; i <= n;i++) {
		if (sol[time][i] > finalAns) {
			finalAns = sol[time][i];
			finalIndex = i;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		int n, e, time;
		cin >> n >> e >> time;
		time = time / 10;
		vector<vector<double>> grid(n + 2, vector<double>(n + 2, 0.0));
		for (int i = 0; i < e; i++) {
			int u, v;
			double x;
			cin >> u >> v >> x;
			grid[u][v] = x;
		}

		solve(n, time, grid);

		cout << "#" << z << " " << finalIndex << " " << finalAns << endl;
	}
}