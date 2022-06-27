#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e8 + 7;

void mul(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    vector<vector<long long>> tmp(3, vector<long long>(3, 0));
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                tmp[i][j] += (a[i][k] * b[k][j]) % MOD;
                tmp[i][j] %= MOD;
            }
        }
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            a[i][j] = tmp[i][j];
        }
    }
}

void solve(vector<vector<long long>> &dp, vector<vector<long long>> &base, int n) {
    if(n == 0) return;

    solve(dp, base, n >> 1);
    mul(dp, dp);
    if(n & 1) {
        mul(dp, base);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<long long>> dp = {
        { 1, 1, 1 },
        { 1, 0, 1 },
        { 1, 1, 0 },
    };

    vector<vector<long long>> ans = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    };

    --n;
    solve(ans, dp, n);

    long long ansVal = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            ansVal += ans[i][j];
            ansVal %= MOD;
        }
    }

    cout << ansVal;
}