#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int now = 1, prev = 0, next = 1;

    while(--n) {
        now = prev + next;
        prev = next;
        next = now;
    }
    cout << now;
}