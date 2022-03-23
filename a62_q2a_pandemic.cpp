#include <bits/stdc++.h>

using namespace std;

const int MXR = 505, MXC = 505;
const int diff[4][2] = {{ 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 1 }};
int board[MXR][MXC];

int main() {
    int r, c, t;
    cin >> r >> c >> t;
    queue<pair<int, pair<int, int>>> q;

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                q.push({ t, { i, j }});
            }
        }
    }

    while(q.size()) {
        int nowT = q.front().first;
        int nowR = q.front().second.first;
        int nowC = q.front().second.second;

        q.pop();
        if(nowT == 0) continue;

        for(int i = 0; i < 4; ++i) {
            int newR = nowR + diff[i][0];
            int newC = nowC + diff[i][1];
            if(newR >= 0 && newR < r && newC >= 0 && newC < c && board[newR][newC] == 0) {
                board[newR][newC] = 1;
                if(nowT > 1) {
                    q.push({ nowT - 1, { newR, newC }});
                }
            }
        }
    }
    
    int ans = 0;

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            ans += (board[i][j] == 1);
        }
    }

    cout << ans;
}