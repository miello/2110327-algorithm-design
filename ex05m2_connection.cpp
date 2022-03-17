#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e3 + 5;

vector<int> edge[MXN];
vector<bool> visited(MXN, false);

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    queue<pair<int, int>> q;

    for(int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int mx = 0;
    for(int i = 0; i < n; ++i) {
        while(q.size()) q.pop();
        q.push({i, 0});

        int ans = 0;
        fill(visited.begin(), visited.begin() + n, false);

        visited[i] = true;

        while(q.size()) {
            int now = q.front().first;
            int cnt = q.front().second;

            q.pop();
            ++ans;

            if(cnt == k) continue;
            

            for(auto &i: edge[now]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.emplace(i, cnt + 1);
                }
            }
        }
        mx = max(ans, mx);
    }
    cout << mx;
}