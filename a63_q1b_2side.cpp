#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w, k;
    cin >> n >> w >> k;

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    
    for(int i = 1; i <= n; ++i) {
        cin >> dp[i][0];
    }

    for(int i = 1; i <= n; ++i) {
        cin >> dp[i][1];
    }

    for(int i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i][0] + dp[max(0, i - w - 1)][1]);
        dp[i][1] = max(dp[i - 1][1], dp[i][1] + dp[max(0, i - w - 1)][0]);
    }

    cout << max(dp[n][0], dp[n][1]);
}