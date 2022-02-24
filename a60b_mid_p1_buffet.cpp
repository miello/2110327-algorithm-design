#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, n, w;
    cin >> f >> w >> n;
    
    vector<int> pos(f, 0);
    for(int i = 0; i < f; ++i) cin >> pos[i];

    sort(pos.begin(), pos.end());
    int ans = 1, left = pos[0], right = pos[0] + 2 * w;

    for(int i = 0; i < f; ++i) {
        if(left <= pos[i] && pos[i] <= right) continue;
        else {
            ++ans;
            left = pos[i];
            right = pos[i] + 2 * w;
        }
    }

    cout << ans;
}