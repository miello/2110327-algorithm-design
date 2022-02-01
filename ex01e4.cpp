#include <bits/stdc++.h>

using namespace std;

int recur(int x, int n, int k) {
    if(n == 0) return 1;

    int tmp = recur(x, n >> 1, k); 
    
    tmp *= tmp;
    tmp %= k;

    if(n & 1) {
        return (tmp * x) % k;
    } else {
        return tmp;
    }
}

int main() {
    int x, n, k;
    cin >> x >> n >> k;

    cout << recur(x, n, k);
}