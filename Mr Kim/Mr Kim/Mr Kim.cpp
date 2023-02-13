// Mr Kim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
	int x, y;
};

int calcDistance(point one, point two) {
	int xDist = abs(one.x - two.x);
	int yDist = abs(one.y - two.y);
	return (xDist + yDist);
}

void backtrack(int currNode, int cost, int nodeLeft, vector<point> &points, vector<int> &visited, int &N, int&minAns) {
	if (nodeLeft == 0) {
		minAns = min(minAns, (cost + calcDistance(points[currNode], points[N + 1])));
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			backtrack(i, cost + calcDistance(points[currNode], points[i]), nodeLeft-1, points, visited, N, minAns);
			visited[i] = 0;
		}
	}
}

int main()
{
	int T = 1;
	int Z = 0;
	while (T--) {
		Z++;
		int minAns = 9999999;
		int N;
		cin >> N;
		vector<point> points(15);
		vector<int> visited(20,0);
		point office, home;
		cin >> office.x >> office.y;
		points[0] = (office);
		cin >> home.x >> home.y;
		points[N+1] = (home);
		for (int i = 1; i <= N; i++) {
			point cust;
			cin >> cust.x >> cust.y;
			points[i] = cust;
		}
		backtrack(0, 0, N, points, visited, N, minAns);
		cout << "# " <<Z<<" "<< minAns << endl;

	}
	return 0;
}

