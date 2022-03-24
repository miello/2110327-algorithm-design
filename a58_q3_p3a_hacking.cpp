#include <bits/stdc++.h>

using namespace std;

const int MXN = 50005, INF = 1e9 + 7;
vector<int> edge[MXN];
vector<int> st, val(MXN, 0), dp(MXN, INF);

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        st.push_back(x);
    }

    for(int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < k; ++i) {
        dp[st[i]] = val[st[i]];
        pq.emplace(val[st[i]], st[i]);
    }

    while(pq.size()) {
        int u = pq.top().second;

        pq.pop();

        for(auto &i: edge[u]) {
            if(dp[i] > dp[u] + val[i]) {
                dp[i] = dp[u] + val[i];
                pq.emplace(dp[i], i);
            }
        }
    }

    int mx = -1;

    for(int i = 0; i < n; ++i) {
        if(dp[i] == INF) continue;
        mx = max(mx, dp[i]);
    }

    cout << mx;
}