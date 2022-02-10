#include <bits/stdc++.h>

using namespace std;

void recur(vector<int> &arr, vector<bool> &chk, vector<pair<int, int>> &condition, vector<int> &pos, int n, int idx) {
    for(auto &i: condition) {
        if(pos[i.first] == -1) {
            if(pos[i.second] != -1) return;
        } else if(pos[i.first] != -1 && pos[i.second] != -1) {
            if(pos[i.first] > pos[i.second]) return;
        }
    }
    if(n == idx) {
        for(auto &i: arr) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(!chk[i]) {
            chk[i] = true;
            arr[idx] = i;
            pos[i] = idx;
            recur(arr, chk, condition, pos, n, idx + 1);

            chk[i] = false;
            pos[i] = -1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> now(n, 0);
    vector<bool> chk(n, false);
    vector<int> pos(n, -1);
    vector<pair<int, int>> condition;
    
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        condition.emplace_back(a, b);
    }

    recur(now, chk, condition, pos, n, 0);
}
