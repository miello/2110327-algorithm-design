#include <bits/stdc++.h>

using namespace std;

// Define v[i] means a number of path that can traverse from
// child to parent idx with length exactly i
vector<int> solve(vector<vector<int>> &edges, int idx, int k, int &ans) {
    // leaf node
    if(edges[idx].size() == 0) {
        vector<int> tmp = vector<int>(k + 1, 0);
        tmp[0] = 1;
        return tmp;
    }

    // internal node
    if(edges[idx].size() == 1) {
        vector<int> f = solve(edges, edges[idx][0], k, ans);
        for(int i = k - 1; i >= 0; --i) {
            f[i + 1] = f[i];
        }

        ans += f[k];
        f[0] = 1;
        return f;
    }

    vector<int> left = solve(edges, edges[idx][0], k, ans);
    vector<int> right = solve(edges, edges[idx][1], k, ans);

    vector<int> finalCnt = vector<int>(k + 1, 0);

    // left to right and vice-versa
    for(int i = 0; i <= k - 2; ++i) {
        ans += left[i] * right[k - i - 2];
    }

    // left to root
    for(int i = 0; i < k; ++i) {
        finalCnt[i + 1] += left[i];
    }

    // right to root
    for(int i = 0; i < k; ++i) {
        finalCnt[i + 1] += right[i];
    }

    finalCnt[0] = 1;
    ans += finalCnt[k];

    return finalCnt;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> edges(n + 1, vector<int>());
    for(int i = 1; i <= n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
    }
    int ans = 0;
    solve(edges, 1, k, ans);
    cout << ans;
}