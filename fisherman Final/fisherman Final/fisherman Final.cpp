#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
int minAns;
int noOfSpots;

struct gates{
	int loc, men;
};

int findLeft(int pos, vector<int> &visited) {
	for (int i = pos; i > 0; i--) {
		if (!visited[i]) return i;
	}
	return 99999;
}

int findRight(int pos, vector<int> &visited) {
	for (int i = pos+1; i <= noOfSpots ; i++) {
		if (!visited[i]) return i;
	}
	return 99999;
}

void solve(int x, int y, int z, int currentGate,int cost, vector<gates> &allGates, int &noOfSpots, vector<int> &visited) {
	if (allGates[currentGate].men == 0) {
		if (currentGate == x) currentGate = y;
		else if (currentGate == y) currentGate = z;
		else {
			minAns = min(minAns, cost);
			return;
		}
	}
	int leftSpot = findLeft(allGates[currentGate].loc, visited);
	int rightSpot = findRight(allGates[currentGate].loc, visited);

	int leftCost = 1 + abs(allGates[currentGate].loc - leftSpot);
	int rightCost = 1 + abs(allGates[currentGate].loc - rightSpot);

	if (leftCost < rightCost) {
		allGates[currentGate].men--;
		visited[leftSpot] = 1;
		solve(x, y, z, currentGate, cost + leftCost, allGates, noOfSpots, visited);
		visited[leftSpot] = 0;
		allGates[currentGate].men++;
	}
	
	else if (leftCost >= rightCost) {
		allGates[currentGate].men--;
		visited[rightSpot] = 1;
		solve(x, y, z, currentGate, cost + rightCost, allGates, noOfSpots, visited);
		visited[rightSpot] = 0;
		allGates[currentGate].men++;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> noOfSpots;
		vector<gates> allGates(5);
		vector<int> visited(noOfSpots + 1, 0);
		for (int i = 1; i <= 3; i++) {
			cin >> allGates[i].loc;
			cin >> allGates[i].men;
		}
		minAns = 9999999;
		solve(1, 2, 3, 1,0, allGates, noOfSpots, visited);
		solve(1, 3, 2, 1, 0,allGates, noOfSpots, visited);
		solve(2, 1, 3, 2, 0,allGates, noOfSpots, visited);
		solve(2, 3, 1, 2, 0,allGates, noOfSpots, visited);
		solve(3, 1, 2, 3, 0,allGates, noOfSpots, visited);
		solve(3, 2, 1, 3, 0,allGates, noOfSpots, visited);

		cout << minAns << endl;
	}
}

