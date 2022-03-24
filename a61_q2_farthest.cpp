#include <bits/stdc++.h>

using namespace std;

const int MXN = 1001;
const int INF = 1e9 + 7;

int dist[MXN][MXN];
int dp[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        dp[i] = INF;
        for(int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
        }
    }

    dp[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 1);

    while(pq.size()) {
        int u = pq.top().second;

        pq.pop();

        for(int i = 1; i <= n; ++i) {
            if(dist[u][i] != -1 && dp[i] > dp[u] + dist[u][i]) {
                dp[i] = dp[u] + dist[u][i];
                pq.emplace(dp[i], i);
            }
        }
    }

    int mx = -1;
    for(int i = 1; i <= n; ++i) {
        if(dp[i] == INF) {
            cout << -1;
            return 0;
        }
        mx = max(mx, dp[i]);
    }
    cout << mx;
}