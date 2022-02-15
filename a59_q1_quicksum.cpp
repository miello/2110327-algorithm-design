#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    while(k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ++a;
        ++b;
        ++c;
        ++d;
        cout << arr[c][d] - arr[c][b - 1] - arr[a - 1][d] + arr[a - 1][b - 1] << "\n";
    }
}