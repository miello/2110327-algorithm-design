#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, m;
    cin >> n >> k >> m;
    
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> dp[i];
        dp[i] -= m;
        dp[i] += dp[i - 1];
    }

    while(k--) {
        int a, b;
        cin >> a >> b;

        b += dp[a - 1];
        auto fin = lower_bound(dp.begin() + 1, dp.begin() + n + 1, b);
        if(fin == dp.end()) {
            cout << n << "\n";
            continue;
        }
        cout << fin - dp.begin() << "\n";
    }
}