#include <iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>

using namespace std;

int flag = 0;

void isCycle(int currNode, int nodeSum, int &minNodeSum, unordered_map<int, vector<int>> &adjList, vector<bool> visited, set<int> temp, set<int> &finalPath,
	vector<bool> Pathvisited) {
	//if (nodeSum >= minNodeSum) return;
	temp.insert(currNode);
	visited[currNode] = 1;
	Pathvisited[currNode] = 1;
	for (auto neighb : adjList[currNode]) {
		if (!visited[neighb]) {
			isCycle(neighb, nodeSum + currNode, minNodeSum, adjList, visited, temp, finalPath, Pathvisited);
		}
		else if (Pathvisited[currNode]) {
			if (nodeSum < minNodeSum) {
				flag = 1;
				minNodeSum = min(minNodeSum, nodeSum);
				finalPath = temp;
				return;
			}
		}
	}
}

int main()
{
	int v, e;
	cin >> v >> e;
	unordered_map<int, vector<int>> adjList;
	vector<bool> visited(v + 1, 0);
	vector<bool> Pathvisited(v + 1, 0);
	int minNodeSum = 999999;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
	}
	set<int> finalPath;
	for (int i = 0; i < v; i++) {
		set<int> temp;
		isCycle(i, 0, minNodeSum, adjList, visited, temp, finalPath, Pathvisited);
	}
	if (flag) {
		for (auto itr : finalPath) {
			cout << itr << " ";
		}
	}
}
