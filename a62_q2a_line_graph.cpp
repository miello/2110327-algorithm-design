#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 2;
vector<int> edge[MXN];
vector<bool> pass(MXN, false);

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(edge[i].size() == 1 && !pass[i]) {
            bool found = true;
            queue<int> q;
            q.emplace(i);
            
            int foundOne = 0;
            
            while(q.size()) {
                int now = q.front();
                
                q.pop();
                pass[now] = true;

                if(edge[now].size() == 1) ++foundOne;
                else if(edge[now].size() > 2) found = false;

                for(auto &j: edge[now]) {
                    if(!pass[j]) {
                        q.emplace(j);
                    }
                } 
            }

            if(foundOne != 2) {
                found = false;
            }

            ans += found;
        } else if(edge[i].size() == 0) {
            pass[i] = true;
            ++ans;
        }
    }

    cout << ans;
}