#include <bits/stdc++.h>

using namespace std;

// dp[n][m][k][color];
int dp[31][31][31];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    dp[1][1][0] = 1;
    for(int a = 2; a <= n; ++a) {
        for(int b = 1; b <= m; ++b) {
            for(int c = 0; c <= k; ++c) {
                dp[a][b][c] += dp[a - 1][b - 1][c];
                if(c != 0) {
                    dp[a][1][c] += dp[a - 1][b][c - 1];
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; ++i) {
        ans += dp[n][i][k];
    }

    cout << ans;
}