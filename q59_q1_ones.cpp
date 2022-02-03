#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &ones, int prev) {
    if(n <= 11) {
        return min(n, 2 + (11 - n));
    }

    int cur = 0;

    for(int i = 0; i < 10; ++i) {
        if(n == ones[i]) {
            return i + 1;
        } else if(n > ones[i]) {
            cur = i;
        } else {
            break;
        }
    }

    int next = cur + 1;

    int invNow = n - ones[cur];
    int invNext = ones[next] - n;

    int left = cur + 1 + solve(invNow, ones, prev);

    if(prev != next) {
        return min(left, next + 1 + solve(invNext, ones, next));
    }

    return left;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> ones(10, 0);
    
    int now = 10;
    ones[0] = 1;
    
    for(int i = 1; i < 10; ++i) {
        ones[i] = ones[i - 1] + now;
        now *= 10;
    }
    
    cout << solve(n, ones, -1) << "\n";
}