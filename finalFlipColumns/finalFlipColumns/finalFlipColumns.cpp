#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cstdio>

using namespace std;


int main(){
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) 
	{
		int N, M, K;
		cin >> N >> M >> K;
		unordered_map<int, int> freq;
		vector<vector<int>> graph(N + 1, vector<int>(M + 1));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> graph[i][j];
			}
		}
		int maxAns = 0;
		for (int i = 0; i < N; i++) {
			int value = 0;
			int zeroCount = 0;
			for (int j = 0; j < M; j++) {
				value = (value << 1) + graph[i][j];
				if (graph[i][j] == 0) zeroCount++;
			}
			if (!freq.count(value)) freq[value] = 1;
			else freq[value]++;

			if ((K - zeroCount) % 2 == 0 && K >= zeroCount) {
				maxAns = max(maxAns, freq[value]);
			}
		}
		cout <<"#" <<z<<" " <<  maxAns << endl;
	}
}
