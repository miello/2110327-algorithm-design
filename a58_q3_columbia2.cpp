#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 7;

const int diff[4][2] = {{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }};

typedef pair<int, int> pii;
typedef pair<pii, pii> node;

int main() {
    int n, m;
    cin >> n >> m;

    int dp[n + 1][m + 1][3], board[n + 1][m + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> board[i][j];
            for(int k = 0; k < 3; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({{ 0, 0 }, { 1, 1 }});
    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = 0;

    while(pq.size()) {
        int used_tear = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        for(int i = 0; i < 4; ++i) {
            int newX = x + diff[i][0];
            int newY = y + diff[i][1];

            if(newX >= 1 && newX <= n && newY >= 1 && newY <= m) {
                if(dp[newX][newY][used_tear] > dp[x][y][used_tear] + board[newX][newY]) {
                    dp[newX][newY][used_tear] = dp[x][y][used_tear] + board[newX][newY];
                    pq.push({{ dp[newX][newY][used_tear], used_tear }, { newX, newY }});
                }
            }
        }
        if(used_tear < 2) {
            for(int i = -2; i <= 2; ++i) {
                for(int j = -2; j <= 2; ++j) {
                    if(abs(i) + abs(j) <= 2) {
                        int newX = x + i;
                        int newY = y + j;

                        if(newX >= 1 && newX <= n && newY >= 1 && newY <= m) {
                            if(dp[newX][newY][used_tear + 1] > dp[x][y][used_tear]) {
                                dp[newX][newY][used_tear + 1] = dp[x][y][used_tear];
                                pq.push({{ dp[newX][newY][used_tear + 1], used_tear + 1 }, { newX, newY }});
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << min({ dp[i][j][0], dp[i][j][1], dp[i][j][2] }) << " ";
        }
        cout << "\n";
    }
}