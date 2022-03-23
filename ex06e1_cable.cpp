#include <bits/stdc++.h>

using namespace std;

const int MXN = 1005;
vector<int> par(MXN, 0);

int root(int idx) {
    while(idx != par[par[idx]]) {
        par[idx] = par[par[idx]];
        idx = par[par[idx]];
    }

    return idx;
}

void mergeroot(int a, int b) {
    par[root(a)] = root(b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> edge;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int x;
            cin >> x;
            edge.push_back({x, { i, j }});
        }
    }

    for(int i = 0; i < n; ++i) {
        par[i] = i;
    }

    int ans = 0;
    sort(edge.begin(), edge.end());

    for(auto &i: edge) {
        int u = i.second.first;
        int v = i.second.second;
        int w = i.first;

        if(root(u) != root(v)) {
            mergeroot(u, v);
            ans += w;
        }
    }

    cout << ans;
}