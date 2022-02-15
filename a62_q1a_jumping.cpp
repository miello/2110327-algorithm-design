#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i) cin >> dp[i];

    int ans = dp[0];

    for(int i = 1; i < n; ++i) {
        int now = dp[i - 1];
        for(int j = 1; j <= 3; ++j) {
            now = max(dp[max(0, i - j)], now);
        }
        dp[i] += now;
        ans = max(ans, dp[i]);
    }

    cout << dp[n - 1];
}