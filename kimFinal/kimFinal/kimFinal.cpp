#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct points{
	int x, y;
};
int calcDist(points one , points two) {
	int xDist = abs(one.x - two.x);
	int yDist = abs(one.y - two.y);
	return xDist + yDist;
}
void backTrack(int currNode, int nodeLeft, int cost, int &minCost, int &N, vector<points> &coOrds, vector<int> &visited) {
	if (nodeLeft == 0) {
		minCost = min(minCost, cost + calcDist(coOrds[currNode], coOrds[N + 1]));
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			backTrack(i, nodeLeft - 1, cost + calcDist(coOrds[currNode], coOrds[i]), minCost, N, coOrds, visited);
			visited[i] = 0;
		}
	}
}

int main()
{
	int T = 10;
	for (int z = 1; z <= T; z++) {
		int N;
		cin >> N;
		vector<points> coOrds(N + 3);
		vector<int> visited(N + 3, 0);
		cin >> coOrds[0].x >> coOrds[0].y;
		cin >> coOrds[N + 1].x >> coOrds[N + 1].y;
		for (int i = 1; i <= N; i++) {
			cin >> coOrds[i].x >> coOrds[i].y;
		}
		int minCost = 999999;
		backTrack(0, N, 0, minCost, N, coOrds, visited);
		cout << "# " << z << " " << minCost << endl;
	}
}

