#include <bits/stdc++.h>

using namespace std;

long long calEnergy(int avenger, int l, int r, long long a, long long b) {
    if(avenger == 0) {
        return a;
    }

    return (long long)(avenger) * b * (long long)(r - l + 1);
}

long long solve(vector<int> &avenger, int l, int r, long long a, long long b) {
    auto lBound = lower_bound(avenger.begin(), avenger.end(), l);
    auto rBound = upper_bound(avenger.begin(), avenger.end(), r);
    long long outer = calEnergy(rBound - lBound, l, r, a, b);
    
    if(r == l) {
        return outer;
    }

    if(rBound - lBound != 0) {
        int mid = (l + r) >> 1;
        long long lEnergy = solve(avenger, l, mid, a, b);
        long long rEnergy = solve(avenger, mid + 1, r, a, b);
        return min(lEnergy + rEnergy, outer);
    } else {
        return outer;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p, k;
    long long a, b;
    cin >> p >> k >> a >> b;

    vector<int> avenger(k, 0);
    for(int i = 0; i < k; ++i) cin >> avenger[i];
 
    sort(avenger.begin(), avenger.end());
    long long ans = solve(avenger, 1, 1 << p, a, b);     
    cout << ans; 
}