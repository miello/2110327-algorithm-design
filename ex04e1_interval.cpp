#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n, {0, 0});

    for(int i = 0; i < n; ++i) {
        cin >> v[i].first;        
    }

    for(int i = 0; i < n; ++i) {
        cin >> v[i].second;
    }

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second || (a.second == b.second && a.first < b.first);
    });
    int nowF = v[0].first, nowS = v[0].second, ans = 1;
    for(int i = 1; i < n; ++i) {
        if(v[i].first >= nowS || nowF >= v[i].second) {
            nowF = v[i].first;
            nowS = v[i].second;
            ++ans;
        }
    }

    cout << ans;
}