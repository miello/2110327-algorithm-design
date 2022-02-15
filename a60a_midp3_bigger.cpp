#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> dp[i];
    for(int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[max(0, i - 3)] + dp[i]);
    } 

    cout << dp[n];
}