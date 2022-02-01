#include <bits/stdc++.h>

using namespace std;

pair<int, bool> validate(vector<int> &arr, int l, int r) {
    if(r - l == 1) {
        return { arr[l] + arr[r], true };
    }

    int mid = (l + r) >> 1;
    auto left = validate(arr, l, mid);
    auto right = validate(arr, mid + 1, r);

    if(!left.second || !right.second) return { -1, false };
    return { left.first + right.first, abs(left.first - right.first) <= 1 };
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        int sz = 1 << k;
        vector<int> arr(sz, 0);
        for(int i = 0; i < sz; ++i) cin >> arr[i];

        auto ans = validate(arr, 0, sz - 1);
        cout << (ans.second ? "yes" : "no") << "\n";
    }
}