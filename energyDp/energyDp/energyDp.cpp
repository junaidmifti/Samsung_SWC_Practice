#include <iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int dp[4040][1010][5];
const int INF = 2E9;

int solve(int remainingEnergy, int remainingDist, int currIndex, vector<int> &cost, vector<int> &time) {
	if (remainingEnergy < 0) return INF;
	if (remainingDist == 0) return 0;
	if (currIndex < 0) return INF;
	if (dp[remainingEnergy][remainingDist][currIndex] != -1) return dp[remainingEnergy][remainingDist][currIndex];
	return dp[remainingEnergy][remainingDist][currIndex] = min(solve(remainingEnergy, remainingDist, currIndex - 1, cost, time),
		time[currIndex] + solve(remainingEnergy - cost[currIndex], remainingDist - 1, currIndex, cost, time)
	);
}

int iniDp(int dist, int maxEnergy, vector<int> &cost, vector<int> &time) {
	memset(dp, -1, sizeof dp);
	return solve(maxEnergy, dist, 4, cost, time);
}


int main()
{
	vector<int> cost{ 4, 5, 2, 3, 6 };
	vector<int> time{ 200, 210, 230, 235, 215 };
	int distance = 600;
	int maxEnergy = 1000;
	cout << iniDp(distance, maxEnergy, cost, time);
}

