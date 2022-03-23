#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 5;

vector<int> edge[MXN];
vector<int> status(MXN, 0);

void dfs(int now, int prev, int &ans, int &cycle_point) {
    status[now] = 1;
    
    for(auto &i: edge[now]) {
        if(i == prev) continue;
        if(status[i] == 2) continue;

        if(status[i] == 0) {
            dfs(i, now, ans, cycle_point);
            if(cycle_point != -1) {
                ++ans;
                if(cycle_point == now) cycle_point = -1;
                break;
            }
            continue;
        }

        ++ans;
        cycle_point = i;
        break;
    }
    status[now] = 2;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int cycle_point = -1;
    int ans = 0;
    dfs(0, -1, ans, cycle_point);

    cout << ans;
}