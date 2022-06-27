#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> dpl(n + 1, 0);
    vector<int> dpr(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dpl[i] = arr[i];
        dpr[i] = arr[i];
    }
    int prevl = 0, nowl = 0, nowr = 0, prevr = 0;
    for(int i = 1, j = n; i <= n; ++i, --j) {
        nowl += arr[i];
        dpl[i] = nowl - prevl;
        if(i != 1) dpl[i] = max(dpl[i], dpl[i - 1]);
        prevl = min(prevl, nowl);

        nowr += arr[j];
        dpr[j] = nowr - prevr;
        if(j != n) dpr[j] = max(dpr[j], dpr[j + 1]);
        prevr = min(prevr, nowr);
    }

    int ans = dpl[1];
    for(int i = 1; i < n; ++i) {
        ans = max({ ans, dpl[i], dpr[i + 1], dpl[i] + dpr[i + 1] });
    }
    ans = max({ ans, dpl[n] });

    cout << ans;
}