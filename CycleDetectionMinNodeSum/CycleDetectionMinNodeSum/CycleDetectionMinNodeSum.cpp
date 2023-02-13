#include <iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

set<int> path;
int isCycle = 0;
int cycleStart = -1;
int cycleEnd = -1;

void detectCycle(int currNode, int nodeSum, unordered_map<int, vector<int>> &adjList, vector<bool> visited, vector<bool> pathVisited, int &minNodeSum,
	set<int> temp) {
	temp.insert(currNode);
	visited[currNode] = 1;
	pathVisited[currNode] = 1;

	for (auto neighbour : adjList[currNode]) {
		if (!visited[neighbour]) {
			detectCycle(neighbour, nodeSum + currNode, adjList, visited, pathVisited, minNodeSum, temp);
			if(isCycle) return;
		}
		else if (pathVisited[neighbour]) {
			if (nodeSum < minNodeSum) {
				minNodeSum = nodeSum;
				path = temp;
				isCycle = 1;
			}
			//return;
		}
	}
}

int main()
{
	int V, E;
	int minNodeSum = 99999;
	cin >> V >> E;
	unordered_map<int, vector<int>> adjList;
	vector<bool> visited(20, 0);
	vector<bool> pathVisited(20, 0);
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
	}
	for (int i = 1; i <= V; i++) {
		if (!visited[i]) {
			set<int> temp = {};
			detectCycle(i, 0, adjList, visited, pathVisited, minNodeSum, temp);
		}
	}
	if (isCycle) {
		for (auto itr : path) {
			cout << itr << " ";
		}
	}
	return 0;
}
