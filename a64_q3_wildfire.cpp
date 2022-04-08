#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> b(n), st(k);
    vector<vector<int>> edge(n);
    vector<bool> pass(n, false);
    int ans = 0;

    for(int i = 0; i < n; ++i) {
        cin >> b[i];
        ans += b[i];
    }
    for(int i = 0; i < k; ++i) cin >> st[i];

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
    }

    for(int i = 0; i < k; ++i) {
        if(pass[st[i]]) {
            cout << ans << " ";
            continue;
        }

        queue<int> q;
        q.emplace(st[i]);

        while(q.size()) {
            int now = q.front();
            q.pop();

            if(pass[now]) continue;

            ans -= b[now];
            pass[now] = true;

            for(auto &j: edge[now]) {
                if(!pass[j]) q.push(j);
            }
        }

        cout << ans << " ";
    }
}