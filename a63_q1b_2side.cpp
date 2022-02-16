#include <bits/stdc++.h>

using namespace std;

// dp[n][k][pos];
int dp[200001][51][2];

int main() {
    int n, w, k;
    cin >> n >> w >> k;

    vector<vector<int>> arr(n + 1, vector<int>(2, 0));
    
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i][0];
    }

    for(int i = 1; i <= n; ++i) {
        cin >> arr[i][1];
    }

    int ans = -1;
    for(int i = 1; i <= n; ++i) {
        if(n != k) {
            // Solve 17 Points
            for(int j = 1; j <= min(i, k); ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], arr[i][0] + dp[max(0, i - w - 1)][j - 1][1]);
                dp[i][j][1] = max(dp[i - 1][j][1], arr[i][1] + dp[max(0, i - w - 1)][j - 1][0]);
                ans = max({dp[i][j][0], dp[i][j][1], ans});
            }
        } else {
            // Solve 83 Points
            dp[i][0][0] = max(dp[i - 1][0][0], arr[i][0] + dp[max(0, i - w - 1)][0][1]);
            dp[i][0][1] = max(dp[i - 1][0][1], arr[i][1] + dp[max(0, i - w - 1)][0][0]);
            ans = max({dp[i][0][0], dp[i][0][1], ans});
        }
    }

    cout << ans;
}