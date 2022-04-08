#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, v;
    cin >> n >> k >> m >> v;

    vector<pair<int, pair<int, int>>> edge;
    vector<int> node;
    vector<int> dist(n, INF);
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        node.push_back(x);
    }
    for(int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        edge.push_back({ b, { a, c }});
    }

    dist[v] = 0;
    for(int i = 0; i < n - 1; ++i) {
        for(auto &each: edge) {
            dist[each.second.first] = min(dist[each.second.first], dist[each.first] + each.second.second);            
        }
    }

    int ans = INF;
    for(auto &i: node) {
        ans = min(ans, dist[i]);
    }
    cout << ans;
}