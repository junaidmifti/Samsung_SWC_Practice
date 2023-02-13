#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
int N;


int dp(int start, int end, vector<int> &ballons, vector<vector<int>>&dpMem) {
    if (start > end) return 0;
    if (dpMem[start][end] != -1) return dpMem[start][end];
    int maxAns = INT_MIN;
    for (int i = start; i <= end; i++) {
        int cost;
        if(start-1 ==0 && end+1 == N+1){
        cost = ballons[i] + 
            dp(start, i - 1, ballons, dpMem) + dp(i + 1, end, ballons, dpMem);
        }
        else {
            cost = ballons[start - 1] * ballons[end + 1] + 
            dp(start, i - 1, ballons, dpMem) + dp(i + 1, end, ballons, dpMem);
        }
        
        maxAns = max(cost, maxAns);
    }
    return dpMem[start][end] = maxAns;
}

int main()
{
    cin >> N;
    vector<int> ballons(N+2);
    vector<vector<int>>dpMem(N+2, vector<int>(N+2, -1));
    for (int i = 1; i <= N; i++) {
        cin >> ballons[i];
    }
    ballons[0] = 1;
    ballons[N + 1] = 1;
    int final = dp(1, N, ballons, dpMem);
    cout << final << endl;

}
