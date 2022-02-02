#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n, 0);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    long long prev = 0, now = 0, ans = arr[0];

    for(int i = 0; i < n; ++i) {
        now += arr[i];
        ans = max(ans, now - prev);
        prev = min(now, prev);
    }

    vector<long long> mxL(n + 1, 0), mxR(n + 1, 0);

    mxL[0] = arr[0];
    now = arr[0];

    for(int i = 1; i < n; ++i) {
        now += arr[i];
        mxL[i] = max(mxL[i - 1], now);
    }
    
    mxR[n - 1] = arr[n - 1];
    now = arr[n - 1];

    for(int i = n - 2; i >= 0; --i) {
        now += arr[i];
        mxR[i] = max(mxR[i + 1], now);
    } 

    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            ans = max(ans, mxR[i]);
        } else if(i == n - 1) {
            ans = max(ans, mxR[i]);
        } else {
            ans = max(ans, mxL[i - 1] + mxR[i]);
        }
    }

    cout << ans;
}