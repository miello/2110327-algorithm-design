#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    deque<pair<int, int>> dq;
    vector<int> arr(n + 1, 0);

    for(int i = 1; i <= n; ++i) { 
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    
    dq.push_back({ 0, 0 });
    int ans = arr[1];
    for(int i = 1; i <= n; ++i) {
        while(dq.size() && i - dq.front().second > w) {
            dq.pop_front();
        }
        ans = max(ans, arr[i] - dq.front().first);

        while (dq.size() && dq.back().first > arr[i]) {
            dq.pop_back();
        }

        dq.push_back({ arr[i], i });
    }

    cout << ans;
}