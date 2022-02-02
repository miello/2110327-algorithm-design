#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> arr;

    long long idx = 2, now = 2;
    long long p = 3;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(3);

    while(arr.back() <= 2e9) {
        while(p <= arr[idx]) {
            arr.push_back(arr.back() + now);
            if(arr.back() > 2e9) break;
            ++p;
        }
        
        ++idx;
        ++now;
    }

    int sz = arr.size();
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        long long x;
        cin >> x;

        auto lBound = lower_bound(arr.begin(), arr.end(), x);

        cout << lBound - arr.begin() << "\n";
    }
}