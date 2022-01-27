#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m;
    
    vector<int> v(n, 0);

    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int i = 0; i < m; ++i) {
        cin >> k;
        int f = 0, s = n - 1, ans = -1;

        while(f <= s) {
            int mid = (f + s) >> 1;
            if(v[mid] > k) {
                s = mid - 1;
            } else {
                ans = mid;
                f = mid + 1;
            }
        }

        cout << ans << "\n";
    }
}