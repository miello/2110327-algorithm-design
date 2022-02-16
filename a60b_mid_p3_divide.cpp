#include <bits/stdc++.h>

using namespace std;

const int MOD = 1997;

int main() {
    int n, k;
    cin >> n >> k;
    
    // dp[n][k]
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for(int i = 1; i <= n; ++i) {
        dp[i][1] = 1;
        for(int j = 2; j <= min(k, i); ++j) {
            // Case 1 ...(j - 1 set) + {i} (dp[i - 1][j - 1] ways)
            // Case 2 insert i into j set (j * dp[i - 1][j] ways)
            dp[i][j] += dp[i - 1][j - 1] + j * (dp[i - 1][j]);
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][k];
}