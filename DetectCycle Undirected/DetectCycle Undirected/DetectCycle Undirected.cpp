#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

bool dfs(int currNode, int parent, unordered_map<int, vector<int>> &adjLst, unordered_map<int, int> &visited) {
	visited[currNode] = 1;
	for (auto neighb : adjLst[currNode]) {
		if (!visited[neighb]) {
			if (dfs(neighb, currNode, adjLst, visited) == true) {
				return true;
			}
		}
		else if (neighb != parent) {
			return true;
		}
	}
	return false;
}

int main() {
	unordered_map<int, vector<int>> adjLst;
	unordered_map<int, int> visited;
	bool ans = false;
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adjLst[u].push_back(v);
		adjLst[v].push_back(u);
	}
	for (int i = 0; i < V; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			if (dfs(i, -1, adjLst, visited)) ans = true; break;
		}
	}
	cout << ans << endl;
	return 0;
}