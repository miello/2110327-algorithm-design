#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    string s;
    for(int i = 1; i <= n; ++i) {
        cin >> s;
        for(int j = 0; j < m; ++j) {
            dp[i][j + 1] = s[j] - '0';
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(dp[i][j]) dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
            ans = max(dp[i][j], ans);
        }
    }
    
    cout << ans;
}
