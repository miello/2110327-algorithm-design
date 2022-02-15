#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> dp[i][j];
        }
    }

    for(int i = 1; i <= m; ++i) {
        dp[1][i] += dp[1][i - 1];
    }
    
    for(int i = 1; i <= n; ++i) {
        dp[i][1] += dp[i - 1][1];
    }

    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= m; ++j) {
            int now = dp[i][j];
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + now;
            dp[i][j] = max(dp[i][j], now * 2 + dp[i - 1][j - 1]);
        }
    }

    cout << dp[n][m];
}