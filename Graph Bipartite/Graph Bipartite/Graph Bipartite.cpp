#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void checkBipart(int currNode, int currColor, unordered_map<int, vector<int>> &adjList, vector<int> &colorMap, bool &ans) {
	if (ans == 0) return;
	if (colorMap[currNode] != -1) {
		if (colorMap[currNode] != currColor) {
			ans = 0;
			return;
		}
		return;
	}
	colorMap[currNode] = currColor;
	for (auto itr : adjList[currNode]) {
		checkBipart(itr, abs(1 - currColor), adjList, colorMap, ans);
	}
}


int main()
{
	// Vertex er input zero hoile inputting sesh
	while (true) {
		unordered_map<int, vector<int>> adjList;
		vector<int> colorMap(200, -1);
		bool ans = 1;
		int vertex, edges;
		cin >> vertex;
		if (vertex == 0) break;
		cin >> edges;

		for (int i = 0; i < edges; i++) {
			int u, v;
			cin >> u >> v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		checkBipart(0, 1,adjList, colorMap, ans);
		if (ans) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;

	}
	return 0;
}

