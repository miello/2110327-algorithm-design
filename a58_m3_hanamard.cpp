#include <bits/stdc++.h>

using namespace std;

vector<int> gen(int l, int r, vector<int> &arr) {
    if(l == r) {
        return { arr[l] };
    }

    int mid = (l + r) >> 1;
    
    vector<int> left = gen(l, mid, arr);
    vector<int> right = gen(mid + 1, r, arr);

    vector<int> fin;
    for(int i = 0; i < left.size(); ++i) fin.push_back(left[i] + right[i]);
    for(int i = 0; i < left.size(); ++i) fin.push_back(left[i] - right[i]);

    return fin;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(auto &i: gen(0, n - 1, arr)) cout << i << " ";
}