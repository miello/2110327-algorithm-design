#include <bits/stdc++.h>

using namespace std;

void mul(vector<vector<int>> &a, vector<vector<int>> b, int mod) {
    vector<vector<int>> tmp(2, vector<int>(2, 0));

    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) {
                tmp[i][j] += (a[i][k] * b[k][j]) % mod;
                tmp[i][j] %= mod;
            }
        }
    }

    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            a[i][j] = tmp[i][j];
        }
    }
}

void recur(vector<vector<int>> &now, vector<vector<int>> base, int n, int k) {
    if(n == 0) return;

    recur(now, base, n >> 1, k);
    if(n > 1) mul(now, now, k);
    
    if(n & 1) {
        mul(now, base, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(2, vector<int>(2, 0));
    vector<vector<int>> ans(2, vector<int>(2, 1));

    ans[0][1] = 0;
    ans[1][0] = 0;

    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            cin >> arr[i][j];
        }
    }

    recur(ans, arr, n, k);
    
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            cout << ans[i][j] << " ";
        }
    }
}