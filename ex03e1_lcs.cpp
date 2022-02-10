#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

int main() {
    string a, b;
    cin >> a >> b;

    int szA = a.length();
    int szB = b.length();

    for(int i = 0; i < szA; ++i) {
        for(int j = 0; j < szB; ++j) {
            if(a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    cout << dp[szA][szB];
}