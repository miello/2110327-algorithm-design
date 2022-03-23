#include <bits/stdc++.h>

using namespace std;

const int MXR = 1005, MXC = 1005;
const int INF = 50001;

bool board[MXR][MXC];
int cnt[MXR][MXC];

const int diff[4][2] = {{ 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 }};

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    for(int i = 0; i < n; ++i) {
        int c, d;
        cin >> c >> d;

        board[c][d] = true;
    }

    for(int i = 0; i < MXR; ++i) {
        for(int j = 0; j < MXC; ++j) {
            cnt[i][j] = INF;
        }
    }

    cnt[a][b] = 0;

    queue<pair<int, int>> q;
    q.emplace(a, b);
    int mn = INF;

    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; ++i) {
            int newX = x + diff[i][0];
            int newY = y + diff[i][1];

            if(newX >= 0 && newX < 1005 && newY >= 0 && newY < 1005) {
                if(cnt[newX][newY] > cnt[x][y] + board[newX][newY]) {
                    cnt[newX][newY] = cnt[x][y] + board[newX][newY];
                    q.emplace(newX, newY);
                }
            }
        }
    }
    for(int i = 0; i < 1005; ++i) {
        mn = min({ cnt[MXR - 1][i], cnt[i][MXR - 1], cnt[i][0], cnt[0][i], mn });
    }
    cout << mn;
}