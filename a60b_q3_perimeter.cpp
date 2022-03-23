#include <bits/stdc++.h>

using namespace std;

const int MXN = 1005;
vector<int> edge[MXN];
vector<int> dist(MXN, MXN + 1);

int main() {
    int n, e, k;
    cin >> n >> e >> k;

    for(int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    dist[0] = 0;

    int ans = 0;

    while(q.size()) {
        int now = q.front();

        q.pop();
        if(dist[now] == k) {
            ++ans;
            continue;
        }

        for(auto &i: edge[now]) {
            if(dist[i] > dist[now] + 1) {
                dist[i] = dist[now] + 1;
                q.emplace(i);
            }
        }
    }
    cout << ans;
}