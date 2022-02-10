#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int dp[101][101];

int main() {
    int n;
    cin >> n;

    vector<int> arr(n + 2, 0);
    for(int i = 1; i <= n + 1; ++i) cin >> arr[i];
    for(int i = 0; i < 101; ++i) {
        for(int j = 0; j < 101; ++j) {
            dp[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; ++i) dp[i][i] = 0;

    for(int i = 1; i <= n - 1; ++i) {
        for(int j = 1; j <= n - i; ++j) {
            int l = j;
            int r = j + i;
            for(int k = l; k <= r - 1; ++k) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + arr[l] * arr[k + 1] * arr[r + 1]);                
            }
        }
    }

    cout << dp[1][n];
}