#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int MAXM = 10005;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(MAXM, INF));
    vector<int> arr(n + 1, 0);

    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 1; i <= 100; ++i) {
        int diff = arr[1] - i;
        dp[1][i * i] = diff * diff;
    }

    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= 100; ++j) {
            for(int k = j * j + 1; k <= m; ++k) {
                int diff = j - arr[i];
                dp[i][k] = min(dp[i][k], dp[i - 1][k - j * j] + diff * diff);
            }
        }
    }
    
    if(dp[n][m] == INF) cout << -1;
    else cout << dp[n][m];
}