#include <bits/stdc++.h>

using namespace std;

const int MXN = 20;
const int BIT = (1 << MXN);
const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> dp(n, vector<int>(1 << n, -INF));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    
    dp[0][1] = 0;
    for(int i = 0; i < (1 << n); ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                if(!(i & (1 << k))) {
                    dp[k][i | (1 << k)] = max(dp[k][i | (1 << k)], dp[j][i] + dist[j][k]);
                }
            }
        }
    }

    cout << dp[n - 1][(1 << n) - 1];
}