#include <bits/stdc++.h>

using namespace std;

void gen(vector<int> &arr, int f, int s, int k) {
    if(k <= 1) return;
    if(f + 1 == s) return;
    int mid = (f + s) >> 1;

    k -= 1;
    int lMx = min(k - 1, 2 * (mid - f) - 1);
    
    gen(arr, f, mid, lMx);
    gen(arr, mid, s, k - lMx);

    if(k == 2) {
        swap(arr[mid - 1], arr[mid]);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    if(!(k & 1) || (n << 1) - 1 < k) {
        cout << -1;
        return 0;
    }

    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) arr[i] = i + 1;

    gen(arr, 0, n, k);
    for(auto &i: arr) {
        cout << i << " ";
    }
}