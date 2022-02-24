#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> t(m, 0);
    for(int i = 0; i < m; ++i) cin >> t[i];
    
    sort(t.begin(), t.end());
    double ans = 0;
    for(int i = 0; i < n; ++i) {
        double now = 0;
        for(int j = i; j < m; j += n) {
            now += t[j];
            ans += now;
        }
    }

    printf("%.3f", ans / m);
}