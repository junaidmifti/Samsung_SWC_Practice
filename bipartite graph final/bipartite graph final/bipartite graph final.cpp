#include <iostream>
#include<unordered_map>
#include<vector>

using namespace std;

bool isBipart(int currNode, int currColor, unordered_map<int, vector<int>> &adjList, vector<int> &colorMap) {
	colorMap[currNode] = currColor;
	for (auto neighb : adjList[currNode]) {
		if (colorMap[neighb] == -1) {
			if (isBipart(neighb, abs(1 - currColor), adjList, colorMap) == false) {
				return false;
			}
		}
		else if (colorMap[neighb] != abs(1 - currColor)) {
			return false;
		}
	}
	return true;
}

int main()
{
	while (true) {
		int V, E;
		cin >> V;
		if (V == 0) break;
		cin >> E;
		unordered_map<int, vector<int>> adjList;
		vector<int> colorMap(V + 1, -1);
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		bool ans = isBipart(0, 1, adjList, colorMap);
		if (ans) {
			cout << "BICOLORABLE." << endl;
		}
		else {
			cout << "NOT BICOLORABLE." << endl;
		}
	} 
}
