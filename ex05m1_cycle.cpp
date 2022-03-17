#include <bits/stdc++.h>

using namespace std;

const int MXN = 1005;

vector<int> edge[MXN];
vector<bool> visited(MXN, false);

bool dfs(int now, int prev) {
    if(visited[now]) return true;
    visited[now] = true;
    for(auto i: edge[now]) {
        if(i != prev) {
            if(dfs(i, now)) return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            edge[i].clear();
            visited[i] = false;
        }
        for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        bool cycle = false;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                if(dfs(i, -1)) {
                    cycle = true;
                    break;
                }
            }
        }

        if(cycle) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}