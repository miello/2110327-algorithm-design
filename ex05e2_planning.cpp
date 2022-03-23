#include <bits/stdc++.h>

using namespace std;

const int MXN = 1005;
vector<int> indegree(MXN, 0);
vector<bool> pass(MXN, false);
vector<int> edge[MXN];

void dfs(int now, int prev) {
    cout << now << " ";
    pass[now] = true;

    for(auto &i: edge[now]) {
        if(i == prev || pass[i]) continue;

        if(--indegree[i] == 0) {
            dfs(i, now);
        }
    }

}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        indegree[i] = m;
        for(int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            edge[x].push_back(i);
        }
    }
    for(int i = 0; i < n; ++i) {
        if(indegree[i] == 0 && !pass[i]) {
            dfs(i, -1);
        }
    }
}