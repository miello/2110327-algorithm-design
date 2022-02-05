#include <bits/stdc++.h>

using namespace std;

int recur(vector<int> &arr, int l, int r, int k) {
    if(l == r) {
        return arr[l];
    }

    int mid = (l + r) >> 1;
    int left = recur(arr, l, mid, k);
    int right = recur(arr, mid + 1, r, k);

    vector<int> leftMx, rightMx;
    
    leftMx.push_back(0);
    int ans = 0;
    for(int i = mid; i >= l && leftMx.size() != k + 1; --i) {
        ans += arr[i];
        if(leftMx.size() == 1) leftMx.push_back(ans);
        else leftMx.push_back(max(leftMx.back(), ans));
    }

    rightMx.push_back(0);
    ans = 0;
    for(int i = mid + 1; i <= r && rightMx.size() != k + 1; ++i) {
        ans += arr[i];
        if(rightMx.size() == 1) rightMx.push_back(ans);
        else rightMx.push_back(max(rightMx.back(), ans));
    }

    int mxL = leftMx.size() - 1;
    int mxR = rightMx.size() - 1;

    ans = leftMx[mxL] + rightMx[min(k - mxL, mxR)];
    for(int i = 0; i <= mxL; ++i) {
        ans = max(ans, leftMx[i] + rightMx[min(k - i, mxR)]);
    }

    return max({ ans, left, right });
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> arr(n, 0);

    for(int i = 0; i < n; ++i) { 
        cin >> arr[i];
    }

    cout << recur(arr, 0, n - 1, w);
}