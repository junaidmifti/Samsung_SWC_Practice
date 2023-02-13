#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

struct point{
	int x, y;
};

int calcDist(point one, point two) {
	int xDist = abs(one.x - two.x);
	int yDist = abs(one.y - two.y);
	return xDist + yDist;
}

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		int Sx, Sy, Dx, Dy, N;
		cin >> Sx >> Sy >> Dx >> Dy;
		cin >> N;
		vector<point> nodes(2 * N + 3);
		vector<vector<int>> costMatrix(2 * N + 3, vector<int>(2 * N + 3, -1));
		nodes[0].x = Sx;
		nodes[0].y = Sy;
		nodes[2 * N + 1].x = Dx;
		nodes[2 * N + 1].y = Dy;
		for (int i = 0; i < N; i++) {
			cin >> nodes[2 * i + 1].x;
			cin >> nodes[2 * i + 1].y;
			cin >> nodes[2 * i + 2].x;
			cin >> nodes[2 * i + 2].y;
			int wW;
			cin >> wW;
			costMatrix[2 * i + 1][2 * i + 2] = wW;
			costMatrix[2 * i + 2][2 * i + 1] = wW;
		}

		for (int i = 0; i < 2*N+2; i++) {
			for (int j = 0; j < 2*N+2; j++) {
				if (costMatrix[i][j] == -1) {
					costMatrix[i][j] = calcDist(nodes[i], nodes[j]);
				}
			}
		}

		for (int k = 0; k < 2*N + 2; k++) {
			for (int i = 0; i < 2*N + 2; i++) {
				for (int j = 0; j < 2*N + 2; j++) {
					if (i == k || j == k) continue;
					costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
				}
			}
		}

		cout << "#" << z << " " <<  costMatrix[0][2*N + 1] << endl;
	}
}
