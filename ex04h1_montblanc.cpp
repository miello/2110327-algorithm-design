#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int calculate_day(int k, vector<int> &h) {
    if(h[0] > k) return -1;
    int sz = h.size(), now = k, day = 1;
    for(int i = 0; i < sz; ++i) {
        if(now < h[i]) {
            ++day;
            now = h[i - 1] + k;
            if(now < h[i]) return -1;
        }
    }

    return day;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n, 0);
    for(int i = 0; i < n; ++i) cin >> h[i];

    int f = 0, s = h[n - 1], ansK = -1, ansDay = -1;
    while(f <= s) {
        int mid = f + (s - f) / 2;
        int day = calculate_day(mid, h);

        if(day == -1 || day > m) {
            f = mid + 1;
        } else {
            ansDay = day;
            ansK = mid;
            s = mid - 1;
        }
    }

    cout << ansK << " " << ansDay;
}