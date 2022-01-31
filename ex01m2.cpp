#include <bits/stdc++.h>

using namespace std;

long long merge(vector<int> &v, int f, int s, vector<int> &tmp) {
    int mid = (f + s) >> 1;
    int l = f;
    int r = mid + 1;
    int now = f;
    long long cnt = 0;
    
    while(l <= mid && r <= s) {
        if (v[l] <= v[r]) {
            cnt += r - mid - 1;
            tmp[now++] = v[l++];
        }
        else tmp[now++] = v[r++];
    }
    
    while(l <= mid) {
        tmp[now++] = v[l++];
        cnt += s - mid;
    }

        
    while(r <= s) tmp[now++] = v[r++];

    for(int i = f; i <= s; ++i) {
        v[i] = tmp[i];
    }

    return cnt;
}

long long count_inversion(vector<int> &v, int f, int s, vector<int> &tmp) {
    if(f < s) {
        int mid = (f + s) >> 1;
        long long leftCnt = count_inversion(v, f, mid, tmp);
        long long rightCnt = count_inversion(v, mid + 1, s, tmp);

        return merge(v, f, s, tmp) + leftCnt + rightCnt;
    }

    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> tmp(n, 0);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    cout << count_inversion(arr, 0, n - 1, tmp);
}
