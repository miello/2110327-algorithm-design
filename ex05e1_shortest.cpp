#include <bits/stdc++.h>

using namespace std;

const int MXR = 105, MXC = 105;

int diff[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dp[MXR][MXC];
bool pass[MXR][MXC];
int r, c;

void dfs(int nowX, int nowY) {
    for(int i = 0; i < 4; ++i) {
        int newX = nowX + diff[i][0];
        int newY = nowY + diff[i][1];

        if(newX > 0 && newX <= r && newY > 0 && newY <= c && pass[newX][newY]) {
            if(dp[newX][newY] > dp[nowX][nowY] + 1) {
                dp[newX][newY] = dp[nowX][nowY] + 1;
                dfs(newX, newY);
            }
        }
    }
}

int main() {
    cin >> r >> c;

    for(int i = 1; i <= r; ++i) {
        string s;
        cin >> s;
        for(int j = 1; j <= c; ++j) {
            pass[i][j] = s[j - 1] == '.';
            dp[i][j] = MXR * MXC;
        }
    }

    dp[1][1] = 0;
    dfs(1, 1);

    if(dp[r][c] == MXR * MXC) {
        cout << -1;
    } else {
        cout << dp[r][c];
    }
}