#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int Z = 0;
	while (T--) {
		Z++;
		unordered_map<int, int> freq;
		int N, M, K;
		int maxAns = 0;
		cin >> N >> M >> K;
		int graph[100][100];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> graph[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			int zeroCount = 0;
			int value = 0;
			for (int j = 0; j < M; j++) {
				value = (value << 1) + graph[i][j];
				if (graph[i][j] == 0) zeroCount++;
			}
			if (!freq.count(value)) {
				freq[value] = 1;
			}
			else freq[value]++;

			if ((K - zeroCount) % 2 == 0 && K >= zeroCount) {
				maxAns = max(maxAns, freq[value]);
			}
		}
		cout << "#" << Z << " " << maxAns << endl;
	}
}

