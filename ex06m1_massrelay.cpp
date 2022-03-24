#include <bits/stdc++.h>

using namespace std;

const int MXN = 5005;
typedef pair<int, pair<int, int>> Edge;

vector<Edge> edge;
vector<int> par(MXN, 0);

int root(int idx) {
    if(par[idx] == idx) return idx;
    return par[idx] = root(par[idx]);
}

void mergeset(int a, int b) {
    par[root(a)] = root(b);
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; ++i) {
        par[i] = i;
    }

    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        edge.push_back({c, { a, b }});
    }
    sort(edge.begin(), edge.end());

    vector<int> ans;

    for(auto &i: edge) {
        int u = i.second.first;
        int v = i.second.second;
        int w = i.first;

        if(root(u) != root(v)) {
            mergeset(u, v);
            ans.push_back(w);
        }
    }

    reverse(ans.begin(), ans.end());
    while(q--) {
        int x;
        cin >> x;
        cout << ans[x - 1] << "\n";
    }
}