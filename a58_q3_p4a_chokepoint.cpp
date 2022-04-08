#include <bits/stdc++.h>

using namespace std;

void dfs(vector<long long> &dp, vector<vector<int>> &edge, int now, int prev) {
    for(auto &i: edge[now]) {
        if(i == prev) continue;

        dfs(dp, edge, i, now);
        dp[now] += dp[i];
    }
}

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n, 1);
    vector<vector<int>> edge(n);

    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(dp, edge, 0, -1);
    for(int i = 0; i < n; ++i) {
        if(edge[i].size() == 1) {
            cout << n - 1 << "\n";
            continue;
        }

        long long now = (n - 1);
        now *= now;
        
        long long cnt = (n - 1);
        for(auto &j: edge[i]) {
            if(dp[i] > dp[j]) {
                now -= dp[j] * dp[j];
                cnt -= dp[j];
            }
        }

        now -= cnt * cnt;

        now /= 2;

        now += n - 1;
        cout << now << "\n";
    }
}