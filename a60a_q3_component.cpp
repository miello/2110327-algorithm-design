#include <bits/stdc++.h>

using namespace std;

const int MXN = 10005;
vector<int> pass(MXN, false);
vector<vector<int>> edge(MXN, vector<int>());

void dfs(int now, int prev) {
    pass[now] = true;
    for(auto &i: edge[now]) {
        if(i == prev || pass[i]) continue;
        dfs(i, now);
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(!pass[i]) {
            ++ans;
            dfs(i, -1);
        }
    }

    cout << ans;
}