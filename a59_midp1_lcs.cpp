#include <bits/stdc++.h>

using namespace std;

void backtracking(string &ans, string &x, string &y, int idxX, int idxY, vector<vector<int>> &dp) {
    if(idxX == 0 || idxY == 0) return;

    if(x[idxX - 1] == y[idxY - 1]) {
        ans += x[idxX - 1];
        backtracking(ans, x, y, idxX - 1, idxY - 1, dp);
        return;
    }
    if(dp[idxX - 1][idxY] == dp[idxX][idxY]) {
        backtracking(ans, x, y, idxX - 1, idxY, dp);
    } else {
        backtracking(ans, x, y, idxX, idxY - 1, dp);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            cin >> dp[i][j];
        }
    }

    string ans;
    backtracking(ans, a, b, n, m, dp);
    reverse(ans.begin(), ans.end());
    cout << ans;
}