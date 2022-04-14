#include <bits/stdc++.h>

using namespace std;

void recur(int now, int n, vector<int> &col, vector<bool> &pass, int &ans) {
    if(now == n) {
        ++ans;
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!pass[i]) {
            bool collide = false;
            
            for(int j = now - 1; j >= 0; --j) {
                if(abs(now - j) == abs(col[j] - i)) {
                    collide = true;
                    break;
                }
            }

            if(collide) continue;
            pass[i] = true;
            col[now] = i;
            recur(now + 1, n, col, pass, ans);
            pass[i] = false;
        }
    }
}

int main() {
    int n, ans = 0;
    cin >> n;

    vector<int> col(n, -1);
    vector<bool> pass(n, false);
    recur(0, n, col, pass, ans);

    cout << ans;
}