#include <iostream>
#include<vector>

using namespace std;

int maxDist = 600;
int minTime = 99999;
int H = 17;
vector<int> cost{ 4, 5, 2, 3, 6 };
vector<int> time{ 200, 210, 230, 235, 215 };
int main()
{
	for (int i = 0; i <= maxDist; i++) {
		for (int j = 0; i + j <= maxDist; i++) {
			for (int k = 0; i + j + k <= maxDist; k++) {
				for (int l = 0; i + j + k + l <= maxDist; l++) {
					for (int m = 0; i + j + k + l + m <= maxDist; m++) {
						if (i + j + k + l + m == maxDist) {
							int currTime = time[0] * i + time[1] * j + time[2] * k + time[3] * l + time[4] * m;
							int currCost = cost[0] * i + cost[1] * j + cost[2] * k + cost[3] * l + cost[4] * m;
							if (currTime < minTime && currCost <= H) {
								minTime = currTime;
							}
						}
					}
				}
			}
		}
	}
	cout << minTime << endl;
}

