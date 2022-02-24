#include <bits/stdc++.h>

using namespace std;

int main() {
    double w;
    int n;
    cin >> w >> n;

    vector<double> value(n, 0.0);
    vector<double> weight(n, 0.0);

    vector<pair<double, int>> arr;

    for(int i = 0; i < n; ++i) cin >> value[i];
    double now = 0.0, ans = 0.0;
    for(int i = 0; i < n; ++i) {
        cin >> weight[i];
        // Somehow it got weight = 0 in testcase
        if(weight[i] == 0) {
            now += value[i];
            continue;
        }
        arr.emplace_back(value[i] / weight[i], i);
    }

    sort(arr.begin(), arr.end(), greater<pair<double, int>>());
    for(int i = 0; i < n && w > 0; ++i) {
        double nowW = min(w, weight[arr[i].second]);
        now += arr[i].first * nowW;
        ans = max(ans, now);
        w -= nowW;
    }

    printf("%.4f", ans);
}