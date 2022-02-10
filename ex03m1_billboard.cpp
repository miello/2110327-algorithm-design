#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for(int i = 1; i <= n; ++i) cin >> arr[i];
    dp[1] = arr[1];
    
    for(int i = 2; i <= n; ++i) {
        // dp[now] = maximum of (not choose at now case, choose at now case)
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    cout << dp[n];
}