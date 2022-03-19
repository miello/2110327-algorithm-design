#include <bits/stdc++.h>

using namespace std;

const int MXR = 101, MXC = 101, MXT = 1001;

const int diff[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int ghost[MXR][MXC];
int walk[MXR][MXC];
bool pass[MXR][MXC];

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int r, c, n, t, x, y;
        cin >> r >> c >> n >> t >> x >> y;

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                ghost[i][j] = -1;
                walk[i][j] = -1;
            }
        }

        queue<pii> q;
        vector<piii> v;
        for(int i = 0; i < n; ++i) {
            int inpT, inpX, inpY;
            cin >> inpT >> inpX >> inpY;
            
            v.push_back({ inpT, { inpX, inpY }});
        }
        sort(v.begin(), v.end());

        for(int i = 0; i < r; ++i) {
            string s;
            cin >> s;
            for(int j = 0; j < c; ++j) {
                pass[i][j] = s[j] == '.';
            }
        }

        for(int i = 0; i < (int) v.size(); ++i) {
            int inpT = v[i].first, inpX = v[i].second.first, inpY = v[i].second.second;
            if(inpT >= ghost[inpX][inpY] && ghost[inpX][inpY] != -1) continue;

            ghost[inpX][inpY] = inpT;
            q.push({ inpX, inpY });
            while(q.size()) {
                int nowX = q.front().first;
                int nowY = q.front().second;

                q.pop();
                
                for(int i = 0; i < 4; ++i) {
                    int newX = nowX + diff[i][0];
                    int newY = nowY + diff[i][1];
                    if(newX >= 0 && newX < r && newY >= 0 && newY < c) {
                        if(pass[newX][newY] && (ghost[newX][newY] == -1 || ghost[newX][newY] > ghost[nowX][nowY] + 1)) {
                            ghost[newX][newY] = ghost[nowX][nowY] + 1;
                            q.push({ newX, newY });
                        }
                    }
                }
            }
        }

        bool found = false;
        int mx = ghost[x][y];

        walk[x][y] = 0;
        q.push({ x, y });
        
        while(q.size()) {
            int nowX = q.front().first;
            int nowY = q.front().second;

            q.pop();
            if(walk[nowX][nowY] == t) continue;

            for(int i = 0; i < 4; ++i) {
                int newX = nowX + diff[i][0];
                int newY = nowY + diff[i][1];
                if(newX >= 0 && newX < r && newY >= 0 && newY < c) {
                    if(pass[newX][newY] && (walk[newX][newY] == -1)) {
                        walk[newX][newY] = walk[nowX][nowY] + 1;
                        q.push({ newX, newY });
                    }
                }
            }
        }

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(walk[i][j] != -1) {
                    if(ghost[i][j] == -1) {
                        found = true;
                        break;
                    } else {
                        mx = max(mx, ghost[i][j]);
                    }
                }
            }
            if(found) break;
        }

        if(found || mx > t) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}