#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    
    vector<int> arr(n + 1, 0);

    for(int i = 1; i <= n; ++i) { 
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    
    int ans = arr[1];
    int mn = 0;
    int j = 0;
    for(int i = 1; i <= n; ++i) {
        int now = arr[i];

        if(i - j > w) {
            mn = arr[j + 1];
            for(int k = j + 1; k < i; ++k) {
                if(mn >= arr[k]) {
                    mn = arr[k];
                    j = k;
                }
            }
        }
        ans = max(ans, now - mn);

        if(arr[i] < mn) {
            mn = arr[i];
            j = i;
        }
    }

    cout << ans;
}