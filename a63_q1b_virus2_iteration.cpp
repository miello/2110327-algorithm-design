#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        int sz = 1 << k;
        vector<int> arr(sz, 0);

        queue<int> q;
        for(int i = 0; i < sz; ++i) {
            int x;
            cin >> x;
            q.emplace(x);
        }

        while(true) {
            if(q.size() == 1) {
                cout << "yes" << "\n";
                break;
            }

            auto x = q.front();
            q.pop();

            auto y = q.front();
            q.pop();

            if(abs(x - y) <= 1) {
                q.push(x + y);
            } else {
                cout << "no" << "\n";
                break;
            }
        }
    }
}