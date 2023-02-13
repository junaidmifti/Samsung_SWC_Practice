#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(int left, int right, vector<int> &nums, int &N, vector<vector<int>> &dp) {
	if (left > right) return 0;
	if (dp[left][right] != -1) return dp[left][right];
	int maxAns = -1;
	for (int i = left; i <= right; i++) {
		int cost;
		if (left - 1 == 0 && right + 1 == N + 1) {
			cost = nums[i] + solve(left, i - 1, nums, N,dp) + solve(i + 1, right, nums, N, dp);
		}
		else {
			cost = nums[left-1] * nums[right+1] + solve(left, i - 1, nums, N, dp) + solve(i + 1, right, nums, N, dp);
		}
		maxAns = max(maxAns, cost);
	}
	return dp[left][right] = maxAns;

}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N + 2);
	vector<vector<int>> dp(N + 2, vector<int>(N + 2, -1));
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}
	nums[0] = 1;
	nums[N + 1] = 1;
	cout << solve(1, N, nums, N, dp) << endl;
}

