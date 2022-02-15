#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e8 + 7;

void muliplier(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    vector<vector<long long>> tmp(4, vector<long long>(4, 0));
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 4; ++k) {
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] %= MOD;
            }
        }
    }

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            a[i][j] = tmp[i][j];
        }
    } 
} 

void recur(long long n, vector<vector<long long>> &transform, vector<vector<long long>> &now) {
    if(n == 0) {
        return;
    }
    recur(n >> 1, transform, now);

    muliplier(now, now);
    if(n & 1) {
        muliplier(now, transform);
    }
}

int main() {
    long long n;
    cin >> n;
    vector<vector<long long>> transform = {
        {1, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 1},
    };

    vector<vector<long long>> st = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };

    n -= 3;
    recur(n, transform, st);
    
    vector<long long> now = {2, 1, 2, 2};
    long long ans = 0;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            ans += (now[j] * st[i][j]) % MOD;
            ans %= MOD;
        }
    }

    cout << ans;
}