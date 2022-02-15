#include <bits/stdc++.h>

using namespace std;

void backtracking(vector<int> &ans, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp, int now, int w) {
    if(now == 0 || w == 0) return;
    
    if(w >= weight[now]) {
        if(dp[now][w] == dp[now - 1][w - weight[now]] + value[now]) {
            ans.push_back(now);
            backtracking(ans, weight, value, dp, now - 1, w - weight[now]);
            return;
        }
    }
    backtracking(ans, weight, value, dp, now - 1, w);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ans, weight(n + 1, 0), value(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i) cin >> value[i];
    for(int i = 1; i <= n; ++i) cin >> weight[i];

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            cin >> dp[i][j];
        }
    }

    backtracking(ans, weight, value, dp, n, m);
    cout << ans.size() << "\n";
    for(auto &i: ans) {
        cout << i << " ";
    }
}