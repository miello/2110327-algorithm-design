#include <bits/stdc++.h>

using namespace std;

void merge(vector<pair<int, int>> &yPos, int f, int s, vector<bool> &cnt) {
    int mid = (f + s) >> 1;
    int l = f;
    int r = mid + 1;
    int sz = s - f + 1;
    int now = 0;

    vector<pair<int, int>> tmp(sz);

    while(l <= mid && r <= s) {
        if(yPos[l].first <= yPos[r].first) {
            cnt[yPos[l].second] = true;
            tmp[now++] = yPos[l++];
        } else {
            tmp[now++] = yPos[r++];
        }
    }

    while(l <= mid) {
        tmp[now++] = yPos[l++];
    }

    while(r <= s) {
        tmp[now++] = yPos[r++];
    }

    for(int i = f; i <= s; ++i) {
        yPos[i] = tmp[i - f];
    }
}

void solveY(vector<pair<int, int>> &yPos, int f, int s, vector<bool> &cnt) {
    if(s <= f) return;

    int mid = (f + s) >> 1;
    solveY(yPos, f, mid, cnt);
    solveY(yPos, mid + 1, s, cnt);

    merge(yPos, f, s, cnt);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n, pair<int, int>());

    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        arr[i] = { x, y };
    }

    sort(arr.begin(), arr.end());
    vector<pair<int, int>> yPos(n, pair<int, int>());
    vector<bool> cnt(n, false);

    for(int i = 0; i < n; ++i) {
        yPos[i] = { arr[i].second, i };
    }

    solveY(yPos, 0, n - 1, cnt);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(!cnt[i]) ++ans;
    }

    cout << ans;
}