#include <bits/stdc++.h>

using namespace std;

const int MXN = 1005;
vector<int> indegree(MXN, 0);
vector<int> edge[MXN];

int main() {
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        ++indegree[b];
    }

    for(int i = 0; i < 5; ++i) {
        bool found = true;
        vector<int> cpy(indegree), order;
        for(int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            order.push_back(x);
        }
        
        for(int j = 0; j < n; ++j) {
            int x = order[j];
            if(cpy[x] == 0) {                
                for(auto &to: edge[x]) {
                    --cpy[to];
                }
            } else {
                found = false;
                break;
            }
        }

        if(found) {
            cout << "SUCCESS\n";
        } else {
            cout << "FAIL\n";
        }
    }
}