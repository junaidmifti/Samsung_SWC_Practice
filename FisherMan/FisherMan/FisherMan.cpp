#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCost = 999999;

struct gate {
	int loc, men;
};

int searchLeft(int start, vector<int> &visitSpot) {
	for (int i = start; i > 0; i--) {
		if (!visitSpot[i]) return i;
	}
	return 999999;
}

int searchRight(int start, vector<int> &visitSpot, int noOfSpot) {
	for (int i = start+1; i <= noOfSpot; i++) {
		if (!visitSpot[i]) return i;
	}
	return 999999;
}

void solve(int x, int y, int z, int cost, vector<int> &visitSpot, int start, int noOfSpot, vector<gate> &allGates) {
	if (cost > minCost) return;
	if (allGates[start].men == 0) {
		if (start == x) start = y;
		else if (start == y) start = z;
		else {
			minCost = min(minCost, cost);
			return;
		}
	}
	int leftSpot = searchLeft(allGates[start].loc, visitSpot);
	int rightSpot = searchRight(allGates[start].loc, visitSpot, noOfSpot);
	int leftCost = 1 + abs(allGates[start].loc - leftSpot);
	int rightCost = 1 + abs(allGates[start].loc - rightSpot);

	if (leftCost < rightCost) {
		visitSpot[leftSpot] = 1;
		allGates[start].men--;
		solve(x, y, z, cost + leftCost, visitSpot, start, noOfSpot, allGates);
		visitSpot[leftSpot] = 0;
		allGates[start].men++;
	}

	else {
		visitSpot[rightSpot] = 1;
		allGates[start].men--;
		solve(x, y, z, cost + rightCost, visitSpot, start, noOfSpot, allGates);
		visitSpot[rightSpot] = 0;
		allGates[start].men++;
	}
}

int main()
{
	int noOfSpot;
	vector<gate> allGates(5);
	vector<int> visitSpot(61, 0);
	cin >> noOfSpot;
	for (int i = 1;i <= 3;i++) {
		cin >> allGates[i].loc;
	}

	for (int i = 1;i <= 3;i++) {
		cin >> allGates[i].men;
	}
	minCost = 999999;
	solve(1, 2, 3, 0, visitSpot, 1, noOfSpot, allGates);
	solve(1, 3, 2, 0, visitSpot, 1, noOfSpot, allGates);
	solve(2, 1, 3, 0, visitSpot, 2, noOfSpot, allGates);
	solve(2, 3, 1, 0, visitSpot, 2, noOfSpot, allGates);
	solve(3, 1, 2, 0, visitSpot, 3, noOfSpot, allGates);
	solve(3, 2, 1, 0, visitSpot, 3, noOfSpot, allGates);

	cout << minCost << endl;
}

