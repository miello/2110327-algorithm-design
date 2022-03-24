#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> piii;
const int INF = 2e9 + 7;
const int diff[4][2] = {{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }

    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({ 0, { 1, 1 }});
    dp[1][1] = 0;
    
    while(pq.size()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        for(int i = 0; i < 4; ++i) {
            int newX = x + diff[i][0];
            int newY = y + diff[i][1];

            if(newX >= 1 && newX <= n && newY >= 1 && newY <= m) {
                if(dp[newX][newY] > dp[x][y] + board[newX][newY]) {
                    dp[newX][newY] = dp[x][y] + board[newX][newY];
                    pq.push({ dp[newX][newY], { newX, newY }});
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}