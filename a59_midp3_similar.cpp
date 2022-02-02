#include <bits/stdc++.h>

using namespace std;

bool validChk(string &a, string &b, int lA, int lB, int rA, int rB) {
    int idxA = lA;
    int idxB = lB;
    bool isFound = true;
    while(idxA <= rA) {
        if(a[idxA++] != b[idxB++]) {
            isFound = false;
            break;
        }
    }

    if(!isFound && lA == rA) return false;
    else if(isFound) return true;

    int midA = (lA + rA) >> 1;
    int midB = (lB + rB) >> 1;

    bool chkL = validChk(a, b, lA, lB, midA, midB) && validChk(a, b, midA + 1, midB + 1, rA, rB);

    if(chkL) return true;

    bool chkR = validChk(a, b, lA, midB + 1, midA, rB) && validChk(a, b, midA + 1, lB, rA, midB);

    return chkR;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << (validChk(a, b, 0, 0, a.size() - 1, b.size() - 1) ? "YES": "NO");
}