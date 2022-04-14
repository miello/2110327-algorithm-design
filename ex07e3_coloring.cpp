#include <bits/stdc++.h>

using namespace std;

bool solve(vector<vector<int>> &edge, vector<int> &color, int now, int n, int mxCol) {
    if(now == n) {
        return true;
    }

    int sz = color.size();

    for(int i = 0; i < mxCol; ++i) {
        bool chk = true;
        for(auto &j: edge[now]) {
            if(i == color[j]) {
                chk = false;
                break;
            }
        }
        
        if(!chk) continue;
    
        color[now] = i;
        if(solve(edge, color, now + 1, n, mxCol)) return true;
        color[now] = -1;
    }

    return false;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n);

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    for(int i = 1; i <= n; ++i) {
        vector<int> color(n, -1);
        if(solve(edge, color, 0, n, i)) {
            cout << i << endl;
            break;
        }
    }
}
