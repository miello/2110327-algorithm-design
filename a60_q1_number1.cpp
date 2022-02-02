#include <bits/stdc++.h>

using namespace std;

int solve(int now, int f, int s, int l, int r) {
    if(l <= f && s <= r) return now;

    if(s < l || f > r) return 0;
    if(now <= 1) return now;

    int mid = (f + s) >> 1;

    int left = solve(now >> 1, f, mid - 1, l, r);
    int right = solve(now >> 1, mid + 1, s, l, r);

    return left + right + (l <= mid && mid <= r && now & 1);
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    int now = 1;
    while(now < n) {
        now *= 2;
    }

    cout << solve(n, 1, (int)((long long)now - 1), l, r);
}