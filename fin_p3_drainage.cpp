#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> pos(n, 0);
    for(int i = 0; i < n; ++i) cin >> pos[i];

    sort(pos.begin(), pos.end());

    int now = pos[0], used = 1;
    for(int i = 0; i < n; ++i) {
        if(now + l - 1 >= pos[i]) {
            continue;
        } else {
            ++used;
            now = pos[i];
        }
    }

    cout << used;
}