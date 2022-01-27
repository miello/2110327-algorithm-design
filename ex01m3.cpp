#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;

    vector<long long> t(n, 0);

    for(int i = 0; i < n; ++i) cin >> t[i];
    for(int i = 0; i < a; ++i) {
        long long num;
        cin >> num;

        long long f = 0, s = 1e12;
        while(f <= s) {
            long long mid = (f + s) >> 1;
            long long cnt = 0;
            for(int j = 0; j < n; ++j) {
                cnt += (mid / t[j]) + 1;
            }

            if(cnt >= num) {
                s = mid - 1;
            } else {
                f = mid + 1;
            }
        }

        cout << f << "\n";
    }
}