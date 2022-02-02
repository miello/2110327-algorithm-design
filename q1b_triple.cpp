#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for(int i = 0; i < m; ++i) {
        long long x;
        cin >> x;

        bool isFound = false;
        for(int j = 0; j < n - 2; ++j) {
            for(int k = j + 1; k < n - 1; ++k) {
                if(x - arr[j] - arr[k] < arr[k + 1]) break;
                if(binary_search(arr.begin() + k + 1, arr.end(), x - arr[j] - arr[k])) {
                    isFound = true;
                    break;
                }
            }

            if(isFound) break;
        }

        if(isFound) cout << "YES";
        else cout << "NO";

        cout << "\n";
    }
}