#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e3 + 5;

vector<int> edge[MXN];
vector<int> edgeT[MXN];
vector<int> pass(MXN, false);

stack<int> final_time;
vector<int> comp_sz;

void dfsT(int now) {
    pass[now] = true;
    for(auto &i: edgeT[now]) {
        if(!pass[i]) {
            dfsT(i);
        }
    }

    final_time.push(now);
}

int dfs(int now) {
    pass[now] = true;
    int ans = 1;
    for(auto &i: edge[now]) {
        if(!pass[i]) {
            ans += dfs(i);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for(int j = 0; j < m; ++j) {
            int x;
            cin >> x;

            edge[i].push_back(x);
            edgeT[x].push_back(i);
        }
    }

    for(int i = 0; i < n; ++i) {
        if(!pass[i]) dfsT(i);           
    }

    fill(pass.begin(), pass.begin() + n, false);

    while(final_time.size()) {
        int now = final_time.top();

        final_time.pop();
        if(!pass[now]) comp_sz.push_back(dfs(now));
    }

    sort(comp_sz.begin(), comp_sz.end());
    for(auto &i: comp_sz) {
        cout << i << " ";
    }
}