#include <bits/stdc++.h>

using namespace std;

const int MXK = 31;
const long long INF = 1e18 + 7;
vector<vector<long long>> upper(MXK, vector<long long>(MXK, INF));

void all_pair_resolver(vector<vector<long long>> &arr) {
    int sz = arr.size();
    for(int i = 0; i < sz; ++i) {
        for(int j = 0; j < sz; ++j) {
            for(int k = 0; k < sz; ++k) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

// Override a
void calculate_new_set(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    int sz = a.size();
    vector<vector<long long>> tmp(sz, vector<long long>(sz, INF));

    // i -> j || k -> l
    for(int i = 0; i < sz; ++i) {
        for(int j = 0; j < sz; ++j) {
            for(int k = 0; k < sz; ++k) {
                if(upper[j][k] == INF) continue;
                for(int l = 0; l < sz; ++l) {
                    tmp[i][l] = min(tmp[i][l], a[i][j] + b[k][l] + upper[j][k]);
                }
            }
        }
    }

    for(int i = 0; i < sz; ++i) {
        for(int j = 0; j < sz; ++j) {
            a[i][j] = tmp[i][j];
        }
    }
}

void solve(int n, vector<vector<long long>> &dp, vector<vector<long long>> &standalone) {
    if(n <= 1) return;
    solve(n >> 1, dp, standalone);

    calculate_new_set(dp, dp);

    if(n & 1) {
        calculate_new_set(dp, standalone);
    }
}

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<long long>> dp(k, vector<long long>(k, INF));

    for(int i = 0; i < k; ++i) {
        long long a, b;
        cin >> a >> b;
        dp[i][((i - 1 + k) % k)] = a;
        dp[i][((i + 1) % k)] = b;

        long long c, d, e;
        cin >> c >> d >> e;
        upper[i][(i - 1 + k) % k] = c;
        upper[i][i] = d;
        upper[i][(i + 1) % k] = e;
    }

    for(int i = 0; i < k; ++i) dp[i][i] = 0;

    all_pair_resolver(dp);

    vector<vector<long long>> standalone = dp;
    solve(n, dp, standalone);
    
    cout << dp[0][p];
}