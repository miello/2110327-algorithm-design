#include <bits/stdc++.h>

using namespace std;
// 0 means correct
// 1 means correct if this section is mutated
// 2 means it can be both valid and invalid
// -1 means invalid
int validate(vector<int> &s, int l, int r, bool canMutate) {
    if(r - l == 1) {
        if(s[l] == s[r]) {
            return -1;         
        }
        if(s[l] == 0) {
            return 0;
        }
        return 1;
    }

    int mid = (l + r) >> 1;
    int left = validate(s, l, mid, true);
    int right = validate(s, mid + 1, r, false);

    if(left == -1 || right == -1) return -1;
    
    // right valid
    if(right == 0) {
        if(left == 0) return 0; 
        if(canMutate) return 2;
        return 0;
    }

    if(right == 1) {
        // left is valid and right needs mutate -> Invalid
        if(left == 0) return -1;
        if(left == 2) {
            if(canMutate) return 2;
            return 1;
        }

        // left and right need mutated
        if(canMutate) return 2;
        return 1;
    }

    // answer from right cannot be 2 (canMutate is required)
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        vector<int> arr(1 << k, 0);
        for(int j = 0; j < 1 << k; ++j) {
            cin >> arr[j];
        }

        int isValid = validate(arr, 0, (1 << k) - 1, false);
        if(isValid == 0) cout << "yes";
        else cout << "no";

        cout << "\n";
    }
}
