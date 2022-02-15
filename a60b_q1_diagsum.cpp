#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> dp[i][j];
        }
    }

    int realAns = -1e9;

    for(int i = 1; i <= n; ++i) {
        int mn = 0;
        int ans = dp[1][i];
        int now = 0;
        for(int j = 0; j <= n - i; ++j) {
            now += dp[j + 1][i + j];
            ans = max(ans, now - mn);
            mn = min(now, mn);
        }

        realAns = max(realAns, ans);

        mn = 0;
        ans = dp[i][1];
        now = 0;

        for(int j = 0; j <= n - i; ++j) {
            now += dp[i + j][j + 1];
            ans = max(ans, now - mn);
            mn = min(now, mn);
        }
        
        realAns = max(realAns, ans);
    }

    cout << realAns;
}