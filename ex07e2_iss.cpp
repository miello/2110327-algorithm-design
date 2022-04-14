#include <bits/stdc++.h>

using namespace std;

void recur_count(int n, int prev, int &ans) {
    if(n == 0) {
        ++ans;
        return;
    }

    for(int i = prev; i <= n; ++i) {
        recur_count(n - i, i, ans);
    }
}

int main() {
    int n;
    cin >> n;

    int ans = 0;

    recur_count(n, 1, ans);
    cout << ans;
}