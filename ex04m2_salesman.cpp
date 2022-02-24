// Is this actually greedy ???
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> order(m + 1, 0);
    vector<int> dp(m + 1, 0);

    for(int i = 0; i < m; ++i) {
        cin >> order[i];
    }

    order[m] = order[0];

    for(int i = 1; i <= m; ++i) {
        cin >> dp[i];
        dp[i] += dp[i - 1];
    }

    for(int j = 0; j < n; ++j) {
        int x, y;
        cin >> x >> y;

        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            int f = order[i];
            int s = order[i - 1];

            // Direct Case
            int direct_clock = abs(dp[s] - dp[f]);
            int direct_counter_clock = dp[m] - abs(dp[s] - dp[f]);

            // Portal Case 1
            int tmp_1 = abs(dp[x] - dp[f]);
            int tmp_2 = abs(dp[y] - dp[s]);

            int portal_1 = min(dp[m] - tmp_1, tmp_1) + min(dp[m] - tmp_2, tmp_2);

            // Portal Case 2            
            tmp_1 = abs(dp[x] - dp[s]);
            tmp_2 = abs(dp[y] - dp[f]);
            int portal_2 = min(dp[m] - tmp_1, tmp_1) + min(dp[m] - tmp_2, tmp_2);
            
            ans += min({ direct_clock, direct_counter_clock, portal_1, portal_2 });
        }

        cout << ans << "\n";
    }    
}