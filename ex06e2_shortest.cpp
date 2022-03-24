#include <bits/stdc++.h>

using namespace std;

const int MXN = 101, INF = 1e9 + 7;
vector<pair<int, int>> edge[MXN];

int dp[MXN];

int main() {
    int n, e, s;
    cin >> n >> e >> s;

    for(int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        edge[u].emplace_back(v, w);
    }

    for(int i = 0; i < n; ++i) dp[i] = INF;
    dp[s] = 0;

    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n; ++j) {
            for(auto &to: edge[j]) {
                if(dp[to.first] > dp[j] + to.second) {
                    dp[to.first] = dp[j] + to.second;
                }
            }
        }
    }

    for(int j = 0; j < n; ++j) {
        for(auto &to: edge[j]) {
            if(dp[to.first] > dp[j] + to.second) {
                cout << -1;
                return 0;
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
}