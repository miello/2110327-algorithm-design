#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e6 + 3;

void recur(int now, vector<int> &dp, vector<int> &arr) {
    if(now == 0) return;

    for(int &i: arr) {
        if(now >= i) {
            if(dp[now - i] == 0) {
                recur(now - i, dp, arr);
            }
            dp[now] += dp[now - i];
            dp[now] %= MOD;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(k, 0);
    vector<int> dp(n + 1, 0);
    for(int i = 0; i < k; ++i) {
        cin >> arr[i];
    }

    dp[0] = 1;

    recur(n, dp, arr);
    cout << dp[n];
}