#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0), cnt(4, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        ++cnt[arr[i]];
    }

    cnt[2] += cnt[1];
    cnt[3] += cnt[2];
    int ans = 0;

    vector<vector<int>> matching(4, vector<int>(4, 0));

    for(int i = 1; i <= 3; ++i) {
        for(int j = cnt[i - 1]; j < cnt[i]; ++j) {
            if(i != arr[j]) {
                ++matching[i][arr[j]];
            }
        }
    }

    for(int i = 1; i < 3; ++i) {
        for(int j = i + 1; j <= 3; ++j) {
            int mn = min(matching[i][j], matching[j][i]);
            matching[i][j] -= mn;
            matching[j][i] -= mn;
            ans += mn;
        }
    }

    for(int i = 1; i <= 3; ++i) {
        for(int j = 1; j <= 3; ++j) {
            if(matching[i][j] != 0) {
                ans += 2 * matching[i][j];
                cout << ans;
                return 0;
            }
        }
    }

    cout << ans;
}