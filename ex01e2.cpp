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

    cout << ans;
}