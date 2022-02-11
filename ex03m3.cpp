// O(nk) solution
#include <bits/stdc++.h>

using namespace std;

int dp[10001];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[i] = 1e9 + 7;
    }

    dp[1] = arr[1];

    for(int i = 1; i <= n; ++i) {
        int mn = 1e9 + 7;
        for(int j = 0; j <= k; ++j) {
            int prev = max(i - j - 1, 0);
            
            mn = min(dp[prev], mn);
        }
        for(int j = 0; j <= k; ++j) {
            int now = min(i + j, n);
            dp[now] = min(mn + arr[i], dp[now]);
        }
    }
    
    cout << dp[n];
}