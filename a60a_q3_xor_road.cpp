#include <bits/stdc++.h>

using namespace std;

const int MXN = 2005;
const int INF = INT_MAX;
vector<bool> selected(MXN, false);
vector<long long> dist(MXN, 0);
vector<int> num(MXN, 0);

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> num[i];

    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        int v = -1;
        for(int j = 0; j < n; ++j) {
            if(!selected[j] && (v == -1 || dist[j] > dist[v])) {
                v = j;
            }
        }

        selected[v] = true;
        ans += dist[v];

        for(int j = 0; j < n; ++j) {
            if(v != j && (num[j] ^ num[v]) > dist[j]) {
                dist[j] = num[j] ^ num[v];
            }
        }
    }

    cout << ans;
}