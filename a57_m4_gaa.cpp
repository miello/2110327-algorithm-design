#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void findGaa(int pos, int idx, vector<int> &gaaCnt) {
    if(idx == 0) {
        if(pos == 1) cout << "g";
        else cout << "a";
        exit(0);
    }

    int midSt = gaaCnt[idx - 1] + 1;
    int midEd = midSt + idx + 2;

    if(midSt <= pos && pos <= midEd) {
        if(midSt == pos) cout << "g";
        else cout << "a";
        exit(0);
    }

    if (pos <= gaaCnt[idx - 1]) findGaa(pos, idx - 1, gaaCnt);
    else findGaa(pos - gaaCnt[idx - 1] - idx - 3, idx - 1, gaaCnt);
} 

int main() {
    vector<int> gaaCnt;
    gaaCnt.push_back(3);

    int cnt = 1;
    while(gaaCnt.back() < (int)1e9) {
        gaaCnt.push_back(gaaCnt.back() * 2 + cnt + 3);
        ++cnt;
    }

    int n, idx;
    cin >> n;

    findGaa(n, cnt - 1, gaaCnt);
}