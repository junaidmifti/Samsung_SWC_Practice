#include <iostream>
#include <vector>
#include<algorithm>
#include<cstdio>

using namespace std;

struct node {
	int x, y;
};

int calcDistance(node one, node two) {
	int distX = abs(one.x - two.x);
	int distY = abs(one.y - two.y);
	return (distX + distY);
}

int main()
{
	freopen("output.txt", "w", stdout);
	int T;
	int Z = 0;
	cin >> T;
	while (T--) {
		Z++;
		int Sx, Sy, Dx, Dy;
		node points[100];
		int weight[100];
		cin >> Sx >> Sy >> Dx >> Dy;
		int warmhole;
		cin >> warmhole;
		int nodes = 2 * warmhole + 2;
		node startNode, endNode;
		startNode.x = Sx;
		startNode.y = Sy;
		points[0] = startNode;
		endNode.x = Dx;
		endNode.y = Dy;
		points[nodes - 1] = endNode;

		for (int i = 0; i < warmhole; i++) {
			int wX1, wY1, wX2, wY2, wW;
			cin >> wX1>> wY1 >> wX2 >> wY2 >> wW;
			node warmNode;
			warmNode.x = wX1;
			warmNode.y = wY1;
			points[2*i+1] = warmNode;
			weight[2 * i + 1] = wW;
			node warmNode2;
			warmNode2.x = wX2;
			warmNode2.y = wY2;
			points[2 * i + 2] = warmNode2;
			weight[2 * i + 2] = wW;
			//cost[2 * i + 1][2 * i + 2] = wW;
			//cost[2 * i + 2][2 * i + 1] = wW;
		}

		// initialize cost matrix
		int **cost = new int*[nodes];
		for (int i = 0; i < nodes; i++) {
			cost[i] = new int[nodes];
		}
		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++) {
				cost[i][j] = -1;
			}
		}

		//making cost matrix

		for (int i = 0;i < warmhole; i++) {
			cost[2 * i + 1][2 * i + 2] = weight[2 * i + 1];
			cost[2 * i + 2][2 * i + 1] = weight[2 * i + 2];
		}

		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++) {
				if (cost[i][j] == -1) {
					cost[i][j] = calcDistance(points[i], points[j]);
				}
			}
		}

		//floyd warshall

		for (int k = 0;k < nodes; k++) {
			for (int i = 0; i < nodes; i++) {
				for (int j = 0; j < nodes; j++) {
					if (i == k || j == k) continue;
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}

		//final ans

		cout << "#" << Z << " " << cost[0][nodes - 1] << endl;




		

		
	}
}
