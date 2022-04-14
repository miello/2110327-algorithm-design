#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n);
    

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    int ans = n;
    for(int i = 0; i < n; ++i) {
        queue<int> q;
        q.push(i);

        int tmp = -1;
        vector<int> color(n, -1);
                
        while(!q.empty()) {
            int now = q.front();
            q.pop();

            if(color[now] != -1) continue;

            vector<bool> pass(n + 1, false);
            for(auto &j: edge[now]) {
                if(color[j] != -1) {
                    pass[color[j]] = true;
                    continue;
                }
                q.emplace(j);
            }

            for(int j = 0; j <= n; ++j) {
                if(!pass[j]) {
                    color[now] = j;
                    break;
                }
            }
        }

        for(int j = 0; j < n; ++j) {
            if(color[j] == -1) continue;
            tmp = max(tmp, color[j] + 1);
        }
        ans = min(tmp, ans);
    }


    cout << ans;
}
